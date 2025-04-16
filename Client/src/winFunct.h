#pragma once

#include <filesystem>
#include <Windows.h>
#include <string>

typedef LPCWSTR String;

namespace fs = std::filesystem;

void setEnvVar(const std::wstring& name, const std::wstring& value) {
#ifdef _WIN32
    // Windows: Use WinAPI for direct control
    SetEnvironmentVariableW(name.c_str(), value.c_str());
#else
    // POSIX: Convert to narrow string (UTF-8)
    std::string narrowName(name.begin(), name.end());
    std::string narrowValue(value.begin(), value.end());
    setenv(narrowName.c_str(), narrowValue.c_str(), 1); // Overwrite if exists
#endif
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