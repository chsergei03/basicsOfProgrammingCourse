#ifndef INC_COUNT_SORT_H
#define INC_COUNT_SORT_H

#include <stddef.h>

#include "../array/array.h"

// возвращает количество элементов в вспомогательном массиве для
// сортировки подсчетом массива a размера n типа int, записывает
// по адресу maxValue максимальный элемент массива, по адресу
// minValue - минимальный; количество находится путём вычисления
// диапазона значений между минимальным и максимальным элементами
// исходного массива, каждый элемент вспомогательного массива
// будет хранить количество появлений значения в массиве начиная
// с минимального и заканчивая максимальным.
size_t getValueAppearsCountArraySize(const int *const a, const size_t n,
                                     int *minValue, int *maxValue);

// возвращает массив количеств появлений в массиве a размера n типа int
// значений начиная с минимального значения minValue и заканчивая maxValue.
int *getValueAppearsCountArray(const int *const a, const size_t n,
                               int *minValue, int *maxValue);

// производит сортировку подсчетом по неубыванию
// массива a размера n типа int.
void countSort(int *a, size_t n);

#endif