#ifndef INC_TEST_MATRIX_H
#define INC_TEST_MATRIX_H

#include "../../../libs/data_structures/matrix/matrix.h"
#include "../../../libs/data_structures/matrix/tasks/tasks_matrix.h"

void test_swapRows_squareMatrix();

void test_swapRows_rowsMoreThanCols();

void test_swapRows_colsMoreThanRows();

void test_swapRows();

void test_swapCols_squareMatrix();

void test_swapCols_rowsMoreThanCols();

void test_swapCols_colsMoreThanRows();

void test_swapCols();

void test_selectionSortRowsMatrixByRowCriteria_squareMatrix();

void test_selectionSortRowsMatrixByRowCriteria_rowsMoreThanCols();

void test_selectionSortRowsMatrixByRowCriteria_colsMoreThanRows();

void test_selectionSortRowsMatrixByRowCriteria_squareMatrix_someEqualCriteriaValues();

void test_selectionSortRowsMatrixByRowCriteria_rowsMoreThanCols_someEqualCriteriaValues();

void test_selectionSortRowsMatrixByRowCriteria_colsMoreThanRows_someEqualCriteriaValues();

void test_selectionSortRowsMatrixByRowCriteria();

void test_selectionSortColsMatrixByColCriteria_squareMatrix();

void test_selectionSortColsMatrixByColCriteria_rowsMoreThanCols();

void test_selectionSortColsMatrixByColCriteria_colsMoreThanRows();

void test_selectionSortColsMatrixByColCriteria_squareMatrix_someEqualCriteriaValues();

void test_selectionSortColsMatrixByColCriteria_rowsMoreThanCols_someEqualCriteriaValues();

void test_selectionSortColsMatrixByColCriteria_colsMoreThanRows_someEqualCriteriaValues();

void test_selectionSortColsMatrixByColCriteria();

void test_isSquareMatrix_squareMatrixOfFirstOrder();

void test_isSquareMatrix_squareMatrixOfSecondOrder();

void test_isSquareMatrix_squareMatrixOfThirdOrder();

void test_isSquareMatrix_rowsMoreThanCols();

void test_isSquareMatrix_colsMoreThanRows();

void test_isSquareMatrix();

void test_areTwoMatricesEqual_identicalMatrices();

void test_areTwoMatricesEqual_nonIdenticalMatrices();

void test_areTwoMatricesEqual_almostIdenticalMatrices();

void test_areTwoMatricesEqual();

void test_isEMatrix_EMatrix();

void test_isEMatrix_almostEMatrix_squareMatrix();

void test_isEMatrix_almostEMatrix_rowsMoreThanCols();

void test_isEMatrix_almostEMatrix_colsMoreThanRows();

void test_isEMatrix_definitelyNotEMatrix_squareMatrix();

void test_isEMatrix_definitelyNotEMatrix_rowsMoreThanCols();

void test_isEMatrix_definitelyNotEMatrix_colsMoreThanRows();

void test_isEMatrix();

void test_isSymmetricMatrix_symmetricMatrix();

void test_isSymmetricMatrix_almostSymmetricEMatrix();

void test_isSymmetricMatrix_definitelyNotSymmetricEMatrix();

void test_isSymmetricMatrix();

void test_transposeSquareMatrix_squareMatrixOfFirstOrder();

void test_transposeSquareMatrix_squareMatrixOfSecondOrder();

void test_transposeSquareMatrix_squareMatrixOfThirdOrder();

void test_transposeSquareMatrix_squareMatrixOfFourthOrder();

void test_transposeSquareMatrix();

void test_getMinValuePos_oneMinValueInMatrix();

void test_getMinValuePos_someMinValuesInMatrix();

void test_getMinValuePos();

void test_getMaxValuePos_oneMaxValueInMatrix();

void test_getMaxValuePos_someMaxValuesInMatrix();

void test_getMaxValuePos();

void test_matrix_lib();

void test_swapRowsWithMaxAndMinValuesOfSquareMatrix_oneMinAndOneMaxValues();

void test_swapRowsWithMaxAndMinValuesOfSquareMatrix_oneMinAndSomeMaxValues();

void test_swapRowsWithMaxAndMinValuesOfSquareMatrix_someMinAndOneMaxValues();

void test_swapRowsWithMaxAndMinValuesOfSquareMatrix_someMinAndSomeMaxValues();

void test_swapRowsWithMaxAndMinValuesOfSquareMatrix_minAndMaxValuesInOneRow();

void test_swapRowsWithMaxAndMinValuesOfSquareMatrix();

void test_sortRowsByMaxElement_squareMatrix();

void test_sortRowsByMaxElement_rowsMoreThanCols();

