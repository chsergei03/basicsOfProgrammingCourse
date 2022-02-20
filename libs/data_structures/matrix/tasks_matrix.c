#include <assert.h>

#include "tasks_matrix.h"

void swapRowsWithMaxAndMinValuesOfSquareMatrix(matrix *m) {
    matrix m2 = *m;
    assert(isSquareMatrix(m2));

    position minValuePos = getMinValuePos(m2);
    position maxValuePos = getMaxValuePos(m2);

    swapRows(m, minValuePos.rowIndex, maxValuePos.rowIndex);
}

void sortRowsByMaxElements(matrix *m) {
    selectionSortRowsMatrixByRowCriteria(m,
                                         (int (*)(int *, size_t)) getMax_);
}

void sortColsByMinElements(matrix *m) {
    selectionSortColsMatrixByColCriteria(m,
                                         (int (*)(int *, size_t)) getMin_);
}

matrix mulMatrices(const matrix m1, const matrix m2) {
    assert(m1.nCols == m2.nRows);

    matrix mulMatrix = getMemMatrix(m1.nRows, m2.nCols);
    int mV;
    for (size_t i = 0; i < m1.nRows; i++)
        for (size_t j = 0; j < m2.nCols; j++) {
            int matrixElement = 0;
            for (size_t k = 0; k < m1.nCols; k++)
                matrixElement += m1.values[i][k] * m2.values[k][j];
            mulMatrix.values[i][j] = matrixElement;
        }

    return mulMatrix;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    assert(isSymmetricMatrix(*m));

    *m = mulMatrices(*m, *m);
}