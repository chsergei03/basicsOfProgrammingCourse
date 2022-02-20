#include <assert.h>

#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix/tasks_matrix.h"

void test_swapRows_squareMatrix() {
    int source[] = {1, 2, 3,
                    4, 5, 6,
                    7, 8, 9};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    swapRows(&m, 0, 2);
    int expectedSource[] = {7, 8, 9,
                            4, 5, 6,
                            1, 2, 3};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_swapRows_rowsMoreThanCols() {
    int source[] = {15, 3, 37,
                    4, 19, 6,
                    5, 25, 8,
                    1, 12, 2};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    swapRows(&m, 1, 2);
    int expectedSource[] = {15, 3, 37,
                            5, 25, 8,
                            4, 19, 6,
                            1, 12, 2};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_swapRows_colsMoreThanRows() {
    int source[] = {2, 0, -1, 7,
                    4, -5, 3, 18,
                    0, 1, 1, 9};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    swapRows(&m, 1, 2);
    int expectedSource[] = {2, 0, -1, 7,
                            0, 1, 1, 9,
                            4, -5, 3, 18};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}


void test_swapRows() {
    test_swapRows_squareMatrix();
    test_swapRows_rowsMoreThanCols();
    test_swapRows_colsMoreThanRows();
}

void test_swapCols_squareMatrix() {
    int source[] = {1, 7, 13,
                    3, 9, 15,
                    5, 11, 17};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    swapCols(&m, 1, 2);
    int expectedSource[] = {1, 13, 7,
                            3, 15, 9,
                            5, 17, 11};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_swapCols_rowsMoreThanCols() {
    int source[] = {1, 0,
                    2, 3,
                    9, 6};
    size_t nRows = 2;
    size_t nCols = 2;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    swapCols(&m, 0, 1);
    int expectedSource[] = {0, 1,
                            3, 2};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_swapCols_colsMoreThanRows() {
    int source[] = {2, 7, 4, 15, 3,
                    6, 29, 55, 0, 1,
                    35, 11, 9, 17, 56};
    size_t nRows = 3;
    size_t nCols = 5;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    swapCols(&m, 2, 3);
    int expectedSource[] = {2, 7, 15, 4, 3,
                            6, 29, 0, 55, 1,
                            35, 11, 17, 9, 56};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_swapCols() {
    test_swapCols_squareMatrix();
    test_swapCols_rowsMoreThanCols();
    test_swapCols_colsMoreThanRows();
}

void test_selectionSortRowsMatrixByRowCriteria_squareMatrix() {
    int source[] = {2, 4, 6,
                    1, 3, 5,
                    1, 2, 3};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortRowsMatrixByRowCriteria(&m,
                                         (int (*)(int *, size_t)) getSum_);
    int expectedSource[] = {1, 2, 3,
                            1, 3, 5,
                            2, 4, 6};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortRowsMatrixByRowCriteria_rowsMoreThanCols() {
    int source[] = {5, 1,
                    6, 15,
                    -2, 0,
                    0, 1,
                    9, 3};
    size_t nRows = 5;
    size_t nCols = 2;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortRowsMatrixByRowCriteria(&m,
                                         (int (*)(int *, size_t)) getSum_);
    int expectedSource[] = {-2, 0,
                            0, 1,
                            5, 1,
                            9, 3,
                            6, 15};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortRowsMatrixByRowCriteria_colsMoreThanRows() {
    int source[] = {-1, 7, 4, 0,
                    0, 5, -7, 1,
                    4, 8, 3, 27};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortRowsMatrixByRowCriteria(&m,
                                         (int (*)(int *, size_t)) getSum_);
    int expectedSource[] = {0, 5, -7, 1,
                            -1, 7, 4, 0,
                            4, 8, 3, 27};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortRowsMatrixByRowCriteria_squareMatrix_someEqualCriteriaValues() {
    int source[] = {2, 4, 0,
                    3, 9, 13,
                    1, 3, 2};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortRowsMatrixByRowCriteria(&m,
                                         (int (*)(int *, size_t)) getSum_);
    int expectedSource[] = {2, 4, 0,
                            1, 3, 2,
                            3, 9, 13};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortRowsMatrixByRowCriteria_rowsMoreThanCols_someEqualCriteriaValues() {
    int source[] = {1, 2,
                    -3, 0,
                    5, -1,
                    -2, -1};
    size_t nRows = 4;
    size_t nCols = 2;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortRowsMatrixByRowCriteria(&m,
                                         (int (*)(int *, size_t)) getSum_);
    int expectedSource[] = {-3, 0,
                            -2, -1,
                            1, 2,
                            5, -1};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortRowsMatrixByRowCriteria_colsMoreThanRows_someEqualCriteriaValues() {
    int source[] = {12, 1, 0, 0, 0,
                    9, 4, -1, 1, 0,
                    7, 4, -3, 2, 1,
                    1, -34, 0, 5, -6};
    size_t nRows = 4;
    size_t nCols = 5;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortRowsMatrixByRowCriteria(&m,

                                         (int (*)(int *, size_t)) getSum_);
    int expectedSource[] = {1, -34, 0, 5, -6,
                            7, 4, -3, 2, 1,
                            9, 4, -1, 1, 0,
                            12, 1, 0, 0, 0};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortRowsMatrixByRowCriteria() {
    test_selectionSortRowsMatrixByRowCriteria_squareMatrix();
    test_selectionSortRowsMatrixByRowCriteria_rowsMoreThanCols();
    test_selectionSortRowsMatrixByRowCriteria_colsMoreThanRows();
    test_selectionSortRowsMatrixByRowCriteria_squareMatrix_someEqualCriteriaValues();
    test_selectionSortRowsMatrixByRowCriteria_rowsMoreThanCols_someEqualCriteriaValues();
    test_selectionSortRowsMatrixByRowCriteria_colsMoreThanRows_someEqualCriteriaValues();
}

void test_selectionSortColsMatrixByColCriteria_squareMatrix() {
    int source[] = {7, 3, 2,
                    9, 4, 3,
                    5, 3, 1};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortColsMatrixByColCriteria(&m,
                                         (int (*)(int *, size_t)) getSum_);
    int expectedSource[] = {2, 3, 7,
                            3, 4, 9,
                            1, 3, 5};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortColsMatrixByColCriteria_rowsMoreThanCols() {
    int source[] = {7, 0, 3,
                    1, 0, 0,
                    -2, 0, 1,
                    5, 1, 2};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortColsMatrixByColCriteria(&m,
                                         (int (*)(int *, size_t)) getSum_);
    int expectedSource[] = {0, 3, 7,
                            0, 0, 1,
                            0, 1, -2,
                            1, 2, 5};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortColsMatrixByColCriteria_colsMoreThanRows() {
    int source[] = {6, 1, 3, 2,
                    3, 1, 1, 0,
                    3, -3, 4, 5};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortColsMatrixByColCriteria(&m,
                                         (int (*)(int *, size_t)) getSum_);
    int expectedSource[] = {1, 2, 3, 6,
                            1, 0, 1, 3,
                            -3, 5, 4, 3};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortColsMatrixByColCriteria_squareMatrix_someEqualCriteriaValues() {
    int source[] = {-1, 5, 3,
                    0, 11, -4,
                    0, 2, 0};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortColsMatrixByColCriteria(&m,
                                         (int (*)(int *, size_t)) getSum_);
    int expectedSource[] = {-1, 3, 5,
                            0, -4, 11,
                            0, 0, 2};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}


void test_selectionSortColsMatrixByColCriteria_rowsMoreThanCols_someEqualCriteriaValues() {
    int source[] = {1, -8, 5, 2,
                    3, 5, 0, 2,
                    4, -12, 9, 2,
                    0, -6, 6, 1,
                    -1, 3, 0, 0};
    size_t nRows = 5;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortColsMatrixByColCriteria(&m,
                                         (int (*)(int *, size_t)) getSum_);
    int expectedSource[] = {-8, 1, 2, 5,
                            5, 3, 2, 0,
                            -12, 4, 2, 9,
                            -6, 0, 1, 6,
                            3, -1, 0, 0};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortColsMatrixByColCriteria_colsMoreThanRows_someEqualCriteriaValues() {
    int source[] = {1, 3, 1, 2, 1,
                    2, 0, -1, 2, 5,
                    0, 5, 0, -1, 6};
    size_t nRows = 3;
    size_t nCols = 5;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortColsMatrixByColCriteria(&m,
                                         (int (*)(int *, size_t)) getSum_);
    int expectedSource[] = {1, 1, 2, 3, 1,
                            -1, 2, 2, 0, 5,
                            0, 0, -1, 5, 6};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortColsMatrixByColCriteria() {
    test_selectionSortColsMatrixByColCriteria_squareMatrix();
    test_selectionSortColsMatrixByColCriteria_rowsMoreThanCols();
    test_selectionSortColsMatrixByColCriteria_colsMoreThanRows();
    test_selectionSortColsMatrixByColCriteria_squareMatrix_someEqualCriteriaValues();
    test_selectionSortColsMatrixByColCriteria_rowsMoreThanCols_someEqualCriteriaValues();
    test_selectionSortColsMatrixByColCriteria_colsMoreThanRows_someEqualCriteriaValues();
}

void test_isSquareMatrix_squareMatrixOfFirstOrder() {
    int source[] = {1};
    size_t nRows = 1;
    size_t nCols = 1;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    assert(isSquareMatrix(m));
    freeMemMatrix(&m);
}

void test_isSquareMatrix_squareMatrixOfSecondOrder() {
    int source[] = {1, 2,
                    3, 4};
    size_t nRows = 2;
    size_t nCols = 2;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    assert(isSquareMatrix(m));
    freeMemMatrix(&m);
}

void test_isSquareMatrix_squareMatrixOfThirdOrder() {
    int source[] = {1, 0, 0,
                    0, 1, 0,
                    0, 0, 1};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    assert(isSquareMatrix(m));
    freeMemMatrix(&m);
}

void test_isSquareMatrix_rowsMoreThanCols() {
    int source[] = {4, 2,
                    -1, 1,
                    1, 3,
                    0, 2};
    size_t nRows = 4;
    size_t nCols = 2;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    assert(!isSquareMatrix(m));
    freeMemMatrix(&m);
}

void test_isSquareMatrix_colsMoreThanRows() {
    int source[] = {3, 0, 9, 4,
                    1, -1, 6, 0,
                    5, 6, 45, 7};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    assert(!isSquareMatrix(m));
    freeMemMatrix(&m);
}

void test_isSquareMatrix() {
    test_isSquareMatrix_squareMatrixOfFirstOrder();
    test_isSquareMatrix_squareMatrixOfSecondOrder();
    test_isSquareMatrix_squareMatrixOfThirdOrder();
    test_isSquareMatrix_rowsMoreThanCols();
    test_isSquareMatrix_colsMoreThanRows();
}

void test_areTwoMatricesEqual_identicalMatrices() {
    int source1[] = {1, 2,
                     3, 4};
    size_t nRows1 = 2;
    size_t nCols1 = 2;
    matrix m1 = createMatrixFromArray(source1,
                                      nRows1,
                                      nCols1);
    int source2[] = {1, 2,
                     3, 4};
    size_t nRows2 = 2;
    size_t nCols2 = 2;
    matrix m2 = createMatrixFromArray(source2,
                                      nRows2,
                                      nCols2);
    assert(areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_areTwoMatricesEqual_nonIdenticalMatrices() {
    int source1[] = {1, 0,
                     0, 1};
    size_t nRows1 = 2;
    size_t nCols1 = 2;
    matrix m1 = createMatrixFromArray(source1,
                                      nRows1,
                                      nCols1);
    int source2[] = {5, 3, 7,
                     8, 6, 1};
    size_t nRows2 = 2;
    size_t nCols2 = 3;
    matrix m2 = createMatrixFromArray(source2,
                                      nRows2,
                                      nCols2);
    assert(!areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_areTwoMatricesEqual_almostIdenticalMatrices() {
    int source1[] = {2, 3,
                     4, 1};
    size_t nRows1 = 2;
    size_t nCols1 = 2;
    matrix m1 = createMatrixFromArray(source1,
                                      nRows1,
                                      nCols1);
    int source2[] = {2, 3,
                     4, 9};
    size_t nRows2 = 2;
    size_t nCols2 = 2;
    matrix m2 = createMatrixFromArray(source2,
                                      nRows2,
                                      nCols2);
    assert(!areTwoMatricesEqual(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}


void test_areTwoMatricesEqual() {
    test_areTwoMatricesEqual_identicalMatrices();
    test_areTwoMatricesEqual_nonIdenticalMatrices();
    test_areTwoMatricesEqual_almostIdenticalMatrices();
}

void test_isEMatrix_EMatrix() {
    int source[] = {1, 0, 0,
                    0, 1, 0,
                    0, 0, 1};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    assert(isEMatrix(m));
    freeMemMatrix(&m);
}

void test_isEMatrix_almostEMatrix_squareMatrix() {
    int source[] = {1, 0, 1,
                    0, 1, 0,
                    0, 0, 1};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    assert(!isEMatrix(m));
    freeMemMatrix(&m);
}

void test_isEMatrix_almostEMatrix_rowsMoreThanCols() {
    int source[] = {1, 0, 1,
                    0, 1, 0,
                    0, 0, 1,
                    0, 0, 0};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    assert(!isEMatrix(m));
    freeMemMatrix(&m);
}

void test_isEMatrix_almostEMatrix_colsMoreThanRows() {
    int source[] = {1, 0, 0,
                    0, 1, 0};
    size_t nRows = 2;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    assert(!isEMatrix(m));
    freeMemMatrix(&m);
}

void test_isEMatrix_definitelyNotEMatrix_squareMatrix() {
    int source[] = {1, 2, 1,
                    -1, 3, 0,
                    0, 4, 7};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    assert(!isEMatrix(m));
    freeMemMatrix(&m);
}

void test_isEMatrix_definitelyNotEMatrix_rowsMoreThanCols() {
    int source[] = {2, -6, 8,
                    2, 1, 6,
                    1, 2, 3,
                    14, 2, -1};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    assert(!isEMatrix(m));
    freeMemMatrix(&m);
}

void test_isEMatrix_definitelyNotEMatrix_colsMoreThanRows() {
    int source[] = {1, 15, 3,
                    2, 24, 5};
    size_t nRows = 2;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    assert(!isEMatrix(m));
    freeMemMatrix(&m);
}

void test_isEMatrix() {
    test_isEMatrix_EMatrix();
    test_isEMatrix_almostEMatrix_squareMatrix();
    test_isEMatrix_almostEMatrix_rowsMoreThanCols();
    test_isEMatrix_almostEMatrix_colsMoreThanRows();
    test_isEMatrix_definitelyNotEMatrix_squareMatrix();
    test_isEMatrix_definitelyNotEMatrix_rowsMoreThanCols();
    test_isEMatrix_definitelyNotEMatrix_colsMoreThanRows();
}

void test_isSymmetricMatrix_symmetricMatrix() {
    int source[] = {2, 1, 2,
                    1, 3, 0,
                    2, 0, 3};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    assert(isSymmetricMatrix(m));
    freeMemMatrix(&m);
}

void test_isSymmetricMatrix_almostSymmetricEMatrix() {
    int source[] = {1, 4, 5, 9,
                    4, 3, 1, 8,
                    5, -1, -7, 2,
                    9, 8, 2, -5};
    size_t nRows = 4;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    assert(!isSymmetricMatrix(m));
    freeMemMatrix(&m);
}

void test_isSymmetricMatrix_definitelyNotSymmetricEMatrix() {
    int source[] = {1, 16, 7,
                    8, 4, 5,
                    6, 7, 8};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    assert(!isSymmetricMatrix(m));
    freeMemMatrix(&m);
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_symmetricMatrix();
    test_isSymmetricMatrix_almostSymmetricEMatrix();
    test_isSymmetricMatrix_definitelyNotSymmetricEMatrix();
}

void test_transposeSquareMatrix_squareMatrixOfFirstOrder() {
    int source[] = {9, 2};
    size_t nRows = 1;
    size_t nCols = 1;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    transposeSquareMatrix(&m);
    int expectedSource[] = {9};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_transposeSquareMatrix_squareMatrixOfSecondOrder() {
    int source[] = {-1, 7,
                    0, 5};
    size_t nRows = 2;
    size_t nCols = 2;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    transposeSquareMatrix(&m);
    int expectedSource[] = {-1, 0,
                            7, 5};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_transposeSquareMatrix_squareMatrixOfThirdOrder() {
    int source[] = {2, 1, 5,
                    1, 3, 6,
                    5, 6, 4};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    transposeSquareMatrix(&m);
    int expectedSource[] = {2, 1, 5,
                            1, 3, 6,
                            5, 6, 4};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_transposeSquareMatrix_squareMatrixOfFourthOrder() {
    int source[] = {-3, 0, 1, 5,
                    0, 1, 2, -1,
                    11, 7, 0, 0,
                    -1, 0, 1, -2};
    size_t nRows = 4;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    transposeSquareMatrix(&m);
    int expectedSource[] = {-3, 0, 11, -1,
                            0, 1, 7, 0,
                            1, 2, 0, 1,
                            5, -1, 0, -2};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_transposeSquareMatrix() {
    test_transposeSquareMatrix_squareMatrixOfFirstOrder();
    test_transposeSquareMatrix_squareMatrixOfSecondOrder();
    test_transposeSquareMatrix_squareMatrixOfThirdOrder();
    test_transposeSquareMatrix_squareMatrixOfFourthOrder();
}

void test_getMinValuePos_oneMinValueInMatrix() {
    int source[] = {2, 1, 0,
                    -2, 3, 1};
    size_t nRows = 2;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    position minValuePos = getMinValuePos(m);
    position expectedMinValuePos = (position) {1, 0};
    assert(areIdenticalPositions(minValuePos, expectedMinValuePos));
    freeMemMatrix(&m);
}

void test_getMinValuePos_someMinValuesInMatrix() {
    int source[] = {1, 0,
                    0, 2,
                    7, 5};
    size_t nRows = 3;
    size_t nCols = 2;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    position minValuePos = getMinValuePos(m);
    position expectedMinValuePos = (position) {0, 1};
    assert(areIdenticalPositions(minValuePos, expectedMinValuePos));
    freeMemMatrix(&m);
}

void test_getMinValuePos() {
    test_getMinValuePos_oneMinValueInMatrix();
    test_getMinValuePos_someMinValuesInMatrix();
}

void test_getMaxValuePos_oneMaxValueInMatrix() {
    int source[] = {6, 7, 3,
                    3, 9, 4};
    size_t nRows = 2;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    position maxValuePos = getMaxValuePos(m);
    position expectedMaxValuePos = (position) {1, 1};
    assert(areIdenticalPositions(maxValuePos, expectedMaxValuePos));
    freeMemMatrix(&m);
}

void test_getMaxValuePos_someMaxValuesInMatrix() {
    int source[] = {3, -6, 18,
                    12, 15, 18};
    size_t nRows = 2;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    position maxValuePos = getMaxValuePos(m);
    position expectedMaxValuePos = (position) {0, 2};
    assert(areIdenticalPositions(maxValuePos, expectedMaxValuePos));
    freeMemMatrix(&m);
}

void test_getMaxValuePos() {
    test_getMaxValuePos_oneMaxValueInMatrix();
    test_getMaxValuePos_someMaxValuesInMatrix();
}

void test_matrix() {
    test_swapRows();
    test_swapCols();
    test_selectionSortRowsMatrixByRowCriteria();
    test_selectionSortColsMatrixByColCriteria();
    test_isSquareMatrix();
    test_areTwoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}

void test_swapRowsWithMaxAndMinValuesOfSquareMatrix_oneMinAndOneMaxValues() {
    int source[] = {5, 25, 6,
                    4, 3, 1,
                    0, 8, 2};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    swapRowsWithMaxAndMinValuesOfSquareMatrix(&m);
    int expectedSource[] = {0, 8, 2,
                            4, 3, 1,
                            5, 25, 6};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_swapRowsWithMaxAndMinValuesOfSquareMatrix_oneMinAndSomeMaxValues() {
    int source[] = {3, 1, 7,
                    4, 2, 0,
                    7, 5, 3};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    swapRowsWithMaxAndMinValuesOfSquareMatrix(&m);
    int expectedSource[] = {4, 2, 0,
                            3, 1, 7,
                            7, 5, 3};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_swapRowsWithMaxAndMinValuesOfSquareMatrix_someMinAndOneMaxValues() {
    int source[] = {9, 13, 5,
                    13, 11, 7,
                    0, 1, 8};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    swapRowsWithMaxAndMinValuesOfSquareMatrix(&m);
    int expectedSource[] = {0, 1, 8,
                            13, 11, 7,
                            9, 13, 5};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_swapRowsWithMaxAndMinValuesOfSquareMatrix_someMinAndSomeMaxValues() {
    int source[] = {1, 9, 5, 4,
                    4, 0, 8, 6,
                    3, 7, 0, 8,
                    9, 2, 5, 7};
    size_t nRows = 4;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    swapRowsWithMaxAndMinValuesOfSquareMatrix(&m);
    int expectedSource[] = {4, 0, 8, 6,
                            1, 9, 5, 4,
                            3, 7, 0, 8,
                            9, 2, 5, 7};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_swapRowsWithMaxAndMinValuesOfSquareMatrix_minAndMaxValuesInOneRow() {
    int source[] = {6, 8, 5, 3,
                    5, 9, 4, 0,
                    4, 1, 1, 7,
                    2, 5, 1, 3};
    size_t nRows = 4;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    swapRowsWithMaxAndMinValuesOfSquareMatrix(&m);
    int expectedSource[] = {6, 8, 5, 3,
                            5, 9, 4, 0,
                            4, 1, 1, 7,
                            2, 5, 1, 3};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_swapRowsWithMaxAndMinValuesOfSquareMatrix() {
    test_swapRowsWithMaxAndMinValuesOfSquareMatrix_oneMinAndOneMaxValues();
    test_swapRowsWithMaxAndMinValuesOfSquareMatrix_oneMinAndSomeMaxValues();
    test_swapRowsWithMaxAndMinValuesOfSquareMatrix_someMinAndOneMaxValues();
    test_swapRowsWithMaxAndMinValuesOfSquareMatrix_someMinAndSomeMaxValues();
    test_swapRowsWithMaxAndMinValuesOfSquareMatrix_minAndMaxValuesInOneRow();
}

void test_sortRowsByMaxElement_squareMatrix() {
    int source[] = {7, 1, 2,
                    1, 8, 1,
                    3, 2, 3};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    sortRowsByMaxElements(&m);
    int expectedSource[] = {3, 2, 3,
                            7, 1, 2,
                            1, 8, 1};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortRowsByMaxElement_rowsMoreThanCols() {
    int source[] = {1, 6, 3,
                    2, 1, 1,
                    5, 3, 8,
                    1, 1, 0};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    sortRowsByMaxElements(&m);
    int expectedSource[] = {1, 1, 0,
                            2, 1, 1,
                            1, 6, 3,
                            5, 3, 8};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortRowsByMaxElement_colsMoreThanRows() {
    int source[] = {9, 4, 5, 0,
                    4, 0, 5, 0,
                    1, 3, 4, 2};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    sortRowsByMaxElements(&m);
    int expectedSource[] = {1, 3, 4, 2,
                            4, 0, 5, 0,
                            9, 4, 5, 0};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortRowsByMaxElement_squareMatrix_someEqualCriteriaValues() {
    int source[] = {1, 4, 7, 13, 0,
                    6, 8, 5, 3, 2,
                    13, 0, 5, 7, 0,
                    0, 2, 8, 1, 5,
                    6, 6, 10, 7, 11};
    size_t nRows = 5;
    size_t nCols = 5;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    sortRowsByMaxElements(&m);
    int expectedSource[] = {6, 8, 5, 3, 2,
                            0, 2, 8, 1, 5,
                            6, 6, 10, 7, 11,
                            1, 4, 7, 13, 0,
                            13, 0, 5, 7, 0};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortRowsByMaxElement_rowsMoreThanCols_someEqualCriteriaValues() {
    int source[] = {15, 36, 1,
                    3, 5, 2,
                    4, 0, 7,
                    2, 4, 5};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    sortRowsByMaxElements(&m);
    int expectedSource[] = {3, 5, 2,
                            2, 4, 5,
                            4, 0, 7,
                            15, 36, 1};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortRowsByMaxElement_colsMoreThanRows_someEqualCriteriaValues() {
    int source[] = {7, 45, 9, 6, 2,
                    2, 4, 6, 3, 1,
                    3, 1, 0, 1, 0,
                    5, 4, 6, 0, 3};
    size_t nRows = 4;
    size_t nCols = 5;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    sortRowsByMaxElements(&m);
    int expectedSource[] = {3, 1, 0, 1, 0,
                            2, 4, 6, 3, 1,
                            5, 4, 6, 0, 3,
                            7, 45, 9, 6, 2};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortRowsByMaxElement() {
    test_sortRowsByMaxElement_squareMatrix();
    test_sortRowsByMaxElement_rowsMoreThanCols();
    test_sortRowsByMaxElement_colsMoreThanRows();
    test_sortRowsByMaxElement_squareMatrix_someEqualCriteriaValues();
    test_sortRowsByMaxElement_rowsMoreThanCols_someEqualCriteriaValues();
    test_sortRowsByMaxElement_colsMoreThanRows_someEqualCriteriaValues();
}

void test_tasks_matrix() {
    test_swapRowsWithMaxAndMinValuesOfSquareMatrix();
    test_sortRowsByMaxElement();
}

int main() {
    test_matrix();
    test_tasks_matrix();

    return 0;
}