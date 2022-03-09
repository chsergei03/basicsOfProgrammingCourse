#include <stdlib.h>

#include "hasStringEveryCharOfWord.h"

// задача 19. определить, входит ли в данную строку
// каждая буква данного слова.

int hasStringEveryCharOfWord(char *s, char *word) {
    char *endStr = getEndOfString(s);
    char *endWord = getEndOfString(word);
    qsort(s, endStr - s,
          sizeof(char), compare_chars);
    qsort(word, endWord - word,
          sizeof(char), compare_chars);

    char *readStrPtr = s;
    char *readWordPtr = word;
    while (readStrPtr != endStr && readWordPtr != endWord) {
        if (*readStrPtr == *readWordPtr)
            readWordPtr++;

        readStrPtr++;
    }

    return readWordPtr == endWord;
}