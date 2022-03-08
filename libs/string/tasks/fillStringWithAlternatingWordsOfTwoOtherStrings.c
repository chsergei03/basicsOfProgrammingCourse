#include "fillStringWithAlternatingWordsOfTwoOtherStrings.h"

// задача 9. даны две строки; получить строку, в которой чередуются слова первой и
// второй строки; если в одной из строк число слов больше, чем в другой, то оставшиееся
// слова этой строки должны быть дописаны в строку-результат; в качестве разделителя между
// словами использовать пробел.

void fillStringWithAlternatingWordsOfTwoOtherStrings(char *recStr, char *s1, char *s2) {
    char *writePtr = recStr;

    wordDescriptor w1, w2;
    int isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    char *endS1 = getEndOfString(s1);
    char *endS2 = getEndOfString(s2);
    size_t i = 0;
    while ((isW1Found = getWord(beginSearch1, &w1)),
            (isW2Found = getWord(beginSearch2, &w2)),
            isW1Found || isW2Found) {
        if (isW1Found && i % 2 == 0 || !isW2Found) {
            writePtr = copy(w1.begin, w1.end, writePtr);
            beginSearch1 = w1.end;
        } else if (i % 2 == 1 || !isW1Found) {
            writePtr = copy(w2.begin, w2.end, writePtr);
            beginSearch2 = w2.end;
        }

        *writePtr = SPACE_CHAR;
        writePtr += findNonSpace(beginSearch1) != endS1 ||
                    findNonSpace(beginSearch2) != endS2;

        i += 1;
    }

    *writePtr = NULL_SYMBOL;
}