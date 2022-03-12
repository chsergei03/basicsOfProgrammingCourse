#ifndef INC_SELECTION_SORT_H
#define INC_SELECTION_SORT_H

#include <stddef.h>

#include "../algorithm.h"
#include "../array/array.h"

// производит сортировку выбором по неубыванию массива a
// размера n типа int.
void selectionSort(int *a, size_t n);

#endif