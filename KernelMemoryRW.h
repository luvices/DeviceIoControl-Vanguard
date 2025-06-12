#pragma once
#include <Windows.h>

BOOL ReadKernelMemory(HANDLE hDevice, DWORD64 address, void* buffer, SIZE_T size);
BOOL WriteKernelMemory(HANDLE hDevice, DWORD64 address, void* buffer, SIZE_T size);
