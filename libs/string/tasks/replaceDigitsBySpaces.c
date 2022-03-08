#include <memory.h>

#include "replaceDigitsBySpaces.h"

#define SPACE_CHAR ' '
#define NULL_CHAR '0'
#define NULL_SYMBOL '\0'

// задача 4. преобразовать строку, заменив каждую цифру
// соответствующим ей числом пробелов.

void replaceDigitsBySpaces(char *s) {
    copy(s, getEndOfString(s), _stringBuffer);
    char *readPtr = _stringBuffer;
    size_t stringLen = strlen_(s);

    memset(s, SPACE_CHAR, MAX_STRING_SIZE + 1);
    char *writePtr = s;

    while (readPtr - _stringBuffer < stringLen) {
        if (!isDigit(*readPtr)) {
            *writePtr = *readPtr;
            writePtr++;
        } else {
            writePtr += *readPtr - NULL_CHAR;
        }

        readPtr++;
    }

    *writePtr = NULL_SYMBOL;
}