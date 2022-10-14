#include <stdio.h>

void printBytes(unsigned char *start, int len) {
	for (int i = 0; i < len; ++i) {
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void printInt(int x) {
	printBytes((unsigned char *) &x, sizeof(int));
}
void printFloat(float x) {
	printBytes((unsigned char *) &x, sizeof(float));
}
void printShort(short x) {
	printBytes((unsigned char *) &x, sizeof(short));
}
void printLong(long x) {
	printBytes((unsigned char *) &x, sizeof(long));
}
void printLongLong(long long x) {
	printBytes((unsigned char *) &x, sizeof(long long));
}
void printDouble(double x) {
	printBytes((unsigned char *) &x, sizeof(double));
}

int main() {
	printInt(4);;/*4 bytes on 64 bit Arch Linux, most significant
		       byte starts on the left (Little Endian)*/

	printFloat(3.14);/*4 bytes on 64 bit Arch Linux,generally bytes 3-2 for
			   the fraction, with bytes 0-1 for int, Depends on input value*/

	printShort(4);/*2 bytes on 64 bit Arch Linux, bits start in byte
			 and spill into byte 2*/

	printLong(9876543210);/*8 bytes on 64 bit Arch Linux, with bits starting in;
				 byte 7 and spilling over to other bytes in descending order*/

	printLongLong(9876543210);/*Appears to function the same as Long, but has higher
				    storage amount than Long usually by 2 times.*/

	printDouble(3.14);;/*8 bytes on 64 bit Arch Linux, 0th byte holds int value, with
			     bytes 1-7 holding fraction amount but with "Double" the precision
			     of a float.*/
}
