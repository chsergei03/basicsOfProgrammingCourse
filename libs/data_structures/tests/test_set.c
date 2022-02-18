#include "test_set.h"

#include <assert.h>
#include <memory.h>

void test_unordered_array_set_in1() {
    int x = 1;
    unordered_array_set set = {(int[]) {}, 0, 0};
    assert(unordered_array_set_in(&set, x) == set.size);
}

void test_unordered_array_set_in2() {
    int x = 10;
    unordered_array_set set = {(int[]) {1, 2, 3}, 3, 3};
    assert(unordered_array_set_in(&set, x) == set.size);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_in3() {
    int x = 7;
    unordered_array_set set = {(int[]) {1, 3, 5, 7}, 4, 4};
    assert(unordered_array_set_in(&set, x) < set.size);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_in() {
    test_unordered_array_set_in1();
    test_unordered_array_set_in2();
    test_unordered_array_set_in3();
}

void test_unordered_array_set_isSubset1() {
    unordered_array_set subset = {(int[]) {}, 0, 0};
    unordered_array_set set = {(int[]) {}, 0, 0};
    assert(unordered_array_set_isSubset(subset, set));
}

void test_unordered_array_set_isSubset2() {
    unordered_array_set subset = {(int[]) {}, 0, 0};
    unordered_array_set set = {(int[]) {4, 6, 8}, 3, 3};
    assert(unordered_array_set_isSubset(subset, set));
    unordered_array_set_delete(set);
}

void test_unordered_array_set_isSubset3() {
    unordered_array_set subset = {(int[]) {1, 5, 9}, 3, 3};
    unordered_array_set set = {(int[]) {3, 7, 11}, 3, 3};
    assert(!unordered_array_set_isSubset(subset, set));
    unordered_array_set_delete(subset);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_isSubset4() {
    unordered_array_set subset = {(int[]) {3, 9}, 2, 2};
    unordered_array_set set = {(int[]) {1, 2, 3}, 3, 3};
    assert(!unordered_array_set_isSubset(subset, set));
    unordered_array_set_delete(subset);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_isSubset5() {
    unordered_array_set subset = {(int[]) {2, 3}, 2, 2};
    unordered_array_set set = {(int[]) {1, 2, 3}, 3, 3};
    assert(unordered_array_set_isSubset(subset, set));
    unordered_array_set_delete(subset);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_isSubset() {
    test_unordered_array_set_isSubset1();
    test_unordered_array_set_isSubset2();
    test_unordered_array_set_isSubset3();
    test_unordered_array_set_isSubset4();
    test_unordered_array_set_isSubset5();
}

void test_unordered_array_set_insert1() {
    int source[] = {1, 2, 3};
    size_t n = 3;
    size_t maxSize = 4;
    unordered_array_set set = unordered_array_set_create(maxSize);
    set.size = n;
    memcpy(set.data, source, set.size * sizeof(int));
    int x = 5;
    unordered_array_set_insert(&set, x);
    unordered_array_set expectedSet = {(int[]) {1, 2, 3, 5}, 4, 4};
    assert(unordered_array_set_isEqual(set, expectedSet));
    unordered_array_set_delete(set);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_insert2() {
    int source[] = {};
    size_t n = 0;
    size_t maxSize = 1;
    unordered_array_set set = unordered_array_set_create(maxSize);
    set.size = n;
    memcpy(set.data, source, set.size * sizeof(int));
    int x = 7;
    unordered_array_set_insert(&set, x);
    unordered_array_set expectedSet = {(int[]) {7}, 1, 1};
    assert(unordered_array_set_isEqual(set, expectedSet));
    unordered_array_set_delete(set);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_insert3() {
    int source[] = {1, 3, 4};
    size_t n = 3;
    size_t maxSize = 4;
    unordered_array_set set = unordered_array_set_create(maxSize);
    set.size = n;
    memcpy(set.data, source, set.size * sizeof(int));
    int x = 2;
    unordered_array_set_insert(&set, x);
    unordered_array_set expectedSet = {(int[]) {1, 3, 4, 2}, 4, 4};
    assert(unordered_array_set_isEqual(set, expectedSet));
    unordered_array_set_delete(set);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_insert() {
    test_unordered_array_set_insert1();
    test_unordered_array_set_insert2();
    test_unordered_array_set_insert3();
}

void test_unordered_array_set_deleteElement1() {
    int x = 10;
    unordered_array_set set = {(int[]) {}, 0, 0};
    unordered_array_set_deleteElement(&set, x);
    unordered_array_set expectedSet = {(int[]) {}, 0, 0};
    assert(unordered_array_set_isEqual(set, expectedSet));
}

void test_unordered_array_set_deleteElement2() {
    int x = 7;
    unordered_array_set set = {(int[]) {6, 2, 4}, 3, 3};
    unordered_array_set_deleteElement(&set, x);
    unordered_array_set expectedSet = {(int[]) {6, 2, 4}, 3, 3};
    assert(unordered_array_set_isEqual(set, expectedSet));
    unordered_array_set_delete(set);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_deleteElement3() {
    int x = 2;
    unordered_array_set set = {(int[]) {3, 2, 4}, 3, 3};
    unordered_array_set_deleteElement(&set, x);
    unordered_array_set expectedSet = {(int[]) {3, 4}, 2, 3};
    assert(unordered_array_set_isEqual(set, expectedSet));
    unordered_array_set_delete(set);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_deleteElement4() {
    int x = 9;
    unordered_array_set set = {(int[]) {9, 3, 6}, 3, 3};
    unordered_array_set_deleteElement(&set, x);
    unordered_array_set expectedSet = {(int[]) {6, 3}, 2, 3};
    assert(unordered_array_set_isEqual(set, expectedSet));
    unordered_array_set_delete(set);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_deleteElement5() {
    int x = 4;
    unordered_array_set set = {(int[]) {3, 5, 4}, 3, 3};
    unordered_array_set_deleteElement(&set, x);
    unordered_array_set expectedSet = {(int[]) {3, 5}, 2, 3};
    assert(unordered_array_set_isEqual(set, expectedSet));
    unordered_array_set_delete(set);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_deleteElement() {
    test_unordered_array_set_deleteElement1();
    test_unordered_array_set_deleteElement2();
    test_unordered_array_set_deleteElement3();
    test_unordered_array_set_deleteElement4();
    test_unordered_array_set_deleteElement5();
}

void test_unordered_array_set_union1() {
    unordered_array_set set1 = {(int[]) {}, 0, 0};
    unordered_array_set set2 = {(int[]) {}, 0, 0};
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet = {(int[]) {}, 0, 0};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
}

void test_unordered_array_set_union2() {
    unordered_array_set set1 = {(int[]) {1, 2, 3}, 3, 3};
    unordered_array_set set2 = {(int[]) {3, 4, 5}, 3, 3};
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set expectedSet = {(int[]) {1, 2, 3, 4, 5}, 5, 5};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union3() {
    unordered_array_set set1 = {(int[]) {9, 5}, 2, 2};
    unordered_array_set set2 = {(int[]) {}, 0, 0};
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set expectedSet = {(int[]) {9, 5}, 2, 2};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union4() {
    unordered_array_set set1 = {(int[]) {5}, 1, 1};
    unordered_array_set set2 = {(int[]) {5}, 1, 1};
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set expectedSet = {(int[]) {5}, 1, 1};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union5() {
    unordered_array_set set1 = {(int[]) {7, 11, 6}, 3, 3};
    unordered_array_set set2 = {(int[]) {6, 7, 11}, 3, 3};
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set expectedSet = {(int[]) {7, 11, 6}, 3, 3};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union6() {
    unordered_array_set set1 = {(int[]) {15, 17, 9}, 3, 3};
    unordered_array_set set2 = {(int[]) {8, 4, 2}, 3, 3};
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set expectedSet = {(int[]) {15, 17, 9, 8, 4, 2}, 6, 6};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union() {
    test_unordered_array_set_union1();
    test_unordered_array_set_union2();
    test_unordered_array_set_union3();
    test_unordered_array_set_union4();
    test_unordered_array_set_union5();
    test_unordered_array_set_union6();
}

void test_unordered_array_set_intersection1() {
    unordered_array_set set1 = {(int[]) {}, 0, 0};
    unordered_array_set set2 = {(int[]) {}, 0, 0};
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set expectedSet = {(int[]) {}, 0, 0};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection2() {
    unordered_array_set set1 = {(int[]) {2, 18}, 2, 2};
    unordered_array_set set2 = {(int[]) {}, 0, 0};
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set_delete(set1);
    unordered_array_set expectedSet = {(int[]) {}, 0, 0};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
}

void test_unordered_array_set_intersection3() {
    unordered_array_set set1 = {(int[]) {7, 3, 5}, 3, 3};
    unordered_array_set set2 = {(int[]) {5, 7, 3}, 3, 3};
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set expectedSet = {(int[]) {5, 7, 3}, 3, 3};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection4() {
    unordered_array_set set1 = {(int[]) {7, 6, 5}, 3, 3};
    unordered_array_set set2 = {(int[]) {9, 7, 4}, 3, 3};
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set expectedSet = {(int[]) {7}, 1, 3};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection5() {
    unordered_array_set set1 = {(int[]) {2, 4, 6}, 3, 3};
    unordered_array_set set2 = {(int[]) {1, 3, 5}, 3, 3};
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set expectedSet = {(int[]) {}, 0, 3};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
}

void test_unordered_array_set_intersection6() {
    unordered_array_set set1 = {(int[]) {2, 3}, 2, 2};
    unordered_array_set set2 = {(int[]) {1, 2, 3}, 3, 3};
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set expectedSet = {(int[]) {2, 3}, 2, 2};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection() {
    test_unordered_array_set_intersection1();
    test_unordered_array_set_intersection2();
    test_unordered_array_set_intersection3();
    test_unordered_array_set_intersection4();
    test_unordered_array_set_intersection5();
    test_unordered_array_set_intersection6();
}

void test_unordered_array_set_difference1() {
    unordered_array_set set1 = {(int[]) {}, 0, 0};
    unordered_array_set set2 = {(int[]) {}, 0, 0};
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet = {(int[]) {}, 0, 0};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
}

void test_unordered_array_set_difference2() {
    unordered_array_set set1 = {(int[]) {7, 45}, 2, 2};
    unordered_array_set set2 = {(int[]) {}, 0, 0};
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set_delete(set1);
    unordered_array_set expectedSet = {(int[]) {7, 45}, 2, 2};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference3() {
    unordered_array_set set1 = {(int[]) {6}, 1, 1};
    unordered_array_set set2 = {(int[]) {42}, 1, 1};
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set expectedSet = {(int[]) {6}, 1, 1};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference4() {
    unordered_array_set set1 = {(int[]) {3, 2, 1}, 3, 3};
    unordered_array_set set2 = {(int[]) {2, 3, 1}, 3, 3};
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set expectedSet = {(int[]) {}, 0, 3};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference() {
    test_unordered_array_set_difference1();
    test_unordered_array_set_difference2();
    test_unordered_array_set_difference3();
    test_unordered_array_set_difference4();
}

void test_unordered_array_set_symmetricDifference1() {
    unordered_array_set set1 = {(int[]) {}, 0, 0};
    unordered_array_set set2 = {(int[]) {}, 0, 0};
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet = {(int[]) {}, 0, 0};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
}

void test_unordered_array_set_symmetricDifference2() {
    unordered_array_set set1 = {(int[]) {}, 0, 0};
    unordered_array_set set2 = {(int[]) {5, 7, 6}, 3, 3};
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set_delete(set2);
    unordered_array_set expectedSet = {(int[]) {5, 7, 6}, 3, 3};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference3() {
    unordered_array_set set1 = {(int[]) {3, 2, 1}, 3, 3};
    unordered_array_set set2 = {(int[]) {3, 4, 5}, 3, 3};
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set expectedSet = {(int[]) {2, 1, 4, 5}, 4, 6};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference4() {
    unordered_array_set set1 = {(int[]) {3, 6, 9, 12}, 4, 4};
    unordered_array_set set2 = {(int[]) {1, 11, 6, 9, 21}, 5, 5};
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set expectedSet = {(int[]) {3, 12, 1, 11, 21}, 5, 8};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference() {
    test_unordered_array_set_symmetricDifference1();
    test_unordered_array_set_symmetricDifference2();
    test_unordered_array_set_symmetricDifference3();
    test_unordered_array_set_symmetricDifference4();
}

void test_unordered_array_set_complement1() {
    unordered_array_set set = {(int[]) {}, 0, 0};
    unordered_array_set universumSet = {(int[]) {}, 0, 0};
    unordered_array_set resSet = unordered_array_set_complement(set, universumSet);
    unordered_array_set expectedSet = {(int[]) {}, 0, 0};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
}

void test_unordered_array_set_complement2() {
    unordered_array_set set = {(int[]) {}, 0, 0};
    unordered_array_set universumSet = {(int[]) {4, 1, 11, 7}, 4, 4};
    unordered_array_set resSet = unordered_array_set_complement(set, universumSet);
    unordered_array_set_delete(universumSet);
    unordered_array_set expectedSet = {(int[]) {4, 1, 11, 7}, 4, 4};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_complement3() {
    unordered_array_set set = {(int[]) {8, 6, 7}, 3, 3};
    unordered_array_set universumSet = {(int[]) {8, 6, 7}, 3, 3};
    unordered_array_set resSet = unordered_array_set_complement(set, universumSet);
    unordered_array_set_delete(set);
    unordered_array_set_delete(universumSet);
    unordered_array_set expectedSet = {(int[]) {}, 0, 3};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
}

void test_unordered_array_set_complement4() {
    unordered_array_set set = {(int[]) {5, 1, 3, 8}, 4, 4};
    unordered_array_set universumSet = {(int[]) {1, 3, 2, 4, 5, 6, 7, 8}, 8, 8};
    unordered_array_set resSet = unordered_array_set_complement(set, universumSet);
    unordered_array_set_delete(set);
    unordered_array_set_delete(universumSet);
    unordered_array_set expectedSet = {(int[]) {2, 4, 6, 7}, 4, 4};
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_complement() {
    test_unordered_array_set_complement1();
    test_unordered_array_set_complement2();
    test_unordered_array_set_complement3();
    test_unordered_array_set_complement4();
}

void test_unordered_array_set() {
    test_unordered_array_set_in();
    test_unordered_array_set_isSubset();
    test_unordered_array_set_insert();
    test_unordered_array_set_deleteElement();
    test_unordered_array_set_union();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_symmetricDifference();
    test_unordered_array_set_complement();
}

void test_ordered_array_set_in1() {
    int x = 3;
    ordered_array_set set = {(int[]) {}, 0, 0};
    assert(ordered_array_set_in(&set, x) == set.size);
}

void test_ordered_array_set_in2() {
    int x = 6;
    ordered_array_set set = {(int[]) {3, 4, 5}, 3, 3};
    assert(ordered_array_set_in(&set, x) == set.size);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_in3() {
    int x = 4;
    ordered_array_set set = {(int[]) {2, 4, 6, 8}, 4, 4};
    assert(ordered_array_set_in(&set, x) < set.size);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_in() {
    test_ordered_array_set_in1();
    test_ordered_array_set_in2();
    test_ordered_array_set_in3();
}

void test_ordered_array_set_isSubset1() {
    ordered_array_set subset = {(int[]) {}, 0, 0};
    ordered_array_set set = {(int[]) {}, 0, 0};
    assert(ordered_array_set_isSubset(subset, set));
}

void test_ordered_array_set_isSubset2() {
    ordered_array_set subset = {(int[]) {}, 0, 0};
    ordered_array_set set = {(int[]) {1, 2, 3}, 3, 3};
    assert(ordered_array_set_isSubset(subset, set));
    ordered_array_set_delete(set);
}

void test_ordered_array_set_isSubset3() {
    ordered_array_set subset = {(int[]) {1, 2, 3}, 3, 3};
    ordered_array_set set = {(int[]) {2, 4, 6}, 3, 3};
    assert(!ordered_array_set_isSubset(subset, set));
    ordered_array_set_delete(subset);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_isSubset4() {
    ordered_array_set subset = {(int[]) {7, 11}, 2, 2};
    ordered_array_set set = {(int[]) {3, 5, 7}, 3, 3};
    assert(!ordered_array_set_isSubset(subset, set));
    ordered_array_set_delete(subset);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_isSubset5() {
    ordered_array_set subset = {(int[]) {3, 5}, 2, 2};
    ordered_array_set set = {(int[]) {3, 4, 5}, 3, 3};
    assert(ordered_array_set_isSubset(subset, set));
    ordered_array_set_delete(subset);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_isSubset6() {
    ordered_array_set subset = {(int[]) {2, 3}, 2, 2};
    ordered_array_set set = {(int[]) {1, 2, 3}, 3, 3};
    assert(ordered_array_set_isSubset(subset, set));
    ordered_array_set_delete(subset);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_isSubset() {
    test_ordered_array_set_isSubset1();
    test_ordered_array_set_isSubset2();
    test_ordered_array_set_isSubset3();
    test_ordered_array_set_isSubset4();
    test_ordered_array_set_isSubset5();
    test_ordered_array_set_isSubset6();
}

void test_ordered_array_set_insert1() {
    int source[] = {};
    size_t maxSize = 1;
    ordered_array_set set = ordered_array_set_create(maxSize);
    set.size = 0;
    memcpy(set.data, source, set.size * sizeof(int));
    int x = 15;
    ordered_array_set_insert(&set, x);
    ordered_array_set expectedSet = {(int[]) {15}, 1, 1};
    assert(ordered_array_set_isEqual(set, expectedSet));
    ordered_array_set_delete(set);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_insert2() {
    int source[] = {3, 5, 7};
    size_t maxSize = 4;
    ordered_array_set set = ordered_array_set_create(maxSize);
    set.size = 3;
    memcpy(set.data, source, set.size * sizeof(int));
    int x = 9;
    ordered_array_set_insert(&set, x);
    ordered_array_set expectedSet = {(int[]) {3, 5, 7, 9}, 4, 4};
    assert(ordered_array_set_isEqual(set, expectedSet));
    ordered_array_set_delete(set);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_insert3() {
    int source[] = {1, 3, 4};
    size_t maxSize = 4;
    ordered_array_set set = ordered_array_set_create(maxSize);
    set.size = 3;
    memcpy(set.data, source, set.size * sizeof(int));
    int x = 2;
    ordered_array_set_insert(&set, x);
    ordered_array_set expectedSet = {(int[]) {1, 2, 3, 4}, 4, 4};
    assert(ordered_array_set_isEqual(set, expectedSet));
    ordered_array_set_delete(set);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_insert4() {
    int source[] = {2, 5, 12};
    size_t maxSize = 4;
    ordered_array_set set = ordered_array_set_create(maxSize);
    set.size = 3;
    memcpy(set.data, source, set.size * sizeof(int));
    int x = 1;
    ordered_array_set_insert(&set, x);
    ordered_array_set expectedSet = {(int[]) {1, 2, 5, 12}, 4, 4};
    assert(ordered_array_set_isEqual(set, expectedSet));
    ordered_array_set_delete(set);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_insert() {
    test_ordered_array_set_insert1();
    test_ordered_array_set_insert2();
    test_ordered_array_set_insert3();
    test_ordered_array_set_insert4();
}

void test_ordered_array_set_deleteElement1() {
    int x = 5;
    ordered_array_set set = {(int[]) {}, 0, 0};
    ordered_array_set_deleteElement(&set, x);
    ordered_array_set expectedSet = {(int[]) {}, 0, 0};
    assert(ordered_array_set_isEqual(set, expectedSet));
}

void test_ordered_array_set_deleteElement2() {
    int x = 7;
    ordered_array_set set = {(int[]) {1, 3, 5}, 3, 3};
    ordered_array_set_deleteElement(&set, x);
    ordered_array_set expectedSet = {(int[]) {1, 3, 5}, 3, 3};
    assert(ordered_array_set_isEqual(set, expectedSet));
    ordered_array_set_delete(set);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_deleteElement3() {
    int x = 2;
    ordered_array_set set = {(int[]) {2, 3, 4}, 3, 3};
    ordered_array_set_deleteElement(&set, x);
    ordered_array_set expectedSet = {(int[]) {3, 4}, 2, 3};
    assert(ordered_array_set_isEqual(set, expectedSet));
    ordered_array_set_delete(set);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_deleteElement4() {
    int x = 9;
    ordered_array_set set = {(int[]) {3, 6, 9}, 3, 3};
    ordered_array_set_deleteElement(&set, x);
    ordered_array_set expectedSet = {(int[]) {3, 6}, 2, 3};
    assert(ordered_array_set_isEqual(set, expectedSet));
    ordered_array_set_delete(set);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_deleteElement5() {
    int x = 4;
    ordered_array_set set = {(int[]) {3, 4, 5, 6}, 4, 4};
    ordered_array_set_deleteElement(&set, x);
    ordered_array_set expectedSet = {(int[]) {3, 5, 6}, 3, 4};
    assert(ordered_array_set_isEqual(set, expectedSet));
    ordered_array_set_delete(set);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_deleteElement() {
    test_ordered_array_set_deleteElement1();
    test_ordered_array_set_deleteElement2();
    test_ordered_array_set_deleteElement3();
    test_ordered_array_set_deleteElement4();
    test_ordered_array_set_deleteElement5();
}

void test_ordered_array_set_union1() {
    ordered_array_set set1 = {(int[]) {}, 0, 0};
    ordered_array_set set2 = {(int[]) {}, 0, 0};
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet = {(int[]) {}, 0, 0};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
}

void test_ordered_array_set_union2() {
    ordered_array_set set1 = {(int[]) {2, 4, 6}, 3, 3};
    ordered_array_set set2 = {(int[]) {6, 8, 10}, 3, 3};
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set expectedSet = {(int[]) {2, 4, 6, 8, 10}, 5, 5};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union3() {
    ordered_array_set set1 = {(int[]) {1, 2, 3}, 3, 3};
    ordered_array_set set2 = {(int[]) {}, 0, 0};
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set_delete(set1);
    ordered_array_set expectedSet = {(int[]) {1, 2, 3}, 3, 3};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union4() {
    ordered_array_set set1 = {(int[]) {6, 7, 8}, 3, 3};
    ordered_array_set set2 = {(int[]) {6, 7, 8}, 3, 3};
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set expectedSet = {(int[]) {6, 7, 8}, 3, 3};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union5() {
    ordered_array_set set1 = {(int[]) {3}, 1, 1};
    ordered_array_set set2 = {(int[]) {3}, 1, 1};
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set expectedSet = {(int[]) {3}, 1, 1};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union6() {
    ordered_array_set set1 = {(int[]) {9, 15, 17}, 3, 3};
    ordered_array_set set2 = {(int[]) {2, 4, 8}, 3, 3};
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set expectedSet = {(int[]) {2, 4, 8, 9, 15, 17}, 6, 6};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union() {
    test_ordered_array_set_union1();
    test_ordered_array_set_union2();
    test_ordered_array_set_union3();
    test_ordered_array_set_union4();
    test_ordered_array_set_union5();
    test_ordered_array_set_union6();
}

void test_ordered_array_set_intersection1() {
    ordered_array_set set1 = {(int[]) {}, 0, 0};
    ordered_array_set set2 = {(int[]) {}, 0, 0};
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set expectedSet = {(int[]) {}, 0, 0};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
}

void test_ordered_array_set_intersection2() {
    ordered_array_set set1 = {(int[]) {}, 0, 0};
    ordered_array_set set2 = {(int[]) {3, 4, 8}, 3, 3};
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set_delete(set2);
    ordered_array_set expectedSet = {(int[]) {}, 0, 0};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
}

void test_ordered_array_set_intersection3() {
    ordered_array_set set1 = {(int[]) {3, 5, 7}, 3, 3};
    ordered_array_set set2 = {(int[]) {3, 5, 7}, 3, 3};
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set expectedSet = {(int[]) {3, 5, 7}, 3, 3};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection4() {
    ordered_array_set set1 = {(int[]) {5, 6, 7}, 3, 3};
    ordered_array_set set2 = {(int[]) {4, 7, 9}, 3, 3};
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set expectedSet = {(int[]) {7}, 1, 3};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection5() {
    ordered_array_set set1 = {(int[]) {2, 4, 6}, 3, 3};
    ordered_array_set set2 = {(int[]) {1, 3, 5}, 3, 3};
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set expectedSet = {(int[]) {}, 0, 3};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
}

void test_ordered_array_set_intersection6() {
    ordered_array_set set1 = {(int[]) {2, 3}, 2, 2};
    ordered_array_set set2 = {(int[]) {1, 2, 3}, 3, 3};
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set expectedSet = {(int[]) {2, 3}, 2, 2};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection() {
    test_ordered_array_set_intersection1();
    test_ordered_array_set_intersection2();
    test_ordered_array_set_intersection3();
    test_ordered_array_set_intersection4();
    test_ordered_array_set_intersection5();
    test_ordered_array_set_intersection6();
}

void test_ordered_array_set_difference1() {
    ordered_array_set set1 = {(int[]) {}, 0, 0};
    ordered_array_set set2 = {(int[]) {}, 0, 0};
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set expectedSet = {(int[]) {}, 0, 0};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
}

void test_ordered_array_set_difference2() {
    ordered_array_set set1 = {(int[]) {5, 9, 45}, 3, 3};
    ordered_array_set set2 = {(int[]) {}, 0, 0};
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set_delete(set1);
    ordered_array_set expectedSet = {(int[]) {5, 9, 45}, 3, 3};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference3() {
    ordered_array_set set1 = {(int[]) {3, 5}, 1, 1};
    ordered_array_set set2 = {(int[]) {2, 4}, 1, 1};
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set expectedSet = {(int[]) {3, 5}, 1, 1};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference4() {
    ordered_array_set set1 = {(int[]) {8, 9, 10}, 3, 3};
    ordered_array_set set2 = {(int[]) {8, 9, 10}, 3, 3};
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set expectedSet = {(int[]) {}, 0, 3};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
}

void test_ordered_array_set_difference() {
    test_ordered_array_set_difference1();
    test_ordered_array_set_difference2();
    test_ordered_array_set_difference3();
    test_ordered_array_set_difference4();
}

void test_ordered_array_set_symmetricDifference1() {
    ordered_array_set set1 = {(int[]) {}, 0, 0};
    ordered_array_set set2 = {(int[]) {}, 0, 0};
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set expectedSet = {(int[]) {}, 0, 0};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
}

void test_ordered_array_set_symmetricDifference2() {
    ordered_array_set set1 = {(int[]) {}, 0, 0};
    ordered_array_set set2 = {(int[]) {6, 7, 8}, 3, 3};
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set_delete(set2);
    ordered_array_set expectedSet = {(int[]) {6, 7, 8}, 3, 3};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference3() {
    ordered_array_set set1 = {(int[]) {2, 3, 4}, 3, 3};
    ordered_array_set set2 = {(int[]) {4, 5, 6}, 3, 3};
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set expectedSet = {(int[]) {2, 3, 5, 6}, 4, 6};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference4() {
    ordered_array_set set1 = {(int[]) {4, 6, 8}, 3, 3};
    ordered_array_set set2 = {(int[]) {2, 5, 7, 9, 21}, 5, 5};
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set expectedSet = {(int[]) {2, 4, 5, 6, 7, 8, 9, 21}, 8, 8};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference() {
    test_ordered_array_set_symmetricDifference1();
    test_ordered_array_set_symmetricDifference2();
    test_ordered_array_set_symmetricDifference3();
    test_ordered_array_set_symmetricDifference4();
}

void test_ordered_array_set_complement1() {
    ordered_array_set set = {(int[]) {}, 0, 0};
    ordered_array_set universumSet = {(int[]) {}, 0, 0};
    ordered_array_set resSet = ordered_array_set_complement(set, universumSet);
    ordered_array_set expectedSet = {(int[]) {}, 0, 0};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
}

void test_ordered_array_set_complement2() {
    ordered_array_set set = {(int[]) {}, 0, 0};
    ordered_array_set universumSet = {(int[]) {1, 4, 7, 11}, 4, 4};
    ordered_array_set resSet = ordered_array_set_complement(set, universumSet);
    ordered_array_set_delete(universumSet);
    ordered_array_set expectedSet = {(int[]) {1, 4, 7, 11}, 4, 4};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_complement3() {
    ordered_array_set set = {(int[]) {5, 6, 7}, 3, 3};
    ordered_array_set universumSet = {(int[]) {5, 6, 7}, 3, 3};
    ordered_array_set resSet = ordered_array_set_complement(set, universumSet);
    ordered_array_set_delete(set);
    ordered_array_set_delete(universumSet);
    ordered_array_set expectedSet = {(int[]) {}, 0, 3};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
}

void test_ordered_array_set_complement4() {
    ordered_array_set set = {(int[]) {1, 3, 5, 8}, 4, 4};
    ordered_array_set universumSet = {(int[]) {1, 2, 3, 4, 5, 6, 7, 8}, 8, 8};
    ordered_array_set resSet = ordered_array_set_complement(set, universumSet);
    ordered_array_set_delete(set);
    ordered_array_set_delete(universumSet);
    ordered_array_set expectedSet = {(int[]) {2, 4, 6, 7}, 4, 4};
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_complement() {
    test_ordered_array_set_complement1();
    test_ordered_array_set_complement2();
    test_ordered_array_set_complement3();
    test_ordered_array_set_complement4();
}

void test_ordered_array_set() {
    test_ordered_array_set_in();
    test_ordered_array_set_isSubset();
    test_ordered_array_set_insert();
    test_ordered_array_set_deleteElement();
    test_ordered_array_set_union();
    test_ordered_array_set_intersection();
    test_ordered_array_set_difference();
    test_ordered_array_set_symmetricDifference();
    test_ordered_array_set_complement();
}

void test_set() {
    test_unordered_array_set();
    test_ordered_array_set();
}