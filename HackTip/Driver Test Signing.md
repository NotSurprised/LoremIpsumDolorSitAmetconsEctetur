# Driver Test Signing

MakeCert -r -pe -ss ITRItest -n "CN=ITRI.org(Test)" ITRItest.cer
SignTool sign /s ITRItest /n ITRItest.cer /t http://timestamp.verisign.com/scripts/timstamp.dll icrlmonitor.cat
SignTool sign /s ITRItest /n ITRItest.cer /t http://timestamp.verisign.com/scripts/timstamp.dll icrlmonitor.sys