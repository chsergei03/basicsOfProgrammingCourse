#ifndef INC_ARRAY_H
#define INC_ARRAY_H

#include <stddef.h>
#include <stdbool.h>

// вводит массив a размера n типа int.
void inputArray_(int *a, size_t n);

// выводит массив a размера n типа int.
void outputArray_(const int *a, size_t n);

// возвращает позицию первого вхождения элемента x
// в массиве a размера n типа int при его наличии, иначе - n.
size_t linearSearch_(const int *a, size_t n, int x);

// возвращает позицию вхождения элемента x в отсортированном
// массиве a размера n типа int при его наличии, иначе - возвращает n.
size_t binarySearch_(const int *a, size_t n, int x);

// возвращает позицию вхождения элемента x в отсортированном
// массиве a размера n типа int (массив хранит значения упорядоченного
// множества) при наличии этого элемента, иначе - возвращает n.
size_t binarySearch_orderedSet_(const int *a, size_t n, int x);

// возвращает позицию первого элемента равного или большего x
// в отсортированном массиве a размера n типа int, при отсутствии
// такого элемента возвращает n.
size_t binarySearchMoreOrEqual_(const int *a, size_t n, int x);

// вставляет элемент со значением value в массив a размера
// n типа int на позицию pos.
void insert_(int *a, size_t *n, size_t pos, int value);

// добавляет элемент value в конец массива a
// размера n типа int.
void append_(int *a, size_t *n, int value);

// удаляет из массива a размера n типа int элемент, находящийся
// на позиции pos, с сохранением порядка оставшихся элементов,
// при этом размер массива уменьшается на единицу.
void deleteByPosSaveOrder_(int *a, size_t *n, size_t pos);

// удаляет из массива a размера n типа int элемент, находящийся
// на позиции pos, без сохранения порядка оставшихся элементов,
// при этом размер массива уменьшается на единицу.
void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos);

// возвращает значение ’истина’, если все элементы массива a
// размера n типа int соответствует функции-предикату predicate,
// иначе - ’ложь’.
int all_(const int *a, size_t n, int (*predicate)(int));

// возвращает значение ’истина’, если хотя бы один элемент
// массива a размера n типа int соответствует функции-предикату
// predicate, иначе - ’ложь’.
int any_(const int *a, size_t n, int (*predicate)(int));

// применяет функцию predicate ко всем элементам массива source
// размера n типа int и сохраняет результат в массиве dest размера
// n типа int.
void forEach_(const int *source, int *dest,
              size_t n, const int (*predicate)(int));

// удаляет из массива a размера n типа int все элементы, удовлетворяющие
// функции-предикату deletePredicate, записывает в n новый размер
// массива.
void deleteIf_(int *a, size_t *n, int(*deletePredicate)(int));

// возвращает количество элементов массива a размера n типа int,
// удовлетворяющих функции-предикату predicate.
int countIf_(const int *a, size_t n, int (*predicate)(int));

// возвращает сумму элементов массива a
// размера n типа int.
long long getSum_(const int *a, size_t n);

// возвращает позицию минимального элемента массива a размера n типа
// long long в области, начинающейся с позиции pos.
size_t getMinPos_longLong_(const long long *a, size_t n, size_t pos);

// возвращает позицию минимального элемента массива a размера n типа
// int в области, начинающейся с позиции pos.
size_t getMinPos_int_(const int *a, size_t n, size_t pos);

// возвращает максимальный элемент
// массива a размера n типа int.
int getMax_(const int *a, size_t n);

// возвращает минимальный элемент
// массива a размера n типа int.
int getMin_(const int *a, size_t n);

// возвращает позицию первого вхождения элемента x в массиве
// a размера n типа long long в области, начинающейся с позиции
// pos при его наличии, иначе - n.
size_t linearSearchFromPos_longLong_(const long long *a, size_t n,
                                     size_t pos, long long x);

// возвращает значение 'истина', если массив
// a размера n типа long long состоит только
// из уникальных элементов, в противном случае
// - 'ложь'.
bool isUnique_longLong_(const long long *a, size_t n);

// возвращает позицию минимального элемента массива a размера n типа
// float в области, начинающейся с позиции pos.
size_t getMinPos_float_(const float *a, size_t n, size_t pos);

// возвращает значение 'истина', если массив a размера n
// типа int является упорядоченным по неубыванию, в противном
// случае - 'ложь'.
bool isNonDescendingSortedArray_(const int *a, size_t n);

// возвращает количество раз наличия значения value
// в массиве a размера n типа int.
int countValues_(const int *a, size_t n, int value);

// возвращает значение 'истина', если массив a1 размера n1 типа int
// и массив a2 размера n2 равны, в противном случае - 'ложь'.
bool areEqualArrays_(const int *const a1, const size_t n1,
                     const int *const a2, const size_t n2);

// возвращает значение 'истина', если массив a размера n типа int
// содержит элемент с положительным значением, в противном случае - 'ложь'
bool hasArrayPositiveElement_(const int *const a, const size_t n);

#endif