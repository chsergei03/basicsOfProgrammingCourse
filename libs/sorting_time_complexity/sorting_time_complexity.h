#ifndef INC_SORTING_TIME_COMPLEXITY_H
#define INC_SORTING_TIME_COMPLEXITY_H

#include <stddef.h>
#include <stdbool.h>

#include "../algorithms/array/array.h"
#include "array_generators/array_generators.h"

// структура 'функция сортировки'.
typedef struct sortFunc {
    void (*sort)(int *a, size_t n); // указатель на функцию сортировки.
    char name[64];                  // имя сортировки, используемое при выводе.
} sortFunc;

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

#endif