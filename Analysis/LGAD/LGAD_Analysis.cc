#include <iostream>
#include <string>
#include "TTree.h"
#include "TFile.h"
#include "pulse.hh"

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


int main( int argc, char** argv)
{

  std::string inputRootFile = ParseCommandLine( argc, argv, "--inputRootFile" );
  if ( inputRootFile == "" )
    {
      std::cerr << "[ERROR]: Please provide a valid ROOT file to run on!! Please use --inputRootFile=<your_file_name>\n";
      return -1;
    }

  TFile* fin = new TFile(inputRootFile.c_str(), "READ");
  TTree* myTree = (TTree*)fin->Get("pulse");
  pulse* myPulse = new pulse( myTree );

  //----------------------
  // MPV
  //----------------------
  //myPulse->CreateMPV_vs_PositionHisto(1, 1, 250, 0.07, 11650., 14300., 25500, 28250.);
  //myPulse->CreateMPV_vs_PositionHisto(1, 2, 250, 0.05, 15000., 17100., 25500, 28250.);
  //--------------------
  // Delta Time
  //--------------------
  //myPulse->CreateDeltaT_vs_PositionHisto(1, 1, 250, 0.07, 11650., 14300., 25500, 28250.);
  //myPulse->CreateDeltaT_vs_PositionHisto(1, 2, 250, 0.05, 15000., 17100., 25500, 28250.);
  //--------------------
  // Time Resolution
  //--------------------
  myPulse->CreateDeltaT_vs_PositionHisto(1, 1, 250, 0.07, 0.25, 11650., 14300., 25500, 28250., false, 0.1, 0.3);
  //myPulse->CreateDeltaT_vs_PositionHisto(1, 3, 250, 0.05, 0.2, 15000., 17100., 25500, 28250., false, 0.16, 0.32);
  //-------------------
  //Efficiency
  //-------------------
  //myPulse->MakeEfficiencyVsXY(1, 200, 0.07, 11650., 14300., 25500, 28250.);
  //myPulse->MakeEfficiencyVsXY(2, 200, 0.05, 15000., 17100., 25500, 28250.);

  /*
  //------------------------
  //Runs 847-851
  //------------------------
  //Efficiency
  myPulse->MakeEfficiencyVsXY(3, 200, 0.02, 11100., 13500., 20500, 23000., 0.16, 0.32);
  myPulse->MakeEfficiencyVsXY(4, 200, 0.02, 11100., 13500., 23500, 26000., 0.16, 0.32);
  myPulse->MakeEfficiencyVsXY(5, 200, 0.02, 13800., 16500., 23500, 26000., 0.16, 0.32);
  myPulse->MakeEfficiencyVsXY(6, 200, 0.02, 13800., 16500., 20500, 23000., 0.16, 0.32);
  //MPV
  myPulse->CreateMPV_vs_PositionHisto(1, 3, 250, 0.02, 0.1, 11100., 13500., 20500, 23000.);
  myPulse->CreateMPV_vs_PositionHisto(1, 4, 250, 0.02, 0.1, 11100., 13500., 23500, 26000.);
  myPulse->CreateMPV_vs_PositionHisto(1, 5, 250, 0.02, 0.1, 13800., 16500., 23500, 26000.);
  myPulse->CreateMPV_vs_PositionHisto(1, 6, 250, 0.02, 0.1, 13800., 16500., 20500, 23000.);
  //--------------------
  // Time Resolution
  //--------------------
  myPulse->CreateDeltaT_vs_PositionHisto(1, 3, 250, 0.02, 0.1, 11100., 13500., 20500, 23000., false, 0.16, 0.32);
  */
  
  return 0;
}
