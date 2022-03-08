#include "replace.h"

// задача 5. заменить все вхождения слова w1 на w2.

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    wordDescriptor word1 = {w1, w1 + w1Size};
    wordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *writePtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        writePtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        writePtr = source;
    }

    int isFirstLetterInWord = 1;
    wordDescriptor currentWord;
    while (*readPtr != NULL_SYMBOL) {
        int isW1 = 0;
        if (isgraph(*readPtr) && isFirstLetterInWord) {
            getWord(readPtr, &currentWord);
            isW1 = areWordsEqual(currentWord, word1);
            isFirstLetterInWord = 0;
        } else if (!isFirstLetterInWord)
            isFirstLetterInWord = 1;

        if (!isW1) {
            *writePtr = *readPtr;
            writePtr++;
            readPtr++;
        } else {
            writePtr = copy(word2.begin, word2.end, writePtr);
            readPtr += w1Size;
        }
    }

    *writePtr = NULL_SYMBOL;
}