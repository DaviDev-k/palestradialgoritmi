/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <math.h>

// input data
int N, L, U;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(3 == scanf("%d %d %d", &N, &L, &U));

    int upper = floor(N * 1.0 / L);
    int lower = ceil(N * 1.0 / U);

    if (lower <= upper) {
        printf("%d\n", lower);
    } else {
        puts("-1");
    }

    return 0;
}
