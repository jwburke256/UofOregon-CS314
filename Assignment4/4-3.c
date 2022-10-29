#include <stdio.h>

#define N 4
typedef long array_t[N][N];
void transpose(array_t a) {
    for (long i = 0; i < N; ++i) {
        for (long j = 0; j < i; ++j) {
            long t1 = a[i][j];
            long t2 = a[j][i];
            a[i][j] = t2;
            a[j][i] = t1;
        }
    }
}

void transposeOpt(array_t a) {
    for (long i = 0; i < N; ++i) {
        long int *rp = &a[i][0];
        long int *cp = &a[0][i];
        for (long j = 0; j < i; ++j) {
            long t1 = *cp;
            long t2 = *rp;
            *cp = t2;
            *rp = t1;
            rp += 1;
            cp += N;
        }

    }
}

void printArray(array_t a) {
    for (long i = 0; i < N; ++i) {
        printf("[");
        for (long j = 0; j < N-1; ++j) {
            long t1 = a[i][j];
            printf("%d,", t1);
        }
        printf("%d", a[i][N-1]);
    printf("]\n");
    }
    
}

int main() {
    array_t a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15,
16}};
    printArray(a);
    printf("\n");
    transpose(a);
    printArray(a);
    printf("\n");
    array_t b = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15,
16}};
    transposeOpt(b);
    printArray(b);
}


//movq    (%rax), %rcx Move a[i][j] into t1
//movq    (%rdx), %rsi Move a[j][i] into t2
//movq    %rsi, (%rax) Move t2 into a[i][j]
//movq    %rcx, (%rdx) Move t1 into a[j][i]
//addq    $8, %rax increment i
//addq    $32, %rdx increment j (for row)
//cmpq    %r9, %rax j < i
//jne     .L3 if above true, return to top of for loop

//%r8 = i starting index
//%rax = i increment index
//leaq    (%rdi,%r8,8), %rdx = j + 8*i
//have to add 4 in order to go to next row