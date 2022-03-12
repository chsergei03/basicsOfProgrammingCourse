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

    static int innerBuffer[100000];
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
}

void timeExperiment() {
    sortFunc sortFuncs[] = {};

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