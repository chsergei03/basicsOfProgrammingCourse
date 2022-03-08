#include "areWordsLexicographicallyOrdered.h"

// задача 6. определить, упорядочены ли лексикографически слова
// данного предложения.

int areWordsLexicographicallyOrdered(char *s) {
    wordDescriptor prevWord, curWord;
    int isWordInString = getWord(s, &prevWord);
    while (isWordInString) {
        s = prevWord.end;
        isWordInString = getWord(s, &curWord);

        if (isWordInString && wordcmp_(prevWord, curWord) > 0)
            return 0;

        prevWord = curWord;
    }

    return 1;
}