#include "getStringFromWordsOfStringWhichAreNotEqualToLastWord.h"

// задача 15. получить строку из слов данной строки, которые отличны
// от последнего слова.

void getStringFromWordsOfStringWhichIsNotEqualToLastWord(char *s) {
    char *readPtr = s;
    char *writePtr = s;
    char *endStr = getEndOfString(s);
    wordDescriptor lastWord;
    getWordReverse(endStr, s, &lastWord);

    wordDescriptor curWord;
    int isWordInString;
    while (isWordInString = getWord(readPtr, &curWord),
            isWordInString) {
        if (!areWordsEqual(curWord, lastWord)) {
            writePtr = copy(curWord.begin, curWord.end, writePtr);
            *writePtr = SPACE_CHAR;
            writePtr += findNonSpace(writePtr) != endStr;
        }

        readPtr = curWord.end;
    }

    if (isgraph(*writePtr))
        writePtr = findNonSpaceReverse(findSpaceReverse(writePtr, s), s) + 1;
    else
        writePtr = findSpace(findNonSpaceReverse(writePtr, s));

    *writePtr = NULL_SYMBOL;
}