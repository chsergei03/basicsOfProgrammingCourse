#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorting_time_complexity.h"

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

#define TIME_TEST(testCode, time) { \
    clock_t startTime = clock(); \
    testCode \
    clock_t endTime = clock(); \
    clock_t sortingTime = endTime - startTime; \
    time = (double) sortingTime / CLOCKS_PER_SEC; \
}

void checkTime(void (*sort)(int *, size_t),
               void (*generate)(int *, size_t),
               size_t size, char *experimentName) {
    static size_t runCounter = 1;

    int *innerBuffer = (int *) malloc(size * sizeof(int));

    generate(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);

    double time;
    TIME_TEST({
                  sort(innerBuffer, size);
              }, time)

    printf("Status: ");
    if (isNonDescendingSortedArray_(innerBuffer, size)) {
        printf("OK! Time: %.3f s.\n", time);

        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu: %.3f\n", size, time);
        fclose(f);
    } else {
        printf("Wrong!\n");

        outputArray_(innerBuffer, size);
    }

    free(innerBuffer);
}

void timeExperiment() {
    sortFunc sortFuncs[] = {
            {bubbleSort,    "bubbleSort"},
            {selectionSort, "selectionSort"},
            {insertionSort, "insertionSort"},
            {combSort,      "combSort"},
            {shellSort,     "shellSort"},
            {digitSort,     "digitSort"}
    };

    const unsigned FUNCS_N = ARRAY_SIZE(sortFuncs);

    generateFunc generateFuncs[] = {
            {generateRandomArray,           "random"},
            {generateOrderedArray,          "ordered"},
            {generateOrderedBackwardsArray, "orderedBackwards"}
    };

    const unsigned CASES_N = ARRAY_SIZE(generateFuncs);

    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf("------------------------------\n");
        printf("size: %zu\n", size);
        for (size_t i = 0; i < FUNCS_N - 4; i++) {
            for (size_t j = 0; j < CASES_N; j++) {
                static char filename[128];
                sprintf(filename, "%s_%s_time",
                        sortFuncs[i].name, generateFuncs[j].name);
                checkTime(sortFuncs[i].sort,
                          generateFuncs[j].generate,
                          size, filename);
            }
        }
        printf("\n");
    }

    for (size_t size = 150000; size <= 350000; size += 10000) {
        printf("------------------------------\n");
        printf("size: %zu\n", size);
        size_t i = 2;
        for (size_t j = 0; j < CASES_N; j++) {
            static char filename[128];
            sprintf(filename, "%s_%s_time",
                    sortFuncs[i].name, generateFuncs[j].name);
            checkTime(sortFuncs[i].sort,
                      generateFuncs[j].generate,
                      size, filename);
        }
        printf("\n");
    }

    for (size_t size = 200000; size <= 2000000; size += 100000) {
        printf("------------------------------\n");
        printf("size: %zu\n", size);
        for (size_t i = FUNCS_N - 3; i < FUNCS_N; i++) {
            for (size_t j = 0; j < CASES_N; j++) {
                static char filename[128];
                sprintf(filename, "%s_%s_time",
                        sortFuncs[i].name, generateFuncs[j].name);
                checkTime(sortFuncs[i].sort,
                          generateFuncs[j].generate,
                          size, filename);
            }
        }
        printf("\n");
    }
}

void checkComparisonsCount(long long (*sort)(int *, size_t),
                           void (*generate)(int *, size_t),
                           const size_t size, char *experimentName) {
    static size_t runCounter = 1;

    int *innerBuffer = (int *) malloc(size * sizeof(int));

    generate(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);

    long long comparisonsCount = sort(innerBuffer, size);

    printf("Status: ");
    if (isNonDescendingSortedArray_(innerBuffer, size)) {
        printf("OK! Comparisons count: %lld.\n", comparisonsCount);

        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu: %lld\n", size, comparisonsCount);
        fclose(f);
    } else {
        printf("Wrong!\n");

        outputArray_(innerBuffer, size);
    }

    free(innerBuffer);
}

void comparisonsCountExperiment() {
    sortFunc_compCount sortFuncs[] = {
            {bubbleSort_comparisonsCount,    "bubbleSort"},
            {selectionSort_comparisonsCount, "selectionSort"},
            {insertionSort_comparisonsCount, "insertionSort"},
            {combSort_comparisonsCount,      "combSort"},
            {shellSort_comparisonsCount,     "shellSort"},
            {digitSort_comparisonsCount,     "digitSort"},
    };

    const unsigned FUNCS_N = ARRAY_SIZE(sortFuncs);

    generateFunc generateFuncs[] = {
            {generateRandomArray,           "random"},
            {generateOrderedArray,          "ordered"},
            {generateOrderedBackwardsArray, "orderedBackwards"}
    };

    const unsigned CASES_N = ARRAY_SIZE(generateFuncs);

    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf("------------------------------\n");
        printf("size: %zu\n", size);
        for (size_t i = 0; i < FUNCS_N; i++) {
            for (size_t j = 0; j < CASES_N; j++) {
                static char filename[128];
                sprintf(filename, "%s_%s_comparisonsCount",
                        sortFuncs[i].name, generateFuncs[j].name);
                checkComparisonsCount(sortFuncs[i].sort,
                                      generateFuncs[j].generate,
                                      size, filename);
            }
        }
        printf("\n");
    }
}

void checkTime_question2(void (*sort)(int *, size_t),
                         void (*generate)(int *, size_t),
                         size_t size, size_t i,
                         char *experimentName) {
    static size_t runCounter = 1;

    int *innerBuffer = (int *) malloc(size * sizeof(int));

    generate(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);

    double time;
    TIME_TEST({
                  sort(innerBuffer, size);
              }, time)

    printf("Status: ");
    if (isNonDescendingSortedArray_(innerBuffer, size)) {
        printf("OK! Time: %.3f s.\n", time);

        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu: %.3f\n", i, time);
        fclose(f);
    } else {
        printf("Wrong!\n");

        outputArray_(innerBuffer, size);
    }

    free(innerBuffer);
}

void timeExperiment_question2() {
    sortFunc sortFunc = {digitSort, "digitSort"};

    generateFunc generateFuncs[] = {
            {generateRandomArray,           "random"},
            {generateOrderedArray,          "ordered"},
            {generateOrderedBackwardsArray, "orderedBackwards"}
    };

    const unsigned CASES_N = ARRAY_SIZE(generateFuncs);


    size_t size = 200000;
    printf("------------------------------\n");
    printf("size: %zu\n", size);
    for (size_t i = 0; i < CASES_N; i++) {
        static char filename[128];
        sprintf(filename, "question2_%s_%s_time",
                sortFunc.name, generateFuncs[i].name);
        for (size_t j = 1; j <= 10; j++) {
            checkTime_question2(sortFunc.sort,
                                generateFuncs[i].generate,
                                size, j, filename);
        }
        printf("\n");
    }

}