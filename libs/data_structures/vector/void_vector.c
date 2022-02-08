#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <memory.h>

#include "void_vector.h"

void isIncorrectMemoryAllocVoid(const int *data,
                                const size_t capacity) {
    if (capacity > 0 && data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

vectorVoid createVectorV(const size_t n,
                         const size_t baseTypeSize) {
    int *data = NULL;
    if (n > 0)
        data = malloc(n * baseTypeSize);

    isIncorrectMemoryAllocVoid(data, n);

    return (vectorVoid) {data, 0, n, baseTypeSize};
}

vectorVoid createVectorVFromArray(const void *a,
                                  const size_t size,
                                  const size_t capacity,
                                  const size_t baseTypeSize) {
    char *data = (char *) malloc(size * baseTypeSize);
    memcpy(data, a, size * baseTypeSize);

    return (vectorVoid) {data, size, capacity, baseTypeSize};
}

bool isIdenticalVoidVectors(const vectorVoid v1,
                            const vectorVoid v2) {
    if (v1.size != v2.size || v1.capacity != v2.capacity ||
        v1.baseTypeSize != v2.baseTypeSize)
        return false;

    return memcmp(v1.data, v2.data,
                  v1.size * v1.baseTypeSize) == 0;
}

void reserveV(vectorVoid *v, const size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else
        v->data = realloc(v->data, newCapacity * v->baseTypeSize);

    isIncorrectMemoryAllocVoid(v->data, newCapacity);

    if (newCapacity < v->size)
        v->size = newCapacity;

    v->capacity = newCapacity;
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
}

bool isEmptyV(const vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(const vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(const vectorVoid *v,
                     const size_t index,
                     void *destination) {
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v,
                     const size_t index,
                     const void *source) {
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void emptyVoidVectorMessage() {
    fprintf(stderr, "empty vector");
    exit(1);
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v))
        emptyVoidVectorMessage();

    v->size -= 1;
}

void pushBackV(vectorVoid *v, const void *source) {
    if (isFullV(v)) {
        size_t newCapacity = v->capacity > 0 ? 2 * v->capacity : 1;
        reserveV(v, newCapacity);
    }

    setVectorValueV(v, v->size, source);
    v->size += 1;
}