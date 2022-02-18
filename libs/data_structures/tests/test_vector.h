#ifndef INC_TEST_VECTOR_H
#define INC_TEST_VECTOR_H

#include "../../../libs/data_structures/vector/vector.h"
#include "../../../libs/data_structures/void_vector/void_vector.h"

void test_createVector_zeroVector();

void test_createVector_emptyVector();

void test_reserve_toEmptyVector();

void test_reserve_toZeroVector_emptyVector();

void test_reserve_toZeroVector_filledVector();

void test_reserve_toZeroVector_fullVector();

void test_reserve_expandedEmptyVector();

void test_reserve_expandedFilledVector();

void test_reserve_expandedFullVector();

void test_reserve_reducedEmptyVector();

void test_reserve_reducedFilledVector_newCapacityLessThanSize();

void test_reserve_reducedFilledVector_newCapacityMoreThanSize();

void test_reserve_reducedFullVector();

void test_clear_clearedZeroVector();

void test_clear_clearedEmptyVector();

void test_clear_clearedFilledVector();

void test_clear_clearedFullVector();

void test_shrinkToFit_zeroVector();

void test_shrinkToFit_emptyVector();

void test_shrinkToFit_fullVector();

void test_shrinkToFit_filledVector();

void test_isEmpty_zeroVector();

void test_isEmpty_emptyVector();

void test_isEmpty_filledVector();

void test_isEmpty_fullVector();

void test_isFull_zeroVector();

void test_isFull_emptyVector();

void test_isFull_filledVector();

void test_isFull_fullVector();

void test_getVectorValue_filledVector();

void test_getVectorValue_filledVector_firstElement();

void test_getVectorValue_filledVector_lastElement();

void test_getVectorValue_fullVector();

void test_getVectorValue_fullVector_firstElement();

void test_getVectorValue_fullVector_lastElement();

void test_pushBack_zeroVector();

void test_pushBack_emptyVector();

void test_pushBack_filledVector();

void test_pushBack_fullVector();

void test_popBack_filledVector();

void test_popBack_filledVector_oneElementInVector();

void test_popBack_fullVector();

void test_popBack_fullVector_oneElementInVector();

void test_atVector_filledVector();

void test_atVector_filledVector_firstElement();

void test_atVector_filledVector_lastElement();

void test_atVector_fullVector();

void test_atVector_fullVector_firstElement();

void test_atVector_fullVector_lastElement();

void test_back_filledVector();

void test_back_filledVector_oneElementInVector();

void test_back_fullVector();

void test_back_fullVector_oneElementInVector();

void test_front_filledVector();

void test_front_filledVector_oneElementInVector();

void test_front_fullVector();

void test_front_fullVector_oneElementInVector();

void test_createVectorV_zeroVector_int();

void test_createVectorV_zeroVector_char();

void test_createVectorV_zeroVector_float();

void test_createVectorV_emptyVector_int();

void test_createVectorV_emptyVector_char();

void test_createVectorV_emptyVector_float();

void test_reserveV_toEmptyVector_int();

void test_reserveV_toEmptyVector_char();

void test_reserveV_toEmptyVector_float();

void test_reserveV_toZeroVector_emptyVector_int();

void test_reserveV_toZeroVector_emptyVector_char();

void test_reserveV_toZeroVector_emptyVector_float();

void test_reserveV_toZeroVector_filledVector_int();

void test_reserveV_toZeroVector_filledVector_char();

void test_reserveV_toZeroVector_filledVector_float();

void test_reserveV_toZeroVector_fullVector_int();

void test_reserveV_toZeroVector_fullVector_char();

void test_reserveV_toZeroVector_fullVector_float();

void test_reserveV_expandedEmptyVector_int();

void test_reserveV_expandedEmptyVector_char();

void test_reserveV_expandedEmptyVector_float();

void test_reserveV_expandedFilledVector_int();

void test_reserveV_expandedFilledVector_char();

void test_reserveV_expandedFilledVector_float();

void test_reserveV_expandedFullVector_int();

void test_reserveV_expandedFullVector_char();

void test_reserveV_expandedFullVector_float();

void test_reserveV_reducedEmptyVector_int();

void test_reserveV_reducedEmptyVector_char();

void test_reserveV_reducedEmptyVector_float();

void test_reserveV_reducedFilledVector_newCapacityLessThanSize_int();

void test_reserveV_reducedFilledVector_newCapacityLessThanSize_char();

void test_reserveV_reducedFilledVector_newCapacityLessThanSize_float();

void test_reserveV_reducedFilledVector_newCapacityMoreThanSize_int();

void test_reserveV_reducedFilledVector_newCapacityMoreThanSize_char();

void test_reserveV_reducedFilledVector_newCapacityMoreThanSize_float();

void test_reserveV_reducedFullVector_int();

