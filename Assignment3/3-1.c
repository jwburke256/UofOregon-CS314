#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define UI unsigned int

struct IntArray{
	int length;
	int *dataPtr;
};

struct IntArray* mallocIntArray(int length) {
	// allocates memory for struct
	struct IntArray *arrayPtr = (struct IntArray *)malloc(sizeof(struct IntArray));
	// allocates memory for array and sets the ptr as struct member
	arrayPtr->dataPtr= (int *)malloc(length * sizeof(int));
	arrayPtr->length= length;
	return arrayPtr;
}

void freeIntArray(struct IntArray *arrayPtr) {
	int i;
	// free memory of array
	//for(i=0; i < (arrayPtr->length); i++) {
		//free((arrayPtr->dataPtr)+i);	
	//}
	free(arrayPtr->dataPtr);
	// free memory of struct
	free(arrayPtr);
}

void readIntArray(struct IntArray *array) {
	//printf("readIntArray\n");
	//printf("%d\n", (array->length));
	int n;
	int i;
	for (i = 0; i < (array->length); i++) {
		char lineBuf[BUFSIZ];
		char *p = NULL;
		printf("Enter an integer: ");
		fgets(lineBuf, sizeof(lineBuf), stdin);
		n = strtol(lineBuf, &p, 10);
		//printf("%d\n", n);
		if (n <= 0) {
			printf("Invalid Input\n");
			i--;
			continue;
		}
		(array->dataPtr)[i] = n;		
	}	
}

void swap(int *xp, int *yp) {
	int newx;
	int newy;
	newx = *yp;
	newy = *xp;
	*xp = newx;
	*yp = newy;
}

void sortIntArray(struct IntArray *array) {
	//sortIntArray PsuedoCode adapted from 
	//https://www.youtube.com/watch?v=6Gv8vg0kcHc
	bool isSorted = false;
	int i;
	int lastUnsorted = (array->length) - 1;
	while(!isSorted) {
		// defaults to true
		isSorted = true;
		// each loop goes through each element once only
		for(i = 0; i < lastUnsorted; i++) {
			if(*((array->dataPtr)+i) > *((array->dataPtr)+i+1)){
				swap(((array->dataPtr)+i), ((array->dataPtr)+i+1));
				//continues loop since resort occurs
				isSorted = false;
		}
		}
		lastUnsorted--;
	}
}

void printIntArray(struct IntArray *array) {
	int i;
	printf("[");
	// loop through array to print each int
	for(i = 0; i < (array->length); i++) {
		if (i < (array->length) - 1){
			printf("%d, ", *((array->dataPtr)+i));
			continue;
		}
		// print last entry in array
		printf("%d", *((array->dataPtr)+i));
	}
	printf("]\n");
}

int main() {
	char lineBuf[10];
	char *p = NULL;
	int length;
	//bool lengthLoop = true;
	while(1) {
		printf("Enter Length of Array: ");
		fgets(lineBuf, sizeof(lineBuf), stdin);
		length = strtol(lineBuf, &p, 10);
		if(length>0){
			break;
		}
		else {
			printf("Invalid Input\n");
		}
	}
	struct IntArray* arrayPtr = mallocIntArray(length);
	readIntArray(arrayPtr);
	//printIntArray(arrayPtr);
	sortIntArray(arrayPtr);
	printIntArray(arrayPtr);
	freeIntArray(arrayPtr);
}
