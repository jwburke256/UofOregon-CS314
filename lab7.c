#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Sum rows is of n X n matrix a
   and store in vector b  */
void sum_rows1(double *a, double *b, long n) {
        for (long i = 0; i < n; i++) {
                b[i] = 0;
                for (long j = 0; j < n; j++) {
                        b[i] += a[i*n + j]; // instead of doing a[i][j]
                }
        }
}

// TODO: optimize lookup to b[i]

void sum_rows2(double *a, double *b, long n) {
        for (long i = 0; i < n; i++) {
                double val = 0;
                for (long j = 0; j < n; j++) {
                        val += a[i*n + j]; // instead of doing a[i][j]
                }
        b[i] = val; // b[i] is now only called once for each for loop
        }
}

// TODO: optimize by precomputing row index

void sum_rows3(double *a, double *b, long n) {
        for (long i = 0; i < n; i++) {
                double val = 0;
                int ixn = i*n;
                for (long j = 0; j < n; j++) {
                        val += a[ixn + j]; // instead of doing a[i][j]
                }
        b[i] = val;
        }
}

int main() {
        size_t size = 100;
        double M[size][size];
        double resVect[size];
        for (size_t i = 0; i < size; ++i) {
                for (size_t j = 0; j < size; ++j) {
                        M[i][j] = rand()/(double)RAND_MAX < 0.5 ? 0 : 1;
                }
        }

        // SUM_ROWS1:

        clock_t start = clock();

        // Do this 100,000 times to exaggerate the time taken.
        for (size_t i = 0; i < 100000; ++i) {
                sum_rows1(&M[0][0], resVect, size);
        }

        clock_t end = clock();
        double totalTime1 = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        // SUM_ROWS2:
        
        start = clock();

        // Do this 100,000 times to exaggerate the time taken.
        for (size_t i = 0; i < 100000; ++i) {
                sum_rows2(&M[0][0], resVect, size);
        }

        end = clock();
        double totalTime2 = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        // SUM_ROWS3:
        
        start = clock();

        // Do this 100,000 times to exaggerate the time taken.
        for (size_t i = 0; i < 100000; ++i) {
                sum_rows3(&M[0][0], resVect, size);
        }

        end = clock();
        double totalTime3 = ((double) (end - start)) / CLOCKS_PER_SEC;
        

        printf("sum_rows1: %f\n", totalTime1);
        printf("sum_rows2: %f\n", totalTime2);
        printf("sum_rows3: %f\n", totalTime3);
}