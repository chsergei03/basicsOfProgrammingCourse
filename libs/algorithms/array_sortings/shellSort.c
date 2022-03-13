#include "shellSort.h"

void shellSort(int *const a, const size_t n) {
    size_t d = n / 2;
    while (d > 0) {
        for (size_t i = d; i < n; i += d) {
            int t = a[i];
            size_t j = i;
            while (j > 0 && a[j - d] > t) {
                a[j] = a[j - d];
                j -= d;
            }
            a[j] = t;
        }
        d /= 2;
    }
}