/*
 * MET CS 472 - Computer Architecture
 * Project 1: MIPS Disassembler
 * Omar Elghoul
 */

#pragma once

#include <cstdint>      // for well-defined integer sizes
#include <cstddef>      // for size_t

using namespace std;

class Disassembler {
private:
    uint32_t *binary;
    size_t size;
    uint32_t pc;
    size_t index;

public:
    Disassembler(uint32_t *, size_t);
    int disassemble();
};

class Iformat {
public:
    Iformat(uint32_t, uint32_t);
    int disassemble();
};

class Rformat {
public:
    Rformat(uint32_t, uint32_t);
};
