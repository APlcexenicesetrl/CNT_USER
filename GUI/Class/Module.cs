using Microsoft.UI.Xaml;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GUI.Class
{
    class Module
    {
        public struct ModuleOpeningState
        {
            public bool succes;
            public int number;
            public Window? LinkTo;
        }
        
        public ModuleOpeningState GetModuleOpeningState(Client _client)
        {
            ModuleOpeningState mos = new ModuleOpeningState();
            mos.succes = false;
            mos.number = 0;
            mos.LinkTo = null;
            if (_client == null) return mos;
            return mos;
        }
    }
}
