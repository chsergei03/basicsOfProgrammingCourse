#ifndef INC_GET_WORD_BEFORE_FIRST_WORD_WITH_A_H
#define INC_GET_WORD_BEFORE_FIRST_WORD_WITH_A_H

#include "../string_.h"

// возврвщает значение 1, если буква a была
// найдено в слове word, в противном случае - 'ложь'.
int isAFoundInWord(wordDescriptor word);

// осуществляет в строке s поиск слова, предшествующего первому слову,
// содержащему букву a (регистр не учитывается), возвращает именнованную
// константу FIRST_WORD_WITH_A, если первое слово в строке содержит букву
// a, возвращает именованную константу NOT_FOUND_A_WORD_WITH_A, если слова
// с буквой a не было найдено в строке, возвращает именованную константу
// EMPTY_STRING, если строка пустая, возвращает именованную константу
// WORD_FOUND, если искомое слово было найдено.
wordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s,
                                                               char **beginWordBefore,
                                                               char **endWordBefore);

#endif
