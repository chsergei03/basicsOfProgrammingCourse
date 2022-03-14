#ifndef INC_DIGIT_SORT_H
#define INC_DIGIT_SORT_H

#include <stddef.h>

#include "countSort.h"
#include "../array/array.h"

// возвращает значение байта с индексом bytePosFromEnd
// целого числа number (индекс отсчитывается с конца числа,
// первый с конца байт имеет индекс 0).
int getCurrentByte(const int number,
                   const size_t bytePosFromEnd);

// возвращает значение 1, если целое значение value не
// превышает значение 0, в противном случае - значение 0.
int isNotPositiveValue(const int value);

// записывает в массив byteValuesArray значения байтов
// с индексом bytePosFromEnd элементов массива a размера n
// типа int, если все значения байтов нулевые, записывает
// по адресу isAnyPositiveCurrentByte значение 'ложь'.
void getCurrentByteValues(const int *const a,
                          const size_t n,
                          const size_t bytePosFromTheEnd,
                          int *const byteValuesArray,
                          bool *isAnyPositiveCurrentByte);

// возвращает позицию первого элемента, байт с индексом bytePosFromEnd (индекс
// отсчитывается с конца числа, первый с конца байт имеет индекс 0) которого
// равен byteValue, в массиве a размера n типа int при его наличии, иначе - n
// (поиск в массиве a ведётся начинается с позиции pos), если элемент найден,
// записывает по адресу pos следующую позицию после позиции найденного элемента
// для последующего поиска.
size_t linearSearchFromPos_searchNumberWithByteValue_int_(const int *const a,
                                                          const size_t n,
                                                          size_t *pos,
                                                          const size_t bytePosFromEnd,
                                                          const int byteValue);

// производит цифровую сортировку по неубыванию
// массива a размера n типа int.
void digitSort(int *a, size_t n);

#endif