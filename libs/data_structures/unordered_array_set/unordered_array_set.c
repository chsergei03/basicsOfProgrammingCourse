#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <memory.h>

#include "unordered_array_set.h"

unordered_array_set unordered_array_set_create(const size_t capacity) {
    return (unordered_array_set) {
            malloc(sizeof(int) * capacity),
            0,
            capacity
    };
}

static void unordered_array_set_shrinkToFit(unordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data,
                                  sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

unordered_array_set unordered_array_set_create_from_array(const int *a,
                                                          const size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        unordered_array_set_insert(&set, a[i]);
    unordered_array_set_shrinkToFit(&set);

    return set;
}

size_t unordered_array_set_in(const unordered_array_set *set,
                              const int value) {
    return linearSearch_(set->data, set->size, value);
}

bool unordered_array_set_isValueInSet(const unordered_array_set *set,
                                      const int value) {
    return unordered_array_set_in(set, value) < set->size;
}

bool unordered_array_set_isEqual(const unordered_array_set set1,
                                 const unordered_array_set set2) {
    if (set1.size != set2.size)
        return false;
    qsort(set1.data, set1.size,
          sizeof(int), compare_ints);
    qsort(set2.data, set2.size,
          sizeof(int), compare_ints);

    return memcmp(set1.data, set2.data,
                  set1.size * sizeof(int)) == 0;
}

bool unordered_array_set_isSubset(const unordered_array_set subset,
                                  const unordered_array_set set) {
    unordered_array_set intersection = unordered_array_set_intersection(subset,
                                                                        set);

    return intersection.size == subset.size || subset.size == 0;
}

void unordered_array_set_isAbleAppend(const unordered_array_set *set) {
    assert(set->size < set->capacity);
}

void unordered_array_set_insert(unordered_array_set *set,
                                const int value) {
    unordered_array_set_isAbleAppend(set);
    if (!unordered_array_set_isValueInSet(set, value)) {
        append_(set->data, &set->size, value);
    }
}

void unordered_array_set_deleteElement(unordered_array_set *set,
                                       const int value) {
    size_t posOfElementToDelete = linearSearch_(set->data, set->size, value);
    if (posOfElementToDelete < set->size)
        deleteByPosUnsaveOrder_(set->data, &set->size, posOfElementToDelete);
}

unordered_array_set unordered_array_set_union(const unordered_array_set set1,
                                              const unordered_array_set set2) {
    size_t unionSetMaxSize = set1.size + set2.size;
    unordered_array_set unionSet = unordered_array_set_create(unionSetMaxSize);
    unionSet.size = set1.size;
    memcpy(unionSet.data, set1.data, set1.size * sizeof(int));
    for (size_t i = 0; i < set2.size; i++) {
        unordered_array_set_insert(&unionSet, set2.data[i]);
    }
    unordered_array_set_shrinkToFit(&unionSet);

    return unionSet;
}

bool intersectionConditionUnorderedSet(const unordered_array_set checkSet,
                                       const int value) {
    return unordered_array_set_isValueInSet(&checkSet, value);
}

bool differenceConditionUnorderedSet(const unordered_array_set checkSet,
                                     const int value) {
    return !intersectionConditionUnorderedSet(checkSet, value);
}

void unordered_array_set_insertIf(unordered_array_set *resSet,
                                  const unordered_array_set checkSet,
                                  const int value,
                                  int (*predicate)(unordered_array_set, int)) {
    if (!unordered_array_set_isValueInSet(resSet, value) &&
        predicate(checkSet, value)) {
        unordered_array_set_isAbleAppend(resSet);
        append_(resSet->data, &resSet->size, value);
    }
}

unordered_array_set unordered_array_set_intersection(const unordered_array_set set1,
                                                     const unordered_array_set set2) {
    size_t intersectionSetSize = min2_size_t(set1.size, set2.size);
    unordered_array_set intersectionSet = unordered_array_set_create(intersectionSetSize);
    for (size_t i = 0; i < set2.size; i++)
        unordered_array_set_insertIf(&intersectionSet,
                                     set1,
                                     set2.data[i],
                                     (int (*)(unordered_array_set, int)) intersectionConditionUnorderedSet);
    unordered_array_set_shrinkToFit(&intersectionSet);

    return intersectionSet;
}


unordered_array_set unordered_array_set_difference(const unordered_array_set set1,
                                                   const unordered_array_set set2) {
    size_t differenceSetSize = set1.size;
    unordered_array_set differenceSet = unordered_array_set_create(differenceSetSize);
    for (size_t i = 0; i < set1.size; i++)
        unordered_array_set_insertIf(&differenceSet,
                                     set2,
                                     set1.data[i],
                                     (int (*)(unordered_array_set, int)) differenceConditionUnorderedSet);
    unordered_array_set_shrinkToFit(&differenceSet);

    return differenceSet;
}

unordered_array_set unordered_array_set_symmetricDifference(const unordered_array_set set1,
                                                            const unordered_array_set set2) {
    unordered_array_set component1 = unordered_array_set_difference(set1, set2);
    unordered_array_set component2 = unordered_array_set_difference(set2, set1);
    unordered_array_set symmetricDifferenceSet = unordered_array_set_union(component1,
                                                                           component2);
    unordered_array_set_delete(component1);
    unordered_array_set_delete(component2);

    return symmetricDifferenceSet;
}

unordered_array_set unordered_array_set_complement(const unordered_array_set set,
                                                   const unordered_array_set universumSet) {
    return unordered_array_set_difference(universumSet, set);;
}

void unordered_array_set_print(const unordered_array_set set) {
    printf("{");
    for (size_t i = 0; i < set.size; i++) {
        printf("%d, ", set.data[i]);
    }
    if (set.size == 0)
        printf("}\n");
    else
        printf("\b\b}\n");
}

void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}