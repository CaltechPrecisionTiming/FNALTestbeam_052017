#define pulse_cxx
#include "pulse.hh"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TGraphErrors.h>
#include "EfficiencyUtils.hh"

using namespace std;

void pulse::Loop()
{
//   In a ROOT session, you can do:
//      root> .L pulse.C
//      root> pulse t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}


void pulse::MakeEfficiencyVsXY(int channelNumber) {

  //declare histograms
  TH1F *histY_den = new TH1F("histX_den",";Y [mm];Number of Events", 50, 25,29);
  TH1F *histY_num = new TH1F("histX_num",";Y [mm];Number of Events", 50, 25,29);
  TH1F *histX_den = new TH1F("histY_den",";X [mm];Number of Events", 50, 14,18);
  TH1F *histX_num = new TH1F("histY_num",";X [mm];Number of Events", 50, 14,18);
  
  if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if (jentry % 100 == 0) cout << "Processing Event " << jentry << " of " << nentries << "\n";

      nb = fChain->GetEntry(jentry);   nbytes += nb;

      //cuts
   
      //require photek to show MIP signal
      if (!(amp[0] > 0.1 && amp[0] < 0.3)) continue;

      //reject events with more than 1 track
      if ( !(ntracks == 1 && chi2 < 10 )) continue;
      if ( !(fabs(xSlope) < 5e-4 && fabs(ySlope) < 5e-4)) continue;
      if ( !(amp[channelNumber] < 0.3 )) continue;

      // if (!(x1 > 15000 && x1 < 18000 && y1 > 21000 && y1 < 24000)) continue; //CNM irradiated
      //if (!(x1 > 11300 && x1 < 14600 && y1 > 25000 && y1 < 28500)) continue; //HPK KU 2 channel
      //if (!(x1 > 15000 && x1 < 17000 && y1 > 25600 && y1 < 28200)) continue; //HPK KU 2 channel

      if (y1 > 25800 && y1 < 28100 ) {
	histX_den->Fill( 0.001*x1);
	if (amp[channelNumber] > 0.05) {
	    histX_num->Fill( 0.001*x1 );
	}
      }
      
      if ( x1 > 15000 && x1 < 17100) {
	histY_den->Fill( 0.001*y1 );
	if (amp[channelNumber] > 0.05) {
	  histY_num->Fill( 0.001*y1 );       
	} 
      }
    
	      
   }

   vector<double> xbins; 
   vector<double> ybins;
   TGraphAsymmErrors* effX = createEfficiencyGraph(histX_num, histX_den,
						   Form("EfficiencyVsX_Channel%d",channelNumber),
						   xbins,
						   14, 18,
						   0.0, 1.0,
						   false
						   );
   TGraphAsymmErrors* effY = createEfficiencyGraph(histY_num, histY_den,
						   Form("EfficiencyVsY_Channel%d",channelNumber),
						   ybins,
						   25.0, 29.0,
						   0.0, 1.0,
						   false
						   );
   

   TFile *file = new TFile(Form("eff_Channel%d.root", channelNumber),"UPDATE");
   file->cd();
   file->WriteTObject(effX, "Efficiency_X", "WriteDelete");
   file->WriteTObject(effY, "Efficiency_Y", "WriteDelete");
   file->WriteTObject(histX_num, "histX_num", "WriteDelete");
   file->WriteTObject(histX_den, "histX_den", "WriteDelete");
   file->WriteTObject(histY_num, "histY_num", "WriteDelete");
   file->WriteTObject(histY_den, "histY_den", "WriteDelete");
   file->Close();
   delete file; 
   
};


