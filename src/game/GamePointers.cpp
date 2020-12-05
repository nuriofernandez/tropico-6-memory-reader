#include "MemoryReader.cpp"

class GamePointers {

private:
    MemoryReader *memoryReader;

public:
    GamePointers(MemoryReader *memoryReader) {
        this->memoryReader = memoryReader;
    }

public:
    DWORD64 GetWin64Shipping() {
        return memoryReader->GetModuleBaseAddress("Tropico6-Win64-Shipping.exe");
    }

public:
    DWORD64 GetMoney() {
        DWORD64 moneyPointer = GetWin64Shipping();
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x03C6DFC0);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x8);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x8);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x100);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0xE0);
        return moneyPointer + 0x9D8;
    }

public:
    DWORD64 GetPopulation() {
        DWORD64 populationPointer = GetWin64Shipping();
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x0382BE80);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x0);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x360);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x9D0);
        return populationPointer + 0xDBC;
    }

public:
    DWORD64 GetSupport() {
        DWORD64 moneyPointer = GetWin64Shipping();
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x03C530D0);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x30);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0x330);
        moneyPointer = memoryReader->ReadDWORD(moneyPointer + 0xD48);
        return moneyPointer + 0x510;
    }

public:
    DWORD64 GetYear() {
        DWORD64 yearPointer = GetWin64Shipping();
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x03C70440);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x148);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x508);
        return yearPointer + 0x28;
    }

public:
    DWORD64 GetMonth() {
        DWORD64 yearPointer = GetWin64Shipping();
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x03C70440);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x148);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x508);
        return yearPointer + 0x2C;
    }

public:
    DWORD64 GetMandateTime() {
        DWORD64 yearPointer = GetWin64Shipping();
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x03C530D0);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x30);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x330);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0xD48);
        return yearPointer + 0x350;
    }

public:
    DWORD64 GetPause() {
        DWORD64 yearPointer = GetWin64Shipping();
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x03C70440);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x148);
        return yearPointer + 0x4B3;
    }

public:
    DWORD64 GetSecondPlayerMoney() {
        DWORD64 populationPointer = GetWin64Shipping();
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x03C6DFC0);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x8);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x8);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x280);
        populationPointer = memoryReader->ReadDWORD(populationPointer + 0x318);
        return populationPointer + 0x9D8;
    }

};