//C++ INCLUDES
#include <vector>
#include <fstream>
//ROOT INCLUDES
//#include <TSYSTEM.h>
#include <TSystem.h>
#include <TTree.h>
#include <TLatex.h>
#include <TString.h>
#include <TFile.h>
#include <TH1D.h>
#include <TF1.h>
#include <TBox.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TRandom3.h>
#include <TLegend.h>
#include <TMath.h>
#include <TROOT.h>
#include <Math/GaussIntegrator.h>
#include <Math/IntegratorOptions.h>
//ROOFIT INCLUDES
#include <RooWorkspace.h>
#include <RooDataSet.h>
#include <RooRealVar.h>
#include <RooExponential.h>
#include <RooAddPdf.h>
#include <RooGaussian.h>
#include <RooLandau.h>
#include <RooFFTConvPdf.h>
#include <RooMinimizer.h>
#include <RooFitResult.h>
#include <RooPlot.h>
#include <RooExtendPdf.h>
#include <RooStats/SPlot.h>
#include <RooStats/ModelConfig.h>
#include <RooGenericPdf.h>
#include <RooFormulaVar.h>
#include <RooBernstein.h>
#include <RooMinuit.h>
#include <RooNLLVar.h>
#include <RooRandom.h>
#include <RooDataHist.h>
#include <RooHistPdf.h>
#include <RooArgList.h>
//#include <RealVar.h>
//LOCAL INCLUDES
#include "MakeFits.hh"

//Axis
const float axisTitleSize = 0.06;
const float axisTitleOffset = .8;

const float axisTitleSizeRatioX   = 0.18;
const float axisLabelSizeRatioX   = 0.12;
const float axisTitleOffsetRatioX = 0.84;

const float axisTitleSizeRatioY   = 0.15;
const float axisLabelSizeRatioY   = 0.108;
const float axisTitleOffsetRatioY = 0.52;

//Margins
const float leftMargin   = 0.12;
const float rightMargin  = 0.05;
const float topMargin    = 0.07;
const float bottomMargin = 0.12;

void LandauFit( TTree* tree, RooWorkspace* ws )
//void LandauFit( TTree* tree )
{
  float a =5;
  RooRealVar amp( "amplitude", "amp", 0, 0.5, "V" );
  amp.setBins(100);
  amp.setRange( "fitRange", 0.02, 0.35 );
  RooDataSet data( "data", "", RooArgSet(amp) );
  
  float Amp[36];
  float x1, y1, chi2, xSlope, ySlope;
  int ntracks;
  tree->SetBranchStatus("*",0);
  tree->SetBranchStatus("amp",1);
  tree->SetBranchStatus("x1", 1);
  tree->SetBranchStatus("y1", 1);
  tree->SetBranchStatus("ntracks", 1);
  tree->SetBranchStatus("chi2", 1);
  tree->SetBranchStatus("xSlope", 1);
  tree->SetBranchStatus("ySlope", 1);
  
  tree->SetBranchAddress("amp", Amp);
  tree->SetBranchAddress("x1", &x1);
  tree->SetBranchAddress("y1", &y1);
  tree->SetBranchAddress("ntracks", &ntracks);
  tree->SetBranchAddress("chi2", &chi2);
  tree->SetBranchAddress("xSlope", &xSlope);
  tree->SetBranchAddress("ySlope", &ySlope);
  
  int nentries = tree->GetEntries();
  int countEntries = 0;
  for ( int i = 0; i < nentries-1; i++ )
    {
      tree->GetEntry(i);
      if ( !(Amp[0] > 0.1 && Amp[0] < 0.3) )continue;
      if ( !(ntracks == 1 && chi2 < 10 )) continue;
      //if ( !(fabs(xSlope) < 5e-4 && fabs(ySlope) < 5e-4)) continue;
      if ( !(fabs(xSlope) < 1e-3 && (fabs(ySlope) < 4e-3) && fabs(ySlope) > 3e-3)) continue;
      
      if ( !(Amp[3] > 0.02  && Amp[3] < 0.4) )continue;
      amp.setVal( Amp[3] );
      data.add(RooArgSet(amp));
      countEntries++;
    }
  
  
  int npoints = data.numEntries();
  
  // Construct landau(t,ml,sl) ;
  RooRealVar ml("ml", "mean landau", 0.05);
  //RooRealVar ml("ml","mean landau",0.055);
  ml.setConstant( kFALSE );
  RooRealVar sl("sl", "sigma landau", 0.003) ;
  //RooRealVar sl("sl","sigma landau",0.01);
  sl.setConstant( kFALSE );
  RooLandau landau("lx", "lx",amp,ml,sl);
  
  // Construct gauss(t,mg,sg)
  RooRealVar mg("mg", "mg", 0);
  RooRealVar sg("sg", "sg", 6.64228e-03);
  sg.setConstant( kFALSE );
  RooGaussian gauss("gauss", "gauss", amp, mg, sg);
  
  
  // C o n s t r u c t   c o n v o l u t i o n   p d f 
  // ---------------------------------------
  
  // Construct landau (x) gauss
  RooFFTConvPdf lxg("lxg", "landau (X) gauss", amp, landau, gauss) ;
  
  
  RooRealVar* Ns = new RooRealVar( "Ns", "N_{s}", 8000, "events");
  Ns->setConstant(kFALSE);
  
  //------------------------------------
  //C r e a t e   E x t e n d e d  p.d.f
  //------------------------------------
  TString ex_pdf_name          = "lxg_ext";
  RooAddPdf* ex_lxg = new RooAddPdf( ex_pdf_name, "extLxG", RooArgList(lxg), RooArgList(*Ns) );
  //RooAddPdf* ex_lxg = new RooAddPdf( ex_pdf_name, "extLxG", RooArgList(landau), RooArgList(*Ns) );
  

  // ----------------------------------------------------------------------
  // f i t   a n d   p l o t   c o n v o l u t e d   p d f 
  // ----------------------------------------------------------------------
  
  // Fit gxlx to data
  ex_lxg->fitTo(data, RooFit::Strategy(0), RooFit::Extended( kTRUE ), RooFit::Range("fitRange") );
  
  RooFitResult* sres = ex_lxg->fitTo(data, RooFit::Strategy(2), RooFit::Extended( kTRUE ), RooFit::Save( kTRUE ), RooFit::Range("fitRange") );
  
  //std::cout << npoints << std::endl;
  //-----------------------
  //C r e a t e  doubleGaus
  //-----------------------
  //ws->pdf( tag )->fitTo( data, RooFit::Strategy(0), RooFit::Extended( kTRUE ), RooFit::Range("signal") );
  //RooFitResult* sres = ws->pdf( "" )->fitTo( data, RooFit::Strategy(2), RooFit::Extended( kTRUE ), RooFit::Save( kTRUE ), RooFit::Range("signal") );
  
  sres->SetName( "sres" );
  ws->import( *sres );
  
  RooPlot* frame = amp.frame();
  data.plotOn( frame );
  
  ex_lxg->plotOn( frame, RooFit::LineColor( kBlue ), RooFit::Range("Full"), RooFit::NormRange("Full") );
  ws->import( amp );
  ws->import( data );
  frame->SetName("MY_frame" );
  ws->import( *frame );
  std::cout << "passed entries ===> " << countEntries << std::endl;
  //return ws;
  std::cout << "here1" << std::endl;
  
  return;
};

