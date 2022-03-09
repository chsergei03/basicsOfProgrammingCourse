#include "hasStringPairOfWordsWithIdenticalCharacters.h"

// задача 14. определить, есть ли в данной строке пара слов,
// составленных из одинаковых букв.

int hasStringPairOfWordsWithIdenticalCharacters(char *s) {
    if (hasStringIdenticalWords(s))
        return 1;

    bagOfWords bag;
    getBagOfWordsWithWordSorting(&bag, s);

    return hasBagOfWordsIdenticalWords(bag);
}