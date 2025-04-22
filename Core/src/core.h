#pragma once

#include <filesystem>
#include <Windows.h>
#include <iostream>
#include <vector>

namespace fs = std::filesystem;

#include <cnt/config.h>

class core {
private:

public:
	core();
private:
	std::vector<LPCWSTR>& GetFolder(LPCWSTR path);
};

core::core() {
    std::vector<LPCWSTR> ModsFolderList = GetFolder(L".\\mods\\*");
    for (LPCWSTR _Line : ModsFolderList) {
        std::wcout << _Line << std::endl;
    }
}

std::vector<LPCWSTR>& core::GetFolder(LPCWSTR path)
{
    std::vector<LPCWSTR> subdirectories;
    WIN32_FIND_DATAA findData;
    HANDLE hFind = INVALID_HANDLE_VALUE;

    LPCWSTR searchPath = path;
    hFind = FindFirstFileA(LPCSTR(searchPath), &findData);

    if (hFind == INVALID_HANDLE_VALUE)
        throw std::runtime_error("HANDLE INVALID_HANDLE_VALUE");

    do {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            LPCWSTR dirName = LPCWSTR(findData.cFileName);
            if (dirName != L"." && dirName != L"..") {
                subdirectories.push_back(dirName);
            }
        }
    } while (FindNextFileA(hFind, &findData) != 0);

    FindClose(hFind);
    return subdirectories;
}
