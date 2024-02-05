/*
 * MET CS 472 - Computer Architecture
 * Project 1: MIPS Disassembler
 * Omar Elghoul
 */

#include <disasm.h>
#include <iostream>
#include <iomanip>

// opcode lookup table
static string opcodes[64] = {
    "", "", "", "", "", "", "", "",         // 0x00
    "", "", "", "", "", "", "", "",         // 0x08
    "", "", "", "", "", "", "", "",         // 0x10
    "", "", "", "", "", "", "", "",         // 0x18
    "", "", "", "", "", "", "", "",         // 0x20
    "", "", "", "", "", "", "", "",         // 0x28
    "", "", "", "", "", "", "", "",         // 0x30
    "", "", "", "", "", "", "", "",         // 0x38
};

Iformat::Iformat(uint32_t instr, uint32_t pc) {
    this->instruction = instr;
    this->pc = pc;
    this->left = (instr >> 21) & 0x1F;  // left and right registers - not naming them src/dest because we -
    this->right = (instr >> 16) & 0x1F; // - don't know what they are until we know the exact instruction
    this->offset = instr & 0xFFFF;
}

int Iformat::disassemble() {
    uint32_t opcode = this->instruction >> 26;

    if(opcodes[opcode].empty()) {
        cout << "undefined I-format instruction: opcode code 0x" << hex << uppercase << setw(2) << opcode << endl;
        return 0;
    } else {
        cout << opcodes[opcode];
        //this->printRegistersOffset();
        return 0;
    }
}