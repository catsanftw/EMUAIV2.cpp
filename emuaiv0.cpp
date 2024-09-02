## 
?>

    // emulator.h
#pragma once
#include "CPU.h"
#include "Memory.h"
#include "Graphics.h"
#include "Audio.h"
#include "Input.h"
#include "ROM.h"

class Emulator {
public:
    Emulator();
    bool loadROM(const std::string& path);
    void run();

private:
    ROM rom;
    Memory memory;
    CPU cpu;
    Graphics graphics;
    Audio audio;
    Input input;
};

// emulator.cpp
#include "emulator.h"

Emulator::Emulator() : cpu(memory) {}

bool Emulator::loadROM(const std::string& path) {
    return rom.load(path);
}

void Emulator::run() {
    while (true) {
        cpu.emulateCycle();
        graphics.render();
        audio.process();
        input.poll();
    }
}
