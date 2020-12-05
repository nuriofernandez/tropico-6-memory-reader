#pragma once

#include <iostream>
#include "MemoryReader.cpp"
#include "GamePointers.cpp"

class GameResources;

using namespace std;

class GameResources {

private:
    MemoryReader *memoryReader = new MemoryReader("Tropico6");
    GamePointers *gamePointers = new GamePointers(memoryReader);

public:
    GameResources() {

    }

public:
    float GetMoney() {
        DWORD64 moneyPointer = gamePointers->GetMoney();
        return memoryReader->ReadFloat(moneyPointer);
    }

public:
    void SetMoney(float money) {
        DWORD64 moneyPointer = gamePointers->GetMoney();
        return memoryReader->WriteFloat(moneyPointer, money);
    }

public:
    int GetPopulation() {
        DWORD64 populationPointer = gamePointers->GetPopulation();
        return memoryReader->ReadInt(populationPointer);
    }

public:
    void SetPopulation(int population) {
        DWORD64 populationPointer = gamePointers->GetPopulation();
        return memoryReader->WriteInt(populationPointer, population);
    }

public:
    float GetSupport() {
        DWORD64 supportPointer = gamePointers->GetSupport();
        return memoryReader->ReadFloat(supportPointer);
    }

public:
    int GetYear() {
        DWORD64 yearPointer = gamePointers->GetYear();
        return memoryReader->ReadInt(yearPointer);
    }

public:
    int GetMonth() {
        DWORD64 yearPointer = gamePointers->GetMonth();
        return memoryReader->ReadInt(yearPointer);
    }

public:
    int GetMandateTime() {
        DWORD64 mandatePointer = gamePointers->GetMandateTime();
        return memoryReader->ReadInt(mandatePointer);
    }

public:
    int GetColonialMandateTime() {
        DWORD64 mandatePointer = gamePointers->GetColonialMandateTime();
        return memoryReader->ReadInt(mandatePointer);
    }

public:
    void SetMandateTime(int mandate) {
        DWORD64 mandatePointer = gamePointers->GetMandateTime();
        memoryReader->WriteInt(mandatePointer, mandate);
    }

public:
    void SetPaused(bool paused) {
        DWORD64 pausePointer = gamePointers->GetPause();
        return memoryReader->WriteBoolean(pausePointer, !paused);
    }

public:
    void TogglePause() {
        DWORD64 pausePointer = gamePointers->GetPause();
        return memoryReader->WriteBoolean(pausePointer, IsPaused());
    }

public:
    bool IsPaused() {
        DWORD64 pausePointer = gamePointers->GetPause();
        return !memoryReader->ReadBoolean(pausePointer);
    }

};