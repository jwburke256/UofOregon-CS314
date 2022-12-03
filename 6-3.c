#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float f(float *a, int n) {
    float prod = 1.0f;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0.0f) {
            prod *= a[i];
        }
    }
    return prod;
}

float g(float *a, int n) {
    float prod = 1.0f;
    for (int i = 0; i < n; ++i) {
            prod *= a[i];
    }
    return prod;
}

float* createArray(int size) {
    float *a = (float *)malloc(size * sizeof(float));
    for (int i = 0; i < size; ++i) {
        // 50% chance that a[i] is 0.0f, random value on the range
        // [0.76, 1.26] otherwise.
        float r = rand()/(float)RAND_MAX;
        a[i] = r < 0.5f ? 0.0f : r + 0.26f;
    }
    return a;
}

int main() {

    int arrayLength = 10000;
    int nonZeroLen = 0;
    float *a = createArray(arrayLength);
    float *b = createArray(arrayLength);
    float result = 0.0f;
    float result2 = 0.0f;
    float result3 = 0.0f;

    // adjust b to not have any 0.0f
    for (int i = 0; i < arrayLength; ++i) {
        if (b[i] == 0.0f){
            b[i] = 1.0f;
        }
    }

    //calculate size needed for c
    for (int i = 0; i < arrayLength; ++i) {
        if (a[i] == 0.0f){
            nonZeroLen++;
        }
    }
    printf("nonZeroLen: %d\n", nonZeroLen);

    //create array c
    float *c = createArray(nonZeroLen);

    //fill c with nonzero elements of a
    for (int i, j = 0; i < nonZeroLen-1; i++) {
        //printf("c[%d]: %f\n", i, c[i]);
        while (a[j] == 0.0f) {
            j++;
        }
        c[i] = a[j];
        //printf("c[%d]: %f\n", i, c[i]);
        j++;
    }
    //printf("c[0]: %f\n", c[50]);

    // f(a) Clock calculation:

    clock_t start = clock();

    // Do this 100,000 times to exaggerate the time taken.
    for (size_t i = 0; i < 1000; ++i) {
        result = f(&a[0], 10000);
    }
    printf("Product1: %f\n", result);


    clock_t end = clock();
    double totalTime1 = ((double) (end - start)) / CLOCKS_PER_SEC;

    // g(b) Clock calculation:
    
    start = clock();

    // Do this 100,000 times to exaggerate the time taken.
    for (size_t i = 0; i < 1000; ++i) {
        result2 = g(&b[0], 10000);
    }
    printf("Product2: %f\n", result2);

    end = clock();
    double totalTime2 = ((double) (end - start)) / CLOCKS_PER_SEC;

    // g(b) clock is faster than f(a) due to extrapolating out the work
    // for checking if there's a zero in the array. This causes
    // the function to not have an inner conditional check on every
    // loop which improves time.


    // g(c) Clock calculation:
    
    start = clock();

    // Do this 100,000 times to exaggerate the time taken.
    for (size_t i = 0; i < 1000; ++i) {
        result3 = g(&c[0], nonZeroLen);
    }
    printf("Product3: %f\n", result3);

    end = clock();
    double totalTime3 = ((double) (end - start)) / CLOCKS_PER_SEC;

    // g(c) clock is faster than both f(a) and g(c). It's similar
    // to how g(b) was faster due to not having to check for zero's
    // in each iteration of the loop. But it also has less elements
    // as there was no swaps to 0.0f to 1.0f, so there's less elements
    // to loop through to produce the product


    printf("f1: %f\n", totalTime1);
    printf("f2: %f\n", totalTime2);
    printf("f3: %f\n", totalTime3);



    free(a);
    free(b);
    free(c);
}