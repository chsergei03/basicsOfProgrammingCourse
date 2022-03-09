#ifndef INC_FIND_WORD_BEFORE_FIRST_W_WORD_H
#define INC_FIND_WORD_BEFORE_FIRST_W_WORD_H

#include "../string_.h"

// возврвщает значение 1, если слово word
// есть в массиве слов bag типа bagOfWords,
// в противном случае - значение 0.
int isWordFoundInBag(wordDescriptor word, bagOfWords bag);

// осуществляет в строке s1 поиск слова, предшествующего слову w (слово w - первое,
// слово из s1, находящееся в s2), возвращает именнованную константу FIRST_WORD_W,
// если первое слово в строке s1 является словом w, возвращает именованную константу
// NOT_WORDS_FROM_S1_IN_S2, если строки s1 и s2 не имеют общих слов, возвращает именованную
// константу EMPTY_S1_STRING, если строка пустая, возвращает именованную константу
// WORD_BEFORE_FIRST_W_FOUND, если искомое слово было найдено.
wordBeforeFirstWWordReturnCode getWordBeforeFirstWWord(char *s1, char *s2,
                                                       char **beginWord,
                                                       char **endWord);

#endif
