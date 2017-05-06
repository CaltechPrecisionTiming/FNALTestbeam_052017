### Job submission script for all .dat files on EOS

import glob
from subprocess import call

if __name__ == '__main__':
    dirs = [
            "/eos/uscms/store/user/cmstestbeam/BTL/",
            "/eos/uscms/store/user/cmstestbeam/ETL/05042017/",
            "/eos/uscms/store/user/cmstestbeam/ETL/05052017/",
            ]
    for d in dirs:
        files = glob.glob(d+"/*.dat")
        for f in files:
            print "File: ",f
            cmd = ['python', 'submit_condor.py', f,
                    #'--no-sub',
                    '--proxy', '/tmp/x509up_u48463',
                    '--out-dir', '/uscms_data/d1/djanders/05May2017',
                    '--config', '15may2017.config',
                    ]
            print ' '.join(cmd)
            call(cmd)
