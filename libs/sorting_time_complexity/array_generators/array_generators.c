#include <stdlib.h>
#include <time.h>

#include "array_generators.h"

void generateRandomArray(int *a, const size_t n) {
    srand(time(0));
    for (size_t i = 0; i < n; i++) {
        a[i] = rand();
    }
}

void generateOrderedArray(int *a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        a[i] = i;
}

void generateOrderedBackwardsArray(int *a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        a[i] = n - i - 1;
}