void pulse::MakeEfficiencyVsXY(int channelNumber, int nbins, float threshold, float xmin, float xmax, float ymin, float ymax,
			       float photek_low, float photek_high)
{
  //declare histograms
  float histo_x_min = 10.;
  float histo_x_max = 30.;
  float histo_y_min = 10.;
  float histo_y_max = 30.;
  
  TH1F *histY_den = new TH1F("histX_den",";Y [mm];Number of Events", nbins, histo_y_min, histo_y_max);
  TH1F *histY_num = new TH1F("histX_num",";Y [mm];Number of Events", nbins, histo_y_min, histo_y_max);
  TH1F *histX_den = new TH1F("histY_den",";X [mm];Number of Events", nbins, histo_x_min, histo_x_max);
  TH1F *histX_num = new TH1F("histY_num",";X [mm];Number of Events", nbins, histo_x_min, histo_x_max);

  //Activate Only Necessary Branches
  fChain->SetBranchStatus("*", 0);
  fChain->SetBranchStatus("amp", 1);
  fChain->SetBranchStatus("x1", 1);
  fChain->SetBranchStatus("y1", 1);
  fChain->SetBranchStatus("ntracks", 1);
  fChain->SetBranchStatus("chi2", 1);
  fChain->SetBranchStatus("xSlope", 1);
  fChain->SetBranchStatus("ySlope", 1);
   
  if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if (jentry % 10000 == 0) cout << "Processing Event " << jentry << " of " << nentries << "\n";

      nb = fChain->GetEntry(jentry);   nbytes += nb;

      //cuts
   
      //require photek to show MIP signal
      if (!(amp[0] > photek_low && amp[0] < photek_high)) continue;

      //reject events with more than 1 track
      if ( !(ntracks == 1 && chi2 < 10 )) continue;
      //if ( !(fabs(xSlope) < 5e-4 && fabs(ySlope) < 5e-4)) continue;
      if ( !(fabs(xSlope) < 1e-3 && (fabs(ySlope) < 4e-3) && fabs(ySlope) > 3e-3)) continue;
      if ( !(amp[channelNumber] < 0.45 )) continue;//No saturation

      if ( y1 > ymin && y1 < ymax ) {
	histX_den->Fill( 0.001*x1);
	if ( amp[channelNumber] > threshold ) {
	    histX_num->Fill( 0.001*x1 );
	}
      }
      
      if ( x1 > xmin && x1 < xmax ) {
	histY_den->Fill( 0.001*y1 );
	if ( amp[channelNumber] > threshold ) {
	  histY_num->Fill( 0.001*y1 );       
	} 
      }
    
	      
   }

   vector<double> xbins; 
   vector<double> ybins;
   TGraphAsymmErrors* effX = createEfficiencyGraph(histX_num, histX_den,
						   Form("EfficiencyVsX_Channel%d",channelNumber),
						   xbins,
						   histo_x_min, histo_x_max,
						   0.0, 1.0,
						   false
						   );
   TGraphAsymmErrors* effY = createEfficiencyGraph(histY_num, histY_den,
						   Form("EfficiencyVsY_Channel%d",channelNumber),
						   ybins,
						   histo_y_min, histo_y_max,
						   0.0, 1.0,
						   false
						   );

   //Find x,y position for the max efficiency
   double x_eff_low, x_eff_high;
   double y_eff_low, y_eff_high;
   double dummy_eff;
   //For X
   for ( int i = 1; i <= nbins; i++ )
     {
       effX->GetPoint( i, x_eff_low, dummy_eff );
       if( dummy_eff > 0.5 ) break;
     }
   
   for ( int i = 1; i <= nbins; i++ )
     {
       effX->GetPoint( nbins-i, x_eff_high, dummy_eff );
       if( dummy_eff > 0.5 ) break;
     }

   //For Y
   for ( int i = 1; i <= nbins; i++ )
     {
       effY->GetPoint( i, y_eff_low, dummy_eff );
       if( dummy_eff > 0.5 ) break;
     }
   
   for ( int i = 1; i <= nbins; i++ )
     {
       effY->GetPoint( nbins-i, y_eff_high, dummy_eff );
       if( dummy_eff > 0.5 ) break;
     }
   

   //std::cout << " x:" << y_eff_low << " - " << y_eff_high << std::endl;
   //Cosmetics
   effX->SetTitle("");
   effX->GetXaxis()->SetTitleSize(0.05);
   effX->GetXaxis()->SetTitleOffset(0.87);
   effX->GetYaxis()->SetTitleSize(0.05);
   effX->GetYaxis()->SetTitleOffset(0.83);
   effX->SetMarkerStyle(kBlue);
   effX->SetMarkerSize(1.1);
   effX->SetMarkerColor(kBlue);
   effX->SetLineColor(kBlue);
   effX->SetMarkerStyle(20);
   effX->GetYaxis()->SetTitle("Efficiency");
   effX->GetXaxis()->SetTitle("x-coordinate [mm]");
   effX->GetXaxis()->SetRangeUser( x_eff_low-1., x_eff_high+1.);
   effX->GetYaxis()->SetRangeUser( 0, 1.11);
   
     
   effY->SetTitle("");
   effY->GetXaxis()->SetTitleSize(0.05);
   effY->GetXaxis()->SetTitleOffset(0.87);
   effY->GetYaxis()->SetTitleSize(0.05);
   effY->GetYaxis()->SetTitleOffset(0.83);
   effY->SetMarkerStyle(20);
   effY->SetMarkerStyle(kBlue);
   effY->SetMarkerSize(1.1);
   effY->SetMarkerColor(kBlue);
   effY->SetLineColor(kBlue);
   effY->SetMarkerStyle(20);
   effY->GetYaxis()->SetTitle("Efficiency");
   effY->GetXaxis()->SetTitle("y-coordinate [mm]");
   effY->GetXaxis()->SetRangeUser( y_eff_low-1., y_eff_high+1.);
   effY->GetYaxis()->SetRangeUser( 0, 1.11);

   TCanvas* c = new TCanvas("canvas","canvas",600,400);
   effX->Draw("AP");
   c->SaveAs(Form("Eff_vs_X_Ch%d.pdf",channelNumber));
   c->SaveAs(Form("Eff_vs_X_Ch%d.C",channelNumber));
   effY->Draw("AP");
   c->SaveAs(Form("Eff_vs_Y_Ch%d.pdf",channelNumber));
   c->SaveAs(Form("Eff_vs_Y_Ch%d.C",channelNumber));
   delete c;

   
   //Activate all branches back to normal
   fChain->SetBranchStatus("*", 1);
   
   TFile *file = new TFile(Form("eff_Channel%d.root", channelNumber),"UPDATE");
   file->cd();
   file->WriteTObject(effX, "Efficiency_X", "WriteDelete");
   file->WriteTObject(effY, "Efficiency_Y", "WriteDelete");
   file->WriteTObject(histX_num, "histX_num", "WriteDelete");
   file->WriteTObject(histX_den, "histX_den", "WriteDelete");
   file->WriteTObject(histY_num, "histY_num", "WriteDelete");
   file->WriteTObject(histY_den, "histY_den", "WriteDelete");
   file->Close();
   delete file; 
};

