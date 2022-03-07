#include "digitToStartReverseTransform.h"

// задача 3. преобразовать строку таким образом, чтобы цифры каждого слова
// были перенесены в его начало с изменением порядка их следования в слове
// на обратный, а буквы - в конец слова (без изменения порядка их следования
// в слове).

void digitToStartReverse(wordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);

    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);

    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartReverseTransform(char *s) {
    wordDescriptor currentWord = {};
    while (getWord(s, &currentWord)) {
        digitToStartReverse(currentWord);
        s = currentWord.end;
    }
}