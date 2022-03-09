#include "lastWordInFirstStringInSecondString.h"

// задача 12. даны две строки, определить последнее из слов
// первой строки, которое есть во второй строке.

wordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2) {
    bagOfWords b1, b2;
    getBagOfWords(&b1, s1);
    getBagOfWords(&b2, s2);

    size_t i = b1.size - 1;
    while (i < b1.size) {
        for (size_t j = 0; j < b2.size; j++)
            if (areWordsEqual(b2.words[j], b1.words[i]))
                return b1.words[i];

        i += i > 0 ? -1 : b1.size;
    }

    wordDescriptor noWord = {"", ""};

    return noWord;
}