void pulse::MakeTimingPlotsVsXY(int channelNumber) {

  //declare histograms
  TH2F *histDeltaTVsX = new TH2F("histDeltaTVsX",";X [mm];Number of Events", 16, 14,18, 800, -10,10);
  TH2F *histDeltaTVsY = new TH2F("histDeltaTVsY",";Y [mm];Number of Events", 16, 25,29, 800, -10,10);
  

  if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if (jentry % 100 == 0) cout << "Processing Event " << jentry << " of " << nentries << "\n";

      nb = fChain->GetEntry(jentry);   nbytes += nb;

      //cuts
   
      //require photek to show MIP signal
      if (!(amp[0] > 0.1 && amp[0] < 0.3)) continue;

      //reject events with more than 1 track
      if ( !(ntracks == 1 && chi2 < 10 )) continue;
      if ( !(fabs(xSlope) < 5e-4 && fabs(ySlope) < 5e-4)) continue;
      if ( !(amp[channelNumber] < 0.3 )) continue;
      if ( !(amp[channelNumber] > 0.05)) continue;

      histDeltaTVsX->Fill( x1*0.001, gauspeak[0] - linearTime45[channelNumber] );
      histDeltaTVsY->Fill( y1*0.001, gauspeak[0] - linearTime45[channelNumber] );     
	      
   }

   int nXBins = histDeltaTVsX->GetXaxis()->GetNbins();
   float meanDeltaTVsX[nXBins];
   float meanDeltaTErrVsX[nXBins];
   float timeResolutionVsX[nXBins];
   float timeResolutionErrVsX[nXBins];
   float xBins[nXBins];
   float xBinsErr[nXBins];
   for (int b=1; b<=nXBins; b++) {
     TH1D *tmphist = histDeltaTVsX->ProjectionY("tmpProjY",b,b+1);

     TF1* fgaus = new TF1("fgaus","gaus", tmphist->GetMean() - 2*tmphist->GetRMS(), tmphist->GetMean() + 2*tmphist->GetRMS());
     tmphist->Fit("fgaus","Q","", tmphist->GetMean() - 2*tmphist->GetRMS(), tmphist->GetMean() + 2*tmphist->GetRMS());     
     xBins[b-1] = histDeltaTVsX->GetXaxis()->GetBinCenter(b);
     xBinsErr[b-1] = histDeltaTVsX->GetXaxis()->GetBinUpEdge(b) - histDeltaTVsX->GetXaxis()->GetBinCenter(b);
     meanDeltaTVsX[b-1] = fgaus->GetParameter(1);
     meanDeltaTErrVsX[b-1] = fgaus->GetParError(1);
     timeResolutionVsX[b-1] = fgaus->GetParameter(2);
     timeResolutionErrVsX[b-1] = fgaus->GetParError(2); 
     cout << b-1 << " : " << xBins[b-1] << " " << meanDeltaTVsX[b-1] << "\n";
   }


   TGraphErrors* GraphDeltaTVsX = new TGraphErrors(nXBins, xBins, meanDeltaTVsX, xBinsErr, meanDeltaTErrVsX);
   TGraphErrors* GraphTimeResolutionVsX = new TGraphErrors(nXBins, xBins, timeResolutionVsX, xBinsErr, timeResolutionErrVsX);

   TFile *file = new TFile("timing.root","UPDATE");
   file->cd();
   file->WriteTObject(GraphDeltaTVsX, "GraphDeltaTVsX", "WriteDelete");  
   file->WriteTObject(GraphTimeResolutionVsX, "GraphTimeResolutionVsX", "WriteDelete");  
   file->WriteTObject(histDeltaTVsX, "histDeltaTVsX", "WriteDelete");  
   file->WriteTObject(histDeltaTVsY, "histDeltaTVsY", "WriteDelete");  
   file->Close();
   delete file; 
   
};


void pulse::MakeEfficiencyVsRun(int channelNumber) {

  //declare histograms
  TH2F *hist_den = new TH2F("hist_den",";X [mm];Number of Events", 10, 15, 17, 100, 0, 26000);
  TH2F *hist_num = new TH2F("hist_num",";X [mm];Number of Events", 10, 15, 17, 100, 0, 26000);
  
  if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if (jentry % 100 == 0) cout << "Processing Event " << jentry << " of " << nentries << "\n";

      nb = fChain->GetEntry(jentry);   nbytes += nb;

      //cuts

      //require photek to show MIP signal
      if (!(amp[0] > 0.1 && amp[0] < 0.3)) continue;
      if (!(x1 > 15000 && x1 < 18000 && y1 > 21000 && y1 < 24000)) continue;

      hist_den->Fill( 0.001*x1, event );

      //cout << "Fill Den: " << 0.001*x2 << " " << 0.001*y2 << "\n";
      
      //numerator
      if (amp[channelNumber] > 0.01) {
	//cout << "Fill NUM: " << 0.001*x2 << " " << 0.001*y2 << "\n";
	hist_num->Fill( 0.001*x1, event );
      }
   }

   vector<double> xbins;
   vector<double> ybins;

   TH2F* eff = createEfficiencyHist2D(hist_num, hist_den,
				      Form("EfficiencyVsX_Channel%d",channelNumber),
				      xbins,ybins
				      );
   
   
   TFile *file = new TFile("eff_vs_run.root","UPDATE");
   file->cd();
   file->WriteTObject(eff, "Efficiency_X", "WriteDelete");
   file->WriteTObject(hist_num, "hist_num", "WriteDelete");
   file->WriteTObject(hist_den, "hist_den", "WriteDelete");
   file->Close();
   delete file; 
   
};


