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
        return memoryReader->GetModuleBaseAddress("Tropico6-Win64-Shipping.exe");
    }

public:
    float GetMoney() {
        DWORD64 win64Shipping = GetWin64Shipping();
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x037B4A08);
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
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x037B4A08);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x8);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x0);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x90);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x108);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0xA28);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x340);
        return memoryReader->WriteFloat(win64Shipping + 0x9D8, money);
    }

public:
    int GetPopulation() {
        DWORD64 win64Shipping = GetWin64Shipping();
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x03C530D0);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x30);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x8F0);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0xF08);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x350);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x230);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x9D0);
        return memoryReader->ReadInt(win64Shipping + 0xDBC);
    }

public:
    void SetPopulation(int population) {
        DWORD64 win64Shipping = GetWin64Shipping();
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x03C530D0);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x30);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x8F0);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0xF08);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x350);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x230);
        win64Shipping = memoryReader->ReadDWORD(win64Shipping + 0x9D0);
        return memoryReader->WriteInt(win64Shipping + 0xDBC, population);
    }

};