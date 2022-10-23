#include <stdio.h>

long f(long x, long y, long z) {
    long result;
    z = y + z; // addq %rsi, %rdx
    x = x * z; // imulq %rdx, %rdi
    z = z<<63; // salq $63, %rdx
    z = z>>63; // sarq $63, %rdx
    result = x; // movq %rdi, %rax
    result ^= z; // xorq %rdx, %rax
    return result;
}

//long x = 1; // %rdi
//long y = 2; // %rsi
//long z = 0; // %rdx

int main() {
    printf("f(1, 2, 4): %i\n", f(1, 2, 4));
    printf("f(3, 5, 7): %i\n", f(3, 5, 7));
    printf("f(10, 20, 30): %i\n", f(10, 20, 30));
}