void pulse::CreateMPV_vs_PositionHisto( int dut, int channelNumber, float binWidth, float threshold_low, float threshold_high,
					float xmin, float xmax, float ymin, float ymax,
					float photek_low, float photek_high)
{
   if ( dut <= 0 || dut > 2 )
     {
       std::cerr << "[ERROR]: please provide a valid dut = <1,2>" << std::endl;
       return;
     }
  //x_init, y_init, and steps are in microns
  //const int npoints = 30;
   

  //------------------
  //Define initial positions and step size, all units are in microns
  //-------------------
  float x_init    = 10000.;//microns
  float y_init    = 10000.;//microns
  int niterations = (int)((30000.-10000.)/binWidth);//microns

  float x_pos[niterations];//x-positions
  float x_pos_un[niterations];//x-position uncertainty
  float mpv_x[niterations];//mpv amplitude for x
  float mpv_x_un[niterations];//uncertainty on mpv amplitude x
  float y_pos[niterations];//y-positions
  float y_pos_un[niterations];//y-position uncertainty
  float mpv_y[niterations];//mpv amplitude for x
  float mpv_y_un[niterations];//uncertainty on mpv amplitude y


  const float um_to_mm = 0.001;
  float average_x = 0;
  float average_y = 0;
  int npoints_above_zero_x = 0;
  int npoints_above_zero_y = 0;
  for ( int i = 0; i < niterations; i++ )
    {
      x_pos[i] = x_init + binWidth*(float)i;
      x_pos_un[i] = 0;
      std::pair<float,float> MPVAndError_X = MPV_vs_Position( dut, "X", channelNumber, x_pos[i], binWidth, threshold_low, threshold_high, ymin, ymax,
							      photek_low, photek_high );
      x_pos[i] = x_pos[i]*um_to_mm;
      mpv_x[i] = MPVAndError_X.first;
      mpv_x_un[i] = MPVAndError_X.second;
      if ( mpv_x_un[i]/mpv_x[i] > 0.2 )
	{
	  mpv_x[i]    = 0;
	  mpv_x_un[i] = 0;
	}
      if ( mpv_x[i] > 0 && mpv_x[i] < 0.5)
	{
	  npoints_above_zero_x++;
	  average_x += mpv_x[i];
	}
      
      
      y_pos[i] = y_init + binWidth*(float)i;
      y_pos_un[i] = 0;
      std::pair<float,float> MPVAndError_Y = MPV_vs_Position( dut, "Y", channelNumber, y_pos[i], binWidth, threshold_low, threshold_high, xmin, xmax,
							      photek_low, photek_high);
      y_pos[i] = y_pos[i]*um_to_mm;
      mpv_y[i] = MPVAndError_Y.first;
      mpv_y_un[i] = MPVAndError_Y.second;
      if ( mpv_y_un[i]/mpv_y[i] > 0.2 )
	{
	  mpv_y[i]    = 0;
	  mpv_y_un[i] = 0;
	}
      if ( mpv_y[i] > 0 && mpv_y[i] < 0.5)
	{
	  npoints_above_zero_y++;
	  average_y += mpv_y[i];
	}
      
    }

  TGraphErrors* gr_mpv_x = new TGraphErrors(niterations, x_pos, mpv_x, x_pos_un, mpv_x_un);
  TGraphErrors* gr_mpv_y = new TGraphErrors(niterations, y_pos, mpv_y, y_pos_un, mpv_y_un);
  average_x = average_x/((float)npoints_above_zero_x);
  average_y = average_y/((float)npoints_above_zero_y);
  std::cout << "x: " <<  average_x << " y: " << average_y << std::endl;

  //Find x,y position for the max efficiency
   double x_eff_low, x_eff_high;
   double y_eff_low, y_eff_high;
   double dummy_eff;
   //For X
   for ( int i = 1; i <= niterations; i++ )
     {
       gr_mpv_x->GetPoint( i, x_eff_low, dummy_eff );
       if( dummy_eff > 0.8*average_x ) break;
     }
   
   for ( int i = 1; i <= niterations; i++ )
     {
       gr_mpv_x->GetPoint( niterations-i, x_eff_high, dummy_eff );
       if( dummy_eff > 0.8*average_x ) break;
     }

   //For Y
   for ( int i = 1; i <= niterations; i++ )
     {
       gr_mpv_y->GetPoint( i, y_eff_low, dummy_eff );
       if( dummy_eff > 0.8*average_y ) break;
     }
   
   for ( int i = 1; i <= niterations; i++ )
     {
       gr_mpv_y->GetPoint( niterations-i, y_eff_high, dummy_eff );
       if( dummy_eff > 0.8*average_y ) break;
     }
  
  //Cosmetics
  gr_mpv_x->GetYaxis()->SetRangeUser(0,1.2*max(average_x,average_y));
  gr_mpv_x->GetXaxis()->SetRangeUser(x_eff_low-1.0,x_eff_high+1.0);
  gr_mpv_x->SetTitle("");
  gr_mpv_x->GetXaxis()->SetTitle("x-coordinate [mm]");
  gr_mpv_x->GetYaxis()->SetTitle("m.p.v [V]");
  gr_mpv_x->GetXaxis()->SetTitleSize(0.05);
  gr_mpv_x->GetXaxis()->SetTitleOffset(0.87);
  gr_mpv_x->GetYaxis()->SetTitleSize(0.05);
  gr_mpv_x->GetYaxis()->SetTitleOffset(0.98);
  gr_mpv_x->SetMarkerStyle(20);
  gr_mpv_x->SetMarkerStyle(kBlue);
  gr_mpv_x->SetMarkerSize(1.1);
  gr_mpv_x->SetMarkerColor(kBlue);
  gr_mpv_x->SetLineColor(kBlue);
  gr_mpv_x->SetMarkerStyle(20);
  
  gr_mpv_y->GetYaxis()->SetRangeUser(0,1.2*max(average_x,average_y));
  gr_mpv_y->GetXaxis()->SetRangeUser(y_eff_low-1.0,y_eff_high+1.0);
  gr_mpv_y->SetTitle("");
  gr_mpv_y->GetXaxis()->SetTitle("y-coordinate [mm]");
  gr_mpv_y->GetYaxis()->SetTitle("m.p.v [V]");
  gr_mpv_y->GetXaxis()->SetTitleSize(0.05);
  gr_mpv_y->GetXaxis()->SetTitleOffset(0.87);
  gr_mpv_y->GetYaxis()->SetTitleSize(0.05);
  gr_mpv_y->GetYaxis()->SetTitleOffset(0.98);
  gr_mpv_y->SetMarkerStyle(20);
  gr_mpv_y->SetMarkerStyle(kBlue);
  gr_mpv_y->SetMarkerSize(1.1);
  gr_mpv_y->SetMarkerColor(kBlue);
  gr_mpv_y->SetLineColor(kBlue);
  gr_mpv_y->SetMarkerStyle(20);
  
  TCanvas* c = new TCanvas("canvas","canvas",600,400);
  gr_mpv_x->Draw("AP");
  c->SaveAs(Form("MPV_vs_X_Ch%d.pdf",channelNumber));
  c->SaveAs(Form("MPV_vs_X_Ch%d.C",channelNumber));
  gr_mpv_y->Draw("AP");
  c->SaveAs(Form("MPV_vs_Y_Ch%d.pdf",channelNumber));
  c->SaveAs(Form("MPV_vs_Y_Ch%d.C",channelNumber));
  delete c;
  TFile* fout = new TFile(Form("mpv_tgraphs_Channel%d.root", channelNumber), "RECREATE");
  gr_mpv_x->Write("mpv_x");
  gr_mpv_y->Write("mpv_y");
  fout->Close();
};


