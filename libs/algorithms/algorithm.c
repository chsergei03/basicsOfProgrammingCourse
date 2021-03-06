#include "algorithm.h"

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

int compare_chars(const void *a, const void *b) {
    char arg1 = *(const char *) a;
    char arg2 = *(const char *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

size_t min2_size_t(const size_t a, const size_t b) {
    return a < b ? a : b;
}

void void_swap(void *a, void *b, const size_t baseTypeSize) {
    char *pa = a;
    char *pb = b;
    for (int i = 0; i < baseTypeSize; i++) {
        char t = *pa;
        *pa = *pb;
        *pb = t;
        pa++;
        pb++;
    }
}

int max2_int(const int a, const int b) {
    return a > b ? a : b;
}

int compare_longLong(const void *a, const void *b) {
    long long arg1 = *(const long long *) a;
    long long arg2 = *(const long long *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

int abs_int(const int a) {
    return a < 0 ? -a : a;
}