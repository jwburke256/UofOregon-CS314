#include <stdio.h>

int le(float x, float y) {
	unsigned int ux = *((unsigned int*) &x); // convert x raw bits
	unsigned int uy = *((unsigned int*) &y); // convert y raw bits
	unsigned int sx = ux >> 31; // extract sign bit of ux
	unsigned int sy = uy >> 31; // extract sign bit of uy
	ux <<= 1; // drop sign bit of ux
	uy <<= 1; // drop sign bit of uy
	// TODO: return using sx, sy, ux, uy
	int result = (ux == 0 && uy == 0) || (sx == 1 && sy == 0) || (sx == 1 && sy == 1 && ux >= uy) || 
		(sx ==0 && sy ==0 && ux <= uy);
	return result;
}
int main() {
	printf("le(%f, %f): %d\n", 0.0f, 0.0f, le(0.0f, 0.0f));
	printf("le(%f, %f): %d\n", -0.0f, 0.0f, le(-0.0f, 0.0f));
	printf("le(%f, %f): %d\n", -1.0f, -1.0f, le(-1.0f, -1.0f));
	printf("le(%f, %f): %d\n", 1.0f, 1.0f, le(1.0f, 1.0f));
	printf("le(%f, %f): %d\n", -1.0f, 0.0f, le(-1.0f, 0.0f));
	printf("le(%f, %f): %d\n", 0.0f, 1.0f, le(0.0f, 1.0f));
	printf("le(%f, %f): %d\n", 1.0f, 0.0f, le(1.0f, 0.0f));
	printf("le(%f, %f): %d\n", 0.0f, -1.0f, le(0.0f, -1.0f));
	printf("le(%f, %f): %d\n", -1.0f, -2.0f, le(-1.0f, -2.0f));
}
