#include "removeNonLetters.h"

// задача 1. удалить из строки все пробельные символы.

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource,
                               s, isgraph);
    *destination = NULL_SYMBOL;
}