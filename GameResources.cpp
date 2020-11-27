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

private:
    DWORD64 GetMoneyPointer() {
        DWORD64 moneyPointer = GetWin64Shipping();
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x037B4A08);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x8);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x0);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x90);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x108);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0xA28);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x340);
        return moneyPointer + 0x9D8;
    }

private:
    DWORD64 GetPopulationPointer() {
        DWORD64 populationPointer = GetWin64Shipping();
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x03C530D0);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x30);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x8F0);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0xF08);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x350);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x230);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x9D0);
        return populationPointer + 0xDBC;
    }

public:
    float GetMoney() {
        DWORD64 moneyPointer = GetMoneyPointer();
        return memoryReader->ReadFloat(moneyPointer);
    }

public:
    void SetMoney(float money) {
        DWORD64 moneyPointer = GetMoneyPointer();
        return memoryReader->WriteFloat(moneyPointer, money);
    }

public:
    int GetPopulation() {
        DWORD64 populationPointer = GetPopulationPointer();
        return memoryReader->ReadInt(populationPointer);
    }

public:
    void SetPopulation(int population) {
        DWORD64 populationPointer = GetPopulationPointer();
        return memoryReader->WriteInt(populationPointer, population);
    }

};