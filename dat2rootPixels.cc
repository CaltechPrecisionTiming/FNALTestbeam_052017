// C++ includes
#include <fstream>
#include <string>
#include <iostream>

// ROOT includes
#include <TROOT.h>
#include <TStyle.h>
#include <TFile.h>
#include <TTree.h>
#include <TGraphErrors.h>
#include <TCanvas.h>

//LOCAL INCLUDES
#include "Aux.hh"
#include "Config.hh"

using namespace std;

struct FTBFPixelEvent {
    double xSlope;
    double ySlope;
    double xIntercept;
    double yIntercept;
    double chi2;
    int trigger;
    int runNumber;
    Long64_t timestamp;    
};


TStyle* style;

int graphic_init();

std::string ParseCommandLine( int argc, char* argv[], std::string opt )
{
  for (int i = 1; i < argc; i++ )
    {
      std::string tmp( argv[i] );
      if ( tmp.find( opt ) != std::string::npos )
        {
          if ( tmp.find( "=" )  != std::string::npos ) return tmp.substr( tmp.find_last_of("=") + 1 );
	  if ( tmp.find( "--" ) != std::string::npos ) return "yes";
	}
    }
  
  return "";
};


int main(int argc, char **argv) {
  gROOT->SetBatch();

  FILE* fp1;
  char stitle[200];
  int dummy;

  //**************************************
  // Parse command line arguments
  //**************************************

  int numRequiredArgs = 4;
  if (argc - 1 < numRequiredArgs) {
      std::cerr << "Usage: dat2root in_file.dat inputPixelFile.root outputFile.root num_events" << std::endl;
      return -1;
  }
  std::cout << "\n=== Beginning program ===\n" << std::endl;

  std::string inputFilename = argv[1];
  std::string pixelInputFilename = argv[2];
  std::string outputFilename = argv[3];
  std::cout << "Input file: " << inputFilename << std::endl;
  std::cout << "Pixel Input file: " << pixelInputFilename << std::endl;
   std::cout << "Output file: " << outputFilename << std::endl;
   
  // Check if has valid input file, otherwise exit with error
  ifstream ifile(inputFilename);
  if (!ifile) {
    printf("!USAGE! Input file does not exist. Please enter valid file name"); 
    exit(0);
  }

  int nEvents = atoi(argv[4]);
  std::cout << "Will process " << nEvents << " events" << std::endl;

  // Board number is fixed at 1 for now because we only have one board
  std::string boardNumber = "1";
  std::cout << "Will use calibration files for board number " << boardNumber << "\n";

  bool saveRaw = false;
  std::string _saveRaw = ParseCommandLine( argc, argv, "--saveRaw" );
  if ( _saveRaw == "yes" ) {
      saveRaw = true;
      std::cout << "Will save raw pulses\n";
  }

  bool drawDebugPulses = false;
  std::string _drawDebugPulses = ParseCommandLine( argc, argv, "--debug" );
  if ( _drawDebugPulses == "yes" ) {
    drawDebugPulses = true;
    std::cout << "draw: " << drawDebugPulses << std::endl;
  }

  std::string configName = "config/15may2017.config";
  //std::string configName = "alignmentTestConfig.config";
  std::string _configName = ParseCommandLine( argc, argv, "--config" );
  if ( _configName != "" ) {
    configName = _configName;
  }
  
  std::cout << "\n=== Parsing configuration file " << configName << " ===\n" << std::endl;
  Config config(configName);
  if ( !config.hasChannels() || !config.isValid() ) {
    std::cerr << "\nFailed to load channel information from config " << configName << std::endl;
    return -1;
  }

  //**************************************
  // Load Voltage Calibration
  //**************************************

  std::cout << "\n=== Loading voltage calibration ===\n" << std::endl;
  double off_mean[4][9][1024];
  for( int i = 0; i < 4; i++ ){
      sprintf( stitle, "v1740_bd%s_group_%d_offset.txt", boardNumber.c_str(), i );
      fp1 = fopen( stitle, "r" );
      printf("Loading offset data from %s\n", stitle);

      for( int k = 0; k < 1024; k++ ) {     
          for( int j = 0; j < 9; j++ ){      
              dummy = fscanf( fp1, "%lf ", &off_mean[i][j][k] ); 
          }
      }
      fclose(fp1);
  }

  //**************************************
  // Load Time Calibration
  //**************************************

  std::cout << "\n=== Loading time calibration ===\n" << std::endl;
  double fdummy;
  double tcal_dV[4][1024];
  for( int i = 0; i < 4; i++ ) {
      sprintf( stitle, "v1740_bd%s_group_%d_dV.txt", boardNumber.c_str(), i );
      fp1 = fopen( stitle, "r" );
      printf("Loading dV data from %s\n", stitle);

      for( int k = 0; k < 1024; k++)      
          dummy = fscanf( fp1, "%lf %lf %lf %lf %lf ", 
                  &fdummy, &fdummy, &fdummy, &fdummy, &tcal_dV[i][k] ); 
      fclose(fp1);
  }
  double dV_sum[4] = {0, 0, 0, 0};
  for( int i = 0; i < 4; i++ ) {
      for( int j = 0; j < 1024; j++ )
          dV_sum[i] += tcal_dV[i][j];
  }

  double tcal[4][1024];
  for( int i = 0; i < 4; i++) {
      for( int j = 0; j < 1024; j++) {
          tcal[i][j] = tcal_dV[i][j] / dV_sum[i] * 200.0;
      }
  }
  
  //**************************************
  // Define output
  //**************************************

  TFile* file = new TFile( outputFilename.c_str(), "RECREATE", "CAEN V1742");
  TTree* tree = new TTree("pulse", "Digitized waveforms");

  int event;
  short tc[4]; // trigger counter bin
  float time[4][1024]; // calibrated time
  short raw[36][1024]; // ADC counts
  short channel[36][1024]; // calibrated input (in V)
  double channelFilter[36][1024]; // calibrated input (in V)
  float xmin[36]; // location of peak
  float base[36]; // baseline voltage
  float amp[36]; // pulse amplitude
  float integral[36]; // integral in a window
  float integralFull[36]; // integral over all bins
  float gauspeak[36]; // time extracted with gaussian fit
  float sigmoidTime[36];//time extracted with sigmoid fit
  float fullFitTime[36];//time extracted with sigmoid fit
  float linearTime0[36]; // constant fraction fit coordinates
  float linearTime15[36];
  float linearTime30[36];
  float linearTime45[36];
  float linearTime60[36];
  float fallingTime[36]; // falling exponential timestamp    
  float risetime[36]; 
  float constantThresholdTime[36];
  bool _isRinging[36];
 
  float xIntercept;
  float yIntercept;
  float xSlope;
  float ySlope;
  float x1;
  float y1;
  float x2;
  float y2;
  float chi2;
  int ntracks;

  tree->Branch("event", &event, "event/I");
  tree->Branch("tc", tc, "tc[4]/s");
  if (saveRaw) {
    tree->Branch("raw", raw, "raw[36][1024]/S");   
  }
  tree->Branch("channel", channel, "channel[36][1024]/S");
  tree->Branch("channelFilter", channelFilter, "channelFilter[36][1024]/D");
  tree->Branch("time", time, "time[4][1024]/F");
  tree->Branch("xmin", xmin, "xmin[36]/F");
  tree->Branch("amp", amp, "amp[36]/F");
  tree->Branch("base", base, "base[36]/F");
  tree->Branch("integral", integral, "integral[36]/F");
  tree->Branch("intfull", integralFull, "intfull[36]/F");
  tree->Branch("gauspeak", gauspeak, "gauspeak[36]/F");
  tree->Branch("sigmoidTime", sigmoidTime, "sigmoidTime[36]/F");
  tree->Branch("fullFitTime", fullFitTime, "fullFitTime[36]/F");
  tree->Branch("linearTime0", linearTime0, "linearTime0[36]/F");
  tree->Branch("linearTime15", linearTime15, "linearTime15[36]/F");
  tree->Branch("linearTime30", linearTime30, "linearTime30[36]/F");
  tree->Branch("linearTime45", linearTime45, "linearTime45[36]/F");
  tree->Branch("linearTime60", linearTime60, "linearTime60[36]/F");
  tree->Branch("fallingTime", fallingTime, "fallingTime[36]/F");
  tree->Branch("risetime", risetime, "risetime[36]/F");
  tree->Branch("constantThresholdTime", constantThresholdTime, "constantThresholdTime[36]/F");
  tree->Branch("isRinging", _isRinging, "isRinging[36]/O");
  tree->Branch("xIntercept", &xIntercept, "xIntercept/F");
  tree->Branch("yIntercept", &yIntercept, "yIntercept/F");
  tree->Branch("xSlope", &xSlope, "xSlope/F");
  tree->Branch("ySlope", &ySlope, "ySlope/F");
  tree->Branch("x1", &x1, "x1/F");
  tree->Branch("y1", &y1, "y1/F");
  tree->Branch("x2", &x2, "x2/F");
  tree->Branch("y2", &y2, "y2/F");
  tree->Branch("chi2", &chi2, "chi2/F");
  tree->Branch("ntracks", &ntracks, "ntracks/I");

  // temp variables for data input
  uint   event_header;
  uint   temp[3];
  ushort samples[9][1024];

  //*************************
  // Open Pixel Tree
  //*************************
  TFile *pixelDataFile = TFile::Open( pixelInputFilename.c_str(),"READ");
  if (!pixelDataFile) {
    cout << "Error: Pixel file not found\n";
    return 0;
  }
  TTree *pixelTree = (TTree*)pixelDataFile->Get("T1037");
  if (!pixelTree) {
    cout << "Error: Pixel Tree not found\n";
    return 0;
  }
 
  FTBFPixelEvent pixelEvent;
  pixelTree->SetBranchAddress("event",&pixelEvent);
  // for( int iEvent = 0; iEvent < pixelTree->GetEntries(); iEvent++){ 
  //   pixelTree->GetEntry(iEvent);
  //   //cout << iEvent << " : " << pixelEvent.xSlope << " " << pixelEvent.ySlope << " " << pixelEvent.xIntercept << " " << pixelEvent.yIntercept << "\n";
   
  // }


  //*************************
  // Open Input File
  //************************* 

  FILE* fpin = fopen( inputFilename.c_str(), "r" );

  //*************************
  //Event Loop
  //*************************

  std::cout << "\n=== Processing input data ===\n" << std::endl;
  int nGoodEvents = 0;
  int maxEvents = nEvents;
  if (nEvents < 0) maxEvents = 999999; maxEvents = nEvents;
  for( int iEvent = 0; iEvent < maxEvents; iEvent++){ 

    //find corresponding pixel event    
    bool foundPixelEvent = false;
    xIntercept = -999;
    yIntercept = -999;
    xSlope = -999;
    ySlope = -999;
    x1 = -999;
    y1 = -999;
    x2 = -999;
    y2 = -999;  
    chi2 = -999.;
    ntracks = 0;

    for( int iPixelEvent = 0; iPixelEvent < pixelTree->GetEntries(); iPixelEvent++){ 
      pixelTree->GetEntry(iPixelEvent);
      if (pixelEvent.trigger == iEvent) {

	xIntercept = pixelEvent.xIntercept;
	yIntercept = pixelEvent.yIntercept;
	xSlope = pixelEvent.xSlope;
	ySlope = pixelEvent.ySlope;
	x1 = xIntercept + xSlope*(-50000);
	y1 = yIntercept + ySlope*(-50000);
	x2 = xIntercept + xSlope*(50000);
	y2 = yIntercept + ySlope*(50000);
	chi2 = pixelEvent.chi2;
	ntracks++;
      }
    }
   
    

    if ( iEvent % 100 == 0 ) {
      if (nEvents >= 0) {
	std::cout << "Event " << iEvent << " of " << nEvents << std::endl;
      } else {
	std::cout << "Event " << iEvent << "\n";
      }
    }
    event = nGoodEvents; // for output tree

    // first header word
    dummy = fread( &event_header, sizeof(uint), 1, fpin);
    // second header word
    dummy = fread( &event_header, sizeof(uint), 1, fpin);  
    uint grM     = event_header & 0x0f; // 4-bit channel group mask
    // third and fourth header words
    dummy = fread( &event_header, sizeof(uint), 1, fpin);  
    dummy = fread( &event_header, sizeof(uint), 1, fpin);  

    // check for end of file
    if (feof(fpin)) break;
    
    //*************************
    // Parse group mask into channels
    //*************************

    bool _isGR_On[4];
    _isGR_On[0] = (grM & 0x01);
    _isGR_On[1] = (grM & 0x02);
    _isGR_On[2] = (grM & 0x04);
    _isGR_On[3] = (grM & 0x08);
    
    int activeGroupsN = 0;
    int realGroup[4] = {-1, -1, -1, -1};
    for ( int l = 0; l < 4; l++ ) {
	if ( _isGR_On[l] ) 
	  {
	    realGroup[activeGroupsN] = l; 
	    activeGroupsN++;
	  }
    }
    
    //************************************
    // Loop over channel groups
    //************************************

    for ( int group = 0; group < activeGroupsN; group++ ) {
      // Read group header
      dummy = fread( &event_header, sizeof(uint), 1, fpin);  
      ushort tcn = (event_header >> 20) & 0xfff; // trigger counter bin
      tc[realGroup[group]] = tcn;
      
      // Check if all channels were active (if 8 channels active return 3072)
      int nsample = (event_header & 0xfff) / 3;
      
      // Define time coordinate
      time[realGroup[group]][0] = 0.0;
      for( int i = 1; i < 1024; i++ ){
	time[realGroup[group]][i] = float(i);
	time[realGroup[group]][i] = float(tcal[realGroup[group]][(i-1+tcn)%1024] 
                + time[realGroup[group]][i-1]);
      }      

      //************************************
      // Read sample info for group
      //************************************      

      for ( int i = 0; i < nsample; i++ ) {
	dummy = fread( &temp, sizeof(uint), 3, fpin );  
	samples[0][i] =  temp[0] & 0xfff;
	samples[1][i] = (temp[0] >> 12) & 0xfff;
	samples[2][i] = (temp[0] >> 24) | ((temp[1] & 0xf) << 8);
	samples[3][i] = (temp[1] >>  4) & 0xfff;
	samples[4][i] = (temp[1] >> 16) & 0xfff;
	samples[5][i] = (temp[1] >> 28) | ((temp[2] & 0xff) << 4);
	samples[6][i] = (temp[2] >>  8) & 0xfff;
	samples[7][i] =  temp[2] >> 20;	
      }

      // Trigger channel
      for(int j = 0; j < nsample/8; j++){
	fread( &temp, sizeof(uint), 3, fpin);  
	samples[8][j*8+0] =  temp[0] & 0xfff;
	samples[8][j*8+1] = (temp[0] >> 12) & 0xfff;
	samples[8][j*8+2] = (temp[0] >> 24) | ((temp[1] & 0xf) << 8);
	samples[8][j*8+3] = (temp[1] >>  4) & 0xfff;
	samples[8][j*8+4] = (temp[1] >> 16) & 0xfff;
	samples[8][j*8+5] = (temp[1] >> 28) | ((temp[2] & 0xff) << 4);
	samples[8][j*8+6] = (temp[2] >>  8) & 0xfff;
	samples[8][j*8+7] =  temp[2] >> 20;
      }

      //************************************
      // Loop over channels 0-8
      //************************************      

      for(int i = 0; i < 9; i++) {

	int totalIndex = realGroup[group]*9 + i;

        // Do not analyze disabled channels
        if ( !config.hasChannel(totalIndex) ) {
            for ( int j = 0; j < 1024; j++ ) {
                raw[totalIndex][j] = 0;
                channel[totalIndex][j] = 0;
            }
            xmin[totalIndex] = 0.;
            amp [totalIndex] = 0.;
            base[totalIndex] = 0.;
            integral[totalIndex] = 0.;
            integralFull[totalIndex] = 0.;
            gauspeak[totalIndex] = 0.;
            sigmoidTime[totalIndex] = 0.;
            linearTime0[totalIndex] = 0.;
            linearTime15[totalIndex] = 0.;
            linearTime30[totalIndex] = 0.;
            linearTime45[totalIndex] = 0.;
            linearTime60[totalIndex] = 0.;
            risetime[totalIndex] = 0.;
            constantThresholdTime[totalIndex] = 0.;
            continue;
        }
	
	// Fill pulses
	for ( int j = 0; j < 1024; j++ ) {
	  raw[totalIndex][j] = (short)(samples[i][j]);
	  channel[totalIndex][j] = (short)((double)(samples[i][j]) 
                  - (double)(off_mean[realGroup[group]][i][(j+tcn)%1024]));
	}

	// Make pulse shape graph
	TString pulseName = Form("pulse_event%d_group%d_ch%d", iEvent, realGroup[group], i);
	TGraphErrors* pulse = new TGraphErrors( GetTGraph( channel[totalIndex], time[realGroup[group]] ) );

	// Estimate baseline
	float baseline;
	baseline = GetBaseline( pulse, 5 ,150, pulseName );
        base[totalIndex] = baseline;

	// Correct pulse shape for baseline offset + amp/att
	for(int j = 0; j < 1024; j++) {
	  float multiplier = config.getChannelMultiplicationFactor(totalIndex);
 	  channel[totalIndex][j] = multiplier * (short)((double)(channel[totalIndex][j]) + baseline);
	}

	//Apply HighPass Filter (clipping circuit)
	HighPassFilter( channel[totalIndex], channelFilter[totalIndex],  time[realGroup[group]], 1000., 0.01 );

	// Find the absolute minimum. This is only used as a rough determination 
        // to decide if we'll use the early time samples
	// or the late time samples to do the baseline fit
	//std::cout << "---event "  << event << "-------ch#: " << totalIndex << std::endl;

	int index_min = FindMinAbsolute(1024, channel[totalIndex]);//Short version
	//int index_min = FindMinAbsolute(1024, channelFilter[totalIndex]);//Float version
	
	// DRS-glitch finder: zero out bins which have large difference
	// with respect to neighbors in only one or two bins
	for(int j = 0; j < 1024; j++) {
	  short a0 = abs(channel[totalIndex][j-1]);
	  short a1 = abs(channel[totalIndex][j]);
	  short a2 = abs(channel[totalIndex][j+1]);
	  short a3 = abs(channel[totalIndex][j+2]);
	  
	  if ( ( a1>3*a0 && a2>3*a0 && a2>3*a3 && a1>30) )
	    {
	      channel[totalIndex][j] = 0;
	      channel[totalIndex][j+1] = 0;
	    }
	  
	  if ( ( a1>3*a0 && a1>3*a2 && a1>30) )
	    channel[totalIndex][j] = 0;
	}
	
        // Recreate the pulse TGraph using baseline-subtracted channel data
	delete pulse;
	pulse = new TGraphErrors( GetTGraph( channel[totalIndex], time[realGroup[group]] ) );//Short Version
	//pulse = new TGraphErrors( *GetTGraph( channelFilter[totalIndex], time[realGroup[group]] ) );//Float Version
	xmin[totalIndex] = index_min;

        float filterWidth = config.getFilterWidth(totalIndex);
	if (filterWidth) {
	  pulse = WeierstrassTransform( channel[totalIndex], time[realGroup[group]], 
					pulseName, filterWidth, false );
	}
	
	//Compute Amplitude : use units V
	Double_t tmpAmp = 0.0;
	Double_t tmpMin = 0.0;
	pulse->GetPoint(index_min, tmpMin, tmpAmp);
	amp[totalIndex] = tmpAmp * (1.0 / 4096.0); 

	// Get pulse integral
	if ( xmin[totalIndex] != 0 ) {
	  //integral[totalIndex] = GetPulseIntegral( index_min , channel[totalIndex]);
	  integral[totalIndex] = GetPulseIntegral( index_min, 20, 50, channel[totalIndex], time[realGroup[group]] );
	  integralFull[totalIndex] = GetPulseIntegral( index_min , channel[totalIndex], "full");
        }
	else {
	    integral[totalIndex] = 0.0;
	    integralFull[totalIndex] = 0.0;
        }

	// Gaussian time stamp and constant-fraction fit
	Double_t min = 0.; Double_t low_edge = 0.; Double_t high_edge = 0.; Double_t y = 0.; 
	pulse->GetPoint(index_min, min, y);	
	pulse->GetPoint(index_min-4, low_edge, y); // time of the low edge of the fit range
	pulse->GetPoint(index_min+4, high_edge, y);  // time of the upper edge of the fit range	

	float timepeak   = 0;
        bool isTrigChannel = ( totalIndex == 8 || totalIndex == 17 
                            || totalIndex == 26 || totalIndex == 35 );
        float fs[6]; // constant-fraction fit output
	float fs_falling[6]; // falling exp timestapms
	float cft_low_range  = 0.03;
	float cft_high_range = 0.20;
        if ( !isTrigChannel ) {
	  if( drawDebugPulses ) {
	    if ( xmin[totalIndex] != 0.0 ) {
	      // if ( totalIndex == 4 && amp[4]>0.08 && amp[4]<0.45){
	      timepeak =  GausFit_MeanTime(pulse, low_edge, high_edge, pulseName);
	      RisingEdgeFitTime( pulse, index_min, cft_low_range, cft_high_range, fs, event, "linearFit_" + pulseName, true );
	      //TailFitTime( pulse, index_min, fs_falling, event, "expoFit_" + pulseName, true );
	      //sigmoidTime[totalIndex] = SigmoidTimeFit( pulse, index_min, event, "linearFit_" + pulseName, true );
	      //fullFitTime[totalIndex] = FullFitScint( pulse, index_min, event, "fullFit_" + pulseName, true );
	    }
	  }
	  else {
	    if ( xmin[totalIndex] != 0.0 ) {
	      timepeak =  GausFit_MeanTime(pulse, low_edge, high_edge);
	      RisingEdgeFitTime( pulse, index_min, cft_low_range, cft_high_range, fs, event, "linearFit_" + pulseName, false );
	      //TailFitTime( pulse, index_min, fs_falling, event, "expoFit_" + pulseName, false );
	      //sigmoidTime[totalIndex] = SigmoidTimeFit( pulse, index_min, event, "linearFit_" + pulseName, false );
	      //fullFitTime[totalIndex] = FullFitScint( pulse, index_min, event, "fullFit_" + pulseName, false );
	    }
	  }
        }
	
        else {
	  for ( int kk = 0; kk < 5; kk++ )
	    {
	      fs[kk] = -999;
	      fs_falling[kk] = -999;
	    }
        }
	
	_isRinging[totalIndex] = isRinging( index_min, channel[totalIndex] );
        // for output tree
	gauspeak[totalIndex] = timepeak;
	risetime[totalIndex] = fs[0];
	linearTime0[totalIndex] = fs[1];
	linearTime15[totalIndex] = fs[2];
	linearTime30[totalIndex] = fs[3];
	linearTime45[totalIndex] = fs[4];
	linearTime60[totalIndex] = fs[5];
	fallingTime[totalIndex] = fs_falling[0];
	constantThresholdTime[totalIndex] = ConstantThresholdTime( pulse, 75);
	
	delete pulse;
      }
      
      dummy = fread( &event_header, sizeof(uint), 1, fpin);
    }
    
    tree->Fill();
    nGoodEvents++;
  }

  fclose(fpin);
  cout << "\nProcessed total of " << nGoodEvents << " events\n";

  file->Write();
  file->Close();

  return 0;
}



