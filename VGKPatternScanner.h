#pragma once
#include <Windows.h>

DWORD64 GetVGKBase();
DWORD64 FindIOCTLDispatchOffset(HANDLE hDevice, DWORD64 vgkBase);