void test_reserveV_reducedFullVector_char();

void test_reserveV_reducedFullVector_float();

void test_clearV_clearedZeroVector_int();

void test_clearV_clearedZeroVector_char();

void test_clearV_clearedZeroVector_float();

void test_clearV_clearedEmptyVector_int();

void test_clearV_clearedEmptyVector_char();

void test_clearV_clearedEmptyVector_float();

void test_clearV_clearedFilledVector_int();

void test_clearV_clearedFilledVector_char();

void test_clearV_clearedFilledVector_float();

void test_clearV_clearedFullVector_int();

void test_clearV_clearedFullVector_char();

void test_clearV_clearedFullVector_float();

void test_shrinkToFitV_zeroVector_int();

void test_shrinkToFitV_zeroVector_char();

void test_shrinkToFitV_zeroVector_float();

void test_shrinkToFitV_emptyVector_int();

void test_shrinkToFitV_emptyVector_char();

void test_shrinkToFitV_emptyVector_float();

void test_shrinkToFitV_filledVector_int();

void test_shrinkToFitV_filledVector_char();

void test_shrinkToFitV_filledVector_float();

void test_shrinkToFitV_fullVector_int();

void test_shrinkToFitV_fullVector_char();

void test_shrinkToFitV_fullVector_float();

void test_isEmptyV_zeroVector_int();

void test_isEmptyV_zeroVector_char();

void test_isEmptyV_zeroVector_float();

void test_isEmptyV_emptyVector_int();

void test_isEmptyV_emptyVector_char();

void test_isEmptyV_emptyVector_float();

void test_isEmptyV_filledVector_int();

void test_isEmptyV_filledVector_char();

void test_isEmptyV_filledVector_float();

void test_isEmptyV_fullVector_int();

void test_isEmptyV_fullVector_char();

void test_isEmptyV_fullVector_float();

void test_isFullV_zeroVector_int();

void test_isFullV_zeroVector_char();

void test_isFullV_zeroVector_float();

void test_isFullV_emptyVector_int();

void test_isFullV_emptyVector_char();

void test_isFullV_emptyVector_float();

void test_isFullV_filledVector_int();

void test_isFullV_filledVector_char();

void test_isFullV_filledVector_float();

void test_isFullV_fullVector_int();

void test_isFullV_fullVector_char();

void test_isFullV_fullVector_float();

void test_getVectorValueV_filledVector_int();

void test_getVectorValueV_filledVector_char();

void test_getVectorValueV_filledVector_float();

void test_getVectorValueV_filledVector_firstElement_int();

void test_getVectorValueV_filledVector_firstElement_char();

void test_getVectorValueV_filledVector_firstElement_float();

void test_getVectorValueV_filledVector_lastElement_int();

void test_getVectorValueV_filledVector_lastElement_char();

void test_getVectorValueV_filledVector_lastElement_float();

void test_getVectorValueV_fullVector_int();

void test_getVectorValueV_fullVector_char();

void test_getVectorValueV_fullVector_float();

void test_getVectorValueV_fullVector_firstElement_int();

void test_getVectorValueV_fullVector_firstElement_char();

void test_getVectorValueV_fullVector_firstElement_float();

void test_getVectorValueV_fullVector_lastElement_int();

void test_getVectorValueV_fullVector_lastElement_char();

void test_getVectorValueV_fullVector_lastElement_float();

void test_setVectorValueV_filledVector_int();

void test_setVectorValueV_filledVector_char();

void test_setVectorValueV_filledVector_float();

void test_setVectorValueV_fullVector_int();

void test_setVectorValueV_fullVector_char();

void test_setVectorValueV_fullVector_float();

void test_popBackV_filledVector_int();

void test_popBackV_filledVector_char();

void test_popBackV_filledVector_float();

void test_popBackV_filledVector_oneElementInVector_int();

void test_popBackV_filledVector_oneElementInVector_char();

void test_popBackV_filledVector_oneElementInVector_float();

void test_popBackV_fullVector_int();

void test_popBackV_fullVector_char();

void test_popBackV_fullVector_float();

void test_popBackV_fullVector_oneElementInVector_int();

void test_popBackV_fullVector_oneElementInVector_char();

void test_popBackV_fullVector_oneElementInVector_float();

void test_pushBackV_zeroVector_int();

void test_pushBackV_zeroVector_char();

void test_pushBackV_zeroVector_float();

void test_pushBackV_emptyVector_int();

void test_pushBackV_emptyVector_char();

void test_pushBackV_emptyVector_float();

void test_pushBackV_filledVector_int();

void test_pushBackV_filledVector_char();

void test_pushBackV_filledVector_float();

void test_pushBackV_fullVector_int();

void test_pushBackV_fullVector_char();

void test_pushBackV_fullVector_float();

void test_vector();

#endif