int graphic_init(){

  style = new TStyle("style", "style");
  
  style->SetLabelFont(132,"X");
  style->SetLabelFont(132,"Y");
  style->SetTitleFont(132,"X");
  style->SetTitleFont(132,"Y");
  style->SetTitleFont(132,"");
  style->SetTitleFontSize( 0.07);
  style->SetStatFont(132);
  style->GetAttDate()->SetTextFont(132);
  style->SetStatW(0.20);
  style->SetStatH(0.23);
  style->SetFuncColor(2);
  style->SetFuncWidth(2);
  style->SetLineWidth(2);
  style->SetOptFile(0);
  style->SetOptTitle(1);
  style->SetFrameBorderMode(0);
  style->SetCanvasBorderMode(0);
  style->SetPadBorderMode(0);
  style->SetTitleStyle(4000);
  style->SetPadColor(0);
  style->SetCanvasColor(0);
  style->SetTitleFillColor(0);
  style->SetTitleBorderSize(0);
  style->SetStatColor(0);
  style->SetStatBorderSize(1);
  style->SetOptStat("emri");
  style->SetOptFit(1);
  style->SetTitleOffset( 1.0,"Y");
  style->SetMarkerStyle(20);
  style->SetMarkerSize( 0.3);
  style->SetMarkerColor(4);

  style->cd();

  return 0;
}

