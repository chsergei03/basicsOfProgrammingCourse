#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <memory.h>

#include "tasks_matrix.h"

// задача 1.

void swapRowsWithMaxAndMinValuesOfSquareMatrix(matrix *m) {
    printErrorMessageIfMatrixIsNotSquare(*m);

    position minValuePos = getMinValuePos(*m);
    position maxValuePos = getMaxValuePos(*m);

    swapRows(m, minValuePos.rowIndex, maxValuePos.rowIndex);
}

// задача 2.

void sortRowsByMaxElements(matrix *m) {
    selectionSortRowsMatrixByRowCriteria(m,
                                         (int (*)(int *, size_t)) getMax_);
}

// задача 3.

void sortColsByMinElements(matrix *m) {
    selectionSortColsMatrixByColCriteria(m,
                                         (int (*)(int *, size_t)) getMin_);
}

// задача 4.

void printErrorMessageIfNColsOfMatrix1IsNotEqualToNRowsOfMatrix2(const matrix m1,
                                                                 const matrix m2) {
    if (m1.nCols != m2.nRows) {
        fprintf(stderr, "nCols of first matrix is not equal to nRows of second matrix");
        exit(1);
    }
}

matrix mulMatrices(const matrix m1, const matrix m2) {
    printErrorMessageIfNColsOfMatrix1IsNotEqualToNRowsOfMatrix2(m1, m2);

    matrix mulMatrix = getMemMatrix(m1.nRows, m2.nCols);
    for (size_t i = 0; i < m1.nRows; i++)
        for (size_t j = 0; j < m2.nCols; j++) {
            int matrixElement = 0;
            for (size_t k = 0; k < m1.nCols; k++)
                matrixElement += m1.values[i][k] * m2.values[k][j];
            mulMatrix.values[i][j] = matrixElement;
        }

    return mulMatrix;
}

