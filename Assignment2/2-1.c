#include <stdio.h>
#define UI unsigned int

UI mask(int n) {
	int shiftAmnt = 32 - n; //amount to he shifted to right
	UI Mask = 0xFFFFFFFF; //mask of all ones
	UI result = Mask >> shiftAmnt;
	return result;
}


int main() {
	printf("mask(%d): 0x%01X\n", 1, mask(1));
	printf("mask(%d): 0x%01X\n", 2, mask(2));
	printf("mask(%d): 0x%01X\n", 3, mask(3));
	printf("mask(%d): 0x%01X\n", 5, mask(5));
	printf("mask(%d): 0x%01X\n", 8, mask(8));
	printf("mask(%d): 0x%01X\n", 16, mask(16));
	printf("mask(%d): 0x%01X\n", 31, mask(31));
}	
