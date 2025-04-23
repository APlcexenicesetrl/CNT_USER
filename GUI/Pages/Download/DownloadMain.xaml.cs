using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using Microsoft.UI.Xaml.Media.Animation;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace GUI.Pages.Download
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class DownloadMain : Page
    {
        public DownloadMain()
        {
            this.InitializeComponent();
        }

        private void DownloadSelectionChanged(NavigationView sender, NavigationViewSelectionChangedEventArgs args)
        {
            //NavigationViewItem selectedItem = sender.Tag;
            //int currentSelectedIndex = sender.Tag.IndexOf(selectedItem);
            //int previousSelectedIndex = 1;
            //System.Type pageType;

            //switch (currentSelectedIndex)
            //{
            //    case 0:
            //        pageType = typeof(Home);
            //        break;
            //    case 1:
            //        pageType = typeof(DownloadMain);
            //        break;
            //    case 2:
            //        pageType = typeof(Setting);
            //        break;
            //    case 3:
            //        pageType = typeof(More);
            //        break;
            //    default:
            //        pageType = typeof(Home);
            //        break;
            //}



            //var slideNavigationTransitionEffect = currentSelectedIndex - previousSelectedIndex > 0 ? SlideNavigationTransitionEffect.FromRight : SlideNavigationTransitionEffect.FromLeft;

            //contentFrame.Navigate(pageType, null, new SlideNavigationTransitionInfo() { Effect = slideNavigationTransitionEffect });

            //previousSelectedIndex = currentSelectedIndex;
        }
    }
}
