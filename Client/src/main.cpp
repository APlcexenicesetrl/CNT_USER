#include "client.h"

int main(int argc, char **argv) {
	// INIT
	SetConsoleOutputCP(CP_UTF8); // Set the console output code page to UTF-8
	logs.getLogger().enableConsoleOutput(false).setOutputFile(".\\logs\\laster.log");

	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	logs.info("Initializing CNT.USER (Version %s)", CNT_VERSION);
	logs.info("Starting CNT.USER (Version %s)", CNT_VERSION);
	logs.info("CNT.USER (Version %s) started", CNT_VERSION);

	logs.info("Arguments count: %d", args.size());
	for (int i = 1; i < argc; ++i) {
		logs.info("Argument %d: %s", i, argv[i]);
		args.push_back((String)argv[i]);
	}

	args.push_back(L"version");
	
	if (args.size() < 1) {
		logs.info("No command provided. Use 'cnt help' for usage information.");
		logs.info("Output Text...(cnt.page.help)");
		std::wcout << L"CNT.USER (Version " << CNT_VERSION << L")\n"
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
		std::wstring newPath_Temp; std::getline(std::wcin, newPath_Temp);
		String newPath = newPath_Temp.c_str();
		logs.info("New CNT_PATH: %s", newPath);
		std::wcout << _RunError_PathNoFound_AddTip;
		do {
			char addPath; std::cin >> addPath;
			if (addPath == 'y' || addPath == 'Y') {
				logs.info("Adding new CNT_PATH to the system...");
				// Add new path to system environment variables
				SetPermanentEnvironmentVariable(L"CNT_PATH", newPath);
				break;
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

	for (String line : args) {
		logs.info("Command: %s", line);
		logs.error("Command '%s' is not found...", line);
	}
}