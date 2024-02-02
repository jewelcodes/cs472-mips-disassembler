/*
 * MET CS 472 - Computer Architecture
 * Project 1: MIPS Disassembler
 * Omar Elghoul
 */

#include <disasm.h>
#include <iostream>

Iformat::Iformat(uint32_t instr, uint32_t pc) {
    this->instruction = instr;
    this->pc = pc;
}

int Iformat::disassemble() {
    return -1;      // TODO
}