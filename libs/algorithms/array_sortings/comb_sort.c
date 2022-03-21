#include "comb_sort.h"

#define DECREASE_FACTOR 1.24733

void combSort(int *const a, const size_t n) {
    size_t t = n;
    bool isSwapped = true;
    while (t > 1 || isSwapped) {
        if (t > 1)
            t /= DECREASE_FACTOR;
        isSwapped = false;
        for (size_t i = 0, j = t; j < n; i++, j++)
            if (a[i] > a[j]) {
                void_swap(&a[i], &a[j], sizeof(int));
                isSwapped = true;
            }
    }
}