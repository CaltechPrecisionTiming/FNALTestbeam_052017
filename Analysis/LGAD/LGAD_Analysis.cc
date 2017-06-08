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
  myPulse->CreateDeltaT_vs_PositionHisto(1, 1, 250, 0.07, 11650., 14300., 25500, 28250., false);
  myPulse->CreateDeltaT_vs_PositionHisto(1, 2, 250, 0.05, 15000., 17100., 25500, 28250., false);
  //-------------------
  //Efficiency
  //-------------------
  //myPulse->MakeEfficiencyVsXY(1, 200, 0.07, 11650., 14300., 25500, 28250.);
  //myPulse->MakeEfficiencyVsXY(2, 200, 0.05, 15000., 17100., 25500, 28250.);
  
  return 0;
}
