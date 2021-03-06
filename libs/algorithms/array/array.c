#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <memory.h>

#include "array.h"

void inputArray_(int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void outputArray_(const int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void append_(int *const a,
             size_t *const n,
             const int value) {
    a[*n] = value;
    (*n)++;
}

void insert_(int *const a, size_t *const n,
             const size_t pos, const int value) {
    assert(pos < *n);
    if (*n != 0) {
        size_t lowBound = (pos == 0) ? SIZE_MAX : pos;
        (*n)++;
        for (size_t i = *n; i != lowBound; i--)
            a[i] = a[i - 1];
        a[pos] = value;
    }
}

void deleteByPosSaveOrder_(int *const a,
                           size_t *const n,
                           const size_t pos) {
    for (size_t i = pos; i < *n; i++)
        a[i] = a[i + 1];
    (*n)--;
}

void deleteByPosUnsaveOrder_(int *const a,
                             size_t *const n,
                             const size_t pos) {
    a[pos] = a[*n - 1];
    (*n)--;
}

size_t linearSearch_(const int *const a,
                     const size_t n,
                     const int x) {
    for (size_t i = 0; i < n; i++)
        if (a[i] == x)
            return i;

    return n;
}

int any_(const int *const a, const size_t n,
         int (*predicate)(int)) {
    for (size_t i = 0; i < n; i++)
        if (predicate(a[i]))
            return 1;

    return 0;
}

int all_(const int *const a, const size_t n,
         int (*predicate)(int)) {
    for (size_t i = 0; i < n; i++)
        if (!predicate(a[i]))
            return 0;

    return 1;
}

int countIf_(const int *const a, const size_t n,
             int (*predicate)(int)) {
    int count = 0;
    for (size_t i = 0; i < n; i++)
        count += predicate(a[i]);

    return count;
}

void deleteIf_(int *const a, size_t *const n,
               int (*deletePredicate)(int)) {
    size_t iRead = 0;
    while (iRead < *n && !deletePredicate(a[iRead]))
        iRead++;
    size_t iWrite = iRead;
    while (iRead < *n) {
        if (!deletePredicate(a[iRead])) {
            a[iWrite] = a[iRead];
            iWrite++;
        }
        iRead++;
    }
    *n = iWrite;
}

void forEach_(const int *const source, int *const dest,
              const size_t n, const int (*predicate)(int)) {
    for (size_t i = 0; i < n; i++)
        dest[i] = predicate(source[i]);
}

size_t binarySearch_(const int *const a,
                     const size_t n,
                     const int x) {
    if (n == 0)
        return n;
    size_t left = 0;
    size_t right = n - 1;
    while (left <= right) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle + 1;
        else if (a[middle] > x)
            right = middle - 1;
        else
            return middle;
    }

    return n;
}

size_t binarySearch_orderedSet_(const int *const a,
                                const size_t n,
                                const int x) {
    if (n == 0)
        return n;
    size_t left = 0;
    size_t right = n - 1;
    while (left <= right) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle + 1;
        else if (a[middle] > x)
            if (left == 0 && right == 0)
                left = 1;
            else
                right = middle > 0 ? middle - 1 : middle;
        else
            return middle;
    }

    return n;
}

size_t binarySearchMoreOrEqual_(const int *const a,
                                const size_t n,
                                const int x) {
    if (a[0] >= x)
        return 0;
    size_t left = 0;
    size_t right = n;
    while (right - left > 1) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle;
        else
            right = middle;
    }

    return right;
}

long long getSum_(const int *const a,
                  const size_t n) {
    int sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

size_t getMinPos_int_(const int *const a,
                      const size_t n,
                      const size_t pos) {
    int min = a[pos];
    size_t minPos = pos;
    for (size_t i = pos; i < n; i++)
        if (a[i] < min) {
            min = a[i];
            minPos = i;
        }

    return minPos;
}

size_t getMinPos_longLong_(const long long *const a,
                           const size_t n,
                           const size_t pos) {
    long long min = a[pos];
    size_t minPos = pos;
    for (size_t i = pos; i < n; i++)
        if (a[i] < min) {
            min = a[i];
            minPos = i;
        }

    return minPos;
}

int getMax_(const int *const a,
            const size_t n) {
    int max = a[0];
    for (size_t i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

int getMin_(const int *const a,
            const size_t n) {
    int min = a[0];
    for (size_t i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];

    return min;
}

size_t linearSearchFromPos_longLong_(const long long *const a,
                                     const size_t n,
                                     const size_t pos,
                                     const long long x) {
    for (size_t i = pos; i < n; i++)
        if (a[i] == x)
            return i;

    return n;
}

bool isUnique_longLong_(const long long *const a,
                        const size_t n) {
    for (size_t i = 0; i < n; i++)
        if (linearSearchFromPos_longLong_(a, n, i + 1, a[i]) != n)
            return false;

    return true;
}

size_t getMinPos_float_(const float *const a,
                        const size_t n,
                        const size_t pos) {
    float min = a[pos];
    size_t minPos = pos;
    for (size_t i = pos; i < n; i++)
        if (a[i] < min) {
            min = a[i];
            minPos = i;
        }

    return minPos;
}

bool isNonDescendingSortedArray_(const int *const a,
                                 const size_t n) {
    int previousElement = a[0];
    for (size_t i = 1; i < n; i++) {
        int currentElement = a[i];
        if (previousElement > currentElement)
            return false;

        previousElement = a[i];
    }

    return true;
}

int countValues_(const int *const a,
                 const size_t n,
                 const int value) {
    int count = 0;
    for (size_t i = 0; i < n; i++)
        count += a[i] == value;

    return count;
}

bool areEqualArrays_(const int *const a1, const size_t n1,
                     const int *const a2, const size_t n2) {
    if (n1 != n2)
        return false;

    return memcmp(a1, a2, n1 * sizeof(int)) == 0;
}

bool hasArrayPositiveElement_(const int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        if (a[i] > 0)
            return true;

    return false;
}