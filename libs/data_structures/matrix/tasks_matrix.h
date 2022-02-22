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

// выводит в поток ошибок сообщение о том, что количество строк матрицы m1
// не равно количеству столбцов матрицы m2, при этом выполнение программы
// завершается с кодом 1.
void errorMessageIfNColsOfMatrix1IsNotEqualToNRowsOfMatrix2(matrix m1,
                                                            matrix m2);

// возвращает матрицу, полученную умножением
// матрицы m1 на матрицу m2.
matrix mulMatrices(matrix m1, matrix m2);

// выводит в поток ошибок сообщение о том, что матрица не является
// симметричной при этом выполнение программы завершается с кодом 1.
void errorMessageIfMatrixIsNotSymmetric(matrix m);

// заменяет квадратную матрицу m её квадратом,
// если матрица симметрична.
void getSquareOfMatrixIfSymmetric(matrix *m);

// выводит в поток ошибок сообщение о том, что массив сумм элементов строк матрицы не
// содержит лишь уникальные элементы, при этом выполнение программы завершается с кодом 1.
void errorMessageIfSumsOfRowsArrayIsNotArrayOfUniqueElements(const long long *a,
                                                             size_t n);

// транспонирует квадратную матрицу m, если среди
// сумм элементов строк матрицы нет равных.
void transposeIfMatrixHasNotEqualSumsOfRows(matrix *m);

// возвращает значение 'истина', если матрицы m1 и m2
// являются взаимно обратными, в противном случае - 'ложь'.
bool areMutuallyInverseMatrices(matrix m1, matrix m2);

// возвращает значение 'истина', если матрица m
// является квадратной матрицей первого порядка,
// в противном случае - 'ложь'.
bool isSquareMatrixOfFirstOrder(matrix m);

// возвращает сумму максимальных элементов всех псевдодиагоналей
// матрицы m.
long long findSumOfMaxesOfPseudoDiagonals(matrix m);

// возвращает минимальный элемент в области
// матрицы m, имеющей форму перевернутой
// ступенчатой пирамиды, вершиной которой
// является максимальный элемент матрицы
int getMinInArea(matrix m);

// возвращает расстояние от начала координат до
// данной точки (массив a - массив координат
// точки).
float getDistance(const int *a, size_t n);

// возвращает среднее арифметическое
// элементов массива a размера n.
float getArithmeticMean(const int *a,
                        size_t n);

// возвращает массив criteriaValuesArray размера m.nRows типа float,
// заполненный значениями функции criteria типа float, применяемой к строкам
// матрицы m.
float *getFilledCriteriaValuesArrayForRows_float(matrix m,
                                                 float (*criteria)(int *, size_t));

// выполняет сортировку вставками строк матрицы m по
// неубыванию значения функции criteria типа float,
// применяемой для строк.
void selectionSortRowsMatrixByRowCriteriaF(matrix *m,
                                           float (*criteria)(int *, size_t));

// сортирует точки по неубыванию их расстояний до
// начала координат (каждая строка матрицы - массив
// координаты точки).
void sortByDistances(matrix *m);

// возвращает количество строк матрицы m, имеющих уникальные
// значения сумм элементов.
int countOfRowsWithUniqueSumOfElements(const long long *a,
                                       size_t n);

// возвращает количество классов эквивалентных
// строк прямоугольной матрицы m (строки считаются
// эквивалентными, если равны суммы их элементов).
int countOfClassesOfEqRowsByRowSum(matrix m);

// возвращает количество 'особых' элементов
// матрицы m (элемент считается особым, если
// он больше суммы остальных элементов своего
// столбца).
int getCountOfSpecialElements(matrix m);

// возвращает позицию первого
// минимума матрицы m относительно
// столбцов.
position getLeftMin(matrix m);

// выводит в поток ошибок сообщение о том, что матрица
// m не содержит предпоследней строки, при этом выполнение
// программы завершается с кодом 1.
void errorMessageIfMatrixHasNotPenultimateRow(matrix m);

// заменяет предпоследнюю строку
// квадратной матрицы m первым из
// столбцов, в котором находится
// минимальный элемент.
void swapPenultimateRow(matrix *m);

// возвращает значение 'истина', если
// все строки матрицы m упорядочены по
// неубыванию, в противном случае - 'ложь'.
bool hasAllNonDescendingRows(matrix m);

// возвращает количество матриц в массиве матриц ms.
// строки которых упорядочены по неубыванию элементов.
int countNonDescendingRowsMatrices(const matrix *ms,
                                   size_t nMatrices);

// возвращает количество нулевых
// строк в матрице m.
int countZeroRows(matrix m);

// возвращает массив criteriaValuesArray размера nMatrices типа int,
// заполненный значениями функции criteria типа int, применяемой к
// матрицам из массива матриц ms.
int *getFilledCriteriaValuesArrayForMatrices(const matrix *ms,
                                             size_t nMatrices,
                                             int (*criteria)(matrix));

// выводит матрицы из массива матриц ms размера nMatrices,
// имеющие наибольшее число нулевых строк.
void printMatricesWithMaxValueOfZeroRows(const matrix *ms,
                                         size_t nMatrices);

// возвращает значение 'истина', если элементы массива
// матриц ms представляют из себя квадратные матрицы,
// в противном случае - 'ложь'.
bool isMatrixArrayOfSquareMatrices(const matrix *ms);

// возвращает норму квадратной матрицы
// m (нормой называется максимум абсолютных
// величин элементов матрицы).
int getMatrixNorm(matrix m);

// выводит в поток ошибок сообщение о том, что массив матриц ms не
// представляет из себя массив квадратных матриц, при этом выполнение
// программы завершается с кодом 1.
void errorMessageIfMatricesInMatrixArrayAreNotSquare(const matrix *ms);

// выводит матрицы из массива матриц ms размера nMatrices,
// с минимальной нормой (нормой называется максимум абсолютных
// величин элементов матрицы).
void printMatricesWithMinNorm(const matrix *ms,
                              size_t nMatrices);

#endif