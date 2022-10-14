#include <stdio.h>
#define UI unsigned int
#define SI signed int

UI extract(UI x, int i) {
	SI mask = 0x000000FF; //mask for byte place
	mask = mask << (i << 3);
	SI extract = x & mask; //extract byte
	char byte = extract >> (i << 3); //move byte to 0th byte place
	UI result = (UI) byte; //recast to sign extend
	return result;
}


int main() {
	printf("extract(0x%08X, %d): 0x%08X\n", 0x12345678, 0, extract(0x12345678, 0));
	printf("extract(0x%08X, %d): 0x%08X\n", 0xABCDEF00, 2, extract(0xABCDEF00, 2));
}	
