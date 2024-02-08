/*
 * MET CS 472 - Computer Architecture
 * Project 1: MIPS Disassembler
 * Omar Elghoul
 */

#include <disasm.h>
#include <iostream>
#include <iomanip>

// for branching
#define OPCODE_BEQ      0x04
#define OPCODE_BNE      0x05

// opcode lookup table
static string opcodes[64] = {
    "", "", "", "", "beq", "bne", "", "",         // 0x00
    "", "", "", "", "", "", "", "",         // 0x08
    "", "", "", "", "", "", "", "",         // 0x10
    "", "", "", "", "", "", "", "",         // 0x18
    "", "", "", "lw", "", "", "", "",         // 0x20
    "", "", "", "sw", "", "", "", "",         // 0x28
    "", "", "", "", "", "", "", "",         // 0x30
    "", "", "", "", "", "", "", "",         // 0x38
};

// Constructor
Iformat::Iformat(uint32_t instr, uint32_t pc) {
    this->instruction = instr;
    this->pc = pc;
    this->left = (instr >> 21) & 0x1F;  // left and right registers - not naming them src/dest because we -
    this->right = (instr >> 16) & 0x1F; // - don't know what they are until we know the exact instruction
    this->offset = instr & 0xFFFF;
}

void Iformat::printBranch() {   // in the format of $reg, $reg, ADDRESS IN HEX
    cout << " " << dec << setw(0);
    cout << "$" << dec << this->left << ", ";
    cout << "$" << dec << this->right << ", ";

    // for branching, addressing is relative to PC and the offset is a signed 16-bit number
    uint32_t absoluteAddress = this->pc;
    uint32_t branchMagnitude;
    
    if(this->offset & 0x8000) {     // sign bit
        // account for two's complement since we've stored this in an unsigned int
        branchMagnitude = ((~this->offset) + 1) & 0xFFFF;
        branchMagnitude <<= 2;
        absoluteAddress -= branchMagnitude;
    } else {
        branchMagnitude = this->offset;
        branchMagnitude <<= 2;
        absoluteAddress += branchMagnitude;
    }

    cout << "0x" << hex << uppercase << setw(8) << absoluteAddress << endl;
}

void Iformat::printRegistersOffset() {  // in the format of $register, OFFSET IN SIGNED DECIMAL($register)
    cout << " " << dec << setw(0);
    cout << "$" << dec << this->right << ", ";
    
    // offset is SIGNED here
    uint32_t fixedOffset;

    if(this->offset & 0x8000) {     // sign bit
        fixedOffset = ((~this->offset) + 1) & 0xFFFF;
        cout << "-";
    } else {
        fixedOffset = this->offset;
    }

    cout << dec << fixedOffset << "(";
    cout << "$" << dec << this->left << ")" << endl;
}

int Iformat::disassemble() {
    uint32_t opcode = this->instruction >> 26;

    if(opcodes[opcode].empty()) {
        cout << "undefined I-format instruction: opcode 0x" << hex << uppercase << setw(2) << opcode << endl;
        return 0;
    } else {
        cout << opcodes[opcode];
        
        // this is slightly different between branching and loads/stores
        // so we can separate them here
        if(opcode == OPCODE_BEQ || opcode == OPCODE_BNE) {
            this->printBranch();
        } else {
            this->printRegistersOffset();
        }

        return 0;
    }
}