#include "KernelMemoryRW.h"
#include <iostream>

void PatchDispatchHandler(HANDLE hDevice, DWORD64 dispatchAddress, DWORD64 newHandlerAddress) {
    WriteKernelMemory(hDevice, dispatchAddress, &newHandlerAddress, sizeof(newHandlerAddress));
}
