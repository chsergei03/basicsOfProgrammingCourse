#include <assert.h>

#include "libs/algorithms/array/array.h"
#include "libs/sorting_time_complexity/array_generators/array_generators.h"
#include "libs/algorithms/array_sortings/bubble_sort.h"
#include "libs/algorithms/array_sortings/selection_sort.h"

void test_bubbleSort_arrayWithOneElement() {
    int a[] = {19};
    size_t n = 1;
    bubbleSort(a, n);
    int expectedA[] = {19};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_bubbleSort_unorderedArray() {
    int a[] = {5, 4, 0, 2, 1, 3, 0, -7};
    size_t n = 8;
    bubbleSort(a, n);
    int expectedA[] = {-7, 0, 0, 1, 2, 3, 4, 5};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_bubbleSort_orderedArray_withRepeatedValues() {
    int a[] = {7, 11, 11, 13, 14, 15};
    size_t n = 6;
    bubbleSort(a, n);
    int expectedA[] = {7, 11, 11, 13, 14, 15};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_bubbleSort_orderedArray_withoutRepeatedValues() {
    int a[5] = {};
    size_t n = 5;
    generateOrderedArray(a, n);
    bubbleSort(a, n);
    int expectedA[] = {0, 1, 2, 3, 4};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_bubbleSort_orderedBackwardsArray_withRepeatedValues() {
    int a[] = {7, 5, 3, 3, 1, 0};
    size_t n = 6;
    bubbleSort(a, n);
    int expectedA[] = {0, 1, 3, 3, 5, 7};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_bubbleSort_orderedBackwardsArray_withoutRepeatedValues() {
    int a[7] = {};
    size_t n = 7;
    generateOrderedBackwardsArray(a, n);
    bubbleSort(a, n);
    int expectedA[] = {0, 1, 2, 3, 4, 5, 6};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_bubbleSort() {
    test_bubbleSort_arrayWithOneElement();
    test_bubbleSort_unorderedArray();
    test_bubbleSort_orderedArray_withRepeatedValues();
    test_bubbleSort_orderedArray_withoutRepeatedValues();
    test_bubbleSort_orderedBackwardsArray_withRepeatedValues();
    test_bubbleSort_orderedBackwardsArray_withoutRepeatedValues();
}

void test_selectionSort_arrayWithOneElement() {
    int a[] = {6};
    size_t n = 1;
    bubbleSort(a, n);
    int expectedA[] = {6};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_selectionSort_unorderedArray() {
    int a[] = {3, 4, 26, -1, 14, 1, 9, 4};
    size_t n = 8;
    bubbleSort(a, n);
    int expectedA[] = {-1, 1, 3, 4, 4, 9, 14, 26};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_selectionSort_orderedArray_withRepeatedValues() {
    int a[] = {3, 5, 5, 9, 10, 11, 30};
    size_t n = 7;
    bubbleSort(a, n);
    int expectedA[] = {3, 5, 5, 9, 10, 11, 30};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_selectionSort_orderedArray_withoutRepeatedValues() {
    int a[4] = {};
    size_t n = 4;
    generateOrderedArray(a, n);
    bubbleSort(a, n);
    int expectedA[] = {0, 1, 2, 3};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_selectionSort_orderedBackwardsArray_withRepeatedValues() {
    int a[] = {22, 10, 7, 7, 5, -3};
    size_t n = 6;
    bubbleSort(a, n);
    int expectedA[] = {-3, 5, 7, 7, 10, 22};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_selectionSort_orderedBackwardsArray_withoutRepeatedValues() {
    int a[8] = {};
    size_t n = 8;
    generateOrderedBackwardsArray(a, n);
    bubbleSort(a, n);
    int expectedA[] = {0, 1, 2, 3, 4, 5, 6, 7};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_selectionSort() {
    test_selectionSort_arrayWithOneElement();
    test_selectionSort_unorderedArray();
    test_selectionSort_orderedArray_withRepeatedValues();
    test_selectionSort_orderedArray_withoutRepeatedValues();
    test_selectionSort_orderedBackwardsArray_withRepeatedValues();
    test_selectionSort_orderedBackwardsArray_withoutRepeatedValues();
}

void test_array_sortings() {
    test_bubbleSort();
    test_selectionSort();
}

int main() {
    test_array_sortings();

    return 0;
}