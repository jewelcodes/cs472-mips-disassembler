/*
 * MET CS 472 - Computer Architecture
 * Project 1: MIPS Disassembler
 * Omar Elghoul
 */

/* Small helper program that writes the hex instructions given in the assignment into
 * a file named sample.bin so that is can be used as input for the disassembler
 *
 * This wasn't required by the assignment but I figured it'd be better than hardcoding
 * the instructions into the disassembler itself or manually inputting them
 */

#include <iostream>
#include <fstream>
#include <cstdint>

using namespace std;

/* this array is directly copied from the assignment */
uint32_t instructions[] = { 0x032BA020, 0x8CE90014, 0x12A90003, 0x022DA822, 0xADB30020,
    0x02697824,0xAE8FFFF4, 0x018C6020, 0x02A4A825, 0x158FFFF7, 0x8ECDFFF0 };

int main(int argc, char **argv) {
    fstream file;
    file.open("sample.bin", ios::out | ios::binary);
    
    for(int i = 0; i < 11; i++) {
        file.write((const char *)&instructions[i], sizeof(uint32_t));
    }

    file.flush();
    file.close();
    return 0;
}
