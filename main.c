#include <assert.h>

#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/void_vector.h"

void test_createVector_zeroVector() {
    size_t capacity = 0;
    vector v = createVector(capacity);
    int expectedSource[] = {};
    size_t expectedSize = capacity;
    size_t expectedCapacity = expectedSize;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_createVector_emptyVector() {
    size_t capacity = 10;
    vector v = createVector(capacity);
    int expectedSource[] = {};
    size_t expectedSize = 0;
    size_t expectedCapacity = capacity;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_toEmptyVector() {
    size_t capacity = 0;
    size_t newCapacity = 10;
    vector v = createVector(capacity);
    reserve(&v, newCapacity);
    int expectedSource[] = {};
    size_t expectedSize = capacity;
    size_t expectedCapacity = newCapacity;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_toZeroVector_emptyVector() {
    size_t capacity = 7;
    size_t newCapacity = 0;
    vector v = createVector(capacity);
    reserve(&v, newCapacity);
    int expectedSource[] = {};
    size_t expectedSize = newCapacity;
    size_t expectedCapacity = expectedSize;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_toZeroVector_filledVector() {
    int source[] = {7, 8, 9, 10};
    size_t size = 4;
    size_t capacity = 5;
    size_t newCapacity = 0;
    vector v = createVectorFromArray(source, size, capacity);
    reserve(&v, newCapacity);
    int expectedSource[] = {};
    size_t expectedSize = newCapacity;
    size_t expectedCapacity = expectedSize;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_toZeroVector_fullVector() {
    int source[] = {3, 5, 7};
    size_t size = 3;
    size_t capacity = size;
    size_t newCapacity = 0;
    vector v = createVectorFromArray(source, size, capacity);
    reserve(&v, newCapacity);
    int expectedSource[] = {};
    size_t expectedSize = newCapacity;
    size_t expectedCapacity = expectedSize;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_expandedEmptyVector() {
    size_t capacity = 5;
    size_t newCapacity = 10;
    vector v = createVector(capacity);
    reserve(&v, newCapacity);
    int expectedSource[] = {};
    size_t expectedSize = 0;
    size_t expectedCapacity = newCapacity;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_expandedFilledVector() {
    int source[] = {3, 6, 9};
    size_t size = 3;
    size_t capacity = 5;
    size_t newCapacity = 10;
    vector v = createVectorFromArray(source, size, capacity);
    reserve(&v, newCapacity);
    size_t expectedSize = size;
    size_t expectedCapacity = newCapacity;
    vector expectedV = createVectorFromArray(source,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_expandedFullVector() {
    int source[] = {3, 6, 9};
    size_t size = 3;
    size_t capacity = size;
    size_t newCapacity = 5;
    vector v = createVectorFromArray(source, size, capacity);
    reserve(&v, newCapacity);
    size_t expectedSize = size;
    size_t expectedCapacity = newCapacity;
    vector expectedV = createVectorFromArray(source,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_reducedEmptyVector() {
    size_t capacity = 10;
    size_t newCapacity = 5;
    vector v = createVector(capacity);
    reserve(&v, newCapacity);
    int expectedSource[] = {};
    size_t expectedSize = 0;
    size_t expectedCapacity = newCapacity;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_reducedFilledVector_newCapacityLessThanSize() {
    int source[] = {4, 6, 8, 10, 12, 14};
    size_t size = 6;
    size_t capacity = 10;
    size_t newCapacity = 4;
    vector v = createVectorFromArray(source, size, capacity);
    reserve(&v, newCapacity);
    int expectedSource[] = {4, 6, 8, 10};
    size_t expectedSize = newCapacity;
    size_t expectedCapacity = expectedSize;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_reducedFilledVector_newCapacityMoreThanSize() {
    int source[] = {4, 6, 8, 10, 12, 14};
    size_t size = 6;
    size_t capacity = 10;
    size_t newCapacity = 8;
    vector v = createVectorFromArray(source, size, capacity);
    reserve(&v, newCapacity);
    int expectedSource[] = {4, 6, 8, 10, 12, 14};
    size_t expectedSize = size;
    size_t expectedCapacity = newCapacity;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_reducedFullVector() {
    int source[] = {1, 2, 3, 4, 5};
    size_t size = 5;
    size_t capacity = size;
    size_t newCapacity = 3;
    vector v = createVectorFromArray(source, size, capacity);
    reserve(&v, newCapacity);
    int expectedSource[] = {1, 2, 3};
    size_t expectedSize = newCapacity;
    size_t expectedCapacity = expectedSize;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_clear_clearedZeroVector() {
    size_t capacity = 0;
    vector v = createVector(capacity);
    clear(&v);
    int expectedSource[] = {};
    size_t expectedSize = capacity;
    size_t expectedCapacity = expectedSize;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_clear_clearedEmptyVector() {
    size_t capacity = 10;
    vector v = createVector(capacity);
    clear(&v);
    int expectedSource[] = {};
    size_t expectedSize = 0;
    size_t expectedCapacity = capacity;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_clear_clearedFilledVector() {
    int source[] = {8, 9, 10};
    size_t size = 3;
    size_t capacity = 5;
    vector v = createVectorFromArray(source, size, capacity);
    clear(&v);
    size_t expectedSize = 0;
    size_t expectedCapacity = capacity;
    vector expectedV = createVectorFromArray(source,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_clear_clearedFullVector() {
    int source[] = {5, 7, 6};
    size_t size = 3;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);
    clear(&v);
    size_t expectedSize = 0;
    size_t expectedCapacity = capacity;
    vector expectedV = createVectorFromArray(source,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_shrinkToFit_zeroVector() {
    size_t capacity = 0;
    vector v = createVector(capacity);
    shrinkToFit(&v);
    int expectedSource[] = {};
    size_t expectedSize = capacity;
    size_t expectedCapacity = expectedSize;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_shrinkToFit_emptyVector() {
    size_t capacity = 4;
    vector v = createVector(capacity);
    shrinkToFit(&v);
    int expectedSource[] = {};
    size_t expectedSize = 0;
    size_t expectedCapacity = expectedSize;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_shrinkToFit_filledVector() {
    int source[] = {4, 8, 9};
    size_t size = 3;
    size_t capacity = 8;
    vector v = createVectorFromArray(source, size, capacity);
    shrinkToFit(&v);
    size_t expectedSize = size;
    size_t expectedCapacity = expectedSize;
    vector expectedV = createVectorFromArray(source,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_shrinkToFit_fullVector() {
    int source[] = {4, 8, 9};
    size_t size = 3;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);
    shrinkToFit(&v);
    size_t expectedSize = size;
    size_t expectedCapacity = expectedSize;
    vector expectedV = createVectorFromArray(source,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_isEmpty_zeroVector() {
    size_t capacity = 0;
    vector v = createVector(capacity);

    assert(isEmpty(&v));

    deleteVector(&v);
}

void test_isEmpty_emptyVector() {
    size_t capacity = 5;
    vector v = createVector(capacity);

    assert(isEmpty(&v));

    deleteVector(&v);
}

void test_isEmpty_filledVector() {
    int source[] = {5, 4, 3};
    size_t size = 3;
    size_t capacity = 5;
    vector v = createVectorFromArray(source, size, capacity);

    assert(!isEmpty(&v));

    deleteVector(&v);
}

void test_isEmpty_fullVector() {
    int source[] = {7, 6, 8};
    size_t size = 3;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);

    assert(!isEmpty(&v));

    deleteVector(&v);
}

void test_isFull_zeroVector() {
    size_t capacity = 0;
    vector v = createVector(capacity);

    assert(isFull(&v));

    deleteVector(&v);
}

void test_isFull_emptyVector() {
    size_t capacity = 5;
    vector v = createVector(capacity);

    assert(!isFull(&v));

    deleteVector(&v);
}

void test_isFull_filledVector() {
    int source[] = {4, 1, 9, 15};
    size_t size = 4;
    size_t capacity = 8;
    vector v = createVectorFromArray(source, size, capacity);

    assert(!isFull(&v));

    deleteVector(&v);
}

void test_isFull_fullVector() {
    int source[] = {1, 2, 3};
    size_t size = 3;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);

    assert(isFull(&v));

    deleteVector(&v);
}

void test_getVectorValue_filledVector() {
    int source[] = {3, 2, 1};
    size_t size = 3;
    size_t capacity = 5;
    vector v = createVectorFromArray(source, size, capacity);
    size_t pos = 1;
    int expectedValue = source[pos];
    int value = getVectorValue(&v, pos);

    assert(value == expectedValue);

    deleteVector(&v);
}

void test_getVectorValue_filledVector_firstElement() {
    int source[] = {7, 5, 8, 9};
    size_t size = 4;
    size_t capacity = 10;
    vector v = createVectorFromArray(source, size, capacity);
    size_t pos = 0;
    int expectedValue = source[pos];
    int value = getVectorValue(&v, pos);

    assert(value == expectedValue);

    deleteVector(&v);
}

void test_getVectorValue_filledVector_lastElement() {
    int source[] = {9, 6, 3};
    size_t size = 3;
    size_t capacity = 8;
    vector v = createVectorFromArray(source, size, capacity);
    size_t pos = size - 1;
    int expectedValue = source[pos];
    int value = getVectorValue(&v, pos);

    assert(value == expectedValue);

    deleteVector(&v);
}

void test_getVectorValue_fullVector() {
    int source[] = {1, 2, 3};
    size_t size = 3;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);
    size_t pos = 1;
    int expectedValue = source[pos];
    int value = getVectorValue(&v, pos);

    assert(value == expectedValue);

    deleteVector(&v);
}


void test_getVectorValue_fullVector_firstElement() {
    int source[] = {6, 14, 8, 7};
    size_t size = 4;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);
    size_t pos = 0;
    int expectedValue = source[pos];
    int value = getVectorValue(&v, pos);

    assert(value == expectedValue);

    deleteVector(&v);
}

void test_getVectorValue_fullVector_lastElement() {
    int source[] = {1, 2, 3};
    size_t size = 3;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);
    size_t pos = size - 1;
    int expectedValue = source[pos];
    int value = getVectorValue(&v, pos);

    assert(value == expectedValue);

    deleteVector(&v);
}

void test_pushBack_zeroVector() {
    size_t capacity = 0;
    vector v = createVector(capacity);
    int x = 4;
    pushBack(&v, x);
    int expectedSource[] = {4};
    size_t expectedSize = 1;
    size_t expectedCapacity = expectedSize;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_pushBack_emptyVector() {
    size_t capacity = 4;
    vector v = createVector(capacity);
    int x = 15;
    pushBack(&v, x);
    int expectedSource[] = {15};
    size_t expectedSize = 1;
    size_t expectedCapacity = capacity;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_pushBack_filledVector() {
    int source[] = {1, 2, 3};
    size_t size = 3;
    size_t capacity = 5;
    vector v = createVectorFromArray(source, size, capacity);
    int x = 4;
    pushBack(&v, x);
    int expectedSource[] = {1, 2, 3, 4};
    size_t expectedSize = 4;
    size_t expectedCapacity = capacity;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_pushBack_fullVector() {
    int source[] = {4, 6, 8, 10};
    size_t size = 4;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);
    int x = 12;
    pushBack(&v, x);
    int expectedSource[] = {4, 6, 8, 10, 12};
    size_t expectedSize = 5;
    size_t expectedCapacity = 2 * capacity;
    vector expectedV = createVectorFromArray(expectedSource,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_popBack_filledVector() {
    int source[] = {4, 5, 6};
    size_t size = 3;
    size_t capacity = 5;
    vector v = createVectorFromArray(source, size, capacity);
    popBack(&v);
    size_t expectedSize = 2;
    size_t expectedCapacity = capacity;
    vector expectedV = createVectorFromArray(source,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_popBack_filledVector_oneElementInVector() {
    int source[] = {4};
    size_t size = 1;
    size_t capacity = 2;
    vector v = createVectorFromArray(source, size, capacity);
    popBack(&v);
    size_t expectedSize = 0;
    size_t expectedCapacity = capacity;
    vector expectedV = createVectorFromArray(source,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_popBack_fullVector() {
    int source[] = {15, 6, 7};
    size_t size = 3;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);
    popBack(&v);
    size_t expectedSize = 2;
    size_t expectedCapacity = capacity;
    vector expectedV = createVectorFromArray(source,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_popBack_fullVector_oneElementInVector() {
    int source[] = {15};
    size_t size = 1;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);
    popBack(&v);
    size_t expectedSize = 0;
    size_t expectedCapacity = capacity;
    vector expectedV = createVectorFromArray(source,
                                             expectedSize,
                                             expectedCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_atVector_filledVector() {
    int source[] = {3, 5, 7, 9};
    size_t size = 4;
    size_t capacity = 5;
    vector v = createVectorFromArray(source, size, capacity);
    size_t index = 2;
    int *pointer = atVector(&v, index);
    int *expectedPointer = &v.data[index];

    assert(pointer == expectedPointer);

    deleteVector(&v);
}

void test_atVector_filledVector_firstElement() {
    int source[] = {5, 8, 9, 4};
    size_t size = 4;
    size_t capacity = 15;
    vector v = createVectorFromArray(source, size, capacity);
    size_t index = 0;
    int *pointer = atVector(&v, index);
    int *expectedPointer = v.data;

    assert(pointer == expectedPointer);

    deleteVector(&v);
}

void test_atVector_filledVector_lastElement() {
    int source[] = {1, 5, 6, 20, 3};
    size_t size = 5;
    size_t capacity = 7;
    vector v = createVectorFromArray(source, size, capacity);
    size_t index = size - 1;
    int *pointer = atVector(&v, index);
    int *expectedPointer = &v.data[index];

    assert(pointer == expectedPointer);

    deleteVector(&v);
}

void test_atVector_fullVector() {
    int source[] = {1, 7, 13};
    size_t size = 3;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);
    size_t index = 1;
    int *pointer = atVector(&v, index);
    int *expectedPointer = &v.data[index];

    assert(pointer == expectedPointer);

    deleteVector(&v);
}

void test_atVector_fullVector_firstElement() {
    int source[] = {9, 3, 12};
    size_t size = 3;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);
    size_t index = 0;
    int *pointer = atVector(&v, index);
    int *expectedPointer = v.data;

    assert(pointer == expectedPointer);

    deleteVector(&v);
}

void test_atVector_fullVector_lastElement() {
    int source[] = {4, 12, 7, 2};
    size_t size = 4;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);
    size_t index = size - 1;
    int *pointer = atVector(&v, index);
    int *expectedPointer = &v.data[index];

    assert(pointer == expectedPointer);

    deleteVector(&v);
}

void test_back_filledVector() {
    int source[] = {1, 2, 3};
    size_t size = 3;
    size_t capacity = 5;
    vector v = createVectorFromArray(source, size, capacity);
    int *pointer = back(&v);
    int *expectedPointer = &v.data[v.size - 1];

    assert(pointer == expectedPointer);

    deleteVector(&v);
}

void test_back_filledVector_oneElementInVector() {
    int source[] = {25};
    size_t size = 1;
    size_t capacity = 3;
    vector v = createVectorFromArray(source, size, capacity);
    int *pointer = back(&v);
    int *expectedPointer = &v.data[v.size - 1];

    assert(pointer == expectedPointer);

    deleteVector(&v);
}

void test_back_fullVector() {
    int source[] = {5, 3, 1};
    size_t size = 3;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);
    int *pointer = back(&v);
    int *expectedPointer = &v.data[v.size - 1];

    assert(pointer == expectedPointer);

    deleteVector(&v);
}

void test_back_fullVector_oneElementInVector() {
    int source[] = {75};
    size_t size = 1;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);
    int *pointer = back(&v);
    int *expectedPointer = &v.data[v.size - 1];

    assert(pointer == expectedPointer);

    deleteVector(&v);
}

void test_front_filledVector() {
    int source[] = {3, 5, 6};
    size_t size = 3;
    size_t capacity = 6;
    vector v = createVectorFromArray(source, size, capacity);
    int *pointer = front(&v);
    int *expectedPointer = v.data;

    assert(pointer == expectedPointer);

    deleteVector(&v);
}

void test_front_filledVector_oneElementInVector() {
    int source[] = {7};
    size_t size = 1;
    size_t capacity = 5;
    vector v = createVectorFromArray(source, size, capacity);
    int *pointer = front(&v);
    int *expectedPointer = v.data;

    assert(pointer == expectedPointer);

    deleteVector(&v);
}

void test_front_fullVector() {
    int source[] = {4, 9, 13};
    size_t size = 3;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);
    int *pointer = front(&v);
    int *expectedPointer = v.data;

    assert(pointer == expectedPointer);

    deleteVector(&v);
}

void test_front_fullVector_oneElementInVector() {
    int source[] = {256};
    size_t size = 1;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);
    int *pointer = front(&v);
    int *expectedPointer = v.data;

    assert(pointer == expectedPointer);

    deleteVector(&v);
}

void test() {
    test_createVector_zeroVector();
    test_createVector_emptyVector();

    test_reserve_toEmptyVector();
    test_reserve_toZeroVector_emptyVector();
    test_reserve_toZeroVector_filledVector();
    test_reserve_toZeroVector_fullVector();
    test_reserve_expandedEmptyVector();
    test_reserve_expandedFilledVector();
    test_reserve_expandedFullVector();
    test_reserve_reducedEmptyVector();
    test_reserve_reducedFilledVector_newCapacityLessThanSize();
    test_reserve_reducedFilledVector_newCapacityMoreThanSize();
    test_reserve_reducedFullVector();

    test_clear_clearedZeroVector();
    test_clear_clearedEmptyVector();
    test_clear_clearedFilledVector();
    test_clear_clearedFullVector();

    test_shrinkToFit_zeroVector();
    test_shrinkToFit_emptyVector();
    test_shrinkToFit_fullVector();
    test_shrinkToFit_filledVector();

    test_isEmpty_zeroVector();
    test_isEmpty_emptyVector();
    test_isEmpty_filledVector();
    test_isEmpty_fullVector();

    test_isFull_zeroVector();
    test_isFull_emptyVector();
    test_isFull_filledVector();
    test_isFull_fullVector();

    test_getVectorValue_filledVector();
    test_getVectorValue_filledVector_firstElement();
    test_getVectorValue_filledVector_lastElement();
    test_getVectorValue_fullVector();
    test_getVectorValue_fullVector_firstElement();
    test_getVectorValue_fullVector_lastElement();

    test_pushBack_zeroVector();
    test_pushBack_emptyVector();
    test_pushBack_filledVector();
    test_pushBack_fullVector();

    test_popBack_filledVector();
    test_popBack_filledVector_oneElementInVector();
    test_popBack_fullVector();
    test_popBack_fullVector_oneElementInVector();

    test_atVector_filledVector();
    test_atVector_filledVector_firstElement();
    test_atVector_filledVector_lastElement();
    test_atVector_fullVector();
    test_atVector_fullVector_firstElement();
    test_atVector_fullVector_lastElement();

    test_back_filledVector();
    test_back_filledVector_oneElementInVector();
    test_back_fullVector();
    test_back_fullVector_oneElementInVector();

    test_front_filledVector();
    test_front_filledVector_oneElementInVector();
    test_front_fullVector();
    test_front_fullVector_oneElementInVector();
}

int main() {
    test();

    vectorVoid v = {(int[]) {}, 0, 0, sizeof(int)};

    return 0;
}