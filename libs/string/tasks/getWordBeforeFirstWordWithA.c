#include "getWordBeforeFirstWordWithA.h"

// задача 11. вывести слово данной строки, предшествующее первому
// из слов, содержащему букву "а", регистр значения не имеет.

int isAChar(char symbol) {
    return symbol == 'A' || symbol == 'a';
}

int isAFoundInWord(wordDescriptor w) {
    while (w.begin != w.end && *w.begin != '\0' && !isAChar(*w.begin))
        w.begin++;

    return isAChar(*w.begin);
}

wordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s,
                                                               char **beginWordBefore,
                                                               char **endWordBefore) {
    wordDescriptor prevWord, curWord;
    int isWordInString = getWord(s, &prevWord);

    if (!isWordInString)
        return EMPTY_STRING;
    else if (isAFoundInWord(prevWord))
        return FIRST_WORD_WITH_A;

    int isAFoundInWordFlag = 0;
    char *readPtr = prevWord.end;
    char *endStr = getEndOfString(s);
    while (isWordInString = getWord(readPtr, &curWord),
            isAFoundInWordFlag = isAFoundInWord(curWord),
            isWordInString && !isAFoundInWordFlag) {

        prevWord = curWord;
        readPtr = findNonSpace(readPtr) != endStr ? curWord.end : readPtr;
    }

    if (isAFoundInWordFlag) {
        *beginWordBefore = prevWord.begin;
        *endWordBefore = prevWord.end;
        return WORD_FOUND;
    } else
        return NOT_FOUND_A_WORD_WITH_A;
}