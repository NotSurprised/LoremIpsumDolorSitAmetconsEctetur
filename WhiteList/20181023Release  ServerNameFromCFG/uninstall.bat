RUNDLL32.EXE SETUPAPI.DLL,InstallHinfSection DefaultUninstall 132 .\IcrlMonitor.inf
sc stop "Whitelist"
sc delete "Whitelist"