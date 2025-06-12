#include "KernelMemoryRW.h"

BOOL ReadKernelMemory(HANDLE hDevice, DWORD64 address, void* buffer, SIZE_T size) {
    DWORD64 input[2] = { address, size };
    DWORD bytesReturned;
    return DeviceIoControl(hDevice, 0x22240C, &input, sizeof(input), buffer, size, &bytesReturned, nullptr);
}

BOOL WriteKernelMemory(HANDLE hDevice, DWORD64 address, void* buffer, SIZE_T size) {
    DWORD64 input[2] = { address, size };
    DWORD bytesReturned;
    return DeviceIoControl(hDevice, 0x222410, &input, sizeof(input), buffer, size, &bytesReturned, nullptr);
}
