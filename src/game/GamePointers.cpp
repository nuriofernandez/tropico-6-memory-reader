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
        DWORD64 baseAddress = GetWin64Shipping();
        DWORD64 offsets[] = {0x03C04680, 0x28, 0x8E8, 0x10, 0x230};

        // Navigate memory pointers
        DWORD64 previousPointer = baseAddress;
        for (DWORD64 offset : offsets) {
            previousPointer = memoryReader->ReadDWORD(previousPointer + offset);
        }

        // Add final address offset
        return previousPointer + 0x9D8;
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
    DWORD64 GetUnemployedCitizens() {
        DWORD64 unemploymentPointer = GetWin64Shipping();
        unemploymentPointer = memoryReader->ReadDWORD(unemploymentPointer + 0x03C70440);
        unemploymentPointer = memoryReader->ReadDWORD(unemploymentPointer + 0x630);
        unemploymentPointer = memoryReader->ReadDWORD(unemploymentPointer + 0x8);
        unemploymentPointer = memoryReader->ReadDWORD(unemploymentPointer + 0x1A0);
        return unemploymentPointer + 0xE18;
    }

public:
    DWORD64 GetHomelessCitizens() {
        DWORD64 unemploymentPointer = GetWin64Shipping();
        unemploymentPointer = memoryReader->ReadDWORD(unemploymentPointer + 0x03C70440);
        unemploymentPointer = memoryReader->ReadDWORD(unemploymentPointer + 0x630);
        unemploymentPointer = memoryReader->ReadDWORD(unemploymentPointer + 0x8);
        unemploymentPointer = memoryReader->ReadDWORD(unemploymentPointer + 0x1A0);
        return unemploymentPointer + 0xDF8;
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
    DWORD64 GetColonialMandateTime() {
        DWORD64 yearPointer = GetWin64Shipping();
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x03C6DFC0);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x8);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x8);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0x1B0);
        yearPointer = memoryReader->ReadDWORD(yearPointer + 0xE0);
        return yearPointer + 0xDF0;
    }

public:
    DWORD64 GetGameSpeed() {
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