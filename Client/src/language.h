#pragma once

#include "winFunct.h"

// CNT Lanuage
String _RunError_PathNoFound_Tip = L"Error: Unable to connect to the default CNT_PATH, please specify the default CNT_PATH\n";
String _RunError_PathNoFound_InputTip = L"Input new CNT_PATH: ";
String _RunError_PathNoFound_AddTip = L"Do you want to add a new CNT_PATH to the system for easy access next time? (y/n): ";
String _RunError_PathNoFound_ResetTip = L"Restart CNT changes have been completed\n";
String _RunError_PathNoFound_InputError = L"Invalid input. Please enter 'y' or 'n': ";

String _HelpPage_Title = L"[CNT.Help] This page can view the CNT command\n";
String _HelpPage_Text = L"Command: \n"
L" help\t\tDisplay CNT help page\n"
L" install\t\tInstall the CNT module/plugin to your device\n"
L" uninstall\t\tUninstall the CNT module/plugin from your device\n";