void pulse::CreateDeltaT_vs_PositionHisto( int dut, int channelNumber, float binWidth, float threshold_low, float threshold_high,
					   float xmin, float xmax, float ymin, float ymax, bool _isMean,
					   float photek_low, float photek_high)
{
   if ( dut <= 0 || dut > 2 )
     {
       std::cerr << "[ERROR]: please provide a valid dut = <1,2>" << std::endl;
       return;
     }
  //x_init, y_init, and steps are in microns
  //const int npoints = 30;
   

  //------------------
  //Define initial positions and step size, all units are in microns
  //-------------------
  float x_init    = 10000.;//microns
  float y_init    = 10000.;//microns
  int niterations = (int)((30000.-10000.)/binWidth);//microns

  float x_pos[niterations];//x-positions
  float x_pos_un[niterations];//x-position uncertainty
  float mpv_x[niterations];//mpv amplitude for x
  float mpv_x_un[niterations];//uncertainty on mpv amplitude x
  float y_pos[niterations];//y-positions
  float y_pos_un[niterations];//y-position uncertainty
  float mpv_y[niterations];//mpv amplitude for x
  float mpv_y_un[niterations];//uncertainty on mpv amplitude y


  const float um_to_mm = 0.001;
  const float ns_to_ps = 1000.;
  float average_x = 0;
  float average_y = 0;
  int npoints_above_zero_x = 0;
  int npoints_above_zero_y = 0;
  for ( int i = 0; i < niterations; i++ )
    {
      x_pos[i] = x_init + binWidth*(float)i;
      x_pos_un[i] = 0;
      std::pair<float,float> MPVAndError_X;
      if ( _isMean )
	{
	  MPVAndError_X = DeltaT_vs_Position( dut, "X", channelNumber, x_pos[i], binWidth, threshold_low, threshold_high, ymin, ymax, true, photek_low, photek_high );
	}
      else
	{
	  MPVAndError_X = DeltaT_vs_Position( dut, "X", channelNumber, x_pos[i], binWidth, threshold_low, threshold_high, ymin, ymax, false, photek_low, photek_high );
	}
      x_pos[i] = x_pos[i]*um_to_mm;
      mpv_x[i] = MPVAndError_X.first*ns_to_ps;
      mpv_x_un[i] = MPVAndError_X.second*ns_to_ps;
      if ( mpv_x_un[i]/mpv_x[i] > 0.9 )
	{
	  mpv_x[i]    = 0;
	  mpv_x_un[i] = 0;
	}
      if ( mpv_x[i] > -10000 && mpv_x[i] < 10000)
	{
	  npoints_above_zero_x++;
	  average_x += mpv_x[i];
	}
      
      
      y_pos[i] = y_init + binWidth*(float)i;
      y_pos_un[i] = 0;
      std::pair<float,float> MPVAndError_Y;
      if ( _isMean )
	{
	  MPVAndError_Y = DeltaT_vs_Position( dut, "Y", channelNumber, y_pos[i], binWidth, threshold_low, threshold_high, xmin, xmax, true, photek_low, photek_high );
	}
      else
	{
	  MPVAndError_Y = DeltaT_vs_Position( dut, "Y", channelNumber, y_pos[i], binWidth, threshold_low, threshold_high, xmin, xmax, false, photek_low, photek_high );
	}
      y_pos[i] = y_pos[i]*um_to_mm;
      mpv_y[i] = MPVAndError_Y.first*ns_to_ps;
      mpv_y_un[i] = MPVAndError_Y.second*ns_to_ps;
      if ( mpv_y_un[i]/mpv_y[i] > 0.9 )
	{
	  mpv_y[i]    = 0;
	  mpv_y_un[i] = 0;
	}
      if ( mpv_y[i] > -10000 && mpv_y[i] < 10000)
	{
	  npoints_above_zero_y++;
	  average_y += mpv_y[i];
	}
      
    }

  TGraphErrors* gr_mpv_x = new TGraphErrors(niterations, x_pos, mpv_x, x_pos_un, mpv_x_un);
  TGraphErrors* gr_mpv_y = new TGraphErrors(niterations, y_pos, mpv_y, y_pos_un, mpv_y_un);
  average_x = average_x/((float)npoints_above_zero_x);
  average_y = average_y/((float)npoints_above_zero_y);
  std::cout << "x: " <<  average_x << " y: " << average_y << std::endl;

  //Find x,y position for the max efficiency
   double x_eff_low, x_eff_high;
   double y_eff_low, y_eff_high;
   double dummy_eff;
   //For X
   for ( int i = 1; i <= niterations; i++ )
     {
       gr_mpv_x->GetPoint( i, x_eff_low, dummy_eff );
       if( dummy_eff > 0.8*average_x ) break;
     }
   
   for ( int i = 1; i <= niterations; i++ )
     {
       gr_mpv_x->GetPoint( niterations-i, x_eff_high, dummy_eff );
       if( dummy_eff > 0.8*average_x ) break;
     }

   //For Y
   for ( int i = 1; i <= niterations; i++ )
     {
       gr_mpv_y->GetPoint( i, y_eff_low, dummy_eff );
       if( dummy_eff > 0.8*average_y ) break;
     }
   
   for ( int i = 1; i <= niterations; i++ )
     {
       gr_mpv_y->GetPoint( niterations-i, y_eff_high, dummy_eff );
       if( dummy_eff > 0.8*average_y ) break;
     }
  
   //Cosmetics
   gr_mpv_x->GetYaxis()->SetRangeUser(0,1.2*max(average_x,average_y));
   //gr_mpv_x->GetYaxis()->SetRangeUser(-10000,10000);
   gr_mpv_x->GetXaxis()->SetRangeUser(x_eff_low-1.0,x_eff_high+1.0);
   gr_mpv_x->SetTitle("");
   gr_mpv_x->GetXaxis()->SetTitle("x-coordinate [mm]");
   if ( _isMean ) gr_mpv_x->GetYaxis()->SetTitle("#Delta t [ps]");
   else gr_mpv_x->GetYaxis()->SetTitle("Time resolution [ps]");
   gr_mpv_x->GetXaxis()->SetTitleSize(0.05);
   gr_mpv_x->GetXaxis()->SetTitleOffset(0.87);
   gr_mpv_x->GetYaxis()->SetTitleSize(0.05);
   gr_mpv_x->GetYaxis()->SetTitleOffset(0.83);
   gr_mpv_x->SetMarkerStyle(20);
   gr_mpv_x->SetMarkerStyle(kBlue);
   gr_mpv_x->SetMarkerSize(1.1);
   gr_mpv_x->SetMarkerColor(kBlue);
   gr_mpv_x->SetLineColor(kBlue);
   gr_mpv_x->SetMarkerStyle(20);
   
   gr_mpv_y->GetYaxis()->SetRangeUser(0,1.2*max(average_x,average_y));
   //gr_mpv_y->GetYaxis()->SetRangeUser(-10000,10000);
   gr_mpv_y->GetXaxis()->SetRangeUser(y_eff_low-1.0,y_eff_high+1.0);
   gr_mpv_y->SetTitle("");
   gr_mpv_y->GetXaxis()->SetTitle("y-coordinate [mm]");
   if ( _isMean ) gr_mpv_y->GetYaxis()->SetTitle("#Delta t [ps]");
   else gr_mpv_y->GetYaxis()->SetTitle("Time resolution [ps]");
   gr_mpv_y->GetXaxis()->SetTitleSize(0.05);
   gr_mpv_y->GetXaxis()->SetTitleOffset(0.87);
   gr_mpv_y->GetYaxis()->SetTitleSize(0.05);
   gr_mpv_y->GetYaxis()->SetTitleOffset(0.83);
   gr_mpv_y->SetMarkerStyle(20);
   gr_mpv_y->SetMarkerStyle(kBlue);
   gr_mpv_y->SetMarkerSize(1.1);
   gr_mpv_y->SetMarkerColor(kBlue);
   gr_mpv_y->SetLineColor(kBlue);
   gr_mpv_y->SetMarkerStyle(20);
   
  TString fname;
  if ( _isMean )
    {
      TCanvas* c = new TCanvas("canvas","canvas",600,400);
      gr_mpv_x->Draw("AP");
      c->SaveAs(Form("MeanTime_vs_X_Ch%d.pdf",channelNumber));
      c->SaveAs(Form("MeanTime_vs_X_Ch%d.C",channelNumber));
      gr_mpv_y->Draw("AP");
      c->SaveAs(Form("MeanTime_vs_Y_Ch%d.pdf",channelNumber));
      c->SaveAs(Form("MeanTime_vs_Y_Ch%d.C",channelNumber));
      delete c;
      fname = Form("deltaT_mean_tgraphs_Channel%d.root", channelNumber);
    }
  else
    {
      TCanvas* c = new TCanvas("canvas","canvas",600,400);
      gr_mpv_x->Draw("AP");
      c->SaveAs(Form("TimeResolution_vs_X_Ch%d.pdf",channelNumber));
      c->SaveAs(Form("TimeResolution_vs_X_Ch%d.C",channelNumber));
      gr_mpv_y->Draw("AP");
      c->SaveAs(Form("TimeResolution_vs_Y_Ch%d.pdf",channelNumber));
      c->SaveAs(Form("TimeResolution_vs_Y_Ch%d.C",channelNumber));
      delete c;
      fname = Form("deltaT_time_resolution_tgraphs_Channel%d.root", channelNumber);
    }
  TFile* fout = new TFile( fname, "RECREATE");
  gr_mpv_x->Write("time_x");
  gr_mpv_y->Write("time_y");
  fout->Close();
};


