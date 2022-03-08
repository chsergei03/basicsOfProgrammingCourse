#include <stdio.h>

#include "printWordsReverse.h"

// задача 7. вывести слова данной строки в обратном порядке
// по одному в строке экрана.

void printWordsReverse(char *s) {
    getBagOfWords(&_bag, s);

    size_t i = _bag.size - 1;
    while (i < _bag.size) {
        printWord(_bag.words[i]);

        i += i > 0 ? -1 : _bag.size;
    }
}