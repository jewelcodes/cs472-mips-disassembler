/*
 * MET CS 472 - Computer Architecture
 * Project 1: MIPS Disassembler
 * Omar Elghoul
 */

#include <iostream>
#include <fstream>
#include <disasm.h>

using namespace std;

int main(int argc, char **argv) {
    if(argc != 2) {
        cout << "usage: " << argv[0] << " input_file.bin" << endl;
        return -1;
    }

    // load the file specified in the arguments and then output the disassembly
    // to stdout -- this makes it easy to pipe
    ifstream file(argv[1], ios::in | ios::binary | ios::ate);
    size_t size = file.tellg();     // file size
    file.clear();
    file.seekg(0);

    vector<char> buffer(size);
    file.read(buffer.data(), size);

    return 0;
}