void test_sortRowsByMaxElement_colsMoreThanRows();

void test_sortRowsByMaxElement_squareMatrix_someEqualCriteriaValues();

void test_sortRowsByMaxElement_rowsMoreThanCols_someEqualCriteriaValues();

void test_sortRowsByMaxElement_colsMoreThanRows_someEqualCriteriaValues();

void test_sortRowsByMaxElement();

void test_sortColsByMinElement_squareMatrix();

void test_sortColsByMinElement_rowsMoreThanCols();

void test_sortColsByMinElement_colsMoreThanRows();

void test_sortColsByMinElement_squareMatrix_someEqualCriteriaValues();

void test_sortColsByMinElement_rowsMoreThanCols_someEqualCriteriaValues();

void test_sortColsByMinElement_colsMoreThanRows_someEqualCriteriaValues();

void test_sortColsByMinElement();

void test_mulMatrices_squareMatrices();

void test_mulMatrices_squareMatrixAndMatrixWithRowsMoreThanCols();

void test_mulMatrices_squareMatrixAndMatrixWithColsMoreThanRows();

void test_mulMatrices_matrixWithRowsMoreThanColsAndSquareMatrix();

void test_mulMatrices_matrixWithColsMoreThanRowsAndSquareMatrix();

void test_mulMatrices_matrixWithRowsMoreThanColsAndMatrixWithColsMoreThanRows();

void test_mulMatrices_matrixWithColsMoreThanRowsAndMatrixWithRowsMoreThanCols();

void test_mulMatrices_matrixWithOneRowAndColsAndMatrixWithOneColAndRows();

void test_mulMatrices_matrixWithOneColAndRowsAndMatrixWithOneRowAndCols();

void test_mulMatrices();

void test_getSquareOfMatrixIfSymmetric_symmetricMatrixOfFirstOrder();

void test_getSquareOfMatrixIfSymmetric_symmetricMatrixOfSecondOrder();

void test_getSquareOfMatrixIfSymmetric_symmetricMatrixOfThirdOrder();

void test_getSquareOfMatrixIfSymmetric_symmetricMatrixOfFourthOrder();

void test_getSquareOfMatrixIfSymmetric();

void test_transposeIfMatrixHasNotEqualSumsOfRows_squareMatrix_noEqualSumsOfRows();

void test_transposeIfMatrixHasNotEqualSumsOfRows();

void test_areMutuallyInverseMatrices_mutuallyInverseMatrices();

void test_areMutuallyInverseMatrices_notMutuallyInverseMatrices();

void test_areMutuallyInverseMatrices();

void test_findSumOfMaxesOfPseudoDiagonals_squareMatrixOfFirstOrder();

void test_findSumOfMaxesOfPseudoDiagonals_squareMatrixOfSecondOrder();

void test_findSumOfMaxesOfPseudoDiagonals_squareMatrixOfThirdOrder();

void test_findSumOfMaxesOfPseudoDiagonals_squareMatrixOfFourthOrder();

void test_findSumOfMaxesOfPseudoDiagonals_rowsMoreThanCols();

void test_findSumOfMaxesOfPseudoDiagonals_colsMoreThanRows();

void test_findSumOfMaxesOfPseudoDiagonal();

void test_minInArea_squareMatrix_areaHasOnlyMaxElementInArea();

void test_minInArea_squareMatrix_maxElementIsNotOneElementInArea();

void test_minInArea_rowsMoreThanCols_areaHasOnlyMaxElementInArea();

void test_minInArea_rowsMoreThanCols_maxElementIsNotOneElementInArea();

void test_minInArea_colsMoreThanRows_areaHasOnlyMaxElementInArea();

void test_minInArea_colsMoreThanRows_maxElementIsNotOneElementInArea();

void test_minInArea();

void test_selectionSortRowsMatrixByRowCriteriaF_squareMatrix();

void test_selectionSortRowsMatrixByRowCriteriaF_rowsMoreThanCols();

void test_selectionSortRowsMatrixByRowCriteriaF_colsMoreThanRows();

void test_selectionSortRowsMatrixByRowCriteriaF_squareMatrix_someEqualCriteriaValues();

void test_selectionSortRowsMatrixByRowCriteriaF_rowsMoreThanCols_someEqualCriteriaValues();

void test_selectionSortRowsMatrixByRowCriteriaF_colsMoreThanRows_someEqualCriteriaValues();

void test_selectionSortRowsMatrixByRowCriteriaF();

void test_sortByDistances_squareMatrix();

void test_sortByDistances_rowsMoreThanCols();

void test_sortByDistances_colsMoreThanRows();

