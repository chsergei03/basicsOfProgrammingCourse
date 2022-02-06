#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

#include "vector.h"

void isIncorrectMemoryAlloc(const int *data,
                            const size_t capacity) {
    if (capacity > 0 && data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

vector createVector(const size_t n) {
    int *data = NULL;
    if (n > 0)
        data = (int *) malloc(n * sizeof(int));

    isIncorrectMemoryAlloc(data, n);

    return (vector) {data, 0, n};
}

vector createVectorFromArray(const int *a,
                             const size_t size,
                             const size_t capacity) {
    vector v = createVector(capacity);
    v.size = size;
    memcpy(v.data, a, v.size * sizeof(int));

    return v;
}

bool isIdenticalVectors(const vector v1, const vector v2) {
    if (v1.size != v2.size || v1.capacity != v2.capacity)
        return false;

    qsort(v1.data, v1.size,
          sizeof(int), compare_ints);
    qsort(v2.data, v2.size,
          sizeof(int), compare_ints);

    return memcmp(v1.data, v2.data,
                  v1.size * sizeof(int)) == 0;
}

void reserve(vector *v, const size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else
        v->data = (int *) realloc(v->data,
                                  newCapacity * sizeof(int));

    isIncorrectMemoryAlloc(v->data, newCapacity);

    if (newCapacity < v->size)
        v->size = newCapacity;

    v->capacity = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}

bool isEmpty(const vector *v) {
    return v->size == 0;
}

bool isFull(const vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(const vector *v, const size_t i) {
    return v->data[i];
}

void pushBack(vector *v, const int x) {
    if (isFull(v)) {
        size_t newCapacity = v->capacity > 0 ? 2 * v->capacity : 1;
        reserve(v, newCapacity);
    }

    v->data[v->size] = x;
    v->size += 1;
}

void emptyVectorMessage() {
    fprintf(stderr, "empty vector");
    exit(1);
}

void popBack(vector *v) {
    if (isEmpty(v))
        emptyVectorMessage();

    v->size -= 1;
}

void notExistingElementMessage(const size_t index) {
    fprintf(stderr, "IndexError: a[%zu] is not exists", index);
    exit(1);
}

int *atVector(const vector *v, const size_t index) {
    if (index >= v->size)
        notExistingElementMessage(index);

    return v->data + index;
}

int *back(const vector *v) {
    size_t lastElementIndex = v->size - (v->size > 0);

    return atVector(v, lastElementIndex);
}

int *front(const vector *v) {
    return atVector(v, 0);
}