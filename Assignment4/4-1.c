// long sum(long from, long to) {
//     long result = 0;
//         loop:
//             result += from;
//             ++from;
//         if (from <= to) goto loop;
//     return result;
// }

#include <stdio.h>

long sum(long from, long to) {
    // Declare and initialize result var – *do not modify*.
    long result = 0;
    // Ensure that argument *from* is in %rdi,
    // argument *to* is in %rsi, *result* is in %rax - *do not  
    // modify*.
    __asm__ ("movq %0, %%rdi # from in rdi;" :: "r" ( from ));
    __asm__ ("movq %0, %%rsi # to in rsi;" :: "r" ( to ));
    __asm__ ("movq %0, %%rax # result in rax;" :: "r" ( result ));
    // Your x86-64 code goes below - comment each instruction...
    __asm__(
        // TODO - Replace the instruction below with add, compare,
        // jump instructions, labels, etc as necessary to implement
        // the loop.
        // "movq %rdi, %rax;" // # For example, this sets result=from
        "movq $0, %rax;" // rax = 0
        ".L2:" // loop:
            "addq %rdi, %rax;" // rax = rax + rdi
            "addq $1, %rdi;" // rdi = rdi + 1
            "cmpq %rsi, %rdi;" // CF = rsi - rdi
            "jle .L2;" 
        // "ret;" // return result;
    );
    // Ensure that *result* is in %rax for return - *do not modify*.
    __asm__ ("movq %%rax, %0 #result in rax;" : "=r" ( result ));
    return result;
}

int main() {
    printf("sum(1, 6): %ld\n", sum(1, 6));
    printf("sum(3, 5): %ld\n", sum(3, 5));
    printf("sum(5, 3): %ld\n", sum(5, 3));
}