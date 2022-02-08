#ifndef INC_VECTOR_H
#define INC_VECTOR_H

#include <stddef.h>
#include <stdbool.h>

#include "../../../libs/algorithms/algorithm.h"

typedef struct vector {
    int *data;       // указатель на элементы вектора.
    size_t size;     // размер вектора.
    size_t capacity; // вместимость вектора.
} vector;

// выводит в поток ошибок сообщение о том, что операционная
// система не может предоставить нужный объем памяти под
// размещение динамического массива, при это выполнение
// программы завершается с кодом 1.
void isIncorrectMemoryAlloc(const int *data,
                            size_t capacity);

// возвращает структуру-дескриптор вектора из n значений.
vector createVector(size_t n);

// возвращает вектор c вместимостью capacity,
// состоящий из элементов целочисленного массива
// a размера size.
vector createVectorFromArray(const int *a,
                             size_t size,
                             size_t capacity);

// возвращает значение 'истина', если векторы v1 и v2 идентичны,
// в противном случае - 'ложь'.
bool isIdenticalVectors(vector v1, vector v2);

// изменяет количество памяти, выделенное под хранение
// элементов вектора v (вместимость вектора при этом
// принимает значение newCapacity).
void reserve(vector *v, size_t newCapacity);

// удаляет элементы из контейнера вектора v
// без освобождения выделенной памяти.
void clear(vector *v);

// освобождает память, выделенную под неиспользуемые элементы
// вектора v.
void shrinkToFit(vector *v);

// освобождает память, выделенную под элементы вектора v.
void deleteVector(vector *v);

// возвращает значение 'истина', если вектор v
// является пустым, в противном случае - 'ложь'.
bool isEmpty(const vector *v);

// возвращает значение 'истина', если вектор v
// является полным, в противном случае - 'ложь'.
bool isFull(const vector *v);

// возвращает i-ый элемент вектора v.
int getVectorValue(const vector *v, size_t i);

// добавляет элемент x в конец вектора v.
void pushBack(vector *v, int x);

// выводит сообщение о том, что вектор пуст, и заканчивает
// выполнение программы с кодом 1.
void emptyVectorMessage();

// удаляет последний элемент из вектора v.
void popBack(vector *v);

// выводит сообщение о том, что элемента с индексом
// index нет в векторе, при этом выполнение программы
// завершается с кодом 1.
void notExistingElementMessage(size_t index);

// возвращает указатель на index-ый элемент вектора v.
int *atVector(const vector *v, size_t index);

// возвращает указатель на последний элемент вектора v.
int *back(const vector *v);

// возвращает указатель на нулевой элемент вектора v.
int *front(const vector *v);

#endif