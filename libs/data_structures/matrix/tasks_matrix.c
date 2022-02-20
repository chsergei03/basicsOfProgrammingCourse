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