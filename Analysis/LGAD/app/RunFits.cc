#include <iostream>
//ROOT INCLUDES
#include <TFile.h>
#include <TTree.h>
#include <TMath.h>
#include <TH1F.h>
#include <TROOT.h>
//LOCAL INCLUDES
#include "MakeFits.hh"

int main( int argc, char* argv[])
{
  gROOT->Reset();
  TFile* f  = new TFile("/Users/cmorgoth/Work/data/test_beam/ETL_TB_May2017/Run847-891_RECO_FINAL.root", "read");
  TTree* tree = (TTree*)f->Get("pulse");  
  RooWorkspace* myws = new RooWorkspace( "ws", "" );
  LandauFit( tree, myws );
  f->Close();

  
  TFile* fout = new TFile("/Users/cmorgoth/git/FNALTestbeam_052017/Analysis/LGAD/outFile.root", "RECREATE");
  
  myws->Write("myws");
  fout->Close();
  
  return 0;
}
