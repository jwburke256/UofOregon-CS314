#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ColorPoint {
    long a;
    long r;
    long g;
    long b;
};

long f(struct ColorPoint **points, int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += points[j][i].a;
            sum += points[j][i].r;
            sum += points[j][i].g;
            sum += points[j][i].b;
        }
    }
    return sum;
}

long g(struct ColorPoint **points, int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += points[i][j].a;
            sum += points[i][j].r;
            sum += points[i][j].g;
            sum += points[i][j].b;
        }
    }
    return sum;
}

struct ColorPoint** create2DArray(int n) {
    // Array to hold a pointer to the beginning of each row
    struct ColorPoint **points =
        (struct ColorPoint **)malloc(n * sizeof(struct ColorPoint *));
    for (int i = 0; i < n; ++i) {
        // Array to hold each row
        points[i] =
            (struct ColorPoint *)malloc(n * sizeof(struct ColorPoint));
        for (int j = 0; j < n; ++j) {
            // Init the ColorPoint struct
            points[i][j].a = rand();
            points[i][j].r = rand();
            points[i][j].g = rand();
            points[i][j].b = rand();
        }
    }
    return points;
}

void free2DArray(struct ColorPoint** points, int n) {
    for (int i = 0; i < n; ++i) {
        free(points[i]);
    }
    free(points);
}


void main() {
    // create color point array
        struct ColorPoint **colorArr = create2DArray(2048);

        // time f:

        clock_t start = clock();

        // Do this 100,000,000 times to exaggerate the time taken.
        for (size_t i = 0; i < 100000000; ++i) {
                f(colorArr, 2048);
        }

        clock_t end = clock();
        double totalTime1 = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        // time g:
        
        start = clock();

        // Do this 100,000,000 times to exaggerate the time taken.
        for (size_t i = 0; i < 100000000; ++i) {
                g(colorArr, 2048);
        }

        end = clock();
        double totalTime2 = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        printf("f: %f\n", totalTime1);
        printf("g: %f\n", totalTime2);

        free(colorArr);
}