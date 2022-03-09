#include "complementS2.h"

// задача 18. даны две строки; пусть n1 – число слов в первой
// строке, а n2 – во второй; требуется дополнить строку, содержащую
// меньшее количество слов, последними словами строки, в которой содержится
// большее количество слов.

void complementS2(char *s1, char *s2) {
    bagOfWords bag1, bag2;
    getBagOfWords(&bag1, s1);
    getBagOfWords(&bag2, s2);

    char *writePtr;
    bagOfWords sourceBag;
    if (bag1.size <= bag2.size) {
        writePtr = s1;
        sourceBag = bag2;
    } else {
        writePtr = s2;
        sourceBag = bag1;
    }

    size_t minSize = min2_size_t(bag1.size, bag2.size);
    size_t complementSize = minSize + abs_int(bag1.size - bag2.size);

    writePtr = getEndOfString(writePtr);

    for (size_t i = minSize; i < complementSize; i++) {
        if (i > 0) {
            *writePtr = SPACE_CHAR;
            writePtr++;
        }
        writePtr = copy(sourceBag.words[i].begin,
                        sourceBag.words[i].end,
                        writePtr);
    }

    *writePtr = NULL_SYMBOL;
}