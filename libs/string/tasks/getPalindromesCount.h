#ifndef INC_GET_PALINDROMES_COUNT_H
#define INC_GET_PALINDROMES_COUNT_H

#include "../string_.h"

// возвращает значение 1, если слово word является
// палиндромом, в противном случае - значение 0.
int isPalindrome(wordDescriptor word);

// возвращает количество слов-палиндромов
// в строке s, слова в которой разделены
// запятыми.
int getPalindromesCount(char *s);

#endif
