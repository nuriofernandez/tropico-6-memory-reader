#pragma once

#include <Windows.h>
#include <iostream>
#include "MemoryReader.cpp"

class GameResources;

using namespace std;

class GameResources {

private:
    MemoryReader *memoryReader = new MemoryReader("Tropico6");

public:
    GameResources() {

    }

private:
    DWORD64 GetWin64Shipping() {
        DWORD64 baseAddress = memoryReader->GetModuleBaseAddress("Tropico6-Win64-Shipping.exe");
        return memoryReader->ReadDWORD(baseAddress + 0x037B4A08);
    }

public:
    float GetMoney() {
        DWORD64 win64Shipping = GetWin64Shipping();
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x8);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x0);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x90);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x108);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0xA28);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x340);
        return memoryReader->ReadFloat(win64Shipping + 0x9D8);
    }

public:
    void SetMoney(float money) {
        DWORD64 win64Shipping = GetWin64Shipping();
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x8);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x0);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x90);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x108);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0xA28);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x340);
        return memoryReader->WriteFloat(win64Shipping + 0x9D8, money);
    }

};