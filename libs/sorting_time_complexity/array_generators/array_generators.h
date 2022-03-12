#ifndef INC_ARRAY_GENERATORS_H
#define INC_ARRAY_GENERATORS_H

#include <stddef.h>

// генерирует массив a размера n типа int со
// случайными значениями.
void generateRandomArray(int *a, size_t n);

// генерирует упорядоченный массив a размера n
// типа int со значениями 0, 1, 2, ... , n - 1.
void generateOrderedArray(int *a, size_t n);

// генерирует упорядоченный массив a размера n
// типа int со значениями n - 1, n - 2, ..., 0.
void generateOrderedBackwardsArray(int *a, size_t n);

#endif