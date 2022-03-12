#include "selection_sort.h"

void selectionSort(int *a, size_t n) {
    for (size_t i = 0; i < n; i++)
        void_swap(&a[i], &a[getMinPos_int_(a, n, i)], sizeof(int));
}