#include <stdio.h>

long fact(long x) {
    if (x <= 1) {
        return 1;
}
    return x * fact(x - 1);
}


int main() {
    printf("fact(1): %i\n", fact(1));
    printf("fact(3): %i\n", fact(3));
    printf("fact(5): %i\n", fact(5));
}

// All x86-64 instructions that modify stack
//
// subq    $8, %rsp (makes space on stack)(Called once)
// pushq   %rbx (stores value on stack)(Called 3 times)
// popq    %rbx (returns value from stack)(Called 3 times)
// addq    $8, %rsp (returns space used for stack)(Called once)
//
// Stack Size at beggining of main before fact called: 8 bytes
// Highest Stack Frame Size: 8 bytes
// (8 bytes returned at the end of each function return)