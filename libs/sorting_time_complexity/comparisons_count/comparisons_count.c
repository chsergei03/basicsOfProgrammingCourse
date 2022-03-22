#include <malloc.h>
#include <memory.h>

#include "comparisons_count.h"

long long bubbleSort_comparisonsCount(int *const a, const size_t n) {
    long long comparisonsCount = 0;
    for (size_t q = 0; ++comparisonsCount && q < n - 1; q++)
        for (size_t i = 0, j = 1; ++comparisonsCount && j < n - q; i++, j++)
            if (++comparisonsCount && a[i] > a[j])
                void_swap(&a[i], &a[j], sizeof(int));

    return comparisonsCount;
}

size_t getMinPos_int_comparisonsCount(const int *const a,
                                      const size_t n,
                                      const size_t pos,
                                      long long *comparisonsCount) {
    int min = a[pos];
    size_t minPos = pos;
    for (size_t i = pos; ++(*comparisonsCount) && i < n; i++)
        if (a[i] < min) {
            min = a[i];
            minPos = i;
        }

    return minPos;
}

long long selectionSort_comparisonsCount(int *a, size_t n) {
    long long comparisonsCount = 0;
    for (size_t i = 0; ++comparisonsCount && i < n; i++) {
        size_t minPos = getMinPos_int_comparisonsCount(a, n,
                                                       i, &comparisonsCount);
        if (++comparisonsCount && i != minPos)
            void_swap(&a[i], &a[minPos], sizeof(int));
    }

    return comparisonsCount;
}

long long insertionSort_comparisonsCount(int *const a, const size_t n) {
    long long comparisonsCount = 0;
    for (size_t i = 1; ++comparisonsCount && i < n; i++) {
        int t = a[i];
        size_t j = i;
        while (++comparisonsCount && j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }

    return comparisonsCount;
}

long long combSort_comparisonsCount(int *const a, const size_t n) {
    long long comparisonsCount = 0;
    size_t t = n;
    bool isSwapped = true;
    while (++comparisonsCount && (t > 1 || isSwapped)) {
        if (++comparisonsCount && t > 1)
            t /= DECREASE_FACTOR;
        isSwapped = false;
        for (size_t i = 0, j = t; ++comparisonsCount && j < n; i++, j++)
            if (++comparisonsCount && a[i] > a[j]) {
                void_swap(&a[i], &a[j], sizeof(int));
                isSwapped = true;
            }
    }

    return comparisonsCount;
}

long long shellSort_comparisonsCount(int *const a, const size_t n) {
    long long comparisonsCount = 0;
    size_t d = n / 2;
    while (++comparisonsCount && d > 0) {
        for (size_t i = d; ++comparisonsCount && i < n; i += 1) {
            int t = a[i];
            size_t j = i;
            while (++comparisonsCount && j >= d && a[j - d] > t) {
                a[j] = a[j - d];
                j -= d;
            }
            a[j] = t;
        }
        d /= 2;
    }

    return comparisonsCount;
}

size_t linearSearchFromPos_searchNumberWithByteValue_int_comparisonsCount(const int *const a,
                                                                          const size_t n,
                                                                          size_t *pos,
                                                                          const size_t bytePosFromEnd,
                                                                          const int byteValue,
                                                                          long long *comparisonsCount) {
    for (size_t i = *pos; ++(*comparisonsCount) && i < n; i++)
        if (++(*comparisonsCount) && getCurrentByte(a[i], bytePosFromEnd) == byteValue) {
            *pos = ++comparisonsCount && i < n ? i + 1 : i;
            return i;
        }

    return n;
}

long long digitSort_comparisonsCount(int *const a, const size_t n) {
    long long comparisonsCount = 0;

    int *byteValuesArray = (int *) malloc(n * sizeof(int));
    int *aCopy = (int *) malloc(n * sizeof(int));
    memcpy(aCopy, a, n * sizeof(int));

    size_t bytePosFromTheEnd = 0;
    bool isAnyPositiveCurrentByte = true;
    getCurrentByteValues(aCopy, n, bytePosFromTheEnd,
                         byteValuesArray, &isAnyPositiveCurrentByte);
    while (++comparisonsCount && isAnyPositiveCurrentByte) {
        int byteMinValue, byteMaxValue;
        int *byteValueAppearsCountArray = getValueAppearsCountArray(byteValuesArray, n,
                                                                    &byteMinValue,
                                                                    &byteMaxValue);

        size_t i = 0;
        for (int q = 0, value = byteMinValue; ++comparisonsCount && value <= byteMaxValue; q++, value++) {
            size_t searchPos = 0;
            for (int j = 0; ++comparisonsCount && j < byteValueAppearsCountArray[q]; j++) {
                size_t pos = linearSearchFromPos_searchNumberWithByteValue_int_comparisonsCount(aCopy, n,
                                                                                                &searchPos,
                                                                                                bytePosFromTheEnd,
                                                                                                value,
                                                                                                &comparisonsCount);
                a[i] = aCopy[pos];
                i += 1;
            }
        }

        memcpy(aCopy, a, n * sizeof(int));

        bytePosFromTheEnd += 1;
        getCurrentByteValues(aCopy, n, bytePosFromTheEnd,
                             byteValuesArray, &isAnyPositiveCurrentByte);

        free(byteValueAppearsCountArray);
    }

    free(aCopy);

    return comparisonsCount;
}