#ifndef INC_MATRIX_H
#define INC_MATRIX_H

#include <stdlib.h>
#include <stdbool.h>

#include "../../../libs/algorithms/array/array.h"
#include "../../../libs/algorithms/algorithm.h"

typedef struct matrix {
    int **values;
    size_t nRows;
    size_t nCols;
} matrix;

typedef struct position {
    size_t rowIndex;
    size_t colIndex;
} position;

// выводит в поток ошибок сообщение о том, что операционная система не может
// предоставить нужный объем памяти под размещение динамического массива
// указателей, при этом выполнение программы завершается с кодом 1.
void isIncorrectMemoryAllocForPointersArray(const int **pointerArrayData);

// выводит в поток ошибок сообщение о том, что операционная
// система не может предоставить нужный объем памяти под
// размещение динамического массива, представляющего из себя
// строку матрицы, при этом выполнение программы завершается
// с кодом 1.
void isIncorrectMemoryAllocForRow(const int *rowData);

// выводит в поток ошибок сообщение о том, что операционная система не может
// предоставить нужный объем памяти под размещение динамического массива матриц,
// при этом выполнение программы завершается с кодом 1.
void isIncorrectMemoryAllocForMatrixArray(const matrix *matrixDataArray);

// возвращает структуру-дескриптор матрицы размера
// nRows на nCols.
matrix getMemMatrix(size_t nRows, size_t nCols);

// возвращает указатель на нулевую матрицу массива из nMatrices матриц размера
// nRows на nCols, размещенного в динамической памяти.
matrix *getMemArrayOfMatrices(size_t nMatrices, size_t nRows, size_t nCols);

// освобождает память, выделенную
// под хранение матрицы m.
void freeMemMatrix(matrix *m);

// освобождает память, выделенную под хранение массива
// ms из nMatrices матриц.
void freeMemMatrices(matrix *ms, size_t nMatrices);

// вводит матрицу m.
void inputMatrix(matrix *m);

// вводит массив из nMatrices матриц, который
// хранится по адресу ms.
void inputMatrices(matrix *ms, size_t nMatrices);

// выводит матрицу m.
void outputMatrix(matrix m);

// выводит массив из nMatrices матриц, который
// хранится по адресу ms.
void outputMatrices(const matrix *ms, size_t nMatrices);

// производит обмен строк с порядковыми номерами
// i1 и i2 в матрице m.
void swapRows(matrix *m, size_t i1, size_t i2);

// производит обмен столбцов с порядковыми номерами
// j1 и j2 в матрице m.
void swapCols(matrix *m, size_t j1, size_t j2);

// возвращает массив criteriaValuesArray размера m.nRows типа long long,
// заполненный значениями функции criteria типа int, применяемой к строкам
// матрицы m.
long long *getFilledCriteriaValuesArrayForRows(matrix m,
                                               int (*criteria)(int *, size_t));

// выполняет сортировку вставками строк матрицы m по
// неубыванию значения функции criteria типа int,
// применяемой к строкам матрицы m.
void selectionSortRowsMatrixByRowCriteria(matrix *m,
                                          int (*criteria)(int *, size_t));

// копирует элементы столбца с индексом
// sourceColIndex матрицы m в массив dest
// типа int.
void copyElementsOfColToArray(int *dest,
                              const matrix *m,
                              size_t sourceColIndex);

// возвращает массив criteriaValuesArray размера m.nCols типа long long,
// заполненный значениями функции criteria, применяемой к столбцам
// матрицы m.
long long *getFilledCriteriaValuesArrayForCols(matrix m,
                                               int (*criteria)(int *, size_t));

// выполняет сортировку вставками столбцов матрицы m по неубыванию значения
// функции criteria типа int, применяемой к столбцам.
void selectionSortColsMatrixByColCriteria(matrix *m,
                                          int (*criteria)(int *, size_t));

// возвращает значение 'истина',
// если матрица m является квадратной,
// в противном случае - 'ложь'.
bool isSquareMatrix(matrix m);

// возвращает значение 'истина', если матрицы m1
// и m2 равны, в противном случае - 'ложь'.
bool areTwoMatricesEqual(matrix m1, matrix m2);

// возвращает значение 'истина', если
// матрица m является единичной, в
// противном случае - 'ложь'.
bool isEMatrix(matrix m);

// возвращает значение 'истина', если
// матрица m является симметричной, в
// противном случае - 'ложь'.
bool isSymmetricMatrix(matrix m);

// выводит в поток ошибок сообщение о том, что
// матрица не является квадратной, при этом
// выполнение программы завершается с кодом 1.
void errorMessageIfMatrixIsNotSquare(matrix m);

// транспонирует квадратную матрицу m.
void transposeSquareMatrix(matrix *m);

// возвращает значение 'истина', если значение
// value меньше значения currentMin, в противном
// случае - 'ложь'.
bool minValueCriteria(int value, int currentMin);

// возвращает значение 'истина', если значение
// value больше значения currentMax, в противном
// случае - 'ложь'.
bool maxValueCriteria(int value, int currentMax);

// возвращает позицию первого элемента
// в матрице m, удовлетворящего функции criteria.
// (поиск осуществляется по строкам матрицы).
position getPosByValueCriteria(matrix m,
                               int (*valueCriteria)(int, int));

// возвращает позицию минимального
// элемента матрицы m.
position getMinValuePos(matrix m);

// возвращает позицию максимального
// элемента матрицы m.
position getMaxValuePos(matrix m);

// возвращает значение 'истина', если
// двумерные позиции pos1 и pos2 идентичны,
// в противном случае - 'ложь'.
bool areIdenticalPositions(position pos1,
                           position pos2);

// возвращает матрицу размера nRows на nCols,
// построенную из элементов массива a и размещенную
// в динамической памяти.
matrix createMatrixFromArray(const int *a,
                             size_t nRows,
                             size_t nCols);

// возвращает указатель на нулевую матрицу массива из
// nMatrices матриц, построенных из элементов массива a
// (массив матриц размещается в динамической памяти).
matrix *createArrayOfMatrixFromArray(const int *values,
                                     size_t nMatrices,
                                     size_t nRows,
                                     size_t nCols);

#endif