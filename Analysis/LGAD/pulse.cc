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
  TH1F *histY_den = new TH1F("histX_den",";Y [mm];Number of Events", 400, 20,30);
  TH1F *histY_num = new TH1F("histX_num",";Y [mm];Number of Events", 400, 20,30);
  TH1F *histX_den = new TH1F("histY_den",";X [mm];Number of Events", 400, 10,20);
  TH1F *histX_num = new TH1F("histY_num",";X [mm];Number of Events", 400, 10,20);
  
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
      if (!(amp[0] > 0.1 && amp[0] < 0.2)) continue;
      if (!(x2 > 11300 && x2 < 14600 && y2 > 25000 && y2 < 28500)) continue;

      histX_den->Fill( 0.001*x2 );
      histY_den->Fill( 0.001*y2 );
      //cout << "Fill Den: " << 0.001*x2 << " " << 0.001*y2 << "\n";
      
      //numerator
      if (amp[channelNumber] > 0.08) {
	//cout << "Fill NUM: " << 0.001*x2 << " " << 0.001*y2 << "\n";
	histX_num->Fill( 0.001*x2 );
	histY_num->Fill( 0.001*y2 );       
      }
   }

   vector<double> xbins;
   vector<double> ybins;
   TGraphAsymmErrors* effX = createEfficiencyGraph(histX_num, histX_den,
						   Form("EfficiencyVsX_Channel%d",channelNumber),
						   xbins,
						   11.5, 14.5,
						   0.0, 1.0,
						   false
						   );
   TGraphAsymmErrors* effY = createEfficiencyGraph(histY_num, histY_den,
						   Form("EfficiencyVsY_Channel%d",channelNumber),
						   ybins,
						   25.3, 28.4,
						   0.0, 1.0,
						   false
						   );
   

   TFile *file = new TFile("eff.root","UPDATE");
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

void pulse::CreateMPV_vs_PositionHisto( )
{
  const int npoints = 30;
  float x_pos[npoints];//x-positions
  float x_pos_un[npoints];//x-position uncertainty
  float mpv_x[npoints];//mpv amplitude for x
  float mpv_x_un[npoints];//uncertainty on mpv amplitude x
  float y_pos[npoints];//y-positions
  float y_pos_un[npoints];//y-position uncertainty
  float mpv_y[npoints];//mpv amplitude for x
  float mpv_y_un[npoints];//uncertainty on mpv amplitude y

  //------------------
  //Define initial positions and step size, all units are in microns
  //-------------------
  float x_init = 11000.;//microns
  float y_init = 13000.;//microns
  float step = 500.;//microns
  for ( int i = 0; i < npoints; i++ )
    {
      x_pos[i] = x_init + step*(float)i;
      x_pos_un[i] = 0;
      mpv_x[i] = MPV_vs_Position( "X", 1, x_pos[i], step, 0.08, 0.2 );
      mpv_x_un[i] = 0;
      y_pos[i] = y_init + step*(float)i;
      y_pos_un[i] = 0;
      mpv_y[i] = MPV_vs_Position( "Y", 1, y_pos[i], step, 0.08, 0.2 );
      mpv_y_un[i] = 0;
    }

  TGraphErrors* gr_mpv_x = new TGraphErrors(npoints, x_pos, mpv_x, x_pos_un, mpv_x_un);
  TGraphErrors* gr_mpv_y = new TGraphErrors(npoints, y_pos, mpv_y, y_pos_un, mpv_y_un);

  TFile* fout = new TFile("mpv_tgraphs.root", "RECREATE");
  gr_mpv_x->Write("mpv_x");
  gr_mpv_y->Write("mpv_y");
  fout->Close();
};

float pulse::MPV_vs_Position( TString coor, const int channel, const float coorLow, const float step,
			      const float AmpLowCut, const float AmpHighCut)
{
  if ( channel < 0 ) return -999.;
  
  fChain->SetBranchStatus("*", 0);
  fChain->SetBranchStatus("amp", 1);
  fChain->SetBranchStatus("x2", 1);
  fChain->SetBranchStatus("y2", 1);
  if (fChain == 0) return -999;
  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  
  TH1F* h_mpv = new TH1F("h_mpv", "h_mpv", 100, 0, 0.5);
  for (Long64_t jentry=0; jentry<nentries;jentry++)
    {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      
      if ( amp[channel] >= AmpLowCut && amp[channel] <= AmpHighCut )
	{
 	  if ( (coor == "x" || coor == "X") && x2 >= coorLow && x2 < coorLow + step ) h_mpv->Fill(amp[channel]);
	  if ( (coor == "y" || coor == "Y") && y2 >= coorLow && y2 < coorLow + step ) h_mpv->Fill(amp[channel]);
	}
    }
  
  TF1* landau = new TF1( "landau", "landau", AmpLowCut, AmpHighCut );
  h_mpv->Fit("landau","Q","", AmpLowCut, AmpHighCut);
  float mpv = landau->GetParameter(1);
  TFile* fout = new TFile("mpv_test.root", "recreate");
  h_mpv->Write();
  fout->Close();
  return mpv;
};
