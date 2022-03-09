#ifndef INC_HAS_STRING_IDENTICAL_WORDS_H
#define INC_HAS_STRING_IDENTICAL_WORDS_H

#include "../string_.h"

// возвращает значение 1, если в массиве слов типа bagOfWords
// есть пара слов, составленных из одинаковых букв, в противном
// случае - значение 0.
int hasBagOfWordsIdenticalWords(bagOfWords bag);

// возвращает значение 1, если в строке s есть одинаковые слова,
// в противном случае - значение 0.
int hasStringIdenticalWords(char *s);

#endif