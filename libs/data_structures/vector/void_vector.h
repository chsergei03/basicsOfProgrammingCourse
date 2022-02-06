#ifndef INC_VOID_VECTOR_H
#define INC_VOID_VECTOR_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>

typedef struct vectorVoid {
    void *data;          // указатель на нулевой элемент вектора.
    size_t size;         // размер вектора.
    size_t capacity;     // вместимость вектора.
    size_t baseTypeSize;
    // размер базового типа:
    // например, если вектор хранит int,
    // то поле baseTypeSize = sizeof(int);
    // если вектор хранит float, то поле
    // baseTypeSize = sizeof(float).
} vectorVoid;

// выводит в поток ошибок сообщение о том, что операционная
// система не может предоставить нужный объем памяти под
// размещение динамического массива, при этом выполнение программы
// заканчивается с кодом 1.
void isIncorrectMemoryAllocVoid(const int *data,
                                size_t capacity) {
    if (capacity > 0 && data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

// возвращает структуру-дескриптор вектора произвольного типа
// из n значений (baseTypeSize - размер этого произвольного типа).
vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    int *data = NULL;
    if (n > 0)
        data = malloc(n * baseTypeSize);

    isIncorrectMemoryAllocVoid(data, n);

    return (vectorVoid) {data, 0, n, baseTypeSize};
}

// возвращает вектор произвольного типа c вместимостью
// capacity, состоящий из элементов массива a размера size
// (baseTypeSize - размер базового типа массива a).
vectorVoid createVectorVFromArray(void *a, size_t size,
                                  size_t capacity,
                                  size_t baseTypeSize) {
    char *data = (char *) malloc(size * baseTypeSize);
    memcpy(data, a, size * baseTypeSize);

    return (vectorVoid) {data, size, capacity, baseTypeSize};
}

// возвращает значение 'истина', если векторы v1 и v2
// произвольного типа идентичны, в противном случае - 'ложь'.
bool isIdenticalVoidVectors(vectorVoid v1,
                            vectorVoid v2) {
    if (v1.size != v2.size || v1.capacity != v2.capacity ||
        v1.baseTypeSize != v2.baseTypeSize)
        return false;

    return memcmp(v1.data, v2.data, v1.size * v1.baseTypeSize) == 0;
}

// изменяет количество памяти, выделенное под хранение
// элементов вектора v произвольного типа (вместимость
// вектора при этом принимает значение newCapacity).
void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else
        v->data = realloc(v->data, newCapacity * v->baseTypeSize);

    isIncorrectMemoryAllocVoid(v->data, newCapacity);

    if (newCapacity < v->size)
        v->size = newCapacity;

    v->capacity = newCapacity;
}

// удаляет элементы из контейнера вектора v произвольного
// типа без освобождения выделенной памяти.
void clearV(vectorVoid *v) {
    v->size = 0;
}

// освобождает память, выделенную под неиспользуемые
// элементы вектора v произвольного типа.
void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

// освобождает память, выделенную вектору v произвольного типа.
void deleteVectorV(vectorVoid *v) {
    free(v->data);
}

#endif