#include <stdio.h>
#include <assert.h>

#include "bitset.h"

bitset bitset_create(const uint32_t maxValue) {
    assert(maxValue < 32);

    return (bitset) {0, maxValue};
}

void bitset_inputValues(bitset *set) {
    scanf("%u", &set->values);
}

bool bitset_checkValue(const bitset set,
                       const uint32_t x) {
    return x >= 0 && x <= set.maxValue;
}

bool bitset_in(const bitset set,
               const uint32_t x) {
    assert(bitset_checkValue(set, x));

    return set.values >> x & 1;
}

bool bitset_isEqual(const bitset set1,
                    const bitset set2) {
    return set1.values == set2.values;
}

bool bitset_isSubset(const bitset subset,
                     const bitset set) {
    uint32_t intersection = subset.values & set.values;

    return subset.values <= set.values && (subset.values == 0 || intersection > 0);
}

void bitset_insert(bitset *set,
                   const uint32_t x) {
    assert(bitset_checkValue(*set, x));
    set->values |= 1 << x;
}

void bitset_deleteElement(bitset *set,
                          const uint32_t x) {
    set->values &= ~(1 << x);
}

bitset bitset_union(const bitset set1,
                    const bitset set2) {
    assert(set1.maxValue == set2.maxValue);

    return (bitset) {set1.values | set2.values, set1.maxValue};
}

bitset bitset_intersection(const bitset set1,
                           const bitset set2) {
    assert(set1.maxValue == set2.maxValue);

    return (bitset) {set1.values & set2.values, set1.maxValue};
}

bitset bitset_difference(const bitset set1,
                         const bitset set2) {
    assert(set1.maxValue == set2.maxValue);

    return (bitset) {set1.values & ~(set2.values), set1.maxValue};
}

bitset bitset_symmetricDifference(const bitset set1,
                                  const bitset set2) {
    assert(set1.maxValue == set2.maxValue);

    return (bitset) {set1.values ^ set2.values, set1.maxValue};
}

bitset bitset_complement(const bitset set) {
    return (bitset) {~set.values, set.maxValue};
}

void bitset_print(const bitset set) {
    printf("{");
    int isEmpty = 1;
    for (int i = 0; i <= set.maxValue; ++i) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = 0;
        }
    }
    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}