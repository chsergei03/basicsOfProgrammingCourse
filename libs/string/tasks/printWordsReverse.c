#include <stdio.h>

#include "printWordsReverse.h"

// задача 7. вывести слова данной строки в обратном порядке
// по одному в строке экрана.

void printWordsReverse(char *s) {
    bagOfWords b;
    getBagOfWords(&b, s);

    size_t i = b.size - 1;
    while (i < b.size) {
        printWord(b.words[i]);

        i += i > 0 ? -1 : b.size;
    }
}