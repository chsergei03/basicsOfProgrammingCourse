#ifndef INC_UNORDERED_ARRAY_SET_H
#define INC_UNORDERED_ARRAY_SET_H

#include <stddef.h>
#include <stdbool.h>

#include "../../../libs/algorithms/array/array.h"
#include "../../../libs/algorithms/algorithm.h"

typedef struct unordered_array_set {
    int *data; // элементы множества.
    size_t size; // количество элементов в множестве.
    size_t capacity; // максимальное количество элементов в множестве.
} unordered_array_set;

// возвращает пустое множество для capacity элементов.
unordered_array_set unordered_array_set_create(size_t capacity);

// возвращает множество, состоящее из элементов массива a размера size.
unordered_array_set unordered_array_set_create_from_array(const int *a,
                                                          size_t size);

// возвращает позицию элемента в множестве, если значение value
// имеется в множестве set, иначе - n.
size_t unordered_array_set_in(const unordered_array_set *set,
                              int value);

// возвращает значение ’истина’, если элементы множеств set1
// и set2 равны, иначе - ’ложь’.
bool unordered_array_set_isEqual(unordered_array_set set1,
                                 unordered_array_set set2);

// возвращает значение ’истина’, если subset является подмножеством
// set, иначе - ’ложь’.
bool unordered_array_set_isSubset(unordered_array_set subset,
                                  unordered_array_set set);

// возбуждает исключение, если в множество по адресу set нельзя вставить
// элемент.
void unordered_array_set_isAbleAppend(const unordered_array_set *set);

// добавляет элемент value в множество set.
void unordered_array_set_insert(unordered_array_set *set, int value);

// удаляет элемент value из множества set.
void unordered_array_set_deleteElement(unordered_array_set *set, int value);

// возвращает объединение множеств set1 и set2.
unordered_array_set unordered_array_set_union(unordered_array_set set1,
                                              unordered_array_set set2);

// возвращает пересечение множеств set1 и set2.
unordered_array_set unordered_array_set_intersection(unordered_array_set set1,
                                                     unordered_array_set set2);

// возвращает разность множеств set1 и set2.
unordered_array_set unordered_array_set_difference(unordered_array_set set1,
                                                   unordered_array_set set2);

// возвращает симметрическую разность множеств set1 и set2.
unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1,
                                                            unordered_array_set set2);

// возвращает дополнение до универсума множества set.
unordered_array_set unordered_array_set_complement(unordered_array_set set,
                                                   unordered_array_set universumSet);

// выводит множество set.
void unordered_array_set_print(unordered_array_set set);

// освобождает память, занимаемую множеством set.
void unordered_array_set_delete(unordered_array_set set);

#endif