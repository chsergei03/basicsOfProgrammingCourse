#ifndef INC_TASKS_MATRIX_H
#define INC_TASKS_MATRIX_H

#include "matrix.h"

// меняет местами строки матрицы m, в которых находятся
// максимальный и минимальный элементы.
void swapRowsWithMaxAndMinValuesOfSquareMatrix(matrix *m);

// сортирует строки матрицы m по неубыванию
// наибольших элементов строк.
void sortRowsByMaxElements(matrix *m);

#endif