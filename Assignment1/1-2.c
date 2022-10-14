#include <stdio.h>
#define UI unsigned int

unsigned int replace(UI x, int n, UI y) {
	UI cleared = 0xFF; //mask to clear byte in x
	cleared = ~(cleared << (n << 3)); //shifting clear byte into position
	UI mask = 0x00000000 | y; //byte to insert
	mask = mask << (n << 3); //shifting insert byte into position
	UI result = x & cleared; //clears byte n to prep for byte x insertion
	result = result | mask; //applies byte x to cleared byte from y
	return result;
}


int main() {
	printf("replace(0x%08X, %d, 0x%02X): 0x%08X.\n", 0x12345678, 3, 0xAB, replace(0x12345678, 3, 0xAB));	
	printf("replace(0x%08X, %d, 0x%02X): 0x%08X.\n", 0x12345678, 0, 0xAB, replace(0x12345678, 0, 0xAB));	
}	
