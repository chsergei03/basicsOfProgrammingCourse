#include "combSort.h"

#define DECREASE_FACTOR 1.24733

void combSort(int *const a, const size_t n) {
    size_t t = n - 1;
    while (t > 0) {
        for (size_t i = 0, j = t; j < n; i++, j++)
            if (a[i] > a[j])
                void_swap(&a[i], &a[j], sizeof(int));
        t /= DECREASE_FACTOR;
    }
}