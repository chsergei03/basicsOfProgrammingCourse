#ifndef INC_SORTING_TIME_COMPLEXITY_H
#define INC_SORTING_TIME_COMPLEXITY_H

#include <stddef.h>
#include <stdbool.h>

#include "../algorithms/array/array.h"
#include "array_generators/array_generators.h"
#include "../algorithms/array_sortings/bubble_sort.h"
#include "../algorithms/array_sortings/selection_sort.h"
#include "../algorithms/array_sortings/count_sort.h"
#include "../algorithms/array_sortings/insertion_sort.h"
#include "../algorithms/array_sortings/comb_sort.h"
#include "../algorithms/array_sortings/shell_sort.h"
#include "../algorithms/array_sortings/digit_sort.h"
#include "comparisons_count/comparisons_count.h"

// структура 'функция сортировки'.
typedef struct sortFunc {
    void (*sort)(int *a, size_t n); // указатель на функцию сортировки.
    char name[64];                  // имя сортировки, используемое при выводе.
} sortFunc;

// структура 'функция сортировки c расчетом количества
// операций сравнения'.
typedef struct sortFunc_compCount {
    long long (*sort)(int *a, size_t n); // указатель на функцию сортировки.
    char name[64];                       // имя сортировки, используемое при выводе.
} sortFunc_compCount;

// структура 'функция-генератор'.
typedef struct generateFunc {
    void (*generate)(int *a, size_t n); // указатель на функцию генерации последовательности.
    char name[64];                      // имя генератора, используемое при выводе.
} generateFunc;

// записывает в текстовые файлы с расширением .csv результаты
// замеров времени выполнения сортировок целочисленных массивов.
void checkTime(void (*sort)(int *, size_t),
               void (*generate)(int *, size_t),
               size_t size, char *experimentName);

// производит запуск замеров времени выполнения сортировок
// целочисленных массивов
void timeExperiment();

// записывает в текстовый файл с расширением .csv результат замера количества
// операций сравнения сортировки sort целочисленных массива размера size типа int,
// сгенерированного функцией генерации массива generate.
void checkComparisonsCount(long long (*sort)(int *, size_t),
                           void (*generate)(int *, size_t),
                           const size_t size, char *experimentName);

// производит запуск замеров количества операций сравнения сортировок
// целочисленных массивов.
void comparisonsCountExperiment();

#endif