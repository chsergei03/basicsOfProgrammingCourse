#include "deleteWordsWhichAreEqualToLastWord.h"

// задача 17.  удалить из строки слова, совпадающие с последним словом.

void deleteWordsWhichAreEqualToLastWord(char *s) {
    char *readPtr = s;
    char *writePtr = s;
    char *endStr = getEndOfString(s);
    wordDescriptor lastWord;
    getWordReverse(endStr, s, &lastWord);

    wordDescriptor word;
    int isWordInString;
    while (isWordInString = getWord(readPtr, &word),
            isWordInString) {
        writePtr = word.begin;
        if (areWordsEqual(word, lastWord)) {
            char *firstSpaceAfterWordToDelete = findSpace(word.begin);
            char *firstOtherNonSpace = findNonSpace(firstSpaceAfterWordToDelete);
            copy(firstSpaceAfterWordToDelete, endStr, writePtr);
            readPtr = firstOtherNonSpace;
        } else
            readPtr = word.end;
    }

    *writePtr = NULL_SYMBOL;
}