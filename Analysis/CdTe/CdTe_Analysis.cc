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
  // Shower Sampling Comparison
  // |Absorber|5mm Air|Silicon|5mm Air|CdTe|
  //----------------------
  //1614-1616, 1617-1627
  // myPulse->CompareShowerSignal( 1, 2, 12.5, 82, 12000, 19000, 16000, 23000);

  //1510-1512
  // myPulse->CompareShowerSignal( 1, 2, 12.5, 12.5, 12000, 19000, 16000, 23000);

  //1513-1514
  // myPulse->CompareShowerSignal( 1, 2, 12.5, 12.5, 12000, 19000, 16000, 23000);

  //1508-1509
  // myPulse->CompareShowerSignal( 1, 2, 82, 12.5, 12000, 19000, 16000, 23000);

  //----------------------
  // Shower Sampling Comparison
  // |Absorber|5mm Air|CdTe|5mm Air|Silicon|
  //----------------------
  // 1628-1630, 1631-1633, 1634-1635
  // myPulse->CompareShowerSignal( 1, 2, 12.5, 82, 12000, 19000, 16000, 23000);
  
  //----------------------
  // Shower Sampling Comparison
  // |Absorber|5mm Air|CdTe
  //----------------------
  // 1502-1506, 1507
  myPulse->CompareShowerSignal( 1, 2, 82, 12.5, 12000, 19000, 16000, 23000);
  
  return 0;
}
