#include <assert.h>

#include "test_matrix.h"

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
                    -1, 5, 7,
                    12, 15, 18};
    size_t nRows = 3;
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

void test_matrix_lib() {
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

void test_sortColsByMinElement_squareMatrix() {
    int source[] = {4, 2, 2,
                    9, 1, 7,
                    3, 4, 1};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    sortColsByMinElements(&m);
    int expectedSource[] = {2, 2, 4,
                            1, 7, 9,
                            4, 1, 3};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortColsByMinElement_rowsMoreThanCols() {
    int source[] = {8, 3, 7,
                    15, 1, 5,
                    6, 4, 2,
                    5, 0, 12};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    sortColsByMinElements(&m);
    int expectedSource[] = {3, 7, 8,
                            1, 5, 15,
                            4, 2, 6,
                            0, 12, 5};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortColsByMinElement_colsMoreThanRows() {
    int source[] = {5, 12, 0, 1,
                    20, 3, 1, 6,
                    4, 7, 1, 2};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    sortColsByMinElements(&m);
    int expectedSource[] = {0, 1, 12, 5,
                            1, 6, 3, 20,
                            1, 2, 7, 4};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortColsByMinElement_squareMatrix_someEqualCriteriaValues() {
    int source[] = {9, 1, 3, 0,
                    3, 2, 1, 1,
                    7, 2, 3, 1,
                    4, 0, 2, 1};
    size_t nRows = 4;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    sortColsByMinElements(&m);
    int expectedSource[] = {1, 0, 3, 9,
                            2, 1, 1, 3,
                            2, 1, 3, 7,
                            0, 1, 2, 4};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortColsByMinElement_rowsMoreThanCols_someEqualCriteriaValues() {
    int source[] = {1, 2, 4, 0,
                    2, 3, 8, 1,
                    3, 1, 4, 2,
                    2, 0, 3, 1,
                    2, 4, 6, 8};
    size_t nRows = 5;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    sortColsByMinElements(&m);
    int expectedSource[] = {2, 0, 1, 4,
                            3, 1, 2, 8,
                            1, 2, 3, 4,
                            0, 1, 2, 3,
                            4, 8, 2, 6};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortColsByMinElement_colsMoreThanRows_someEqualCriteriaValues() {
    int source[] = {8, 7, 5, 15, 2,
                    13, 3, 1, 3, 1,
                    10, 6, 4, 5, 0};
    size_t nRows = 3;
    size_t nCols = 5;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    sortColsByMinElements(&m);
    int expectedSource[] = {2, 5, 7, 15, 8,
                            1, 1, 3, 3, 13,
                            0, 4, 6, 5, 10};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortColsByMinElement() {
    test_sortColsByMinElement_squareMatrix();
    test_sortColsByMinElement_rowsMoreThanCols();
    test_sortColsByMinElement_colsMoreThanRows();
    test_sortColsByMinElement_squareMatrix_someEqualCriteriaValues();
    test_sortColsByMinElement_rowsMoreThanCols_someEqualCriteriaValues();
    test_sortColsByMinElement_colsMoreThanRows_someEqualCriteriaValues();
}

void test_mulMatrices_squareMatrices() {
    int source1[] = {2, 4,
                     7, 6};
    size_t nRows = 2;
    size_t nCols = 2;
    matrix m1 = createMatrixFromArray(source1, nRows, nCols);
    int source2[] = {1, 6,
                     3, 5};
    matrix m2 = createMatrixFromArray(source2, nRows, nCols);
    matrix mulMatrix = mulMatrices(m1, m2);
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    int expectedSource[] = {14, 32,
                            25, 72};
    size_t expectedNRows = 2;
    size_t expectedNCols = 2;
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             expectedNRows,
                                             expectedNCols);
    assert(areTwoMatricesEqual(mulMatrix, expectedM));
    freeMemMatrix(&expectedM);
}

void test_mulMatrices_squareMatrixAndMatrixWithRowsMoreThanCols() {
    int source1[] = {2, 3, 4,
                     1, 2, 0,
                     2, 3, 1};
    size_t nRows1 = 3;
    size_t nCols1 = 3;
    matrix m1 = createMatrixFromArray(source1, nRows1, nCols1);
    int source2[] = {1, 2,
                     3, 4,
                     5, 6};
    size_t nRows2 = 3;
    size_t nCols2 = 2;
    matrix m2 = createMatrixFromArray(source2, nRows2, nCols2);
    matrix mulMatrix = mulMatrices(m1, m2);
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    int expectedSource[] = {31, 40,
                            7, 10,
                            16, 22};
    size_t expectedNRows = 3;
    size_t expectedNCols = 2;
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             expectedNRows,
                                             expectedNCols);
    assert(areTwoMatricesEqual(mulMatrix, expectedM));
    freeMemMatrix(&expectedM);
}

void test_mulMatrices_squareMatrixAndMatrixWithColsMoreThanRows() {
    int source1[] = {1, 2,
                     3, 4};
    size_t nRows1 = 2;
    size_t nCols1 = 2;
    matrix m1 = createMatrixFromArray(source1, nRows1, nCols1);
    int source2[] = {2, 3, 1,
                     0, 0, 1};
    size_t nRows2 = 2;
    size_t nCols2 = 3;
    matrix m2 = createMatrixFromArray(source2, nRows2, nCols2);
    matrix mulMatrix = mulMatrices(m1, m2);
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    int expectedSource[] = {2, 3, 3,
                            6, 9, 7};
    size_t expectedNRows = 2;
    size_t expectedNCols = 3;
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             expectedNRows,
                                             expectedNCols);
    assert(areTwoMatricesEqual(mulMatrix, expectedM));
    freeMemMatrix(&expectedM);
}

void test_mulMatrices_matrixWithRowsMoreThanColsAndSquareMatrix() {
    int source1[] = {1, 3,
                     3, 4,
                     2, 5};
    size_t nRows1 = 3;
    size_t nCols1 = 2;
    matrix m1 = createMatrixFromArray(source1, nRows1, nCols1);
    int source2[] = {2, 5,
                     1, 2};
    size_t nRows2 = 2;
    size_t nCols2 = 2;
    matrix m2 = createMatrixFromArray(source2, nRows2, nCols2);
    matrix mulMatrix = mulMatrices(m1, m2);
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    int expectedSource[] = {5, 11,
                            10, 23,
                            9, 20};
    size_t expectedNRows = 3;
    size_t expectedNCols = 2;
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             expectedNRows,
                                             expectedNCols);
    assert(areTwoMatricesEqual(mulMatrix, expectedM));
    freeMemMatrix(&expectedM);
}

void test_mulMatrices_matrixWithColsMoreThanRowsAndSquareMatrix() {
    int source1[] = {7, 9, 2,
                     8, 1, 3};
    size_t nRows1 = 2;
    size_t nCols1 = 3;
    matrix m1 = createMatrixFromArray(source1, nRows1, nCols1);
    int source2[] = {2, 5, 6,
                     1, 2, 5,
                     1, 3, 2};
    size_t nRows2 = 3;
    size_t nCols2 = 3;
    matrix m2 = createMatrixFromArray(source2, nRows2, nCols2);
    matrix mulMatrix = mulMatrices(m1, m2);
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    int expectedSource[] = {25, 59, 91,
                            20, 51, 59};
    size_t expectedNRows = 2;
    size_t expectedNCols = 3;
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             expectedNRows,
                                             expectedNCols);
    assert(areTwoMatricesEqual(mulMatrix, expectedM));
    freeMemMatrix(&expectedM);
}

void test_mulMatrices_matrixWithRowsMoreThanColsAndMatrixWithColsMoreThanRows() {
    int source1[] = {2, 1,
                     0, 3,
                     1, 2};
    size_t nRows1 = 3;
    size_t nCols1 = 2;
    matrix m1 = createMatrixFromArray(source1, nRows1, nCols1);
    int source2[] = {1, 1, 0,
                     2, 1, 2};
    size_t nRows2 = 2;
    size_t nCols2 = 3;
    matrix m2 = createMatrixFromArray(source2, nRows2, nCols2);
    matrix mulMatrix = mulMatrices(m1, m2);
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    int expectedSource[] = {4, 3, 2,
                            6, 3, 6,
                            5, 3, 4};
    size_t expectedNRows = 3;
    size_t expectedNCols = 3;
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             expectedNRows,
                                             expectedNCols);
    assert(areTwoMatricesEqual(mulMatrix, expectedM));
    freeMemMatrix(&expectedM);
}

void test_mulMatrices_matrixWithColsMoreThanRowsAndMatrixWithRowsMoreThanCols() {
    int source1[] = {2, 3, 0,
                     1, 0, 4};
    size_t nRows1 = 2;
    size_t nCols1 = 3;
    matrix m1 = createMatrixFromArray(source1, nRows1, nCols1);
    int source2[] = {1, 0,
                     1, 4,
                     0, 2};
    size_t nRows2 = 3;
    size_t nCols2 = 2;
    matrix m2 = createMatrixFromArray(source2, nRows2, nCols2);
    matrix mulMatrix = mulMatrices(m1, m2);
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    int expectedSource[] = {5, 12,
                            1, 8};
    size_t expectedNRows = 2;
    size_t expectedNCols = 2;
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             expectedNRows,
                                             expectedNCols);
    assert(areTwoMatricesEqual(mulMatrix, expectedM));
    freeMemMatrix(&expectedM);
}

