/*
 * MET CS 472 - Computer Architecture
 * Project 1: MIPS Disassembler
 * Omar Elghoul
 */

#include <disasm.h>
#include <iostream>
#include <iomanip>

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

        cout << internal << setfill('0');
        cout << "  " << hex << uppercase << setw(4) << this->pc << "    ";

        // check R- or I-format
        uint8_t opcode = instr >> 26;
        if(opcode) {
            // I-format
            cout << "TODO: I-format" << endl;
            //Iformat i(instr, this->pc);
            //if(i.disassemble()) return -1;
        } else {
            // R-format
            Rformat r(instr, this->pc);
            if(r.disassemble()) return -1;
        }

        this->pc += 4;
    }

    return 0;
}