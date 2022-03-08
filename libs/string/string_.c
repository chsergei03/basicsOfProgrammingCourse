#include <assert.h>
#include <memory.h>

#include "string_.h"

size_t strlen_(const char *begin) {
    const char *end = begin;
    while (*end != '\0') {
        end++;
    }

    return end - begin;
}

char *find(char *begin, const char *end, const int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && !isgraph(*begin))
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isgraph(*rbegin))
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination) {
    size_t fragmentToCopyLen = endSource - beginSource;

    memcpy(beginDestination, beginSource,
           fragmentToCopyLen * sizeof(char));

    return beginDestination + fragmentToCopyLen;
}

int isDigit(int ch) {
    return '0' <= ch && ch <= '9';
}

char *copyIf(const char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            memcpy(beginDestination,
                   beginSource,
                   sizeof(char));
            beginDestination++;
        }
        beginSource++;
    }

    return beginDestination;
}

char *copyIfReverse(const char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource)) {
            memcpy(beginDestination,
                   rbeginSource,
                   sizeof(char));
            beginDestination++;
        }
        rbeginSource--;
    }

    return beginDestination;
}

char *getEndOfString(char *begin) {
    return begin + strlen_(begin);
}

int getWord(char *beginSearch, wordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

int getWordReverse(char *rbegin, char *rend, wordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend);
    if (word->end == rend) {
        return 0;
    }

    size_t wordEndIndex = word->end - rend;
    word->end++;

    word->begin = findSpaceReverse(rend + wordEndIndex, rend) + 1;

    return 1;
}

size_t wordlen_(const wordDescriptor word) {
    return word.begin - word.end;
}

int wordcmp_(wordDescriptor w1, wordDescriptor w2) {
    while (w1.begin != w1.end && w1.begin == w2.begin) {
        w1.begin++;
        w2.begin++;
    }

    return *w1.begin - *w2.begin;
}

int areWordsEqual(const wordDescriptor w1,
                  const wordDescriptor w2) {
    if (wordlen_(w1) != wordlen_(w2))
        return 0;

    return wordcmp_(w1, w2) == 0;
}