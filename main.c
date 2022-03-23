#include <assert.h>

#include "libs/algorithms/array/array.h"
#include "libs/sorting_time_complexity/array_generators/array_generators.h"
#include "libs/sorting_time_complexity/sorting_time_complexity.h"
#include "libs/algorithms/array_sortings/bubble_sort.h"
#include "libs/algorithms/array_sortings/selection_sort.h"
#include "libs/algorithms/array_sortings/insertion_sort.h"
#include "libs/algorithms/array_sortings/comb_sort.h"
#include "libs/algorithms/array_sortings/shell_sort.h"
#include "libs/algorithms/array_sortings/count_sort.h"
#include "libs/algorithms/array_sortings/digit_sort.h"

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
    selectionSort(a, n);
    int expectedA[] = {6};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_selectionSort_unorderedArray() {
    int a[] = {3, 4, 26, -1, 14, 1, 9, 4};
    size_t n = 8;
    selectionSort(a, n);
    int expectedA[] = {-1, 1, 3, 4, 4, 9, 14, 26};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_selectionSort_orderedArray_withRepeatedValues() {
    int a[] = {3, 5, 5, 9, 10, 11, 30};
    size_t n = 7;
    selectionSort(a, n);
    int expectedA[] = {3, 5, 5, 9, 10, 11, 30};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_selectionSort_orderedArray_withoutRepeatedValues() {
    int a[4] = {};
    size_t n = 4;
    generateOrderedArray(a, n);
    selectionSort(a, n);
    int expectedA[] = {0, 1, 2, 3};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_selectionSort_orderedBackwardsArray_withRepeatedValues() {
    int a[] = {22, 10, 7, 7, 5, -3};
    size_t n = 6;
    selectionSort(a, n);
    int expectedA[] = {-3, 5, 7, 7, 10, 22};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_selectionSort_orderedBackwardsArray_withoutRepeatedValues() {
    int a[8] = {};
    size_t n = 8;
    generateOrderedBackwardsArray(a, n);
    selectionSort(a, n);
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

void test_insertionSort_arrayWithOneElement() {
    int a[] = {1};
    size_t n = 1;
    insertionSort(a, n);
    int expectedA[] = {1};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_insertionSort_unorderedArray() {
    int a[] = {5, 15, 2, -6, 0, 89};
    size_t n = 6;
    insertionSort(a, n);
    int expectedA[] = {-6, 0, 2, 5, 15, 89};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_insertionSort_orderedArray_withRepeatedValues() {
    int a[] = {10, 12, 12, 20, 30};
    size_t n = 5;
    insertionSort(a, n);
    int expectedA[] = {10, 12, 12, 20, 30};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_insertionSort_orderedArray_withoutRepeatedValues() {
    int a[6] = {};
    size_t n = 6;
    generateOrderedArray(a, n);
    insertionSort(a, n);
    int expectedA[] = {0, 1, 2, 3, 4, 5};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_insertionSort_orderedBackwardsArray_withRepeatedValues() {
    int a[] = {3, 3, 2, 0};
    size_t n = 4;
    insertionSort(a, n);
    int expectedA[] = {0, 2, 3, 3};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_insertionSort_orderedBackwardsArray_withoutRepeatedValues() {
    int a[3] = {};
    size_t n = 3;
    generateOrderedArray(a, n);
    insertionSort(a, n);
    int expectedA[] = {0, 1, 2};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_insertionSort() {
    test_insertionSort_arrayWithOneElement();
    test_insertionSort_unorderedArray();
    test_insertionSort_orderedArray_withRepeatedValues();
    test_insertionSort_orderedArray_withoutRepeatedValues();
    test_insertionSort_orderedBackwardsArray_withRepeatedValues();
    test_insertionSort_orderedBackwardsArray_withoutRepeatedValues();
}

void test_combSort_arrayWithOneElement() {
    int a[] = {20};
    size_t n = 1;
    combSort(a, n);
    int expectedA[] = {20};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_combSort_unorderedArray() {
    int a[] = {1021, 123, -94, 6, 738, 1021, -350, 2, 7};
    size_t n = 9;
    combSort(a, n);
    int expectedA[] = {-350, -94, 2, 6, 7, 123, 738, 1021, 1021};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_combSort_orderedArray_withRepeatedValues() {
    int a[] = {3, 13, 15, 25, 25, 89, 100};
    size_t n = 7;
    combSort(a, n);
    int expectedA[] = {3, 13, 15, 25, 25, 89, 100};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_combSort_orderedArray_withoutRepeatedValues() {
    int a[4] = {};
    size_t n = 4;
    generateOrderedArray(a, n);
    combSort(a, n);
    int expectedA[] = {0, 1, 2, 3};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_combSort_orderedBackwardsArray_withRepeatedValues() {
    int a[] = {45, 42, 31, 9, 9, 4};
    size_t n = 6;
    combSort(a, n);
    int expectedA[] = {4, 9, 9, 31, 42, 45};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_combSort_orderedBackwardsArray_withoutRepeatedValues() {
    int a[9] = {};
    size_t n = 9;
    generateOrderedBackwardsArray(a, n);
    combSort(a, n);
    int expectedA[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_combSort() {
    test_combSort_arrayWithOneElement();
    test_combSort_unorderedArray();
    test_combSort_orderedArray_withRepeatedValues();
    test_combSort_orderedArray_withoutRepeatedValues();
    test_combSort_orderedBackwardsArray_withRepeatedValues();
    test_combSort_orderedBackwardsArray_withoutRepeatedValues();
}

void test_shellSort_arrayWithOneElement() {
    int a[] = {5};
    size_t n = 1;
    shellSort(a, n);
    int expectedA[] = {5};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_shellSort_unorderedArray() {
    int a[] = {163, 5, 2, -17, -17, 81, -4};
    size_t n = 7;
    shellSort(a, n);
    int expectedA[] = {-17, -17, -4, 2, 5, 81, 163};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_shellSort_orderedArray_withRepeatedValues() {
    int a[] = {0, 0, 2, 5, 7, 8, 8};
    size_t n = 7;
    shellSort(a, n);
    int expectedA[] = {0, 0, 2, 5, 7, 8, 8};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_shellSort_orderedArray_withoutRepeatedValues() {
    int a[6] = {};
    size_t n = 6;
    generateOrderedArray(a, n);
    shellSort(a, n);
    int expectedA[] = {0, 1, 2, 3, 4, 5};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_shellSort_orderedBackwardsArray_withRepeatedValues() {
    int a[] = {56, 50, 50, 9, 9, -4};
    size_t n = 6;
    shellSort(a, n);
    int expectedA[] = {-4, 9, 9, 50, 50, 56};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_shellSort_orderedBackwardsArray_withoutRepeatedValues() {
    int a[10] = {};
    size_t n = 10;
    generateOrderedBackwardsArray(a, n);
    shellSort(a, n);
    int expectedA[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_shellSort() {
    test_shellSort_arrayWithOneElement();
    test_shellSort_unorderedArray();
    test_shellSort_orderedArray_withRepeatedValues();
    test_shellSort_orderedArray_withoutRepeatedValues();
    test_shellSort_orderedBackwardsArray_withRepeatedValues();
    test_shellSort_orderedBackwardsArray_withoutRepeatedValues();
}

void test_countSort_arrayWithOneElement() {
    int a[] = {7};
    size_t n = 1;
    countSort(a, n);
    int expectedA[] = {7};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_countSort_unorderedArray() {
    int a[] = {3, -1, 3, 1, 2, 2, 1, 2, 3, 2, 1};
    size_t n = 11;
    countSort(a, n);
    int expectedA[] = {-1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_countSort_orderedArray_withRepeatedValues() {
    int a[] = {4, 4, 5, 6, 7, 7, 8, 8, 8, 9, 10};
    size_t n = 11;
    countSort(a, n);
    int expectedA[] = {4, 4, 5, 6, 7, 7, 8, 8, 8, 9, 10};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_countSort_orderedArray_withoutRepeatedValues() {
    int a[6] = {};
    size_t n = 6;
    generateOrderedArray(a, n);
    countSort(a, n);
    int expectedA[] = {0, 1, 2, 3, 4, 5};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_countSort_orderedBackwardsArray_withRepeatedValues() {
    int a[] = {4, 3, 3, 2, 1, 0, 0, -2, -4};
    size_t n = 9;
    countSort(a, n);
    int expectedA[] = {-4, -2, 0, 0, 1, 2, 3, 3, 4};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_countSort_orderedBackwardsArray_withoutRepeatedValues() {
    int a[7] = {};
    size_t n = 7;
    generateOrderedBackwardsArray(a, n);
    countSort(a, n);
    int expectedA[] = {0, 1, 2, 3, 4, 5, 6};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_countSort() {
    test_countSort_arrayWithOneElement();
    test_countSort_unorderedArray();
    test_countSort_orderedArray_withRepeatedValues();
    test_countSort_orderedArray_withoutRepeatedValues();
    test_countSort_orderedBackwardsArray_withRepeatedValues();
    test_countSort_orderedBackwardsArray_withoutRepeatedValues();
}

void test_digitSort_arrayWithOneElement() {
    int a[] = {7};
    size_t n = 1;
    digitSort(a, n);
    int expectedA[] = {7};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_digitSort_unorderedArray() {
    int a[] = {40, 3, 127, 2, 12, 12, 1000};
    size_t n = 7;
    digitSort(a, n);
    int expectedA[] = {2, 3, 12, 12, 40, 127, 1000};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_digitSort_orderedArray_withRepeatedValues() {
    int a[] = {0, 3, 5, 5, 7, 9, 13, 15};
    size_t n = 8;
    digitSort(a, n);
    int expectedA[] = {0, 3, 5, 5, 7, 9, 13, 15};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_digitSort_orderedArray_withoutRepeatedValues() {
    int a[6] = {};
    size_t n = 6;
    generateOrderedArray(a, n);
    digitSort(a, n);
    int expectedA[] = {0, 1, 2, 3, 4, 5};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_digitSort_orderedBackwardsArray_withRepeatedValues() {
    int a[] = {300, 264, 85, 85, 30, 10, 10, 9, 0};
    size_t n = 9;
    digitSort(a, n);
    int expectedA[] = {0, 9, 10, 10, 30, 85, 85, 264, 300};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_digitSort_orderedBackwardsArray_withoutRepeatedValues() {
    int a[9] = {};
    size_t n = 9;
    generateOrderedArray(a, n);
    digitSort(a, n);
    int expectedA[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    size_t expectedN = n;
    assert(areEqualArrays_(a, n, expectedA, expectedN));
}

void test_digitSort() {
    test_digitSort_arrayWithOneElement();
    test_digitSort_unorderedArray();
    test_digitSort_orderedArray_withRepeatedValues();
    test_digitSort_orderedArray_withoutRepeatedValues();
    test_digitSort_orderedBackwardsArray_withRepeatedValues();
    test_digitSort_orderedBackwardsArray_withoutRepeatedValues();
}

void test_array_sortings() {
    test_bubbleSort();
    test_selectionSort();
    test_insertionSort();
    test_combSort();
    test_shellSort();
    test_countSort();
    test_digitSort();
}

int main() {
    test_array_sortings();

    timeExperiment();

    return 0;
}