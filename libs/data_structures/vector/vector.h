#ifndef INC_VECTOR_H
#define INC_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct vector {
    int *data;       // указатель на элементы вектора.
    size_t size;     // размер вектора.
    size_t capacity; // вместимость вектора.
} vector;

// выводит в поток ошибок сообщение о том, что операционная
// система не может предоставить нужный объем памяти под
// размещение динамического массива, программа при этом
// заканчивается с кодом 1.
void isIncorrectMemoryAlloc(const int *data,
                            const size_t capacity) {
    if (capacity > 0 && data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

// возвращает структуру-дескриптор вектора из n значений.
vector createVector(size_t n) {
    int *data = NULL;
    if (n > 0)
        data = (int *) malloc(n * sizeof(int));

    isIncorrectMemoryAlloc(data, n);

    return (vector) {data, 0, n};
}

// возвращает вектор c вместимостью capacity,
// состоящий из элементов массива a размера size.
vector createVectorFromArray(int *a, size_t size, size_t capacity) {
    vector v = createVector(capacity);
    v.size = size;
    memcpy(v.data, a, v.size * sizeof(int));
    return v;
}

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

// возвращает значение 'истина', если векторы v1 и v2 идентичны,
// в противном случае - 'ложь'.
bool isIdenticalVectors(vector v1, vector v2) {
    if (v1.size != v2.size || v1.capacity != v2.capacity)
        return false;
    qsort(v1.data, v1.size, sizeof(int), compare_ints);
    qsort(v2.data, v2.size, sizeof(int), compare_ints);
    return memcmp(v1.data, v2.data, v1.size * sizeof(int)) == 0;
}

// изменяет количество памяти, выделенное под хранение
// элементов вектора v (вместимость вектора при этом
// принимает значение newCapacity).
void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else
        v->data = (int *) realloc(v->data, newCapacity * sizeof(int));

    isIncorrectMemoryAlloc(v->data, newCapacity);

    if (newCapacity < v->size)
        v->size = newCapacity;

    v->capacity = newCapacity;
}

// удаляет элементы из контейнера вектора v
// без освобождения выделенной памяти.
void clear(vector *v) {
    v->size = 0;
}

// освобождает память, выделенную под неиспользуемые элементы
// в векторе v.
void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

// освобождает память, выделенную вектору v.
void deleteVector(vector *v) {
    free(v->data);
}

// возвращает значение 'истина', если вектор v
// является пустым, в противном случае - 'ложь'.
bool isEmpty(vector *v) {
    return v->size == 0;
}

// возвращает значение 'истина', если вектор v
// является полным, в противном случае - 'ложь'.
bool isFull(vector *v) {
    return v->size == v->capacity;
}

// возвращает i-ый элемент вектора v.
int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

// добавляет элемент x в конец вектора v.
void pushBack(vector *v, int x) {
    if (isFull(v)) {
        size_t newCapacity = v->capacity > 0 ? 2 * v->capacity : 1;
        reserve(v, newCapacity);
    }

    v->data[v->size] = x;
    v->size += 1;
}

// выводит сообщение о том, что вектор пуст и заканчивает
// выполнение программы с кодом 1.
void emptyVectorMessage() {
    fprintf(stderr, "empty vector");
    exit(1);
}

// удаляет последний элемент из вектора v.
void popBack(vector *v) {
    if (isEmpty(v))
        emptyVectorMessage();

    v->size -= 1;
}

#endif