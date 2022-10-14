#include <stdio.h>
#include <stdlib.h>


// int f(int a, int b, int c, int d, int n) {
//     int result = 0;
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             result += a * b + i * c * d + j;
//         }
//     }
//     return result;
// }


int f(int a, int b, int c, int d, int n) {
    int result = 0;
    //int multVal = a *b * c * d;
    int ab = a * b;
    int cd = c * d;
    int icdj = 0;
    int cd_count = 0;
    int ab_count = 0;
    for (int i = 0; i < n; ++i) {
        //abi += ab + i;
        for (int j = 0; j < n; ++j) {
            ab_count += ab;
            icdj += cd_count + j;
            //ab += ab;

            //result += a * b + i * c * d + j;
            //PEMDAS
        }
        cd_count += cd;
    }
    result = ab_count + icdj;
    return result;
}

int main() {
    printf("f(%d, %d, %d, %d, %d): %d\n", 1, 2, 3, 4, 5, f(1, 2, 3, 4, 5));
    printf("f(%d, %d, %d, %d, %d): %d\n", 2, 3, 4, 5, 6, f(2, 3, 4, 5, 6));
    printf("f(%d, %d, %d, %d, %d): %d\n", 6, 5, 4, 3, 2, f(6, 5, 4, 3, 2));
    printf("f(%d, %d, %d, %d, %d): %d\n", 5, 4, 3, 2, 1, f(5, 4, 3, 2, 1));
}