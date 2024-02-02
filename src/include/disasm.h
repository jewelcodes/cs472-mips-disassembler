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
public:
    Disassembler(uint8_t *, size_t);
};

class Iformat {
public:
    Iformat(uint32_t, uint32_t);
};

class Rformat {
public:
    Rformat(uint32_t, uint32_t);
};
