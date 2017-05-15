ls /eos/uscms/store/user/cmstestbeam/ETL/MT6Section1Data/052017/ | grep convert | awk -F'_' '{print $1}' | sed 's/Run//' | sort | uniq > ! totalList
ls /eos/uscms/store/user/cmstestbeam/ETL/MT6Section1Data/052017/RECO/ | awk -F'_' '{print $1}' | sed 's/Run//' | sort | uniq > ! doneList
sdiff totalList doneList | grep "<" | awk '{print $1}' >! newList

foreach f(`cat newList`)
   echo "Processing Run${f}"
   echo "./dat2rootPixels /eos/uscms/store/user/cmstestbeam/ETL/MT6Section1Data/052017/RawDataSaver0CMSTiming0_Run${f}_0_Raw.dat /eos/uscms/store/user/cmstestbeam/ETL/MT6Section1Data/052017/Run${f}_CMSTiming_converted.root /eos/uscms/store/user/cmstestbeam/ETL/MT6Section1Data/052017/RECO/Run${f}_RECO.root -1"
   ./dat2rootPixels /eos/uscms/store/user/cmstestbeam/ETL/MT6Section1Data/052017/RawDataSaver0CMSTiming0_Run${f}_0_Raw.dat /eos/uscms/store/user/cmstestbeam/ETL/MT6Section1Data/052017/Run${f}_CMSTiming_converted.root /eos/uscms/store/user/cmstestbeam/ETL/MT6Section1Data/052017/RECO/Run${f}_RECO.root 
end
