#include <stdio.h>
#include <math.h>

// COMPILE WITH -lm !!!
void printTSO(int blockSizeInBytes, int numSets, int archSizeInBits) {
        int setBits = 0;
        if (numSets > 1) {
            setBits = log2(numSets);
        }
        int offsetBits = log2(blockSizeInBytes);
        int tagBits = archSizeInBits - setBits - offsetBits;
        printf("%dB blocks, %d sets, %d-bit architecture: %d tag bits, %d set bits, %d offset bits.\n",
                        blockSizeInBytes, numSets, archSizeInBits, tagBits, setBits, offsetBits);
}

// address: 0x12345678
// points to *one* byte in memory


// for an X-bit architecture
// how many possible pointers are there?
// normal arch is 32 or 64 bits
// Answer: x^2

// "X-Bit arch" means: 0x<X bits>

// for an X-bit arch, we can point to 2^x different bytes
// ex 32: we have 0x00000000
// ex 64: doubles 32 so 0x0000000000000000

// cache: fast paert of memory close to CPU, different circuits than RAM

//  more effiecitent to read more than we need from RAM and keep it around in case we need
// 'spatially close' values soon

// cache block size is the amount taken from RAM and kept 'next' to the CPU

// cache blocks implicitly divides RAM into blocks

// ex: if we had a block size of 8 and we access the 6th address (byte) from RAM,
//     our cache now contains byte 0-7 from RAM

// RAM is 'aligned' by block size

// we need a way to quickly tell which bytes we have in our cache - use the address!

// 256 block, 1 set, 32-bit architecture
// example: 24 bit tag, 8 bit offset
// adress: 0x12345678
// read into cache: 0x12345600 through 0x123456FF (roughly)
// access bytes in cahce 00 through FF

// format is always <tag><set><offset>

// LAB 8: 256B block, 1 set, 32 bit arch
unsigned int getOffset(unsigned int address) {
        unsigned int mask = 0x000000FF;
        unsigned int offset = mask & address;
        return offset;
}

unsigned int getTag(unsigned int address) {
        unsigned int mask = 0xFFFFFF00;
        unsigned int tag = mask & address;
        tag >>= 8;
        return tag;
}

void main() {
        printTSO(256, 1, 32);
        unsigned int testAddr1 = 0x12345678;
        unsigned int testAddr2 = 0x87654321;
        // uncomment after implementing
        printf("0x%08x: offset - %x, tag - %x.\n", testAddr1, getOffset(testAddr1), getTag(testAddr1));
        printf("0x%08x: offset - %x, tag - %x.\n", testAddr2, getOffset(testAddr2), getTag(testAddr2));
}