void printErrorMessageIfMatrixIsNotSymmetric(const matrix m) {
    if (!isSymmetricMatrix(m)) {
        fprintf(stderr, "matrix is not symmetric");
    }
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    printErrorMessageIfMatrixIsNotSymmetric(*m);

    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

// задача 5.

void printErrorMessageIfSumsOfRowsArrayIsNotArrayOfUniqueElements(const long long *const a,
                                                                  const size_t n) {
    if (!isUnique_longLong_(a, n)) {
        fprintf(stderr,
                "array of sums of rows is not array of unique elements");
        exit(1);
    }
}

void transposeIfMatrixHasNotEqualSumsOfRows(matrix *m) {
    printErrorMessageIfMatrixIsNotSquare(*m);

    long long *rowSumsArray = (long long *) malloc(m->nRows *
                                                   sizeof(long long));
    for (size_t i = 0; i < m->nRows; i++) {
        rowSumsArray[i] = getSum_(m->values[i], m->nCols);
    }

    printErrorMessageIfSumsOfRowsArrayIsNotArrayOfUniqueElements(rowSumsArray,
                                                                 m->nRows);

    transposeSquareMatrix(m);

    free(rowSumsArray);
}

// задача 6.

bool areMutuallyInverseMatrices(const matrix m1, const matrix m2) {
    matrix mulMatrix = mulMatrices(m1, m2);

    bool isEMatrixFlag = isEMatrix(mulMatrix);

    freeMemMatrix(&mulMatrix);

    return isEMatrixFlag;
}

// задача 7.

bool isSquareMatrixOfFirstOrder(const matrix m) {
    return m.nRows * m.nCols == 1;
}

long long findSumOfMaxesOfPseudoDiagonals(const matrix m) {
    if (isSquareMatrixOfFirstOrder(m))
        return 0;

    size_t nOfMaxes = m.nRows + m.nCols - 2;
    int *arrayOfMaxes = (int *) malloc(nOfMaxes * sizeof(int));

    size_t iWrite = 0;
    for (size_t i = m.nRows - 1; i > 0; i--) {
        arrayOfMaxes[iWrite] = m.values[i][0];
        iWrite += 1;
    }

    for (size_t j = 1; j < m.nCols; j++) {
        arrayOfMaxes[iWrite] = m.values[0][j];
        iWrite += 1;
    }

    iWrite = nOfMaxes - 2;
    for (size_t i = 1; i < m.nRows; i++) {
        for (size_t j = m.nCols - 1; j > 0; j--) {
            if (i != j) {
                arrayOfMaxes[iWrite] = max2_int(arrayOfMaxes[iWrite],
                                                m.values[i][j]);
                iWrite -= 1;
            }
        }
        iWrite += 1;
    }

    long long sumOfMaxesOfPseudoDiagonals = getSum_(arrayOfMaxes, nOfMaxes);

    free(arrayOfMaxes);

    return sumOfMaxesOfPseudoDiagonals;
}

// задача 8.

int getMinInArea(const matrix m) {
    position maxPos = getMaxValuePos(m);

    int min = m.values[maxPos.rowIndex][maxPos.colIndex];
    size_t i = maxPos.rowIndex - 1;
    size_t j = maxPos.colIndex - 1;
    size_t currentRowLen = 1;
    while (i < m.nRows && j < m.nRows) {
        if (m.nCols - currentRowLen >= 2)
            currentRowLen += 2;
        else if (m.nCols - currentRowLen == 1)
            currentRowLen += 1;

        for (size_t k = j; k < currentRowLen; k++)
            if (m.values[i][k] < min)
                min = m.values[i][k];

        i += i > 0 ? -1 : m.nRows;
        j += j > 0 ? -1 : m.nCols;
    }

    return min;
}

// задача 9.

float getDistance(const int *const a,
                  const size_t n) {
    int squaresSum = 0;
    for (size_t i = 0; i < n; i++)
        squaresSum += a[i] * a[i];

    return sqrtf((float) squaresSum);
}

float getArithmeticMean(const int *const a,
                        const size_t n) {
    long long sum = getSum_(a, n);

    return (float) sum / (float) n;
}

float *getFilledCriteriaValuesArrayForRows_float(const matrix m,
                                                 float (*criteria)(int *, size_t)) {
    float *criteriaValueArray = (float *) malloc(m.nRows *
                                                 sizeof(float));
    for (size_t i = 0; i < m.nRows; i++)
        criteriaValueArray[i] = criteria(m.values[i], m.nCols);

    return criteriaValueArray;
}

void selectionSortRowsMatrixByRowCriteriaF(matrix *m,
                                           float (*criteria)(int *, size_t)) {
    float *criteriaValuesArray = getFilledCriteriaValuesArrayForRows_float(*m,
                                                                           criteria);

    for (size_t i = 0; i < m->nRows; i++) {
        size_t minPos = getMinPos_float_(criteriaValuesArray, m->nRows, i);
        void_swap(&criteriaValuesArray[i],
                  &criteriaValuesArray[minPos],
                  sizeof(float));
        swapRows(m, i, minPos);
    }

    free(criteriaValuesArray);
}

void sortByDistances(matrix *m) {
    selectionSortRowsMatrixByRowCriteriaF(m,
                                          (float (*)(int *, size_t)) getDistance);
}

// задача 10.

int countOfRowsWithUniqueSumOfElements(const long long *const a,
                                       const size_t n) {
    int count = 0;
    long long currentSum = a[0];
    int basicLen = 1;
    int lenOfEqualValuesSequence = basicLen;
    int lenOfRowsWithUniqueRowSumSequence = 1;
    for (size_t i = 1; i < n; i++) {
        if (a[i] != currentSum) {
            currentSum = a[i];
            count += lenOfEqualValuesSequence == basicLen;
            lenOfEqualValuesSequence = basicLen;
            lenOfRowsWithUniqueRowSumSequence += 1;
        } else {
            lenOfEqualValuesSequence += 1;
            lenOfRowsWithUniqueRowSumSequence -= lenOfRowsWithUniqueRowSumSequence > 0;
        }

    }

    return lenOfRowsWithUniqueRowSumSequence == n ? (int) n : count;
}

int countOfClassesOfEqRowsByRowSum(const matrix m) {
    long long *rowSumsArray = getFilledCriteriaValuesArrayForRows(m,
                                                                  (int (*)(int *, size_t)) getSum_);

    qsort(rowSumsArray, m.nRows,
          sizeof(long long), compare_longLong);

    int nRowsWithUniqueSumOfElements = countOfRowsWithUniqueSumOfElements(rowSumsArray,
                                                                          m.nRows);

    long long currentRowSum = rowSumsArray[0];
    int nClasses = 1;
    for (size_t i = 1; i < m.nRows; i++) {
        if (rowSumsArray[i] > currentRowSum) {
            currentRowSum = rowSumsArray[i];
            nClasses += 1;
        }
    }

    free(rowSumsArray);

    return nClasses - nRowsWithUniqueSumOfElements;
}

// задача 11.

int getCountOfSpecialElements(const matrix m) {
    long long *colSumsArray = getFilledCriteriaValuesArrayForCols(m,
                                                                  (int (*)(int *, size_t)) getSum_);

    int count = 0;
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            if (2 * m.values[i][j] > colSumsArray[j])
                count += 1;

    free(colSumsArray);

    return count;
}

// задача 12.

position getLeftMin(const matrix m) {
    size_t leftMinRowIndex = 0;
    size_t leftMinColIndex = 0;
    int leftMin = m.values[leftMinRowIndex][leftMinColIndex];

    for (size_t j = 0; j < m.nCols; j++)
        for (size_t i = 0; i < m.nRows; i++)
            if (m.values[i][j] < leftMin) {
                leftMin = m.values[i][j];
                leftMinRowIndex = i;
                leftMinColIndex = j;
            }

    return (position) {leftMinRowIndex, leftMinColIndex};
}

void printErrorMessageIfMatrixHasNotPenultimateRow(const matrix m) {
    if (m.nRows < 2) {
        fprintf(stderr, "matrix has not penultimate row");
        exit(1);
    }
}

void swapPenultimateRow(matrix *m) {
    printErrorMessageIfMatrixIsNotSquare(*m);
    printErrorMessageIfMatrixHasNotPenultimateRow(*m);

    position firstMinPos = getLeftMin(*m);

    int *colWithFirstMin = (int *) malloc(m->nRows * sizeof(int));
    copyElementsOfColToArray(colWithFirstMin, m, firstMinPos.colIndex);

    memcpy(m->values[m->nRows - 2], colWithFirstMin, m->nCols * sizeof(int));

    free(colWithFirstMin);
}

// задача 13.

bool hasAllNonDescendingRows(const matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        if (!isNonDescendingSortedArray_(m.values[i], m.nCols))
            return false;

    return true;
}

int countNonDescendingRowsMatrices(const matrix *ms,
                                   const size_t nMatrices) {
    int count = 0;
    for (size_t matrixIndex = 0; matrixIndex < nMatrices; matrixIndex++)
        count += hasAllNonDescendingRows(ms[matrixIndex]);

    return count;
}

// задача 14.

int countZeroRows(const matrix m) {
    int nZeroRows = 0;
    for (size_t i = 0; i < m.nRows; i++)
        nZeroRows += countValues_(m.values[i], m.nCols, 0) == m.nCols;

    return nZeroRows;
}

int *getFilledCriteriaValuesArrayForMatrices(const matrix *ms,
                                             const size_t nMatrices,
                                             int (*criteria)(matrix)) {
    int *criteriaValuesArray = (int *) malloc(nMatrices * sizeof(int));

    for (size_t i = 0; i < nMatrices; i++)
        criteriaValuesArray[i] = criteria(ms[i]);

    return criteriaValuesArray;
}

void printMatricesWithMaxValueOfZeroRows(const matrix *ms,
                                         const size_t nMatrices) {
    int *nZeroRowsArray = getFilledCriteriaValuesArrayForMatrices(ms, nMatrices,
                                                                  countZeroRows);

    int nZeroRowsMaxValue = getMax_(nZeroRowsArray, nMatrices);

    for (size_t matrixIndex = 0; matrixIndex < nMatrices; matrixIndex++)
        if (countZeroRows(ms[matrixIndex]) == nZeroRowsMaxValue)
            outputMatrix(ms[matrixIndex]);
}

// задача 15.

bool isMatrixArrayOfSquareMatrices(const matrix *ms) {
    return isSquareMatrix(ms[0]);
}

int getMatrixNorm(const matrix m) {
    int norm = abs_int(m.values[0][0]);

    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            norm = max2_int(abs_int(m.values[i][j]), norm);

    return norm;
}

void printErrorMessageIfMatricesInMatrixArrayAreNotSquare(const matrix *ms) {
    if (!isMatrixArrayOfSquareMatrices(ms)) {
        fprintf(stderr, "ms is not matrix array of square matrices");
        exit(1);
    }
}

void printMatricesWithMinNorm(const matrix *ms,
                              const size_t nMatrices) {
    printErrorMessageIfMatricesInMatrixArrayAreNotSquare(ms);

    int *matricesNormsArray = getFilledCriteriaValuesArrayForMatrices(ms, nMatrices,
                                                                      getMatrixNorm);

    int normMinValue = getMin_(matricesNormsArray, nMatrices);

    for (size_t matrixIndex = 0; matrixIndex < nMatrices; matrixIndex++)
        if (getMatrixNorm(ms[matrixIndex]) == normMinValue)
            outputMatrix(ms[matrixIndex]);
}