/*
 * MET CS 472 - Computer Architecture
 * Project 1: MIPS Disassembler
 * Omar Elghoul
 */

#include <iostream>
#include <cstdint>

using namespace std;

int main(int argc, char **argv) {
    if(argc != 2) {
        cout << "usage: " << argv[0] << " input_file.bin" << endl;
        return -1;
    }

    // load the file specified in the arguments and then output the disassembly
    // to stdout -- this makes it easy to pipe
    
    // TODO
    return 0;
}
