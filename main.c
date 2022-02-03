#include <assert.h>
#include <malloc.h>
#include <memory.h>

#include "libs/data_structures/vector/vector.h"

void test_createVector_zeroVector() {
    size_t capacity = 0;
    vector v = createVector(capacity);
    int expectedSource[] = {};
    size_t expectedSize = 0;
    vector expectedV = createVectorFromArray(expectedSource, expectedSize, capacity);
    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_createVector_nonZeroVector() {
    size_t capacity = 10;
    vector v = createVector(capacity);
    int expectedSource[] = {};
    size_t expectedSize = 0;
    vector expectedV = createVectorFromArray(expectedSource, expectedSize, capacity);
    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_toNonZeroVector() {
    size_t capacity = 0;
    size_t newCapacity = 10;
    vector v = createVector(capacity);
    reserve(&v, newCapacity);
    int expectedSource[] = {};
    size_t expectedSize = capacity;
    vector expectedV = createVectorFromArray(expectedSource, expectedSize, newCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
}

void test_reserve_toZeroVector_equalSizeAndCapacity() {
    int source[] = {3, 5, 7};
    size_t size = 3;
    size_t capacity = size;
    size_t newCapacity = 0;
    vector v = createVectorFromArray(source, size, capacity);
    reserve(&v, newCapacity);
    int expectedSource[] = {};
    size_t expectedSize = 0;
    vector expectedV = createVectorFromArray(expectedSource, expectedSize, newCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_toZeroVector_notEqualSizeAndCapacity() {
    int source[] = {7, 8, 9, 10};
    size_t size = 4;
    size_t capacity = 5;
    size_t newCapacity = 0;
    vector v = createVectorFromArray(source, size, capacity);
    reserve(&v, newCapacity);
    int expectedSource[] = {};
    size_t expectedSize = 0;
    vector expectedV = createVectorFromArray(expectedSource, expectedSize, newCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_expandedEmptyNonZeroVector() {
    size_t capacity = 0;
    size_t newCapacity = 10;
    vector v = createVector(capacity);
    reserve(&v, newCapacity);
    vector expectedV = createVector(newCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_expandedFilledNonZeroVector_equalSizeAndCapacity() {
    int source[] = {3, 6, 9};
    size_t size = 3;
    size_t capacity = size;
    size_t newCapacity = 5;
    vector v = createVectorFromArray(source, size, capacity);
    reserve(&v, newCapacity);
    vector expectedV = createVectorFromArray(source, size, newCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_expandedFilledNonZeroVector_notEqualSizeAndCapacity() {
    int source[] = {3, 6, 9};
    size_t size = 3;
    size_t capacity = 5;
    size_t newCapacity = 10;
    vector v = createVectorFromArray(source, size, capacity);
    reserve(&v, newCapacity);
    vector expectedV = createVectorFromArray(source, size, newCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
}

void test_reserve_reducedFilledNonZeroVector_equalSizeAndCapacity() {
    int source[] = {1, 2, 3, 4, 5};
    size_t size = 5;
    size_t capacity = size;
    size_t newCapacity = 3;
    vector v = createVectorFromArray(source, size, capacity);
    reserve(&v, newCapacity);
    int expectedSource[] = {1, 2, 3};
    size_t expectedSize = newCapacity;
    vector expectedV = createVectorFromArray(expectedSource, expectedSize, newCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_reserve_reducedFilledNonZeroVector_notEqualSizeAndCapacity() {
    int source[] = {4, 6, 8, 10, 12, 14};
    size_t size = 6;
    size_t capacity = 10;
    size_t newCapacity = 4;
    vector v = createVectorFromArray(source, size, capacity);
    reserve(&v, newCapacity);
    int expectedSource[] = {4, 6, 8, 10};
    size_t expectedSize = newCapacity;
    vector expectedV = createVectorFromArray(expectedSource, expectedSize, newCapacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_clear_clearedZeroVector() {
    size_t capacity = 0;
    vector v = createVector(capacity);
    clear(&v);
    int expectedSource[] = {};
    size_t expectedSize = 0;
    vector expectedV = createVectorFromArray(expectedSource, expectedSize, capacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_clear_clearedEmptyNonZeroVector() {
    size_t capacity = 10;
    vector v = createVector(capacity);
    clear(&v);
    int expectedSource[] = {};
    size_t expectedSize = 0;
    vector expectedV = createVectorFromArray(expectedSource, expectedSize, capacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_clear_clearedFilledNonZeroVector() {
    int source[] = {5, 7, 6};
    size_t size = 3;
    size_t capacity = size;
    vector v = createVectorFromArray(source, size, capacity);
    clear(&v);
    size_t expectedSize = 0;
    vector expectedV = createVectorFromArray(source, expectedSize, capacity);

    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_shrinkToFit_zeroVector() {
    size_t capacity = 0;
    vector v = createVector(capacity);
    shrinkToFit(&v);
    size_t expectedCapacity = 0;
    vector expectedV = createVector(expectedCapacity);
    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_shrinkToFit_emptyNonZeroVector() {
    size_t capacity = 4;
    vector v = createVector(capacity);
    shrinkToFit(&v);
    size_t expectedCapacity = 0;
    vector expectedV = createVector(expectedCapacity);
    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_shrinkToFit_filledNonZeroVector_equalSizeAndCapacity() {
    int source[] = {4, 8, 9};
    size_t size = 3;
    size_t capacity = 8;
    vector v = createVectorFromArray(source, size, capacity);
    shrinkToFit(&v);
    size_t expectedCapacity = size;
    vector expectedV = createVectorFromArray(source, size, expectedCapacity);
    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test_shrinkToFit_filledNonZeroVector_notEqualSizeAndCapacity() {
    int source[] = {4, 8, 9};
    size_t size = 3;
    size_t capacity = 8;
    vector v = createVectorFromArray(source, size, capacity);
    shrinkToFit(&v);
    size_t expectedCapacity = size;
    vector expectedV = createVectorFromArray(source, size, expectedCapacity);
    assert(isIdenticalVectors(v, expectedV));

    deleteVector(&v);
    deleteVector(&expectedV);
}

void test() {
    test_createVector_zeroVector();
    test_createVector_nonZeroVector();
    test_reserve_toNonZeroVector();
    test_reserve_toZeroVector_equalSizeAndCapacity();
    test_reserve_toZeroVector_notEqualSizeAndCapacity();
    test_reserve_expandedEmptyNonZeroVector();
    test_reserve_expandedFilledNonZeroVector_equalSizeAndCapacity();
    test_reserve_expandedFilledNonZeroVector_notEqualSizeAndCapacity();
    test_reserve_reducedFilledNonZeroVector_equalSizeAndCapacity();
    test_reserve_reducedFilledNonZeroVector_notEqualSizeAndCapacity();
    test_clear_clearedZeroVector();
    test_clear_clearedEmptyNonZeroVector();
    test_clear_clearedFilledNonZeroVector();
    test_shrinkToFit_zeroVector();
    test_shrinkToFit_emptyNonZeroVector();
    test_shrinkToFit_filledNonZeroVector_equalSizeAndCapacity();
    test_shrinkToFit_filledNonZeroVector_notEqualSizeAndCapacity();
}

int main() {
    test();

    return 0;
}