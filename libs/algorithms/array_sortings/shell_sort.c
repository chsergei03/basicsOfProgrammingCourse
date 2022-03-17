#include "shell_sort.h"

void shellSort(int *const a, const size_t n) {
    size_t d = n / 2;
    while (d > 0) {
        for (size_t i = d; i < n; i += 1) {
            int t = a[i];
            size_t j = i;
            while (j >= d && a[j - d] > t) {
                a[j] = a[j - d];
                j -= d;
            }
            a[j] = t;
        }
        d /= 2;
    }
}