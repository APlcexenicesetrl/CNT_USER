using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using GUI.Class;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using Windows.Foundation;
using Windows.Foundation.Collections;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace GUI.Pages
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class Home : Page
    {
        public Home()
        {
            this.InitializeComponent();
            updateModuleOpeningState();
        }

        private void updateModuleOpeningState()
        {
            Module module = new Module();
            Module.ModuleOpeningState moduleOpeningState = module.GetModuleOpeningState(null);

            if (moduleOpeningState.succes)
            {
                ModuleOpeningStateInfo.Severity = InfoBarSeverity.Success;
                ModuleOpeningStateInfo.Message = moduleOpeningState.number + " module has been started, everything is normal so far";
            }
            else
            {
                ModuleOpeningStateInfo.Severity = InfoBarSeverity.Error;
                ModuleOpeningStateInfo.Message = "Module has crashed";
            }
        }
    }
}
