#ifndef INC_ALGORITHM_H
#define INC_ALGORITHM_H

#include <stddef.h>

// применяется в качестве функции-компаратора
// целочисленных значений типа int для быстрой
// сортировки массива qsort.
int compare_ints(const void *a, const void *b);

// возвращает минимальное из двух значений a и b
// типа size_t.
size_t min2_size_t(size_t a, size_t b);

#endif