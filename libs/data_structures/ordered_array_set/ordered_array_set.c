#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <memory.h>

#include "ordered_array_set.h"

ordered_array_set ordered_array_set_create(const size_t capacity) {
    return (ordered_array_set) {
            (int *) malloc(capacity * sizeof(int)),
            0,
            capacity
    };
}

static void ordered_array_set_shrinkToFit(ordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, a->size * sizeof(int));
        a->capacity = a->size;
    }
}

ordered_array_set ordered_array_set_create_from_array(const int *a,
                                                      const size_t size) {
    ordered_array_set set = ordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        ordered_array_set_insert(&set, a[i]);
    ordered_array_set_shrinkToFit(&set);

    return set;
}

size_t ordered_array_set_in(const ordered_array_set *set,
                            const int value) {
    return binarySearch_orderedSet_(set->data, set->size, value);
}

size_t ordered_array_set_isValueInSet(const ordered_array_set *set,
                                      const int value) {
    return ordered_array_set_in(set, value) < set->size;
}

bool ordered_array_set_isEqual(const ordered_array_set set1,
                               const ordered_array_set set2) {
    if (set1.size != set2.size)
        return false;

    return memcmp(set1.data, set2.data,
                  set1.size * sizeof(int)) == 0;
}

bool ordered_array_set_isSubset(const ordered_array_set subset,
                                const ordered_array_set set) {
    ordered_array_set intersection = ordered_array_set_intersection(subset,
                                                                    set);

    return intersection.size == subset.size || subset.size == 0;
}

void ordered_array_set_isAbleAppend(const ordered_array_set *set) {
    assert(set->size < set->capacity);
}

void ordered_array_set_insert(ordered_array_set *set,
                              const int value) {
    ordered_array_set_isAbleAppend(set);
    size_t pos = binarySearchMoreOrEqual_(set->data, set->size, value);
    if (!ordered_array_set_isValueInSet(set, value)) {
        if (pos < set->size)
            insert_(set->data, &set->size, pos, value);
        else
            append_(set->data, &set->size, value);
    }
}

void ordered_array_set_deleteElement(ordered_array_set *set,
                                     const int value) {
    size_t pos = binarySearch_orderedSet_(set->data, set->size, value);
    if (pos < set->size)
        deleteByPosSaveOrder_(set->data, &set->size, pos);
}

ordered_array_set ordered_array_set_union(const ordered_array_set set1,
                                          const ordered_array_set set2) {
    size_t unionSetMaxSize = set1.size + set2.size;
    ordered_array_set unionSet = ordered_array_set_create(unionSetMaxSize);
    unionSet.size = set1.size;
    memcpy(unionSet.data, set1.data, set1.size * sizeof(int));
    for (size_t i = 0; i < set2.size; i++) {
        ordered_array_set_insert(&unionSet, set2.data[i]);
    }
    ordered_array_set_shrinkToFit(&unionSet);

    return unionSet;
}

bool intersectionConditionOrderedSet(const ordered_array_set checkSet,
                                     const int value) {
    return ordered_array_set_isValueInSet(&checkSet, value);
}

bool differenceConditionOrderedSet(const ordered_array_set checkSet,
                                   const int value) {
    return !intersectionConditionOrderedSet(checkSet, value);
}

void ordered_array_set_insertIf(ordered_array_set *resSet,
                                const ordered_array_set checkSet,
                                const int value,
                                int (*predicate)(ordered_array_set, int)) {

    if (!ordered_array_set_isValueInSet(resSet, value) &&
        predicate(checkSet, value)) {
        ordered_array_set_isAbleAppend(resSet);
        ordered_array_set_insert(resSet, value);
    }
}

ordered_array_set ordered_array_set_intersection(const ordered_array_set set1,
                                                 const ordered_array_set set2) {
    size_t intersectionSetSize = min2_size_t(set1.size, set2.size);
    ordered_array_set intersectionSet = ordered_array_set_create(intersectionSetSize);
    for (size_t i = 0; i < set2.size; i++)
        ordered_array_set_insertIf(&intersectionSet,
                                   set1,
                                   set2.data[i],
                                   (int (*)(ordered_array_set, int)) intersectionConditionOrderedSet);
    ordered_array_set_shrinkToFit(&intersectionSet);

    return intersectionSet;
}

ordered_array_set ordered_array_set_difference(const ordered_array_set set1,
                                               const ordered_array_set set2) {
    size_t differenceSetSize = set1.size;
    ordered_array_set differenceSet = ordered_array_set_create(differenceSetSize);
    for (size_t i = 0; i < set1.size; i++)
        ordered_array_set_insertIf(&differenceSet,
                                   set2,
                                   set1.data[i],
                                   (int (*)(ordered_array_set, int)) differenceConditionOrderedSet);
    ordered_array_set_shrinkToFit(&differenceSet);

    return differenceSet;
}

ordered_array_set ordered_array_set_symmetricDifference(const ordered_array_set set1,
                                                        const ordered_array_set set2) {
    ordered_array_set component1 = ordered_array_set_difference(set1, set2);
    ordered_array_set component2 = ordered_array_set_difference(set2, set1);
    ordered_array_set symmetricDifferenceSet = ordered_array_set_union(component1,
                                                                       component2);
    ordered_array_set_delete(component1);
    ordered_array_set_delete(component2);

    return symmetricDifferenceSet;
}


ordered_array_set ordered_array_set_complement(const ordered_array_set set,
                                               const ordered_array_set universumSet) {
    return ordered_array_set_difference(universumSet, set);
}

void ordered_array_set_print(const ordered_array_set set) {
    printf("{");
    for (size_t i = 0; i < set.size; i++) {
        printf("%d, ", set.data[i]);
    }
    if (set.size == 0)
        printf("}\n");
    else
        printf("\b\b}\n");
}

void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}