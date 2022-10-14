#include <stdio.h>
#define UI unsigned int

int oddBit(UI x) {
	UI oddMask = 0xAAAAAAAA; //mask to isolate odd bits
	UI oddNum = x & oddMask; //isolating odd bits
	int result = !!oddNum; //returns 0 if oddNum only zeroes, 1 if otherwise
	return result;
}


int main() {
	printf("oddBit(0x%01X): %d\n", 0x1, oddBit(0x1));
	printf("oddBit(0x%01X): %d\n", 0x2, oddBit(0x2));
	printf("oddBit(0x%01X): %d\n", 0x3, oddBit(0x3));
	printf("oddBit(0x%01X): %d\n", 0x4, oddBit(0x4));
	printf("oddBit(0x%01X): %d\n", 0xFFFFFFFF, oddBit(0xFFFFFFFF));
	printf("oddBit(0x%01X): %d\n", 0xAAAAAAAA, oddBit(0xAAAAAAAA));
	printf("oddBit(0x%01X): %d\n", 0x55555555, oddBit(0x55555555));
}	
