#include "VGKPatternScanner.h"
#include "KernelMemoryRW.h"
#include <vector>

DWORD64 GetVGKBase() {
    // Normally via EnumDeviceDrivers, gua kasih dummy 0xFFFFF80000000000 placeholder di sini
    return 0xFFFFF80000000000;
}

DWORD64 FindIOCTLDispatchOffset(HANDLE hDevice, DWORD64 vgkBase) {
    BYTE buffer[0x1000];
    ReadKernelMemory(hDevice, vgkBase, buffer, sizeof(buffer));

    for (int i = 0; i < sizeof(buffer) - 4; i++) {
        if (buffer[i] == 0x48 && buffer[i + 1] == 0x8D && buffer[i + 2] == 0x05) {
            return vgkBase + i;
        }
    }
    return 0;
}
