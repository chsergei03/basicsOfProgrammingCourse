#include "insertion_sort.h"

void insertionSort(int *const a, const size_t n) {
    for (size_t i = 1; i < n; i++) {
        int t = a[i];
        size_t j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}