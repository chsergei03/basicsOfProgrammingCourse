#include "getPalindromesCount.h"

// задача 8. в данной строке соседние слова разделены
// запятыми. определить количество слов-палиндромов.

int isPalindrome(wordDescriptor word) {
    word.end -= 1;

    while (word.end >= word.begin) {
        if (*word.begin != *word.end)
            return 0;

        word.begin++;
        word.end--;
    }

    return 1;
}

int getPalindromesCount(char *s) {
    int count = 0;
    int divider = ',';

    wordDescriptor word;
    int isWordInString = getWordByDivider(s, &word, divider);
    while (isWordInString) {
        count += isPalindrome(word);

        s = word.end + 1;
        isWordInString = getWordByDivider(s, &word, divider);
    }

    return count;
}