#include <memory.h>

#include "reverseWordOrderInString.h"

// задача 10. преобразовать строку изменив порядок следования
// в строке на обратный.

void reverseWordOrderInString(char *s) {
    char *endStr = getEndOfString(s);
    copy(s, endStr, _stringBuffer);
    char *endBuffer = getEndOfString(_stringBuffer);
    char *beginSearch = endBuffer;

    char *writePtr = s;
    wordDescriptor word;
    int isWordInString;
    while (isWordInString = getWordReverse(beginSearch, _stringBuffer, &word),
            isWordInString) {

        writePtr = copy(word.begin, word.end, writePtr);

        *writePtr = SPACE_CHAR;

        beginSearch = word.begin;
        beginSearch -= beginSearch != _stringBuffer;
        writePtr += findNonSpaceReverse(beginSearch, _stringBuffer) != _stringBuffer;
    }

    *writePtr = NULL_SYMBOL;

    freeBuffer();
}