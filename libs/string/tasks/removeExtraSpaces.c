#include "removeExtraSpaces.h"

// задача 2. сократить количество пробелов
// между словами данного предложения до одного.

void removeExtraSpaces(char *s) {
    char *firstNonSpace = findNonSpace(s);
    char *lastNonSpace = findNonSpaceReverse(s + strlen_(s), s);
    char *substrBegin = s;
    size_t spaceSequenceLen = 0;
    while (*substrBegin != NULL_SYMBOL) {
        if (isspace(*substrBegin))
            spaceSequenceLen += substrBegin >= firstNonSpace &&
                                substrBegin <= lastNonSpace;
        else
            spaceSequenceLen = 0;

        if (spaceSequenceLen <= 1) {
            *s = *substrBegin;
            s++;
        }

        substrBegin++;
    }

    *s = NULL_SYMBOL;
}
