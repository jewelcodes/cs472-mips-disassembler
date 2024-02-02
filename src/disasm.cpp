/*
 * MET CS 472 - Computer Architecture
 * Project 1: MIPS Disassembler
 * Omar Elghoul
 */

#include <disasm.h>
#include <iostream>

// constructor -- called from main
Disassembler::Disassembler(uint32_t *b, size_t s) {
    this->binary = b;
    this->size = s/4;       // size of the binary in 32-bit words
    this->pc = 0x9A040;     // in accordance with the instructions
}

// here the actual work is done
int Disassembler::disassemble() {
    for(this->index = 0; this->index < this->size; this->index++) {
        uint32_t instr = this->binary[this->index];

        // check R- or I-format
        uint8_t opcode = instr >> 26;
        if(opcode) {
            // I-format
            Iformat i(instr, this->pc);
            i.disassemble();
        } else {
            // R-format
            cout << "TODO: R-format" << endl;
        }
    }

    return 0;
}