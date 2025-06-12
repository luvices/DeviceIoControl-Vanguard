#pragma once
#include <Windows.h>

BOOL LoadDriver(const std::wstring& driverPath);
BOOL UnloadDriver();
HANDLE OpenRTCoreDevice();
