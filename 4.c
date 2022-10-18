#include <stdio.h>
#include <stdlib.h>

int readInt() {
    // can use this for assignment 3 problem 1
        char lineBuf[10];
        char *p = NULL;
        int n;

        while (1) {
                // char* fgets (char* str, int num, FILE* stream);
                // reads stdin into lineBuf
                fgets(lineBuf, sizeof(lineBuf), stdin);

                // long int strtol (const char* str, char** endptr, int base);
                n = strtol(lineBuf, &p, 10);
                if (lineBuf != p) {
                        break;
                }

                printf("Invalid input\n");
        }

        return n;
}

int main() {
        // TODO:

        // call stack is a stack of code to keep track of instructions and variables
        // created when we run a program and destroyde on program completion

        // heap is a list  of addresses that store information:  0x00000001, 0x00000002, ... up to "RAM" size

        // create int array of fixed length

        // this length will be from stdin in assignment 3
        int length = 3;
        // cast malloc size
        int *arr = (int *)malloc(length * sizeof(int));
        // could've just done int arr[length]; but would have been put on call stack, so it is not dynamic

        // loop over array and fill with readInt
        int i;
        for (i = 0; i < length; i++) {
            arr[i] = readInt();
        }

        // loop over again and print
        printf("[");
        for (i = 0; i < length; i++) {
            if (i< length - 1) {
                printf("%d, ", arr[i]);
                continue;
            }
            printf("%d", arr[i]);
        }
        printf("]\n");

        // free malloc'd array pointer
        free(arr);
}