#include <iostream>
#include "VulnDriverLoader.h"
#include "KernelMemoryRW.h"
#include "VGKPatternScanner.h"

int main() {
    std::wcout << L"[+] Loading vulnerable driver...\n";
    LoadDriver(L"C:\\RTCore64.sys");

    HANDLE hDevice = OpenRTCoreDevice();
    if (hDevice == INVALID_HANDLE_VALUE) {
        std::cerr << "[-] Failed to open RTCore64 device\n";
        return 1;
    }

    DWORD64 vgkBase = GetVGKBase();
    std::wcout << L"[+] VGK.sys base at: " << std::hex << vgkBase << L"\n";

    DWORD64 dispatchOffset = FindIOCTLDispatchOffset(hDevice, vgkBase);
    std::wcout << L"[+] Dispatch table offset at: " << std::hex << dispatchOffset << L"\n";

    DWORD64 customHandler = vgkBase + 0x2000; // dummy handler address (replace with your stub)
    PatchDispatchHandler(hDevice, dispatchOffset, customHandler);

    std::cout << "[+] DeviceIoControl dispatch patched!\n";

    std::cin.get();

    std::wcout << L"[+] Cleaning up...\n";
    UnloadDriver();
    return 0;
}