void test_mulMatrices_matrixWithOneRowAndColsAndMatrixWithOneColAndRows() {
    int source1[] = {4,
                     5,
                     6};
    size_t nRows1 = 3;
    size_t nCols1 = 1;
    matrix m1 = createMatrixFromArray(source1, nRows1, nCols1);
    int source2[] = {1, 2, 3};
    size_t nRows2 = 1;
    size_t nCols2 = 3;
    matrix m2 = createMatrixFromArray(source2, nRows2, nCols2);
    matrix mulMatrix = mulMatrices(m1, m2);
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    int expectedSource[] = {4, 8, 12,
                            5, 10, 15,
                            6, 12, 18};
    size_t expectedNRows = 3;
    size_t expectedNCols = 3;
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             expectedNRows,
                                             expectedNCols);
    assert(areTwoMatricesEqual(mulMatrix, expectedM));
    freeMemMatrix(&expectedM);
}

void test_mulMatrices_matrixWithOneColAndRowsAndMatrixWithOneRowAndCols() {
    int source1[] = {1, 2, 3};
    size_t nRows1 = 1;
    size_t nCols1 = 3;
    matrix m1 = createMatrixFromArray(source1, nRows1, nCols1);
    int source2[] = {4,
                     5,
                     6};
    size_t nRows2 = 3;
    size_t nCols2 = 1;
    matrix m2 = createMatrixFromArray(source2, nRows2, nCols2);
    matrix mulMatrix = mulMatrices(m1, m2);
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    int expectedSource[] = {32};
    size_t expectedNRows = 1;
    size_t expectedNCols = 1;
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             expectedNRows,
                                             expectedNCols);
    assert(areTwoMatricesEqual(mulMatrix, expectedM));
    freeMemMatrix(&expectedM);
}

void test_mulMatrices() {
    test_mulMatrices_squareMatrices();
    test_mulMatrices_squareMatrixAndMatrixWithRowsMoreThanCols();
    test_mulMatrices_squareMatrixAndMatrixWithColsMoreThanRows();
    test_mulMatrices_matrixWithRowsMoreThanColsAndSquareMatrix();
    test_mulMatrices_matrixWithColsMoreThanRowsAndSquareMatrix();
    test_mulMatrices_matrixWithRowsMoreThanColsAndMatrixWithColsMoreThanRows();
    test_mulMatrices_matrixWithColsMoreThanRowsAndMatrixWithRowsMoreThanCols();
    test_mulMatrices_matrixWithOneRowAndColsAndMatrixWithOneColAndRows();
    test_mulMatrices_matrixWithOneColAndRowsAndMatrixWithOneRowAndCols();
}

