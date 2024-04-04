# MIPS Disassembler Project for MET CS 472
Self-explanatory title. This is the first project for MET CS 472 (Computer Architecture) taken in spring 2024. The instructions implemented are exactly those specified in the assignment: add, sub, and, or, slt, lw, sw, beq, bne, lb, sb, and nop. Notably, I noticed the slt instruction is not present in the given sample binary.

The lb, sb, and nop instructions were added later in the semester (after submission) while working on the third project (MIPS pipeline emulator) to cross-reference what was happening and verify that my output looks like what I expect it to.

## Input
The helper program in helper/ basically just writes the array given in the assignment into a file called sample.bin, so that the main disassembler in src/ can read its input from a file. This was not required but the assignment did mention some of this code would need to be reused for another project, so I figured this would be a better approach than to hardcode the instructions into the disassembler itself. The instructions are:
```c
{ 0x032BA020, 0x8CE90014, 0x12A90003, 0x022DA822, 0xADB30020, 0x02697824,
  0xAE8FFFF4, 0x018C6020, 0x02A4A825, 0x158FFFF7, 0x8ECDFFF0 }
```
## Output
```asm
  9A040   add $20, $25, $11
  9A044   lw $9, 20($7)
  9A048   beq $21, $9, 0x0009A058
  9A04C   sub $21, $17, $13
  9A050   sw $19, 32($13)
  9A054   and $15, $19, $9
  9A058   sw $15, -12($20)
  9A05C   add $12, $12, $12
  9A060   or $21, $21, $4
  9A064   bne $12, $15, 0x0009A044
  9A068   lw $13, -16($22)
```
Plaintext output is also in output.asm.

## References
The reference I used for the MIPS instruction encoding is in docs/ and the original can be found [here](https://uweb.engr.arizona.edu/~ece369/Resources/spim/MIPSReference.pdf). 
