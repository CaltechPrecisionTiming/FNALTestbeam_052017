#define pulse_cxx
#include "pulse.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "EfficiencyUtils.hh"

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
  TH1F *histX_den = new TH1F("histX_den",";X [mm];Number of Events"; 400, 20,30);
  TH1F *histX_num = new TH1F("histX_num",";X [mm];Number of Events"; 400, 20,30);
  TH1F *histY_den = new TH1F("histY_den",";Y [mm];Number of Events"; 400, 10,20);
  TH1F *histY_num = new TH1F("histY_num",";Y [mm];Number of Events"; 400, 10,20);
  
  if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      //cuts

      //require photek to show MIP signal
      if (!(amp[0] > 0.1 && amp[0] < 0.2)) continue;

      histX_den->Fill( 0.001*x2 );
      histY_den->Fill( 0.001*y2 );
      
      //numerator
      if (amp[channelNumber] > 0.08) {
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
						   25.5, 28.5,
						   0.0, 1.0,
						   false
						   );
   
   TCanvas *cv = new TCanvas ("cv","cv", 800,800);

   effX->Draw("AP");

   


}



