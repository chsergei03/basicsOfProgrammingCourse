#ifndef INC_DIGIT_TO_START_TRANSFORM_H
#define INC_DIGIT_TO_START_TRANSFORM_H

#include "../string_.h"

// переносит цифры слова word в его начало с изменением порядка их следования
// в слове на обратный, а буквы - в конец слова (без изменения порядка их
// следования в слове).
void digitToStartReverse(wordDescriptor word);

// преобразует строку s таким образом, чтобы цифры каждого слова были перенесены
// в его начало с изменением порядка их следования в слове на обратный, а буквы -
// в конец слова (без изменения порядка их следования в слове).
void digitToStartReverseTransform(char *s);

#endif