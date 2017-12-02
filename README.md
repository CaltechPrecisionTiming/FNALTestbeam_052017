# FNALTestbeam Code
Analysis code for CAEN DRS4 readout with/without pixel telescope
informtion

You only need C++11 and  ROOT to be correctly setup to compile this
repository. If these requirements are satisfaid you can just do:

```
git clone git@github.com:CaltechPrecisionTiming/FNALTestbeam_052017.git
cd FNALTestbeam_052017
make
```


## Converting CAEN DRS4 file without pixel telescope file

The executable is called: "ConvertDat2Root". The corresponding source
code is located 
in app/ConvertDat2Root.cc

Here is an example  on how to run the program

```./ConvertDat2Root --inputFileName=<your_caen_drs4_file.dat> --outputFileName=<your_output_file.root> --nEvents=<number_of_events_to_be_processed>```

Sometimes you want numbered lists:

1. One
2. Two
3. Three
