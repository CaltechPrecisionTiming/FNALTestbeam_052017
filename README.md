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


## Converting CAEN DRS4 file **without** pixel telescope file

The executable is called: **ConvertDat2Root**. The corresponding source
code is located 
in app/ConvertDat2Root.cc

Here is an example  on how to run the program

```
./ConvertDat2Root --inputFileName=<your_caen_drs4_file.dat> --outputFileName=<your_output_file.root> --nEvents=<number_of_events_to_be_processed>
```

By default this program will note save the raw waveform from the CAEN
DRS4 digitizer and will only stored the analysis level variables:
amplitudes, timestamps, risetimes, etc.

To save the raw data you have to add the flag: **--saveRaw**. Here is an
example how to use this option:

```
./ConvertDat2Root --inputFileName=<your_caen_drs4_file.dat> --outputFileName=<your_output_file.root> --nEvents=<number_of_events_to_be_processed> --saveRaw
```

There is another option which make is it easier to debug if you think
your results are not correct. Usually this means that the rising edge
or gaussian fits carried out to obtain the timespams maybe failing or
there is some pulse/fit related issue. The option **--debug** creates
pdf files with the pulses and their fits. It is adviced to run this
only with a few number of events (about 100) since there will be at
least nchannelsx100 plots automatically made. Here is an
example how to use this option:

```
./ConvertDat2Root --inputFileName=<your_caen_drs4_file.dat> --outputFileName=<your_output_file.root> --nEvents=<number_of_events_to_be_processed> --debug
```

Please create a directory called **plots** before attempting this
command. Otherwise you will get no plots.


Another important file is the **config file**. This file specifies the
active channels in the experiment you are running. It also allows you
to set other properties such as the polarity of the pulse, whether or
not perform certain fits or try to apply some filter. The are config
file example located in: **FNALTestbeam_052017/config**.

By default the program will take the following config file:
**FNALTestbeam_052017/config/15may2017.config**.

You can set the config file by using the optional flag:
**--config=**. Here is an example on how to use this optional flag:

```
./ConvertDat2Root --inputFileName=<your_caen_drs4_file.dat> --outputFileName=<your_output_file.root> --nEvents=<number_of_events_to_be_processed> --config=<your_config>
```

## Converting CAEN DRS4 file **with** pixel telescope file

The executable is called: **ConvertDat2RootWithPixels**. The corresponding source
code is located 
in **app/ConvertDat2RootWithPixels.cc**

Here is an example  on how to run the program

```
./ConvertDat2RootWithPixels --inputFileName=<your_caen_drs4_file.dat> --pixelInputFileName=<your_pixel_file.root> --outputFileName=<your_output_file.root> --nEvents=<number_of_events_to_be_processed>
```

By default this program will note save the raw waveform from the CAEN
DRS4 digitizer and will only stored the analysis level variables:
amplitudes, timestamps, risetimes, etc.

To save the raw data you have to add the flag: **--saveRaw**. Here is an
example how to use this option:

```
./ConvertDat2RootWithPixels --inputFileName=<your_caen_drs4_file.dat> --pixelInputFileName=<your_pixel_file.root> --outputFileName=<your_output_file.root> --nEvents=<number_of_events_to_be_processed> --saveRaw
```

There is another option which make is it easier to debug if you think
your results are not correct. Usually this means that the rising edge
or gaussian fits carried out to obtain the timespams maybe failing or
there is some pulse/fit related issue. The option **--debug** creates
pdf files with the pulses and their fits. It is adviced to run this
only with a few number of events (about 100) since there will be at
least nchannelsx100 plots automatically made. Here is an
example how to use this option:

```
. ./ConvertDat2RootWithPixels --inputFileName=<your_caen_drs4_file.dat> --pixelInputFileName=<your_pixel_file.root> --outputFileName=<your_output_file.root> --nEvents=<number_of_events_to_be_processed> --debug
```

Please create a directory called **plots** before attempting this
command. Otherwise you will get no plots.


Another important file is the **config file**. This file specifies the
active channels in the experiment you are running. It also allows you
to set other properties such as the polarity of the pulse, whether or
not perform certain fits or try to apply some filter. The are config
file example located in: **FNALTestbeam_052017/config**.

By default the program will take the following config file:
**FNALTestbeam_052017/config/15may2017.config**.

You can set the config file by using the optional flag:
**--config=**. Here is an example on how to use this optional flag:

```
./ConvertDat2RootWithPixels --inputFileName=<your_caen_drs4_file.dat> --pixelInputFileName=<your_pixel_file.root> --outputFileName=<your_output_file.root> --nEvents=<number_of_events_to_be_processed> --config=<your_config>
```
