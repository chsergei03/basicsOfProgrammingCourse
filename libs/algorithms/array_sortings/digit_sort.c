#include <malloc.h>
#include <memory.h>

#include "digit_sort.h"
#include "../array/array.h"

#define MAX_8BIT_NUMBER 255
#define N_BITS_IN_BYTE 8

int getCurrentByte(const int number,
                   const size_t bytePosFromEnd) {
    int shiftValue = bytePosFromEnd * N_BITS_IN_BYTE;

    return (number & MAX_8BIT_NUMBER << shiftValue) >> shiftValue;
}

int isNotPositiveValue(const int value) {
    return value <= 0;
}

void getCurrentByteValues(const int *const a,
                          const size_t n,
                          const size_t bytePosFromTheEnd,
                          int *const byteValuesArray,
                          bool *isAnyPositiveCurrentByte) {
    for (size_t i = 0; i < n; i++) {
        byteValuesArray[i] = getCurrentByte(a[i], bytePosFromTheEnd);
    }

    if (all_(byteValuesArray, n, isNotPositiveValue))
        *isAnyPositiveCurrentByte = false;
}

size_t linearSearchFromPos_searchNumberWithByteValue_int_(const int *const a,
                                                          const size_t n,
                                                          size_t *pos,
                                                          const size_t bytePosFromEnd,
                                                          const int byteValue) {
    for (size_t i = *pos; i < n; i++)
        if (getCurrentByte(a[i], bytePosFromEnd) == byteValue) {
            *pos = i < n ? i + 1 : i;
            return i;
        }

    return n;
}

void digitSort(int *const a, const size_t n) {
    int *byteValuesArray = (int *) malloc(n * sizeof(int));
    int *aCopy = (int *) malloc(n * sizeof(int));
    memcpy(aCopy, a, n * sizeof(int));

    size_t bytePosFromTheEnd = 0;
    bool isAnyPositiveCurrentByte = true;
    getCurrentByteValues(aCopy, n, bytePosFromTheEnd,
                         byteValuesArray, &isAnyPositiveCurrentByte);
    while (isAnyPositiveCurrentByte) {
        int byteMinValue, byteMaxValue;
        int *byteValueAppearsCountArray = getValueAppearsCountArray(byteValuesArray, n,
                                                                    &byteMinValue, &byteMaxValue);

        size_t i = 0;
        for (int q = 0, value = byteMinValue; value <= byteMaxValue; q++, value++) {
            size_t searchPos = 0;
            for (int j = 0; j < byteValueAppearsCountArray[q]; j++) {
                size_t pos = linearSearchFromPos_searchNumberWithByteValue_int_(aCopy, n,
                                                                                &searchPos,
                                                                                bytePosFromTheEnd,
                                                                                value);
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
}