/*
 * MET CS 472 - Computer Architecture
 * Project 1: MIPS Disassembler
 * Omar Elghoul
 */

#include <disasm.h>
#include <iostream>
#include <iomanip>

// constructor
Rformat::Rformat(uint32_t instr, uint32_t pc) {
    this->instruction = instr;
    this->pc = pc;
    this->src1 = (instr >> 21) & 0x1F;
    this->src2 = (instr >> 16) & 0x1F;
    this->dst = (instr >> 11) & 0x1F;
}

void Rformat::printRegisters() {
    cout << " " << dec << setw(0);
    cout << "$" << dec << dst << ", ";
    cout << "$" << dec << src1 << ", ";
    cout << "$" << dec << src2 << endl;
}

// function code lookup table
static string functionCodes[64] = {
    "", "", "", "", "", "", "", "",         // 0x00
    "", "", "", "", "", "", "", "",         // 0x08
    "", "", "", "", "", "", "", "",         // 0x10
    "", "", "", "", "", "", "", "",         // 0x18
    "add", "", "sub", "", "and", "or", "", "",         // 0x20
    "", "", "slt", "", "", "", "", "",         // 0x28
    "", "", "", "", "", "", "", "",         // 0x30
    "", "", "", "", "", "", "", "",         // 0x38
};

int Rformat::disassemble() {
    uint32_t func = this->instruction & 0x3F;    // function code

    if(functionCodes[func].empty()) {
        cout << "undefined R-format instruction: function code 0x" << hex << uppercase << setw(2) << (int)func << endl;
        return 0;
    } else {
        cout << functionCodes[func];
        this->printRegisters();

        return 0;
    }
}