std::pair<float,float> pulse::MPV_vs_Position( int dut, TString coor, const int channel, const float coorLow, const float step,
					       const float AmpLowCut, const float AmpHighCut,
					       float other_corr_low, float other_corr_high,
					       float photek_low, float photek_high)
{
  if ( channel < 0 ) return std::pair<float,float>(-999,0);
  if ( dut <= 0 || dut > 2 )
    {
      std::cerr << "[ERROR]: please provide a valid dut = <1,2>" << std::endl;
      return std::pair<float,float>(-999,0);
    }
  
  fChain->SetBranchStatus("*", 0);
  fChain->SetBranchStatus("amp", 1);
  fChain->SetBranchStatus("x1", 1);
  fChain->SetBranchStatus("y1", 1);
  fChain->SetBranchStatus("x2", 1);
  fChain->SetBranchStatus("y2", 1);
  if (fChain == 0) return std::pair<float,float>(-999,0);
  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  
  cout << "Running MPV_vs_Position Analysis\n";
  cout << "Total Events: " << nentries << "\n";
  TH1F* h_mpv = new TH1F("h_mpv", "h_mpv", 100, 0, 0.5);
  for (Long64_t jentry=0; jentry<nentries;jentry++)
    {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if (ientry % 10000 == 0) cout << "Processing Event " << ientry << "\n";
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      
      if ( amp[channel] >= AmpLowCut && amp[channel] <= AmpHighCut && amp[0] > photek_low && amp[0] < photek_high )
	{
	  if ( dut == 1 )
	    {
	      if ( (coor == "x" || coor == "X") && x1 >= coorLow && x1 < (coorLow + step) && y1 > other_corr_low && y1 < other_corr_high ) h_mpv->Fill(amp[channel]);
	      if ( (coor == "y" || coor == "Y") && y1 >= coorLow && y1 < (coorLow + step) && x1 > other_corr_low && x1 < other_corr_high ) h_mpv->Fill(amp[channel]);
	    }
	  else if ( dut == 2 )
	    {
	      if ( (coor == "x" || coor == "X") && x2 >= coorLow && x2 < (coorLow + step) && y2 > other_corr_low && y2 < other_corr_high ) h_mpv->Fill(amp[channel]);
	      if ( (coor == "y" || coor == "Y") && y2 >= coorLow && y2 < (coorLow + step) && x2 > other_corr_low && x2 < other_corr_high ) h_mpv->Fill(amp[channel]);
	    }
	}
    }

  //Restoring all branches
  fChain->SetBranchStatus("*", 1);
  //Fitting
  TF1* landau = new TF1( "landau", "landau", AmpLowCut, AmpHighCut );
  h_mpv->Fit("landau","Q","", AmpLowCut, AmpHighCut);
  std::pair<float,float> result;
  result.first = landau->GetParameter(1);
  result.second = landau->GetParError(1);
  //Creating output file
  //Creating output file
  std::string myCoor;
  if ( coor == "X" || coor == "x" ) myCoor = "X";
  if ( coor == "Y" || coor == "y" ) myCoor = "Y";
  
  TString fname = Form("mpv_Channel%d_step%.2f_%s.root", channel,coorLow + step, myCoor.c_str());
  TFile* fout = new TFile(fname, "recreate");
  h_mpv->Write();
  fout->Close();
  return result;
};


