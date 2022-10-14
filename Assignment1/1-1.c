#include <stdio.h>
#define UI unsigned int

unsigned int combine(UI x, UI y) {
	UI mask1 = 0xFFFFFF00; //bytes 0-2 mask
	UI mask2 = 0x000000FF; //byte 3 mask
	UI byte1 = x & mask1; //pull bytes 0-2 from x
	UI byte2 = y & mask2; //pull byte 3 from y
	UI result = byte1 | byte2; //combine bytes 0-2 from x with byte 3 from y
	return result;
}


int main() {
	printf("combine(0x%08X, 0x%08X): 0x%08X.\n", 0x12345678, 0xABCDEF00, combine(0x12345678, 0xABCDEF00));	
	printf("combine(0x%08X, 0x%08X): 0x%08X.\n", 0xABCDEF00, 0x12345678, combine(0xABCDEF00, 0x12345678));
}	
