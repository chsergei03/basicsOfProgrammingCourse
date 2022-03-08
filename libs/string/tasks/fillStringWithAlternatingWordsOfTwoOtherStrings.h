#ifndef INC_FILL_STRING_WITH_ALTERNATING_WORDS_OF_TWO_STRINGS_H
#define INC_FILL_STRING_WITH_ALTERNATING_WORDS_OF_TWO_STRINGS_H

#include "../string_.h"

// возвращает строку, в которой чередуются слова строки s1 и строки s2; если в
// одной из строк число слов больше, чем в другой, то оставшиееся слова этой строки
// должны быть дописывает в строку-результат; в качестве разделителя между словами
// использует пробел.
void fillStringWithAlternatingWordsOfTwoOtherStrings(char *recStr, char *s1, char *s2);

#endif
