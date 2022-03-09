#include "getWordBeforeFirstWWord.h"

// задача 16. даны две строки s1 и s2; пусть w – первое из слов
// строки s1, которое есть в строке s2; найти слово, предшествующее
// первому вхождению w в s1.

int isWordFoundInBag(wordDescriptor word, bagOfWords bag) {
    for (size_t i = 0; i < bag.size; i++)
        if (areWordsEqual(word, bag.words[i]))
            return 1;

    return 0;
}

wordBeforeFirstWWordReturnCode getWordBeforeFirstWWord(char *s1, char *s2,
                                                       char **beginWord,
                                                       char **endWord) {
    bagOfWords bag1, bag2;
    getBagOfWords(&bag1, s1);

    if (bag1.size == 0)
        return EMPTY_S1_STRING;

    getBagOfWords(&bag2, s2);

    wordDescriptor prevWord, curWord;
    prevWord = bag1.words[0];

    if (isWordFoundInBag(prevWord, bag2))
        return FIRST_WORD_W;

    for (size_t i = 1; i < bag1.size; i++) {
        curWord = bag1.words[i];
        for (size_t j = 0; j < bag2.size; j++) {
            if (areWordsEqual(curWord, bag2.words[j])) {
                *beginWord = prevWord.begin;
                *endWord = prevWord.end;
                return WORD_BEFORE_FIRST_W_FOUND;
            }
        }
        prevWord = curWord;
    }

    return NO_WORDS_FROM_S1_IN_S2;
}