#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inner(float *u, float *v, int length, float *dest) {
    int i;
    float sum = 0.0f;
    for (i = 0; i < length; ++i) {
        sum += u[i] * v[i];
    }
    *dest = sum;
    // printf("%f\n", *dest);
}


void inner2(float *u, float *v, int length, float *dest) {
    int i;
    float sum1 = 0.0f;
    float sum2 = 0.0f;
    float sum3 = 0.0f;
    float sum4 = 0.0f;
    int limit = length-1;
    // Calculat the products of 4 elements in each Arr
    for (i = 0; i < limit; i+=4) {
        sum1 += u[i] * v[i];
        sum2 += u[i+1] * v[i+1];
        sum3 += u[i+2] * v[i+2];
        sum4 += u[i+3] * v[i+3];
    }
    //finish remaining operations for missing elements
    for (; i < length; i++) {
        sum1 += u[i] * v[i];
    }
    sum1 = sum1 + sum2 + sum3 + sum4;
    *dest = sum1;
    // printf("%f\n", *dest);
}

int main() {
    float location;
    float location2;
    size_t size = 100;
    float M[size];
    for (size_t i = 0; i < size; ++i) {
                M[i] = rand()/(float)RAND_MAX < 0.5 ? 0 : 1;
            }
    float N[size];
    for (size_t i = 0; i < size; ++i) {
                N[i] = rand()/(float)RAND_MAX < 0.5 ? 0 : 1;
            }
    

    inner(&M[0], &N[0], size, &location);
    printf("%f\n", location);
    inner2(&M[0], &N[0], size, &location2);
    printf("%f\n", location2);

        // inner1:

        clock_t start = clock();

        // Do this 100,000 times to exaggerate the time taken.
        for (size_t i = 0; i < 100000; ++i) {
                inner(&M[0], &N[0], size, &location);
        }

        clock_t end = clock();
        double totalTime1 = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        // inner2:
        
        start = clock();

        // Do this 100,000 times to exaggerate the time taken.
        for (size_t i = 0; i < 100000; ++i) {
                inner2(&M[0], &N[0], size, &location2);
        }

        end = clock();
        double totalTime2 = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        // inner3:
        
        start = clock();

        // Do this 100,000 times to exaggerate the time taken.
        for (size_t i = 0; i < 100000; ++i) {
                inner(&M[0], &N[0], size, &location);
        }

        end = clock();
        double totalTime3 = ((double) (end - start)) / CLOCKS_PER_SEC;

        // inner4:
        
        start = clock();

        // Do this 100,000 times to exaggerate the time taken.
        for (size_t i = 0; i < 100000; ++i) {
                inner2(&M[0], &N[0], size, &location2);
        }

        end = clock();
        double totalTime4 = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        printf("\n");
        printf("inner1: %f\n", totalTime1);
        printf("inner2: %f\n", totalTime2);
        printf("inner3: %f\n", totalTime3);
        printf("inner4: %f\n", totalTime4);
}