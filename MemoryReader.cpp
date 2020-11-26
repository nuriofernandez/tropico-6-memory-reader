#pragma once

#include <Windows.h>
#include <iostream>
#include <stdint.h>
#include <psapi.h>
#include <tlhelp32.h>

using namespace std;

class MemoryReader {

private:
    HANDLE process;
    DWORD procID;
    string processName;
    LPCWSTR processNameLP;

public:
    MemoryReader(string processName) {
        // Obtain a long pointer to the process name string.
        wstring tempName = wstring(processName.begin(), processName.end());
        this->processNameLP = tempName.c_str();
        this->processName = processName;

        // Find process with that name.
        FindProcess();
    }

private:
    void FindProcess() {
        printf("Searching for process '%s'...\n", processName.c_str());
        bool hasHooked = HookToProcess();
        if (!hasHooked) {
            printf("Process '%s' not found. Retrying in 2 seconds...\n", processName.c_str());
            Sleep(2000);
            FindProcess();
            return;
        }
        printf("Successfully hooked to '%s'.\n", processName.c_str());
    }

private:
    bool HookToProcess() {
        // Find windows process with provided name.
        HWND hwnd = GetForegroundWindow(); // Handle the windows of the game/process.
        if (hwnd == NULL) {
            printf("Error: '%s' window process not found!\n", processName.c_str());
            return false;
        }

        string title = GetActiveWindowTitle();
        if (!strstr(title.c_str(), processName.c_str())) {
            printf("Error: Active window name doesn't match '%s'.\n", processName.c_str());
            return false;
        }

        // Find windows process with provided name.
        GetWindowThreadProcessId(hwnd, &procID);
        process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID); // Give all access to the process.
        if (procID == NULL) {
            printf("Error: '%s' window process found but we can not access to process PID!\n", processName.c_str());
            return false;
        }

        // Process found, we can continue. :)
        return true;
    }

public:
    int ReadInt(DWORD64 pointerAddress) {
        int response;
        if (!ReadProcessMemory(process, (LPVOID) pointerAddress, &response, sizeof(response), NULL)) {
            printf("Error: Failed to read a int from '%lx' memory address.\n", pointerAddress);
            throw -1;
        }
        return response;
    }

public:
    float ReadFloat(DWORD64 pointerAddress) {
        float response;
        if (!ReadProcessMemory(process, (LPVOID) pointerAddress, &response, sizeof(response), NULL)) {
            printf("Error: Failed to read a float from '%lx' memory address.\n", pointerAddress);
            throw -1;
        }
        return response;
    }

public:
    DWORDLONG ReadDWORD(DWORD64 pointerAddress) {
        DWORDLONG response;
        if (!ReadProcessMemory(process, (void *) pointerAddress, &response, sizeof(response), NULL)) {
            printf("Error: Failed to read a DWORD from '%lx' memory address.\n", pointerAddress);
            throw -1;
        }
        return response;
    }

public:
    uint8_t ReadUint8(DWORD64 pointerAddress) {
        uint8_t response;
        if (!ReadProcessMemory(process, (LPVOID) pointerAddress, &response, sizeof(response), NULL)) {
            printf("Error: Failed to read a int8 from '%lx' memory address.\n", pointerAddress);
            throw -1;
        }
        return response;
    }

public:
    string GetActiveWindowTitle() {
        char wnd_title[256];
        HWND hwnd = GetForegroundWindow();
        GetWindowText(hwnd, wnd_title, sizeof(wnd_title));
        return wnd_title;
    }

public:
    void WriteFloat(DWORD64 pointerAddress, float value) {
        WriteProcessMemory(process, (void *) pointerAddress, &value, sizeof(value), NULL);
    }

public:
    DWORD64 GetModuleBaseAddress(TCHAR *moduleName) {
        DWORD64 moduleBaseAddress = 0;
        HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procID);
        if (hSnapshot == INVALID_HANDLE_VALUE) throw -1;

        MODULEENTRY32 moduleEntry32;
        moduleEntry32.dwSize = sizeof(MODULEENTRY32);
        if (Module32First(hSnapshot, &moduleEntry32)) {
            do {
                if (strcmp(moduleEntry32.szModule, moduleName) == 0) {
                    moduleBaseAddress = (DWORD64) moduleEntry32.modBaseAddr;
                    break;
                }
            } while (Module32Next(hSnapshot, &moduleEntry32));
        }
        CloseHandle(hSnapshot);
        return moduleBaseAddress;
    }

};