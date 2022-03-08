#include <malloc.h>

#include "digitToEndTransform.h"

// задача 3 (дополнительная задача для закрепления). преобразовать строку
// таким образом, чтобы цифры каждого слова были перенесены в его конец
// без изменения порядка их следования в слове, а буквы - в начало слова
// (также без изменения порядка их следования в слове).

void digitToEnd(wordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);

    char *recPosition = copyIf(_stringBuffer,
                               endStringBuffer,
                               word.begin, isalpha);

    copyIf(_stringBuffer, endStringBuffer, recPosition, isdigit);

    freeBuffer();
}

void digitToEndTransform(char *s) {
    wordDescriptor currentWord = {};
    while (getWord(s, &currentWord)) {
        digitToEnd(currentWord);
        s = currentWord.end;
    }
}