std::pair<float,float> pulse::DeltaT_vs_Position( int dut, TString coor, const int channel, const float coorLow, const float step,
						  const float AmpLowCut, const float AmpHighCut,
						  float other_corr_low, float other_corr_high, bool _isMean,
						  float photek_low, float photek_high)
{
  if ( channel < 0 ) return std::pair<float,float>(-999,0);
  if ( dut <= 0 || dut > 2 )
    {
      std::cerr << "[ERROR]: please provide a valid dut = <1,2>" << std::endl;
      return std::pair<float,float>(-999,0);
    }
  
  fChain->SetBranchStatus("*", 0);
  fChain->SetBranchStatus("amp", 1);
  fChain->SetBranchStatus("gauspeak", 1);
  fChain->SetBranchStatus("linearTime0", 1);
  fChain->SetBranchStatus("linearTime15", 1);
  fChain->SetBranchStatus("linearTime30", 1);
  fChain->SetBranchStatus("linearTime45", 1);
  fChain->SetBranchStatus("linearTime60", 1);
  fChain->SetBranchStatus("x1", 1);
  fChain->SetBranchStatus("y1", 1);
  fChain->SetBranchStatus("x2", 1);
  fChain->SetBranchStatus("y2", 1);
  if (fChain == 0) return std::pair<float,float>(-999,0);
  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  
  cout << "Running MPV_vs_Position Analysis\n";
  cout << "Total Events: " << nentries << "\n";
  TH1F* h_deltaT = new TH1F("h_delta_T", "h_delta_T", 1000, -10, 10);
  for (Long64_t jentry=0; jentry<nentries;jentry++)
    {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if (ientry % 10000 == 0) cout << "Processing Event " << ientry << "\n";
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      
      if ( amp[channel] >= AmpLowCut && amp[channel] <= AmpHighCut && amp[0] > photek_low && amp[0] < photek_high )
	{
	  if ( dut == 1 )
	    {
	      if ( (coor == "x" || coor == "X") && x1 >= coorLow && x1 < (coorLow + step) && y1 > other_corr_low && y1 < other_corr_high ) h_deltaT->Fill(linearTime45[channel]-gauspeak[0]);
	      if ( (coor == "y" || coor == "Y") && y1 >= coorLow && y1 < (coorLow + step) && x1 > other_corr_low && x1 < other_corr_high ) h_deltaT->Fill(linearTime45[channel]-gauspeak[0]);
	    }
	  else if ( dut == 2 )
	    {
	      if ( (coor == "x" || coor == "X") && x2 >= coorLow && x2 < (coorLow + step) && y2 > other_corr_low && y2 < other_corr_high ) h_deltaT->Fill(linearTime45[channel]-gauspeak[0]);
	      if ( (coor == "y" || coor == "Y") && y2 >= coorLow && y2 < (coorLow + step) && x2 > other_corr_low && x2 < other_corr_high ) h_deltaT->Fill(linearTime45[channel]-gauspeak[0]);
	    }
	}
    }

  if ( h_deltaT->GetEntries() < 10 ) return std::pair<float,float>(-999,0);
  double mean = h_deltaT->GetMean();
  double rms = h_deltaT->GetRMS();
  //Restoring all branches
  fChain->SetBranchStatus("*", 1);
  //Fitting
  TF1* gaus = new TF1( "gaus", "gaus", mean -2.*rms, mean +2.*rms );
  h_deltaT->Fit("gaus","Q","", mean -2.*rms, mean +2.*rms);
  std::pair<float,float> result;
  if ( _isMean )
    {
      result.first  = gaus->GetParameter(1);
      result.second = gaus->GetParError(1);
    }
  else
    {
      result.first  = gaus->GetParameter(2);
      result.second = gaus->GetParError(2);
    }
  //Creating output file
  std::string myCoor;
  if ( coor == "X" || coor == "x" ) myCoor = "X";
  if ( coor == "Y" || coor == "y" ) myCoor = "Y";
  TString fname;
  if ( _isMean ) fname  = Form("gaus_mean_Channel%d_step%.2f_%s.root", channel,coorLow + step, myCoor.c_str());
  else fname  = Form("gaus_sigma_Channel%d_step%.2f_%s.root", channel,coorLow + step, myCoor.c_str());
  TFile* fout = new TFile(fname, "recreate");
  h_deltaT->Write();
  fout->Close();
  return result;
};




