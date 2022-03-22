#ifndef INC_COMPARISONS_COUNT_H
#define INC_COMPARISONS_COUNT_H

#include <stddef.h>

#include "../../algorithms/array/array.h"
#include "../../algorithms/algorithm.h"
#include "../../algorithms/array_sortings/digit_sort.h"

#define DECREASE_FACTOR 1.24733

// возвращает количество операций сравнения при обменной сортировке
// по неубыванию массива a размера n типа int.
long long bubbleSort_comparisonsCount(int *const a, const size_t n);

// возвращает количество операций сравнения при сортировке выбором
// по неубыванию массива a размера n типа int.
long long selectionSort_comparisonsCount(int *a, size_t n);

// возвращает количество операций сравнения при сортировке вставками
// по неубыванию массива a размера n типа int.
long long insertionSort_comparisonsCount(int *const a, const size_t n);

// возвращает количество операций сравнения при сортировке расческой
// по неубыванию массива a размера n типа int.
long long combSort_comparisonsCount(int *const a, const size_t n);

// возвращает количество операций сравнения при сортировке Шелла
// по неубыванию массива a размера n типа int.
long long shellSort_comparisonsCount(int *const a, const size_t n);

// возвращает количество операций сравнения при цифровой сортировке
// по неубыванию массива a размера n типа int.
long long digitSort_comparisonsCount(int *const a, const size_t n);

#endif