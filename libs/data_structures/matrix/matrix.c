#include <stdio.h>
#include <assert.h>
#include <malloc.h>

#include "matrix.h"

void isIncorrectMemoryAllocForPointersArray(const int **pointerArrayData) {
    if (pointerArrayData == NULL) {
        fprintf(stderr, "bad alloc for pointers array");
        exit(1);
    }
}

void isIncorrectMemoryAllocForRow(const int *rowData) {
    if (rowData == NULL) {
        fprintf(stderr, "bad alloc for row");
        exit(1);
    }
}

void isIncorrectMemoryAllocForMatrixArray(const matrix *matrixDataArray) {
    if (matrixDataArray == NULL) {
        fprintf(stderr, "bad alloc for matrix array");
        exit(1);
    }
}

matrix getMemMatrix(const size_t nRows, const size_t nCols) {
    int **values = (int **) malloc(nRows * sizeof(int *));

    isIncorrectMemoryAllocForPointersArray((const int **) values);

    for (size_t i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(nCols * sizeof(int));

        isIncorrectMemoryAllocForRow(values[i]);
    }

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(const size_t nMatrices,
                              const size_t nRows,
                              const size_t nCols) {
    matrix *ms = (matrix *) malloc(nMatrices * sizeof(matrix));

    isIncorrectMemoryAllocForMatrixArray(ms);

    for (size_t i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix *m) {
    for (size_t i = 0; i < m->nRows; i++)
        free(m->values[i]);

    free(m->values);
}

void freeMemMatrices(matrix *ms,
                     const size_t nMatrices) {
    for (size_t i = 0; i < nMatrices; i++)
        freeMemMatrix(&ms[i]);

    free(ms);
}

void inputMatrix(matrix *m) {
    for (size_t i = 0; i < m->nRows; i++)
        for (size_t j = 0; j < m->nCols; j++)
            scanf("%d", &m->values[i][j]);
}

void inputMatrices(matrix *ms,
                   const size_t nMatrices) {
    for (size_t i = 0; i < nMatrices; i++)
        inputMatrix(&ms[i]);
}

void outputMatrix(const matrix m) {
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
    printf("\n");
}

void outputMatrices(const matrix *ms, const size_t nMatrices) {
    for (size_t i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void swapRows(matrix *m, const size_t i1, const size_t i2) {
    void_swap(&m->values[i1],
              &m->values[i2],
              sizeof(int *));
}

void swapCols(matrix *m, const size_t j1, const size_t j2) {
    for (int i = 0; i < m->nRows; i++)
        void_swap(&m->values[i][j1],
                  &m->values[i][j2],
                  sizeof(int));
}

long long *getFilledCriteriaValuesArrayForRows(const matrix m,
                                               int (*criteria)(int *, size_t)) {
    long long *criteriaValuesArray = (long long *) malloc(m.nRows *
                                                          sizeof(long long));
    for (size_t i = 0; i < m.nRows; i++)
        criteriaValuesArray[i] = criteria(m.values[i], m.nCols);

    return criteriaValuesArray;
}

void selectionSortRowsMatrixByRowCriteria(matrix *m,
                                          int (*criteria)(int *, size_t)) {
    long long *criteriaValuesArray = getFilledCriteriaValuesArrayForRows(*m,
                                                                         criteria);

    for (size_t i = 0; i < m->nRows; i++) {
        size_t minPos = getMinPos_longLong_(criteriaValuesArray,
                                            m->nRows,
                                            i);
        void_swap(&criteriaValuesArray[i],
                  &criteriaValuesArray[minPos],
                  sizeof(long long));
        swapRows(m, i, minPos);
    }

    free(criteriaValuesArray);
}

void copyElementsOfColToArray(int *dest,
                              const matrix *m,
                              const size_t sourceColIndex) {
    for (int i = 0; i < m->nRows; i++)
        dest[i] = m->values[i][sourceColIndex];
}

long long *getFilledCriteriaValuesArrayForCols(const matrix m,
                                               int (*criteria)(int *, size_t)) {
    long long *criteriaValuesArray = (long long *) malloc(m.nCols *
                                                          sizeof(long long));
    int *currentCol = (int *) malloc(m.nRows * sizeof(int));

    for (size_t i = 0; i < m.nCols; i++) {
        copyElementsOfColToArray(currentCol, &m, i);
        criteriaValuesArray[i] = criteria(currentCol, m.nRows);
    }

    free(currentCol);

    return criteriaValuesArray;
}

void selectionSortColsMatrixByColCriteria(matrix *m,
                                          int (*criteria)(int *, size_t)) {
    long long *criteriaValuesArray = getFilledCriteriaValuesArrayForCols(*m,
                                                                         criteria);

    for (size_t i = 0; i < m->nCols; i++) {
        size_t minPos = getMinPos_longLong_(criteriaValuesArray,
                                            m->nCols,
                                            i);
        void_swap(&criteriaValuesArray[i],
                  &criteriaValuesArray[minPos],
                  sizeof(long long));
        swapCols(m, i, minPos);
    }

    free(criteriaValuesArray);
}

bool isSquareMatrix(const matrix m) {
    return m.nRows == m.nCols;
}

bool areTwoMatricesEqual(const matrix m1,
                         const matrix m2) {
    bool areEqualDimensions = m1.nRows == m2.nRows &&
                              m1.nCols == m2.nCols;
    if (!areEqualDimensions)
        return false;

    for (size_t i = 0; i < m1.nRows; i++)
        for (size_t j = 0; j < m1.nCols; j++)
            if (m1.values[i][j] != m2.values[i][j])
                return false;

    return true;
}

bool isEMatrix(const matrix m) {
    if (!isSquareMatrix(m))
        return false;

    for (size_t i = 0; i < m.nRows; i++) {
        long long rowSum = getSum_(m.values[i], m.nCols);
        if (m.values[i][i] != 1 || rowSum != 1)
            return false;
    }

    return true;
}

bool isSymmetricMatrix(const matrix m) {
    if (!isSquareMatrix(m))
        return false;

    for (size_t i = 1, j = 0; i < m.nRows; i++, j++)
        for (size_t k = i; k < m.nRows; k++)
            if (m.values[k][j] != m.values[j][k])
                return false;

    return true;
}

void printErrorMessageIfMatrixIsNotSquare(const matrix m) {
    if (!isSquareMatrix(m)) {
        fprintf(stderr, "matrix is not square");
        exit(1);
    }
}

void transposeSquareMatrix(matrix *m) {
    printErrorMessageIfMatrixIsNotSquare(*m);

    for (size_t i = 1, j = 0; i < m->nRows; i++, j++)
        for (size_t k = i; k < m->nRows; k++)
            void_swap(&m->values[k][j],
                      &m->values[j][k],
                      sizeof(int));
}

bool minValueCriteria(const int value, const int currentMin) {
    bool isValueLessThanCurrentMin = value < currentMin;

    return isValueLessThanCurrentMin;
}

bool maxValueCriteria(const int value, const int currentMax) {
    bool isValueMoreThanCurrentMin = value > currentMax;

    return isValueMoreThanCurrentMin;
}

position getPosByValueCriteria(const matrix m,
                               int (*valueCriteria)(int, int)) {
    size_t valueRowIndex = 0;
    size_t valueColIndex = 0;
    int value = m.values[valueRowIndex][valueColIndex];
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            if (valueCriteria(m.values[i][j], value)) {
                value = m.values[i][j];
                valueRowIndex = i;
                valueColIndex = j;
            }
        }
    }

    return (position) {valueRowIndex, valueColIndex};
}

position getMinValuePos(const matrix m) {
    return getPosByValueCriteria(m,
                                 (int (*)(int, int)) minValueCriteria);
}

position getMaxValuePos(const matrix m) {
    return getPosByValueCriteria(m,
                                 (int (*)(int, int)) maxValueCriteria);
}

bool areIdenticalPositions(const position pos1,
                           const position pos2) {
    return pos1.rowIndex == pos2.rowIndex &&
           pos1.colIndex == pos2.colIndex;
}

matrix createMatrixFromArray(const int *a,
                             const size_t nRows,
                             const size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    size_t k = 0;
    for (size_t i = 0; i < nRows; i++)
        for (size_t j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values,
                                     const size_t nMatrices,
                                     const size_t nRows,
                                     const size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    size_t l = 0;

    for (size_t k = 0; k < nMatrices; k++)
        for (size_t i = 0; i < nRows; i++)
            for (size_t j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}