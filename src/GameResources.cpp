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
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x03C6DFC0);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x8);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x8);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x100);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0xE0);
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

private:
    DWORD64 GetSecondPlayerMoneyPointer() {
        DWORD64 populationPointer = GetWin64Shipping();
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x03C6DFC0);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x8);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x8);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x280);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x318);
        return populationPointer + 0x9D8;
    }

private:
    DWORD64 GetYearPointer() {
        DWORD64 yearPointer = GetWin64Shipping();
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x03C70440);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x148);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x508);
        return yearPointer + 0x28;
    }


private:
    DWORD64 GetMonthPointer() {
        DWORD64 yearPointer = GetWin64Shipping();
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x03C70440);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x148);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x508);
        return yearPointer + 0x2C;
    }

private:
    DWORD64 GetPausePointer() {
        DWORD64 yearPointer = GetWin64Shipping();
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x03C70440);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x148);
        return yearPointer + 0x4B3;
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

public:
    int GetYear() {
        DWORD64 yearPointer = GetYearPointer();
        return memoryReader->ReadInt(yearPointer);
    }

public:
    int GetMonth() {
        DWORD64 yearPointer = GetMonthPointer();
        return memoryReader->ReadInt(yearPointer);
    }

public:
    void SetPaused(bool paused) {
        DWORD64 pausePointer = GetPausePointer();
        return memoryReader->WriteBoolean(pausePointer, !paused);
    }

public:
    void TogglePause() {
        DWORD64 pausePointer = GetPausePointer();
        return memoryReader->WriteBoolean(pausePointer, IsPaused());
    }

public:
    bool IsPaused() {
        DWORD64 pausePointer = GetPausePointer();
        return !memoryReader->ReadBoolean(pausePointer);
    }

};