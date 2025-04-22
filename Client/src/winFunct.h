#pragma once

#include <filesystem>
#include <Windows.h>
#include <cstring>

typedef LPCWSTR String;

namespace fs = std::filesystem;

bool SetPermanentEnvironmentVariable(LPCTSTR value, LPCTSTR data)
{
    HKEY hKey;
    LPCTSTR keyPath = TEXT("System\\CurrentControlSet\\Control\\Session Manager\\Environment");
    LSTATUS lOpenStatus = RegOpenKeyEx(HKEY_LOCAL_MACHINE, keyPath, 0, KEY_ALL_ACCESS, &hKey);
    if (lOpenStatus == ERROR_SUCCESS)
    {
        LSTATUS lSetStatus = RegSetValueEx(hKey, value, 0, REG_SZ, (LPBYTE)data, lstrlen(data) + 1);
        RegCloseKey(hKey);

        if (lSetStatus == ERROR_SUCCESS)
        {
            SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, (LPARAM)"Environment", SMTO_BLOCK, 100, NULL);
            return true;
        }
    }

    return false;
}

void deleteEnvVar(const std::wstring& name) {
#ifdef _WIN32
    SetEnvironmentVariableW(name.c_str(), nullptr);
#else
    std::string narrowName(name.begin(), name.end());
    unsetenv(narrowName.c_str());
#endif
}

std::wstring getEnvVar(const std::wstring& name) {
#ifdef _WIN32
    // Windows: Use WinAPI
    wchar_t buffer[32767];
    DWORD result = GetEnvironmentVariableW(name.c_str(), buffer, 32767);
    return (result > 0) ? std::wstring(buffer) : L"";
#else
    // POSIX: Narrow strings
    std::string narrowName(name.begin(), name.end());
    char* value = getenv(narrowName.c_str());
    return value ? std::wstring(value, value + strlen(value)) : L"";
#endif
}

int isFile(LPCWSTR path) { // 0: not found; 1: is directory; 2: is file
    // Example path (supports narrow/wide strings)
    fs::path target_path = path;  // Wide string (Windows)
    // fs::path target_path = "/home/user/Documents";    // Narrow string (Linux/macOS)

    // Check if the path exists
    bool path_exists = fs::exists(target_path);

    // Check if the path is a directory/file
    bool is_directory = fs::is_directory(target_path);
    bool is_file = fs::is_regular_file(target_path);

    if (path_exists) {
        if (is_directory) return 1;
        if (is_file) return 2;
    }
    else return 0;

}

bool PathExists(const std::wstring& path) {
    DWORD attrib = GetFileAttributesW(path.c_str());
    return (attrib != INVALID_FILE_ATTRIBUTES) &&
        !(attrib & FILE_ATTRIBUTE_DIRECTORY);  // Adjust for file/directory checks
}