void test_getSquareOfMatrixIfSymmetric_symmetricMatrixOfFirstOrder() {
    int source[] = {15};
    size_t nRows = 1;
    size_t nCols = 1;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    getSquareOfMatrixIfSymmetric(&m);
    int expectedSource[] = {225};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_getSquareOfMatrixIfSymmetric_symmetricMatrixOfSecondOrder() {
    int source[] = {1, 2,
                    2, 0};
    size_t nRows = 2;
    size_t nCols = 2;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    getSquareOfMatrixIfSymmetric(&m);
    int expectedSource[] = {5, 2,
                            2, 4};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_getSquareOfMatrixIfSymmetric_symmetricMatrixOfThirdOrder() {
    int source[] = {1, 4, 2,
                    4, 3, 6,
                    2, 6, 5};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    getSquareOfMatrixIfSymmetric(&m);
    int expectedSource[] = {21, 28, 36,
                            28, 61, 56,
                            36, 56, 65};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_getSquareOfMatrixIfSymmetric_symmetricMatrixOfFourthOrder() {
    int source[] = {1, 2, 3, 4,
                    2, 3, 4, 1,
                    3, 4, 1, 2,
                    4, 1, 2, 3};
    size_t nRows = 4;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    getSquareOfMatrixIfSymmetric(&m);
    int expectedSource[] = {30, 24, 22, 24,
                            24, 30, 24, 22,
                            22, 24, 30, 24,
                            24, 22, 24, 30};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_symmetricMatrixOfFirstOrder();
    test_getSquareOfMatrixIfSymmetric_symmetricMatrixOfSecondOrder();
    test_getSquareOfMatrixIfSymmetric_symmetricMatrixOfThirdOrder();
    test_getSquareOfMatrixIfSymmetric_symmetricMatrixOfFourthOrder();
}

void test_transposeIfMatrixHasNotEqualSumsOfRows_squareMatrix_noEqualSumsOfRows() {
    int source[] = {1, 7, 4,
                    0, 5, 3,
                    4, 8, 7};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    transposeIfMatrixHasNotEqualSumsOfRows(&m);
    int expectedSource[] = {1, 0, 4,
                            7, 5, 8,
                            4, 3, 7};
    matrix expectedM = createMatrixFromArray(expectedSource, nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_transposeIfMatrixHasNotEqualSumsOfRows() {
    test_transposeIfMatrixHasNotEqualSumsOfRows_squareMatrix_noEqualSumsOfRows();
}

void test_areMutuallyInverseMatrices_mutuallyInverseMatrices() {
    int source1[] = {3, -5,
                     1, -2};
    size_t nRows1 = 2;
    size_t nCols1 = 2;
    matrix m1 = createMatrixFromArray(source1, nRows1, nCols1);
    int source2[] = {2, -5,
                     1, -3};
    size_t nRows2 = 2;
    size_t nCols2 = 2;
    matrix m2 = createMatrixFromArray(source2, nRows2, nCols2);
    assert(areMutuallyInverseMatrices(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_areMutuallyInverseMatrices_notMutuallyInverseMatrices() {
    int source1[] = {9, 7,
                     3, 4};
    size_t nRows1 = 2;
    size_t nCols1 = 2;
    matrix m1 = createMatrixFromArray(source1, nRows1, nCols1);
    int source2[] = {1, 0,
                     2, 1};
    size_t nRows2 = 2;
    size_t nCols2 = 2;
    matrix m2 = createMatrixFromArray(source2, nRows2, nCols2);
    assert(!areMutuallyInverseMatrices(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_areMutuallyInverseMatrices() {
    test_areMutuallyInverseMatrices_mutuallyInverseMatrices();
    test_areMutuallyInverseMatrices_notMutuallyInverseMatrices();
}

void test_findSumOfMaxesOfPseudoDiagonals_squareMatrixOfFirstOrder() {
    int source[] = {9};
    size_t nRows = 1;
    size_t nCols = 1;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    long long sum = findSumOfMaxesOfPseudoDiagonals(m);
    long long expectedSum = 0;
    assert(sum == expectedSum);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonals_squareMatrixOfSecondOrder() {
    int source[] = {2, 4,
                    3, 5};
    size_t nRows = 2;
    size_t nCols = 2;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    long long sum = findSumOfMaxesOfPseudoDiagonals(m);
    long long expectedSum = 7;
    assert(sum == expectedSum);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonals_squareMatrixOfThirdOrder() {
    int source[] = {7, 5, 1,
                    5, 3, 1,
                    1, 2, 3};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    long long sum = findSumOfMaxesOfPseudoDiagonals(m);
    long long expectedSum = 12;
    assert(sum == expectedSum);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonals_squareMatrixOfFourthOrder() {
    int source[] = {1, 8, 2, 3,
                    3, 2, 0, 4,
                    5, 3, 7, 1,
                    3, 2, 0, 2};
    size_t nRows = 4;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    long long sum = findSumOfMaxesOfPseudoDiagonals(m);
    long long expectedSum = 26;
    assert(sum == expectedSum);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonals_rowsMoreThanCols() {
    int source[] = {3, 2, 0,
                    1, 1, 2,
                    4, 5, 1,
                    1, 2, 3};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    long long sum = findSumOfMaxesOfPseudoDiagonals(m);
    long long expectedSum = 12;
    assert(sum == expectedSum);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonals_colsMoreThanRows() {
    int source[] = {0, 4, 1, 1,
                    4, 2, 1, 3,
                    1, 3, 4, 3};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    long long sum = findSumOfMaxesOfPseudoDiagonals(m);
    long long expectedSum = 13;
    assert(sum == expectedSum);
    freeMemMatrix(&m);
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    test_findSumOfMaxesOfPseudoDiagonals_squareMatrixOfFirstOrder();
    test_findSumOfMaxesOfPseudoDiagonals_squareMatrixOfSecondOrder();
    test_findSumOfMaxesOfPseudoDiagonals_squareMatrixOfThirdOrder();
    test_findSumOfMaxesOfPseudoDiagonals_squareMatrixOfFourthOrder();
    test_findSumOfMaxesOfPseudoDiagonals_rowsMoreThanCols();
    test_findSumOfMaxesOfPseudoDiagonals_colsMoreThanRows();
}

void test_minInArea_squareMatrix_areaHasOnlyMaxElementInArea() {
    int source[] = {3, 6, 17,
                    2, 4, 6,
                    1, 2, 3};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    long long min = getMinInArea(m);
    long long expectedMin = 17;
    assert(min == expectedMin);
    freeMemMatrix(&m);
}

void test_minInArea_squareMatrix_maxElementIsNotOneElementInArea() {
    int source[] = {5, 3, 7,
                    3, 2, 0,
                    2, 14, 4};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    long long min = getMinInArea(m);
    long long expectedMin = 0;
    assert(min == expectedMin);
    freeMemMatrix(&m);
}

void test_minInArea_rowsMoreThanCols_areaHasOnlyMaxElementInArea() {
    int source[] = {12, 0, 1,
                    3, 1, 7,
                    1, 3, 2,
                    2, 2, 1};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    long long min = getMinInArea(m);
    long long expectedMin = 12;
    assert(min == expectedMin);
    freeMemMatrix(&m);
}

void test_minInArea_rowsMoreThanCols_maxElementIsNotOneElementInArea() {
    int source[] = {6, 8, 9,
                    7, 12, 3,
                    10, 11, 5,
                    2, 4, 1};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    long long min = getMinInArea(m);
    long long expectedMin = 6;
    assert(min == expectedMin);
    freeMemMatrix(&m);
}

void test_minInArea_colsMoreThanRows_areaHasOnlyMaxElementInArea() {
    int source[] = {3, 2, 25, 8,
                    3, 2, 1, 5,
                    1, 0, 2, 10};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    long long min = getMinInArea(m);
    long long expectedMin = 25;
    assert(min == expectedMin);
    freeMemMatrix(&m);
}

void test_minInArea_colsMoreThanRows_maxElementIsNotOneElementInArea() {
    int source[] = {10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    long long min = getMinInArea(m);
    long long expectedMin = 5;
    assert(min == expectedMin);
    freeMemMatrix(&m);
}

void test_minInArea() {
    test_minInArea_squareMatrix_areaHasOnlyMaxElementInArea();
    test_minInArea_squareMatrix_maxElementIsNotOneElementInArea();
    test_minInArea_rowsMoreThanCols_areaHasOnlyMaxElementInArea();
    test_minInArea_rowsMoreThanCols_maxElementIsNotOneElementInArea();
    test_minInArea_colsMoreThanRows_areaHasOnlyMaxElementInArea();
    test_minInArea_colsMoreThanRows_maxElementIsNotOneElementInArea();
}

void test_selectionSortRowsMatrixByRowCriteriaF_squareMatrix() {
    int source[] = {2, 7, 2,
                    3, 4, 0,
                    1, 1, 2};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortRowsMatrixByRowCriteriaF(&m,
                                          (float (*)(int *, size_t)) getArithmeticMean);
    int expectedSource[] = {1, 1, 2,
                            3, 4, 0,
                            2, 7, 2};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortRowsMatrixByRowCriteriaF_rowsMoreThanCols() {
    int source[] = {6, 2, 10,
                    5, 7, 4,
                    2, 4, 2,
                    3, 0, 7};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortRowsMatrixByRowCriteriaF(&m,
                                          (float (*)(int *, size_t)) getArithmeticMean);
    int expectedSource[] = {2, 4, 2,
                            3, 0, 7,
                            5, 7, 4,
                            6, 2, 10};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortRowsMatrixByRowCriteriaF_colsMoreThanRows() {
    int source[] = {3, 1, 4, 16,
                    1, 2, 3, 4,
                    2, 6, 4, 3};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortRowsMatrixByRowCriteriaF(&m,
                                          (float (*)(int *, size_t)) getArithmeticMean);
    int expectedSource[] = {1, 2, 3, 4,
                            2, 6, 4, 3,
                            3, 1, 4, 16};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortRowsMatrixByRowCriteriaF_squareMatrix_someEqualCriteriaValues() {
    int source[] = {0, 5, 1, 3,
                    1, 0, 0, 1,
                    2, 1, 2, 6,
                    2, 0, 0, 0};
    size_t nRows = 4;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortRowsMatrixByRowCriteriaF(&m,
                                          (float (*)(int *, size_t)) getArithmeticMean);
    int expectedSource[] = {1, 0, 0, 1,
                            2, 0, 0, 0,
                            0, 5, 1, 3,
                            2, 1, 2, 6};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortRowsMatrixByRowCriteriaF_rowsMoreThanCols_someEqualCriteriaValues() {
    int source[] = {4, 5, 1,
                    5, 3, 1,
                    3, 2, 8,
                    2, 4, 3};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortRowsMatrixByRowCriteriaF(&m,
                                          (float (*)(int *, size_t)) getArithmeticMean);
    int expectedSource[] = {5, 3, 1,
                            2, 4, 3,
                            4, 5, 1,
                            3, 2, 8};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortRowsMatrixByRowCriteriaF_colsMoreThanRows_someEqualCriteriaValues() {
    int source[] = {4, 1, 1, 5, 25,
                    0, 1, 3, 4, 9,
                    2, 0, 1, 3, 3,
                    1, 1, 1, 1, 5};
    size_t nRows = 4;
    size_t nCols = 5;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    selectionSortRowsMatrixByRowCriteriaF(&m,
                                          (float (*)(int *, size_t)) getArithmeticMean);
    int expectedSource[] = {2, 0, 1, 3, 3,
                            1, 1, 1, 1, 5,
                            0, 1, 3, 4, 9,
                            4, 1, 1, 5, 25};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_selectionSortRowsMatrixByRowCriteriaF() {
    test_selectionSortRowsMatrixByRowCriteriaF_squareMatrix();
    test_selectionSortRowsMatrixByRowCriteriaF_rowsMoreThanCols();
    test_selectionSortRowsMatrixByRowCriteriaF_colsMoreThanRows();
    test_selectionSortRowsMatrixByRowCriteriaF_squareMatrix_someEqualCriteriaValues();
    test_selectionSortRowsMatrixByRowCriteriaF_rowsMoreThanCols_someEqualCriteriaValues();
    test_selectionSortRowsMatrixByRowCriteriaF_colsMoreThanRows_someEqualCriteriaValues();
}

void test_sortByDistances_squareMatrix() {
    int source[] = {2, 1, -8,
                    -3, 1, 6,
                    1, 0, 3};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    sortByDistances(&m);
    int expectedSource[] = {1, 0, 3,
                            -3, 1, 6,
                            2, 1, -8};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortByDistances_rowsMoreThanCols() {
    int source[] = {-1, 2, 5,
                    3, 0, 6,
                    4, 3, -4,
                    1, 1, 0};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    sortByDistances(&m);
    int expectedSource[] = {1, 1, 0,
                            -1, 2, 5,
                            4, 3, -4,
                            3, 0, 6};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortByDistances_colsMoreThanRows() {
    int source[] = {-6, 1, 11, 3,
                    9, 2, -5, 0,
                    0, 3, 7, 1};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    sortByDistances(&m);
    int expectedSource[] = {0, 3, 7, 1,
                            9, 2, -5, 0,
                            -6, 1, 11, 3};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortByDistances_squareMatrix_someEqualDistances() {
    int source[] = {0, 5, 24, 2,
                    1, 4, 4, 5,
                    4, 2, 0, 6,
                    2, 2, -5, -5};
    size_t nRows = 4;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    sortByDistances(&m);
    int expectedSource[] = {4, 2, 0, 6,
                            1, 4, 4, 5,
                            2, 2, -5, -5,
                            0, 5, 24, 2};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortByDistances_rowsMoreThanCols_someEqualDistances() {
    int source[] = {-3, 0, 1, 2,
                    1, 9, -7, 6,
                    2, 1, 3, 0,
                    5, 3, 1, 2,
                    0, 0, 0, 1};
    size_t nRows = 5;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    sortByDistances(&m);
    int expectedSource[] = {0, 0, 0, 1,
                            2, 1, 3, 0,
                            -3, 0, 1, 2,
                            5, 3, 1, 2,
                            1, 9, -7, 6};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortByDistances_colsMoreThanRows_someEqualDistances() {
    int source[] = {-3, 0, 4, 3, 0,
                    -1, 2, 2, 2, 1,
                    2, 2, 7, 1, -6,
                    3, -2, -4, 2, 1};
    size_t nRows = 4;
    size_t nCols = 5;
    matrix m = createMatrixFromArray(source,
                                     nRows, nCols);
    sortByDistances(&m);
    int expectedSource[] = {-1, 2, 2, 2, 1,
                            -3, 0, 4, 3, 0,
                            3, -2, -4, 2, 1,
                            2, 2, 7, 1, -6};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_sortByDistances() {
    test_sortByDistances_squareMatrix();
    test_sortByDistances_rowsMoreThanCols();
    test_sortByDistances_colsMoreThanRows();
    test_sortByDistances_squareMatrix_someEqualDistances();
    test_sortByDistances_rowsMoreThanCols_someEqualDistances();
    test_sortByDistances_colsMoreThanRows_someEqualDistances();
}

void test_countOfClassesOfEqRowsByRowSum_squareMatrix() {
    int source[] = {6, 2, 4, 0,
                    2, 9, 5, 4,
                    15, 2, 2, 1,
                    8, 2, 1, 1};
    size_t nRows = 4;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nClasses = countOfClassesOfEqRowsByRowSum(m);
    int expectedNClasses = 2;
    assert(nClasses == expectedNClasses);
    freeMemMatrix(&m);
}

void test_countOfClassesOfEqRowsByRowSum_rowsMoreThanCols() {
    int source[] = {7, 1,
                    2, 7,
                    5, 4,
                    4, 3,
                    1, 6,
                    8, 0};
    size_t nRows = 6;
    size_t nCols = 2;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nClasses = countOfClassesOfEqRowsByRowSum(m);
    int expectedNClasses = 3;
    assert(nClasses == expectedNClasses);
    freeMemMatrix(&m);
}


void test_countOfClassesOfEqRowsByRowSum_colsMoreThanRows() {
    int source[] = {3, 3, 1, 0, 2,
                    6, 8, 1, -1, 1,
                    5, 5, 5, 5, 5,
                    4, 2, 3, 0, 0};
    size_t nRows = 4;
    size_t nCols = 5;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nClasses = countOfClassesOfEqRowsByRowSum(m);
    int expectedNClasses = 2;
    assert(nClasses == expectedNClasses);
    freeMemMatrix(&m);
}

void test_countOfClassesOfEqRowsByRowSum_squareMatrix_matrixHasRowWithUniqueSumOfElements() {
    int source[] = {19, 2, 2, 0, 2,
                    6, 15, -6, -5, 1,
                    2, -2, 11, 7, 7,
                    1, 1, 3, 4, 2,
                    1, 2, 0, -3, 0};
    size_t nRows = 5;
    size_t nCols = 5;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nClasses = countOfClassesOfEqRowsByRowSum(m);
    int expectedNClasses = 2;
    assert(nClasses == expectedNClasses);
    freeMemMatrix(&m);
}

void test_countOfClassesOfEqRowsByRowSum_rowsMoreThanCols_matrixHasRowWithUniqueSumOfElements() {
    int source[] = {4, 1, 1,
                    0, 0, 1,
                    2, 3, 2,
                    5, 1, 1,
                    0, 3, 3};
    size_t nRows = 5;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nClasses = countOfClassesOfEqRowsByRowSum(m);
    int expectedNClasses = 2;
    assert(nClasses == expectedNClasses);
    freeMemMatrix(&m);
}

void test_countOfClassesOfEqRowsByRowSum_colsMoreThanRows_matrixHasRowWithUniqueSumOfElements() {
    int source[] = {4, 6, 3, 1, 6, 5,
                    3, 4, 4, 1, 0, 0,
                    5, 10, 10, -20, 20, 0,
                    7, 6, 8, 1, 2, 3,
                    3, 9, 7, 8, 0, 0};
    size_t nRows = 5;
    size_t nCols = 6;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nClasses = countOfClassesOfEqRowsByRowSum(m);
    int expectedNClasses = 2;
    assert(nClasses == expectedNClasses);
    freeMemMatrix(&m);
}

void test_countOfClassesOfEqRowsByRowSum_squareMatrix_noClassesOfEqRowsByRowsSum() {
    int source[] = {3, -2, 9,
                    8, 5, 4,
                    2, 0, 1};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nClasses = countOfClassesOfEqRowsByRowSum(m);
    int expectedNClasses = 0;
    assert(nClasses == expectedNClasses);
    freeMemMatrix(&m);
}

void test_countOfClassesOfEqRowsByRowSum_rowsMoreThanCols_noClassesOfEqRowsByRowsSum() {
    int source[] = {2, 4,
                    1, 3,
                    9, 8};
    size_t nRows = 3;
    size_t nCols = 2;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nClasses = countOfClassesOfEqRowsByRowSum(m);
    int expectedNClasses = 0;
    assert(nClasses == expectedNClasses);
    freeMemMatrix(&m);
}

void test_countOfClassesOfEqRowsByRowSum_colsMoreThanRows_noClassesOfEqRowsByRowsSum() {
    int source[] = {5, 6, 2,
                    1, 3, 7};
    size_t nRows = 2;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nClasses = countOfClassesOfEqRowsByRowSum(m);
    int expectedNClasses = 0;
    assert(nClasses == expectedNClasses);
    freeMemMatrix(&m);
}

void test_countOfClassesOfEqRowsByRowSum() {
    test_countOfClassesOfEqRowsByRowSum_squareMatrix();
    test_countOfClassesOfEqRowsByRowSum_rowsMoreThanCols();
    test_countOfClassesOfEqRowsByRowSum_colsMoreThanRows();
    test_countOfClassesOfEqRowsByRowSum_squareMatrix_matrixHasRowWithUniqueSumOfElements();
    test_countOfClassesOfEqRowsByRowSum_rowsMoreThanCols_matrixHasRowWithUniqueSumOfElements();
    test_countOfClassesOfEqRowsByRowSum_colsMoreThanRows_matrixHasRowWithUniqueSumOfElements();
    test_countOfClassesOfEqRowsByRowSum_squareMatrix_noClassesOfEqRowsByRowsSum();
    test_countOfClassesOfEqRowsByRowSum_rowsMoreThanCols_noClassesOfEqRowsByRowsSum();
    test_countOfClassesOfEqRowsByRowSum_colsMoreThanRows_noClassesOfEqRowsByRowsSum();
}

void test_getCountOfSpecialElements_squareMatrix() {
    int source[] = {15, 4, -9,
                    8, -1, 7,
                    23, 3, 21};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nSpecialElements = getCountOfSpecialElements(m);
    int expectedNSpecialElements = 2;
    assert(nSpecialElements == expectedNSpecialElements);
    freeMemMatrix(&m);
}

void test_getCountOfSpecialElements_rowsMoreThanCols() {
    int source[] = {-2, 29, 10,
                    11, 0, 7,
                    5, 15, 1,
                    3, 4, 1};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nSpecialElements = getCountOfSpecialElements(m);
    int expectedNSpecialElements = 3;
    assert(nSpecialElements == expectedNSpecialElements);
    freeMemMatrix(&m);
}

void test_getCountOfSpecialElements_colsMoreThanRows() {
    int source[] = {3, 1, 17, 10,
                    9, 5, 10, 6,
                    1, 4, 7, 30};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nSpecialElements = getCountOfSpecialElements(m);
    int expectedNSpecialElements = 2;
    assert(nSpecialElements == expectedNSpecialElements);
    freeMemMatrix(&m);
}

void test_getCountOfSpecialElements_squareMatrix_noSpecialElementsInMatrix() {
    int source[] = {3, 18, 4,
                    2, 3, 11,
                    5, 15, 7};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nSpecialElements = getCountOfSpecialElements(m);
    int expectedNSpecialElements = 0;
    assert(nSpecialElements == expectedNSpecialElements);
    freeMemMatrix(&m);
}

void test_getCountOfSpecialElements_rowsMoreThanCols_noSpecialElementsInMatrix() {
    int source[] = {4, 7, 5,
                    0, 21, 14,
                    31, 6, 22,
                    27, 8, 3};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nSpecialElements = getCountOfSpecialElements(m);
    int expectedNSpecialElements = 0;
    assert(nSpecialElements == expectedNSpecialElements);
    freeMemMatrix(&m);
}

void test_getCountOfSpecialElements_colsMoreThanRows_noSpecialElementsInMatrix() {
    int source[] = {28, 20, 8, 10,
                    6, 30, 3, 12,
                    22, 10, 5, 2};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nSpecialElements = getCountOfSpecialElements(m);
    int expectedNSpecialElements = 0;
    assert(nSpecialElements == expectedNSpecialElements);
    freeMemMatrix(&m);
}

void test_getCountOfSpecialElements() {
    test_getCountOfSpecialElements_squareMatrix();
    test_getCountOfSpecialElements_rowsMoreThanCols();
    test_getCountOfSpecialElements_colsMoreThanRows();
    test_getCountOfSpecialElements_squareMatrix_noSpecialElementsInMatrix();
    test_getCountOfSpecialElements_rowsMoreThanCols_noSpecialElementsInMatrix();
    test_getCountOfSpecialElements_colsMoreThanRows_noSpecialElementsInMatrix();
}

void test_getLeftMin_oneMinValueInMatrix() {
    int source[] = {14, 7, 4,
                    -3, 8, 2,
                    9, -1, 6};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    position leftMinPos = getLeftMin(m);
    position expectedPos = {1, 0};
    assert(areIdenticalPositions(leftMinPos, expectedPos));
    freeMemMatrix(&m);
}

void test_getLeftMin_someMinValuesInMatrix() {
    int source[] = {3, -5, 6, 1,
                    13, 9, 7, 11,
                    2, 4, 8, -5};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    position leftMinPos = getLeftMin(m);
    position expectedPos = {0, 1};
    assert(areIdenticalPositions(leftMinPos, expectedPos));
    freeMemMatrix(&m);
}

void test_getLeftMin() {
    test_getLeftMin_oneMinValueInMatrix();
    test_getLeftMin_someMinValuesInMatrix();
}

void test_swapPenultimateRow_squareMatrixOfSecondOrder() {
    int source[] = {2, -1,
                    9, 3};
    size_t nRows = 2;
    size_t nCols = 2;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    swapPenultimateRow(&m);
    int expectedSource[] = {-1, 3,
                            9, 3};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_swapPenultimateRow_squareMatrixOfThirdOrder() {
    int source[] = {1, 2, 3,
                    4, 5, 6,
                    7, 8, 1};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    swapPenultimateRow(&m);
    int expectedSource[] = {1, 2, 3,
                            1, 4, 7,
                            7, 8, 1};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}

void test_swapPenultimateRow_squareMatrixOfFourthOrder() {
    int source[] = {0, 2, 3, 5,
                    7, 3, 1, 4,
                    -18, 9, 6, 11,
                    3, 16, 7, 23};
    size_t nRows = 4;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    swapPenultimateRow(&m);
    int expectedSource[] = {0, 2, 3, 5,
                            7, 3, 1, 4,
                            0, 7, -18, 3,
                            3, 16, 7, 23};
    matrix expectedM = createMatrixFromArray(expectedSource,
                                             nRows, nCols);
    assert(areTwoMatricesEqual(m, expectedM));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedM);
}


void test_swapPenultimateRow() {
    test_swapPenultimateRow_squareMatrixOfSecondOrder();
    test_swapPenultimateRow_squareMatrixOfThirdOrder();
    test_swapPenultimateRow_squareMatrixOfFourthOrder();
}

void test_hasAllNonDescendingRows_squareMatrix() {
    int source[] = {1, 6,
                    2, 2};
    size_t nRows = 2;
    size_t nCols = 2;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    assert(hasAllNonDescendingRows(m));
    freeMemMatrix(&m);
}

void test_hasAllNonDescendingRows_rowsMoreThanCols() {
    int source[] = {-1, 3,
                    7, 9,
                    15, 25};
    size_t nRows = 3;
    size_t nCols = 2;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    assert(hasAllNonDescendingRows(m));
    freeMemMatrix(&m);
}

void test_hasAllNonDescendingRows_colsMoreThanRows() {
    int source[] = {3, 6, 9, 12,
                    1, 1, 2, 2,
                    2, 5, 7, 13};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    assert(hasAllNonDescendingRows(m));
    freeMemMatrix(&m);
}

void test_hasAllNonDescendingRows_squareMatrix_someRowsIsNotNonDescending() {
    int source[] = {1, 8, 8, 19,
                    15, 12, 16, 16,
                    1, 1, -7, -9,
                    15, 6, 5, 4};
    size_t nRows = 4;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    assert(!hasAllNonDescendingRows(m));
    freeMemMatrix(&m);
}

void test_hasAllNonDescendingRows_rowsMoreThanCols_someRowsIsNotNonDescending() {
    int source[] = {8, 5, 3,
                    16, 16, 19,
                    -3, 7, 11,
                    31, 29, 27};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    assert(!hasAllNonDescendingRows(m));
    freeMemMatrix(&m);
}

void test_hasAllNonDescendingRows_colsMoreThanRows_someRowsIsNotNonDescending() {
    int source[] = {5, 9, 7, 2, 0,
                    -1, 1, 2, 2, 5,
                    3, 5, 7, 9, 11,
                    4, 2, 0, -2, -4};
    size_t nRows = 4;
    size_t nCols = 5;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    assert(!hasAllNonDescendingRows(m));
    freeMemMatrix(&m);
}

void test_hasAllNonDescendingRows() {
    test_hasAllNonDescendingRows_squareMatrix();
    test_hasAllNonDescendingRows_rowsMoreThanCols();
    test_hasAllNonDescendingRows_colsMoreThanRows();
    test_hasAllNonDescendingRows_squareMatrix_someRowsIsNotNonDescending();
    test_hasAllNonDescendingRows_rowsMoreThanCols_someRowsIsNotNonDescending();
    test_hasAllNonDescendingRows_colsMoreThanRows_someRowsIsNotNonDescending();
}

void test_countNonDescendingRowsMatrices_squareMatrices_msHasRequestedMatrices() {
    int source[] = {7, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    7, 9};
    size_t nRows = 2;
    size_t nCols = 2;
    size_t nMatrices = 4;
    matrix *ms = createArrayOfMatrixFromArray(source, nMatrices,
                                              nRows, nCols);
    int nNonDescendingRowsMatrices = countNonDescendingRowsMatrices(ms,
                                                                    nMatrices);
    int expectedNNonDescendingRowsMatrices = 2;
    assert(nNonDescendingRowsMatrices ==
           expectedNNonDescendingRowsMatrices);
    freeMemMatrices(ms, nMatrices);
}

void test_countNonDescendingRowsMatrices_rowsMoreThanColsMatrices_msHasRequestedMatrices() {
    int source[] = {-5, 3,
                    1, 2,
                    0, 7,

                    4, 6,
                    2, 8,
                    11, 12,

                    9, 2,
                    5, 5,
                    6, 3};
    size_t nRows = 3;
    size_t nCols = 2;
    size_t nMatrices = 3;
    matrix *ms = createArrayOfMatrixFromArray(source, nMatrices,
                                              nRows, nCols);
    int nNonDescendingRowsMatrices = countNonDescendingRowsMatrices(ms,
                                                                    nMatrices);
    int expectedNNonDescendingRowsMatrices = 2;
    assert(nNonDescendingRowsMatrices ==
           expectedNNonDescendingRowsMatrices);
    freeMemMatrices(ms, nMatrices);
}

void test_countNonDescendingRowsMatrices_colsMoreThanRowsMatrices_msHasRequestedMatrices() {
    int source[] = {2, 1, 0,
                    1, 5, 12,

                    4, 5, 7,
                    -2, 0, 1,

                    1, 1, 4,
                    1, 0, 1};
    size_t nRows = 2;
    size_t nCols = 3;
    size_t nMatrices = 3;
    matrix *ms = createArrayOfMatrixFromArray(source, nMatrices,
                                              nRows, nCols);
    int nNonDescendingRowsMatrices = countNonDescendingRowsMatrices(ms,
                                                                    nMatrices);
    int expectedNNonDescendingRowsMatrices = 1;
    assert(nNonDescendingRowsMatrices ==
           expectedNNonDescendingRowsMatrices);
    freeMemMatrices(ms, nMatrices);
}

void test_countNonDescendingRowsMatrices_squareMatrices_msHasNotRequestedMatrices() {
    int source[] = {11, 8,
                    3, 3,

                    2, -1,
                    4, 3,

                    2, 2,
                    19, 17};
    size_t nRows = 2;
    size_t nCols = 2;
    size_t nMatrices = 3;
    matrix *ms = createArrayOfMatrixFromArray(source, nMatrices,
                                              nRows, nCols);
    int nNonDescendingRowsMatrices = countNonDescendingRowsMatrices(ms,
                                                                    nMatrices);
    int expectedNNonDescendingRowsMatrices = 0;
    assert(nNonDescendingRowsMatrices ==
           expectedNNonDescendingRowsMatrices);
    freeMemMatrices(ms, nMatrices);
}

void test_countNonDescendingRowsMatrices_rowsMoreThanColsMatrices_msHasNotRequestedMatrices() {
    int source[] = {25, 25,
                    6, 5,
                    1, 2,

                    8, 8,
                    6, 4,
                    3, 2,

                    0, 0,
                    7, 9,
                    2, -3};
    size_t nRows = 3;
    size_t nCols = 2;
    size_t nMatrices = 3;
    matrix *ms = createArrayOfMatrixFromArray(source, nMatrices,
                                              nRows, nCols);
    int nNonDescendingRowsMatrices = countNonDescendingRowsMatrices(ms,
                                                                    nMatrices);
    int expectedNNonDescendingRowsMatrices = 0;
    assert(nNonDescendingRowsMatrices ==
           expectedNNonDescendingRowsMatrices);
    freeMemMatrices(ms, nMatrices);
}

void test_countNonDescendingRowsMatrices_colsMoreThanRowsMatrices_msHasNotRequestedMatrices() {
    int source[] = {7, 5, 6,
                    4, 7, 2,

                    1, 1, 0,
                    5, 6, 7,

                    3, 2, 1,
                    1, 3, 9};
    size_t nRows = 2;
    size_t nCols = 3;
    size_t nMatrices = 3;
    matrix *ms = createArrayOfMatrixFromArray(source, nMatrices,
                                              nRows, nCols);
    int nNonDescendingRowsMatrices = countNonDescendingRowsMatrices(ms,
                                                                    nMatrices);
    int expectedNNonDescendingRowsMatrices = 0;
    assert(nNonDescendingRowsMatrices ==
           expectedNNonDescendingRowsMatrices);
    freeMemMatrices(ms, nMatrices);
}

void test_countNonDescendingRowsMatrices() {
    test_countNonDescendingRowsMatrices_squareMatrices_msHasRequestedMatrices();
    test_countNonDescendingRowsMatrices_rowsMoreThanColsMatrices_msHasRequestedMatrices();
    test_countNonDescendingRowsMatrices_colsMoreThanRowsMatrices_msHasRequestedMatrices();
    test_countNonDescendingRowsMatrices_squareMatrices_msHasNotRequestedMatrices();
    test_countNonDescendingRowsMatrices_rowsMoreThanColsMatrices_msHasNotRequestedMatrices();
    test_countNonDescendingRowsMatrices_colsMoreThanRowsMatrices_msHasNotRequestedMatrices();
}

void test_countZeroRows_squareMatrix_matrixHasZeroRows() {
    int source[] = {3, 17, 16,
                    0, 0, 0,
                    0, 0, 0};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nZeroRows = countZeroRows(m);
    int expectedNZeroRows = 2;
    assert(nZeroRows == expectedNZeroRows);
    freeMemMatrix(&m);
}

void test_countZeroRows_rowsMoreThanCols_matrixHasZeroRows() {
    int source[] = {0, 0,
                    0, -1,
                    4, 7};
    size_t nRows = 3;
    size_t nCols = 2;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nZeroRows = countZeroRows(m);
    int expectedNZeroRows = 1;
    assert(nZeroRows == expectedNZeroRows);
    freeMemMatrix(&m);
}

void test_countZeroRows_colsMoreThanRows_matrixHasZeroRows() {
    int source[] = {14, 2, 7, 1,
                    0, 0, 0, 0,
                    0, -8, 0, 0};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nZeroRows = countZeroRows(m);
    int expectedNZeroRows = 1;
    assert(nZeroRows == expectedNZeroRows);
    freeMemMatrix(&m);
}

void test_countZeroRows_squareMatrix_matrixHasNotZeroRows() {
    int source[] = {4, 0, 2,
                    5, 7, -9,
                    0, 2, 1};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nZeroRows = countZeroRows(m);
    int expectedNZeroRows = 0;
    assert(nZeroRows == expectedNZeroRows);
    freeMemMatrix(&m);
}

void test_countZeroRows_rowsMoreThanCols_matrixHasNotZeroRows() {
    int source[] = {1, 1,
                    2, 1,
                    1, 1};
    size_t nRows = 3;
    size_t nCols = 2;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nZeroRows = countZeroRows(m);
    int expectedNZeroRows = 0;
    assert(nZeroRows == expectedNZeroRows);
    freeMemMatrix(&m);
}

void test_countZeroRows_colsMoreThanRows_matrixHasNotZeroRows() {
    int source[] = {1, 1, 0, 0,
                    15, 3, -9, 6,
                    3, 4, 7, 0};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int nZeroRows = countZeroRows(m);
    int expectedNZeroRows = 0;
    assert(nZeroRows == expectedNZeroRows);
    freeMemMatrix(&m);
}

void test_countZeroRows() {
    test_countZeroRows_squareMatrix_matrixHasZeroRows();
    test_countZeroRows_rowsMoreThanCols_matrixHasZeroRows();
    test_countZeroRows_colsMoreThanRows_matrixHasZeroRows();
    test_countZeroRows_squareMatrix_matrixHasNotZeroRows();
    test_countZeroRows_rowsMoreThanCols_matrixHasNotZeroRows();
    test_countZeroRows_colsMoreThanRows_matrixHasNotZeroRows();
}

void test_isMatrixArrayOfSquareMatrices_matrixArrayOfSquareMatrices() {
    int source[] = {2, 3,
                    6, 0,

                    -12, 12,
                    3, 2,

                    5, -4,
                    8, 12};
    size_t nRows = 2;
    size_t nCols = 2;
    size_t nMatrices = 3;
    matrix *ms = createArrayOfMatrixFromArray(source, nMatrices,
                                              nRows, nCols);
    assert(isMatrixArrayOfSquareMatrices(ms));
    freeMemMatrices(ms, nMatrices);
}

void test_isMatrixArrayOfSquareMatrices_matrixArrayOfRowsMoreThanColsMatrices() {
    int source[] = {1, 7,
                    7, -2,
                    5, 4,

                    3, 4,
                    -6, 1,
                    8, 95,

                    3, 5,
                    0, 4,
                    -2, 3};
    size_t nRows = 3;
    size_t nCols = 2;
    size_t nMatrices = 3;
    matrix *ms = createArrayOfMatrixFromArray(source, nMatrices,
                                              nRows, nCols);
    assert(!isMatrixArrayOfSquareMatrices(ms));
    freeMemMatrices(ms, nMatrices);
}

void test_isMatrixArrayOfSquareMatrices_matrixArrayOfColsMoreThanRowsMatrices() {
    int source[] = {1, -4, 7,
                    7, 8, 1,

                    1, 0, 2,
                    0, 0, -1,

                    25, 35, 45,
                    3, 7, -9};
    size_t nRows = 2;
    size_t nCols = 3;
    size_t nMatrices = 3;
    matrix *ms = createArrayOfMatrixFromArray(source, nMatrices,
                                              nRows, nCols);
    assert(!isMatrixArrayOfSquareMatrices(ms));
    freeMemMatrices(ms, nMatrices);
}

void test_isMatrixArrayOfSquareMatrices() {
    test_isMatrixArrayOfSquareMatrices_matrixArrayOfSquareMatrices();
    test_isMatrixArrayOfSquareMatrices_matrixArrayOfRowsMoreThanColsMatrices();
    test_isMatrixArrayOfSquareMatrices_matrixArrayOfColsMoreThanRowsMatrices();
}

void test_getMatrixNorm_squareMatrix() {
    int source[] = {3, 5, 1,
                    -35, 6, 7,
                    2, 4, 6};
    size_t nRows = 3;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int norm = getMatrixNorm(m);
    int expectedNorm = 35;
    assert(norm == expectedNorm);
    freeMemMatrix(&m);
}

void test_getMatrixNorm_rowsMoreThanCols() {
    int source[] = {-5, 1, 5,
                    2, 18, 2,
                    3, 1, -3,
                    4, 6, 1};
    size_t nRows = 4;
    size_t nCols = 3;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int norm = getMatrixNorm(m);
    int expectedNorm = 18;
    assert(norm == expectedNorm);
    freeMemMatrix(&m);
}

void test_getMatrixNorm_colsMoreThanRows() {
    int source[] = {3, 2, 0, 5,
                    4, -3, 5, 0,
                    1, 0, -2, 3};
    size_t nRows = 3;
    size_t nCols = 4;
    matrix m = createMatrixFromArray(source, nRows, nCols);
    int norm = getMatrixNorm(m);
    int expectedNorm = 5;
    assert(norm == expectedNorm);
    freeMemMatrix(&m);
}

void test_getMatrixNorm() {
    test_getMatrixNorm_squareMatrix();
    test_getMatrixNorm_rowsMoreThanCols();
    test_getMatrixNorm_colsMoreThanRows();
}

void test_matrix_tasks() {
    test_swapRowsWithMaxAndMinValuesOfSquareMatrix();
    test_sortRowsByMaxElement();
    test_sortColsByMinElement();
    test_mulMatrices();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumsOfRows();
    test_areMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_minInArea();
    test_selectionSortRowsMatrixByRowCriteriaF();
    test_sortByDistances();
    test_countOfClassesOfEqRowsByRowSum();
    test_getCountOfSpecialElements();
    test_getLeftMin();
    test_swapPenultimateRow();
    test_hasAllNonDescendingRows();
    test_countNonDescendingRowsMatrices();
    test_countZeroRows();
    test_isMatrixArrayOfSquareMatrices();
    test_getMatrixNorm();
}

void test_matrix() {
    test_matrix_lib();
    test_matrix_tasks();
}