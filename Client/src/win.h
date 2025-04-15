#pragma once

#include <Windows.h>
#include <vector>

#include <cnt/loggings.h> ][APlcexenicesetrl (C) 2025 

typedef LPCWSTR String;

cnt::Logging logs(new cnt::Logger("root"));
std::vector<LPCWSTR> args;

// CNT Information
#define CNT_VERSION L"Beta 0.5"
#define CNT_VERSION_DATE L"2025-10-01"
#define CNT_NAME L"cnt.user"
#define CNT_AUTHOR L"APlcexenicesetrl"

#define CNT_DEFAULT_RUNPATH L"%CNT_PATH%"

// CNT Lanuage
LPCWSTR _RunError_PathNoFound_Tip = L"Error: Unable to connect to the default CNT_PATH, please specify the default CNT_PATH\n";
LPCWSTR _RunError_PathNoFound_InputTip = L"Input new CNT_PATH: ";
LPCWSTR _RunError_PathNoFound_AddTip = L"Do you want to add a new CNT_PATH to the system for easy access next time? (y/n): ";
LPCWSTR _RunError_PathNoFound_ResetTip = L"Restart CNT changes have been completed\n";
LPCWSTR _RunError_PathNoFound_InputError = L"Invalid input. Please enter 'y' or 'n': ";

LPCWSTR _HelpPage_Title = L"[CNT.Help] This page can view the CNT command\n";
LPCWSTR _HelpPage_Text = L"Command: \n"
						 L" help\t\tDisplay CNT help page\n"
						 L" install\t\tInstall the CNT module/plugin to your device\n"
						 L" uninstall\t\tUninstall the CNT module/plugin from your device\n";


// CNT Functions

auto showHelpPage = [](LPCWSTR ShowCommand) {
	std::wcout << _HelpPage_Title << _HelpPage_Text;
};