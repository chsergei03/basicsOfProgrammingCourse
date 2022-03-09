#include "hasStringIdenticalWords.h"

// задача 13. определить, есть ли в данной строке одинаковые слова.

int hasBagOfWordsIdenticalWords(bagOfWords bag) {
    for (size_t i = 0; i < bag.size; i++)
        for (size_t j = 0; j < bag.size; j++)
            if (i != j && areWordsEqual(bag.words[i], bag.words[j]))
                return 1;

    return 0;
}

int hasStringIdenticalWords(char *s) {
    bagOfWords bag;
    getBagOfWords(&bag, s);

    return hasBagOfWordsIdenticalWords(bag);
}

