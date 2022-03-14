#include <malloc.h>

#include "countSort.h"

size_t getValueAppearsCountArraySize(const int *const a,
                                     const size_t n,
                                     int *minValue,
                                     int *maxValue) {
    *minValue = getMin_(a, n);
    *maxValue = getMax_(a, n);

    return *maxValue - *minValue + 1;
}

int *getValueAppearsCountArray(const int *const a, const size_t n,
                               int *minValue, int *maxValue) {
    size_t valueAppearsCountArraySize = getValueAppearsCountArraySize(a, n,
                                                                      minValue,
                                                                      maxValue);

    int *valueAppearsCountArray = (int *) malloc(valueAppearsCountArraySize *
                                                 sizeof(int));

    for (int i = 0, value = *minValue; value <= *maxValue; i++, value++)
        valueAppearsCountArray[i] = countValues_(a, n, value);

    return valueAppearsCountArray;
}

void countSort(int *const a, const size_t n) {
    int minValue, maxValue;
    int *valueAppearsCountArray = getValueAppearsCountArray(a, n,
                                                            &minValue,
                                                            &maxValue);

    size_t k = 0;
    for (int i = 0, value = minValue; value <= maxValue; i++, value++) {
        for (int q = 0; q < valueAppearsCountArray[i]; q++) {
            a[k] = value;
            k += 1;
        }
    }

    free(valueAppearsCountArray);
}