void pulse::CompareShowerSignal(int CdTeChannel, int SiliconChannel, 
				double CdTeAmplification, double SiliconAmplification,
				double xLeftBoundary, double xRightBoundary,
				double yLeftBoundary, double yRightBoundary
				) {

  //For Run 1510-1512, 1513-1514
  // TH1F *histCdTeAmplitude = new TH1F("histCdTeAmplitude",";CdTe Amplitude [V];Number of Events", 20, 0, 0.05);
  // TH1F *histCdTeCharge = new TH1F("histCdTeCharge",";CdTe Charge [pC];Number of Events", 20, 0, 10);
  // TH1F *histSiliconAmplitude = new TH1F("histSiliconAmplitude",";Silicon Amplitude [V];Number of Events", 20, 0, 0.03);
  // TH1F *histSiliconCharge = new TH1F("histSiliconCharge",";Silicon Charge [pC];Number of Events", 20, 0, 2);
  // TH1F *histCdTeAmplitudeOverSiliconAmplitude = new TH1F("histCdTeAmplitudeOverSiliconAmplitude",";CdTe Amplitude / Silicon Amplitude;Number of Events", 20, 0, 30);
  // TH1F *histCdTeChargeOverSiliconCharge = new TH1F("histCdTeChargeOverSiliconCharge",";CdTe Charge / Silicon Charge;Number of Events", 20, 0, 30);   

  //For Run 1508-1509
  // TH1F *histCdTeAmplitude = new TH1F("histCdTeAmplitude",";CdTe Amplitude [V];Number of Events", 20, 0, 0.5);
  // TH1F *histCdTeCharge = new TH1F("histCdTeCharge",";CdTe Charge [pC];Number of Events", 20, 0, 100);
  // TH1F *histSiliconAmplitude = new TH1F("histSiliconAmplitude",";Silicon Amplitude [V];Number of Events", 20, 0, 0.03);
  // TH1F *histSiliconCharge = new TH1F("histSiliconCharge",";Silicon Charge [pC];Number of Events", 20, 0, 2);
  // TH1F *histCdTeAmplitudeOverSiliconAmplitude = new TH1F("histCdTeAmplitudeOverSiliconAmplitude",";CdTe Amplitude / Silicon Amplitude;Number of Events", 20, 0, 300);
  // TH1F *histCdTeChargeOverSiliconCharge = new TH1F("histCdTeChargeOverSiliconCharge",";CdTe Charge / Silicon Charge;Number of Events", 20, 0, 300);   

  //Run 1614-1616
  TH1F *histCdTeAmplitude = new TH1F("histCdTeAmplitude",";CdTe Amplitude [mV];Number of Events", 20, 0, 5);
  TH1F *histCdTeCharge = new TH1F("histCdTeCharge",";CdTe Charge [fC];Number of Events", 20, 0, 1000);
  TH1F *histSiliconAmplitude = new TH1F("histSiliconAmplitude",";Silicon Amplitude [mV];Number of Events", 20, 0, 1);
  TH1F *histSiliconCharge = new TH1F("histSiliconCharge",";Silicon Charge [fC];Number of Events", 20, 0, 200);
  TH1F *histCdTeAmplitudeOverSiliconAmplitude = new TH1F("histCdTeAmplitudeOverSiliconAmplitude",";CdTe Amplitude / Silicon Amplitude;Number of Events", 20, 0, 30);
  TH1F *histCdTeChargeOverSiliconCharge = new TH1F("histCdTeChargeOverSiliconCharge",";CdTe Charge / Silicon Charge;Number of Events", 20, 0, 30);   


  if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if (jentry % 100 == 0) cout << "Processing Event " << jentry << " of " << nentries << "\n";

      nb = fChain->GetEntry(jentry);   nbytes += nb;

      //cuts
   
      //require photek signal
      // if (!(amp[0] > 0.03)) continue;

      //reject events with more than 1 track
      //if ( !(ntracks == 1 && chi2 < 10 )) continue;
      if ( isRinging[CdTeChannel] || isRinging[SiliconChannel]) continue;

      if (!(x1 > xLeftBoundary && x1 < xRightBoundary && y1 > yLeftBoundary && y1 < yRightBoundary )) continue;
    
      histCdTeAmplitude->Fill( 1000 * ampRestricted[CdTeChannel] / CdTeAmplification );
      histCdTeCharge->Fill( 1000 * integral[CdTeChannel] / CdTeAmplification );
      histSiliconAmplitude->Fill( 1000 * ampRestricted[SiliconChannel] / SiliconAmplification);
      histSiliconCharge->Fill( 1000 * integral[SiliconChannel] / SiliconAmplification);
      histCdTeChargeOverSiliconCharge->Fill( (integral[CdTeChannel] / CdTeAmplification)  / (integral[SiliconChannel] / SiliconAmplification));
      histCdTeAmplitudeOverSiliconAmplitude->Fill( (ampRestricted[CdTeChannel]/CdTeAmplification) / (ampRestricted[SiliconChannel]/ SiliconAmplification) );    
   }

   TFile *file = new TFile("CdTeCalo.root","UPDATE");
   file->cd();
   file->WriteTObject(histCdTeAmplitude, "histCdTeAmplitude", "WriteDelete");  
   file->WriteTObject(histCdTeCharge, "histCdTeCharge", "WriteDelete");  
   file->WriteTObject(histSiliconAmplitude, "histSiliconAmplitude", "WriteDelete");  
   file->WriteTObject(histSiliconCharge, "histSiliconCharge", "WriteDelete");  
   file->WriteTObject(histCdTeChargeOverSiliconCharge, "histCdTeChargeOverSiliconCharge", "WriteDelete");  
   file->WriteTObject(histCdTeAmplitudeOverSiliconAmplitude, "histCdTeAmplitudeOverSiliconAmplitude", "WriteDelete");  
   file->Close();
   delete file; 
   
};