void test_sortByDistances_squareMatrix_someEqualDistances();

void test_sortByDistances_rowsMoreThanCols_someEqualDistances();

void test_sortByDistances_colsMoreThanRows_someEqualDistances();

void test_sortByDistances();

void test_countOfClassesOfEqRowsByRowSum_squareMatrix();

void test_countOfClassesOfEqRowsByRowSum_rowsMoreThanCols();

void test_countOfClassesOfEqRowsByRowSum_colsMoreThanRows();

void test_countOfClassesOfEqRowsByRowSum_squareMatrix_matrixHasRowWithUniqueSumOfElements();

void test_countOfClassesOfEqRowsByRowSum_rowsMoreThanCols_matrixHasRowWithUniqueSumOfElements();

void test_countOfClassesOfEqRowsByRowSum_colsMoreThanRows_matrixHasRowWithUniqueSumOfElements();

void test_countOfClassesOfEqRowsByRowSum_squareMatrix_noClassesOfEqRowsByRowsSum();

void test_countOfClassesOfEqRowsByRowSum_rowsMoreThanCols_noClassesOfEqRowsByRowsSum();

void test_countOfClassesOfEqRowsByRowSum_colsMoreThanRows_noClassesOfEqRowsByRowsSum();

void test_countOfClassesOfEqRowsByRowSum();

void test_getCountOfSpecialElements_squareMatrix();

void test_getCountOfSpecialElements_rowsMoreThanCols();

void test_getCountOfSpecialElements_colsMoreThanRows();

void test_getCountOfSpecialElements_squareMatrix_noSpecialElementsInMatrix();

void test_getCountOfSpecialElements_rowsMoreThanCols_noSpecialElementsInMatrix();

void test_getCountOfSpecialElements_colsMoreThanRows_noSpecialElementsInMatrix();

void test_getCountOfSpecialElements();

void test_getLeftMin_oneMinValueInMatrix();

void test_getLeftMin_someMinValuesInMatrix();

void test_getLeftMin();

void test_swapPenultimateRow_squareMatrixOfSecondOrder();

void test_swapPenultimateRow_squareMatrixOfThirdOrder();

void test_swapPenultimateRow_squareMatrixOfFourthOrder();

void test_swapPenultimateRow();

void test_hasAllNonDescendingRows_squareMatrix();

void test_hasAllNonDescendingRows_rowsMoreThanCols();

void test_hasAllNonDescendingRows_colsMoreThanRows();

void test_hasAllNonDescendingRows_squareMatrix_someRowsIsNotNonDescending();

void test_hasAllNonDescendingRows_rowsMoreThanCols_someRowsIsNotNonDescending();

void test_hasAllNonDescendingRows_colsMoreThanRows_someRowsIsNotNonDescending();

void test_hasAllNonDescendingRows();

void test_countNonDescendingRowsMatrices_squareMatrices_msHasRequestedMatrices();

void test_countNonDescendingRowsMatrices_rowsMoreThanColsMatrices_msHasRequestedMatrices();

void test_countNonDescendingRowsMatrices_colsMoreThanRowsMatrices_msHasRequestedMatrices();

void test_countNonDescendingRowsMatrices_squareMatrices_msHasNotRequestedMatrices();

void test_countNonDescendingRowsMatrices_rowsMoreThanColsMatrices_msHasNotRequestedMatrices();

void test_countNonDescendingRowsMatrices_colsMoreThanRowsMatrices_msHasNotRequestedMatrices();

void test_countNonDescendingRowsMatrices();

void test_countZeroRows_squareMatrix_matrixHasZeroRows();

void test_countZeroRows_rowsMoreThanCols_matrixHasZeroRows();

void test_countZeroRows_colsMoreThanRows_matrixHasZeroRows();

void test_countZeroRows_squareMatrix_matrixHasNotZeroRows();

void test_countZeroRows_rowsMoreThanCols_matrixHasNotZeroRows();

void test_countZeroRows_colsMoreThanRows_matrixHasNotZeroRows();

void test_countZeroRows();

void test_isMatrixArrayOfSquareMatrices_matrixArrayOfSquareMatrices();

void test_isMatrixArrayOfSquareMatrices_matrixArrayOfRowsMoreThanColsMatrices();

void test_isMatrixArrayOfSquareMatrices_matrixArrayOfColsMoreThanRowsMatrices();

void test_isMatrixArrayOfSquareMatrices();

void test_getMatrixNorm_squareMatrix();

void test_getMatrixNorm_rowsMoreThanCols();

void test_getMatrixNorm_colsMoreThanRows();

void test_getMatrixNorm();

void test_matrix_tasks();

void test_matrix();

#endif