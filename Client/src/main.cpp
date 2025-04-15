#include "client.h"

int main(int argc, char **argv) {
	// INIT
	SetConsoleOutputCP(CP_UTF8); // Set the console output code page to UTF-8
	logs.getLogger().enableConsoleOutput(false).setOutputFile(".\\logs\\laster.log");

	logs.info("Initializing CNT.USER (Version %s)", CNT_VERSION);
	logs.info("Starting CNT.USER (Version %s)", CNT_VERSION);
	logs.info("CNT.USER (Version %s) started", CNT_VERSION);

	for (int i = 0; i < argc; ++i) {
		logs.info("Argument %d: %s", i, argv[i]);
		args.push_back((LPCWSTR)argv[i]);
	}
		

	if (args.size() < 2) {
		logs.info("No command provided. Use 'cnt help' for usage information.");
		logs.info("Output Text...(cnt.page.help)");
		std::wcout << L"CNT.USER (Version" << CNT_VERSION << L")\n"
			L"Usage:\ncnt <command> [parameters]\n\n";
		showHelpPage(L"");
		exit(0);
	}

	client host(CNT_DEFAULT_RUNPATH);
	if (host.fail()) {
		logs.info("CNT.USER (Version %s) failed to start", CNT_VERSION);
		std::wcout << _RunError_PathNoFound_Tip << _RunError_PathNoFound_InputTip;
		logs.info("Error: Unable to connect to the default CNT_PATH, please specify the default CNT_PATH\n");
		logs.info("Input new CNT_PATH...");
		LPCWSTR newPath; std::getline(std::wcin, newPath);
		logs.info("New CNT_PATH: %s", newPath);
		std::wcout << _RunError_PathNoFound_AddTip;
		do {
			char addPath; std::cin >> addPath;
			if (addPath == 'y' || addPath == 'Y') {
				logs.info("Adding new CNT_PATH to the system...");
				// Add new path to system environment variables
				HKEY hKey;
				if (RegOpenKeyEx(HKEY_CURRENT_USER, L"Environment", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
					RegSetValueEx(hKey, L"PATH", 0, REG_SZ, (const BYTE*)newPath, (wcslen(newPath) + 1) * sizeof(wchar_t));
					RegCloseKey(hKey);
					logs.info("New CNT_PATH added successfully.");
					std::wcout << _RunError_PathNoFound_ResetTip;
					break;
				}
			}
			else if (addPath == 'n' || addPath == 'N') {
				logs.info("CNT_PATH not added.");
				break;
			}
			else {
				std::wcout << _RunError_PathNoFound_InputError;
			}
		} while (true);

		exit(0);
	}

	for (LPCWSTR line : args) {
		logs.info("Command: %s", line);

	}
}