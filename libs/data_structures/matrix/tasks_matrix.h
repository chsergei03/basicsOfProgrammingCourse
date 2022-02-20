#ifndef INC_TASKS_MATRIX_H
#define INC_TASKS_MATRIX_H

#include "matrix.h"

// меняет местами строки матрицы m, в которых находятся
// максимальный и минимальный элементы.
void swapRowsWithMaxAndMinValuesOfSquareMatrix(matrix *m);

// сортирует строки матрицы m по неубыванию
// наибольших элементов строк.
void sortRowsByMaxElements(matrix *m);

// сортирует столбцы матрицы m по неубыванию
// наименьших элементов столбцов.
void sortColsByMinElements(matrix *m);

// возвращает матрицу, полученную умножением
// матрицы m1 на матрицу m2.
matrix mulMatrices(matrix m1, matrix m2);

// заменяет квадратную матрицу m её квадратом,
// если матрица симметрична.
void getSquareOfMatrixIfSymmetric(matrix *m);

// транспонирует квадратную матрицу m, если среди
// сумм элементов строк матрицы нет равных.
void transposeIfMatrixHasNotEqualSumsOfRows(matrix *m);

#endif