#pragma once

#include <Windows.h>
#include <vector>
#include <crtdbg.h>

#include <cnt/loggings.h> ][APlcexenicesetrl (C) 2025 

#include "language.h"

cnt::Logging logs(new cnt::Logger("root"));
std::vector<String> args;

// CNT Information
#define CNT_VERSION L"Beta 0.5"
#define CNT_VERSION_DATE L"2025-10-01"
#define CNT_NAME L"cnt.user"
#define CNT_AUTHOR L"APlcexenicesetrl"

#define CNT_DEFAULT_RUNPATH L"%CNT_PATH%"

// CNT Functions

auto showHelpPage = [](String ShowCommand) {
	std::wcout << _HelpPage_Title << _HelpPage_Text;
};