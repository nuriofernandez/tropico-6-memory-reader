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
    int GetUnemployedCitizens() {
        DWORD64 unemploymentPointer = gamePointers->GetUnemployedCitizens();
        return memoryReader->ReadInt(unemploymentPointer);
    }

/**
 * This method will return the number of homeless citizens of the last time that Almanac were open.
 */
public:
    int GetHomelessCitizens() {
        DWORD64 homelessPointer = gamePointers->GetHomelessCitizens();
        return memoryReader->ReadInt(homelessPointer);
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
    uint8_t GetGameSpeed() {
        DWORD64 pausePointer = gamePointers->GetGameSpeed();
        return memoryReader->ReadUint8(pausePointer);
    }

public:
    void SetGameSpeed(uint8_t speed) {
        DWORD64 pausePointer = gamePointers->GetGameSpeed();
        memoryReader->WriteUint8(pausePointer, speed);
    }

public:
    bool IsPaused() {
        return GetGameSpeed() == 0;
    }

public:
    void SetPaused(bool paused) {
        SetGameSpeed(paused ? 0 : 1);
    }

public:
    void TogglePause() {
        SetPaused(!IsPaused());
    }

};