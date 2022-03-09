#include <stdio.h>
#include <assert.h>

#include "libs/string/string_.h"
#include "libs/string/tasks/removeNonLetters.h"
#include "libs/string/tasks/removeExtraSpaces.h"
#include "libs/string/tasks/digitToStartReverseTransform.h"
#include "libs/string/tasks/digitToEndTransform.h"
#include "libs/string/tasks/replaceDigitsBySpaces.h"
#include "libs/string/tasks/replace.h"
#include "libs/string/tasks/areWordsLexicographicallyOrdered.h"
#include "libs/string/tasks/getPalindromesCount.h"
#include "libs/string/tasks/fillStringWithAlternatingWordsOfTwoOtherStrings.h"
#include "libs/string/tasks/reverseWordOrderInString.h"
#include "libs/string/tasks/getWordBeforeFirstWordWithA.h"
#include "libs/string/tasks/lastWordInFirstStringInSecondString.h"
#include "libs/string/tasks/hasStringIdenticalWords.h"
#include "libs/string/tasks/hasStringPairOfWordsWithIdenticalCharacters.h"
#include "libs/string/tasks/getStringFromWordsOfStringWhichAreNotEqualToLastWord.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

void test_strlen_emptyString() {
    char s[] = "";
    size_t len = strlen_(s);
    size_t expectedLen = 0;
    assert(len == expectedLen);
}

void test_strlen_stringWithOneSymbol() {
    char s[] = "#";
    size_t len = strlen_(s);
    size_t expectedLen = 1;
    assert(len == expectedLen);
}

void test_strlen_filledString() {
    char s[15] = "programming";
    size_t len = strlen_(s);
    size_t expectedLen = 11;
    assert(len == expectedLen);
}

void test_strlen_fullString() {
    char s[] = "hi";
    size_t len = strlen_(s);
    size_t expectedLen = 2;
    assert(len == expectedLen);
}

void test_strlen_stringWithNullSymbol_beforeOtherSymbols() {
    char s[] = "\0 goodbye";
    size_t len = strlen_(s);
    size_t expectedLen = 0;
    assert(len == expectedLen);
}

void test_strlen_stringWithNullSymbol_betweenOtherSymbols() {
    char s[] = "abc\0defg";
    size_t len = strlen_(s);
    size_t expectedLen = 3;
    assert(len == expectedLen);
}

void test_strlen_() {
    test_strlen_emptyString();
    test_strlen_stringWithOneSymbol();
    test_strlen_filledString();
    test_strlen_fullString();
    test_strlen_stringWithNullSymbol_beforeOtherSymbols();
    test_strlen_stringWithNullSymbol_betweenOtherSymbols();
}

void test_find_emptyString() {
    char s[] = "";
    char symbol = '@';
    size_t endIndex = strlen_(s);
    char *pSymbol = find(s, s + endIndex, symbol);
    char expectedSymbol = *s;
    assert(*pSymbol == expectedSymbol);
}

void test_find_stringWithRequestedSymbol() {
    char s[] = "course";
    char symbol = 'u';
    size_t endIndex = strlen_(s);
    char *pSymbol = find(s, s + endIndex, symbol);
    char expectedSymbol = 'u';
    assert(*pSymbol == expectedSymbol);
}

void test_find_stringWithoutRequestedSymbol() {
    char s[] = "shift";
    char symbol = 'a';
    size_t endIndex = strlen_(s);
    char *pSymbol = find(s, s + endIndex, symbol);
    char expectedSymbol = '\0';
    assert(*pSymbol == expectedSymbol);
}

void test_find() {
    test_find_emptyString();
    test_find_stringWithRequestedSymbol();
    test_find_stringWithoutRequestedSymbol();
}

void test_findNonSpace_emptyString() {
    char s[] = "";
    char *pNonSpaceSymbol = findNonSpace(s);
    char expectedSymbol = *s;
    assert(*pNonSpaceSymbol == expectedSymbol);
}

void test_findNonSpace_stringWithRequestedSymbol() {
    char s[] = "  yesterday";
    char *pNonSpaceSymbol = findNonSpace(s);
    char expectedSymbol = 'y';
    assert(*pNonSpaceSymbol == expectedSymbol);
}

void test_findNonSpace_stringWithoutRequestedSymbol() {
    char s[] = "\v  ";
    char *pNonSpaceSymbol = findNonSpace(s);
    char expectedSymbol = '\0';
    assert(*pNonSpaceSymbol == expectedSymbol);
}

void test_findNonSpace() {
    test_findNonSpace_emptyString();
    test_findNonSpace_stringWithRequestedSymbol();
    test_findNonSpace_stringWithoutRequestedSymbol();
}

void test_findSpace_emptyString() {
    char s[] = "";
    char *pNonSpaceSymbol = findSpace(s);
    char expectedSymbol = *s;
    assert(*pNonSpaceSymbol == expectedSymbol);
}

void test_findSpace_stringWithRequestedSymbol() {
    char s[] = "code writing\n";
    char *pNonSpaceSymbol = findSpace(s);
    char expectedSymbol = ' ';
    assert(*pNonSpaceSymbol == expectedSymbol);
}

void test_findSpace_stringWithoutRequestedSymbol() {
    char s[] = "method";
    char *pNonSpaceSymbol = findSpace(s);
    char expectedSymbol = '\0';
    assert(*pNonSpaceSymbol == expectedSymbol);
}

void test_findSpace() {
    test_findSpace_emptyString();
    test_findSpace_stringWithRequestedSymbol();
    test_findSpace_stringWithoutRequestedSymbol();
}

void test_findNonSpaceReverse_emptyString() {
    char s[] = "";
    size_t beginIndex = strlen_(s);
    char *pNonSpaceSymbol = findNonSpaceReverse(s + beginIndex, s);
    char expectedSymbol = *s;
    assert(*pNonSpaceSymbol == expectedSymbol);
}

void test_findNonSpaceReverse_stringWithRequestedSymbol() {
    char s[] = "git  ";
    size_t beginIndex = strlen_(s) - 1;
    char *pNonSpaceSymbol = findNonSpaceReverse(s + beginIndex, s);
    char expectedSymbol = 't';
    assert(*pNonSpaceSymbol == expectedSymbol);
}

void test_findNonSpaceReverse_stringWithoutRequestedSymbol() {
    char s[] = " \t ";
    size_t beginIndex = strlen_(s) - 1;
    char *pNonSpaceSymbol = findNonSpaceReverse(s + beginIndex, s);
    char expectedSymbol = *s;
    assert(*pNonSpaceSymbol == expectedSymbol);
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_emptyString();
    test_findNonSpaceReverse_stringWithRequestedSymbol();
    test_findNonSpaceReverse_stringWithoutRequestedSymbol();
}

void test_findSpaceReverse_emptyString() {
    char s[] = "";
    size_t beginIndex = strlen_(s);
    char *pNonSpaceSymbol = findSpaceReverse(s + beginIndex, s);
    char expectedSymbol = '\0';
    assert(*pNonSpaceSymbol == expectedSymbol);
}

void test_findSpaceReverse_stringWithRequestedSymbol() {
    char s[] = " leaving \t atmo";
    size_t beginIndex = strlen_(s) - 1;
    char *pNonSpaceSymbol = findSpaceReverse(s + beginIndex, s);
    char expectedSymbol = ' ';
    assert(*pNonSpaceSymbol == expectedSymbol);
}

void test_findSpaceReverse_stringWithoutRequestedSymbol() {
    char s[] = "document";
    size_t beginIndex = strlen_(s) - 1;
    char *pNonSpaceSymbol = findSpaceReverse(s + beginIndex, s);
    char expectedSymbol = *s;
    assert(*pNonSpaceSymbol == expectedSymbol);
}

void test_findSpaceReverse() {
    test_findSpaceReverse_emptyString();
    test_findSpaceReverse_stringWithRequestedSymbol();
    test_findSpaceReverse_stringWithoutRequestedSymbol();
}

void test_strcmp_emptyStrings() {
    char s1[] = "";
    char s2[] = "";
    assert(strcmp_(s1, s2) == 0);
}

void test_strcmp_identicalNonEmptyStrings() {
    char s1[] = "refactoring is necessary!";
    char s2[] = "refactoring is necessary!";
    assert(strcmp_(s1, s2) == 0);
}

void test_strcmp_almostIdenticalNonEmptyStrings_lhs_before_rhs() {
    char s1[] = "ins3rt";
    char s2[] = "insert";
    assert(strcmp_(s1, s2) < 0);
}

void test_strcmp_almostIdenticalNonEmptyStrings_lhs_after_rhs() {
    char s1[] = "backup";
    char s2[] = "bAckup";
    assert(strcmp_(s1, s2) > 0);
}

void test_strcmp_definitelyNotIdenticalNonEmptyStrings_lhs_before_rhs() {
    char s1[] = "integration";
    char s2[] = "support";
    assert(strcmp_(s1, s2) < 0);
}

void test_strcmp_definitelyNotIdenticalNonEmptyStrings_lhs_after_rhs() {
    char s1[] = "testing";
    char s2[] = "implementation";
    assert(strcmp_(s1, s2) > 0);
}

void test_strcmp_() {
    test_strcmp_emptyStrings();
    test_strcmp_identicalNonEmptyStrings();
    test_strcmp_almostIdenticalNonEmptyStrings_lhs_before_rhs();
    test_strcmp_almostIdenticalNonEmptyStrings_lhs_after_rhs();
    test_strcmp_definitelyNotIdenticalNonEmptyStrings_lhs_before_rhs();
    test_strcmp_definitelyNotIdenticalNonEmptyStrings_lhs_after_rhs();
}

void test_copy_partialCopying_emptyString() {
    char s[3] = "";
    char copySource[] = "ide";
    size_t endIndex = 2;
    char *freeFragment = copy(copySource,
                              copySource + endIndex,
                              s);
    char expectedS[] = "id";
    char expectedFreeFragment = '\0';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copy_partialCopying_filledString() {
    char s[10] = "hello/";
    char copySource[] = "lab work";
    size_t endIndex = 5;
    char *freeFragment = copy(copySource,
                              copySource + endIndex,
                              s);
    char expectedS[] = "lab w/";
    char expectedFreeFragment = '/';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copy_partialCopying_fullString() {
    char s[] = "how are you????";
    char copySource[] = "testing process";
    size_t endIndex = 11;
    char *freeFragment = copy(copySource,
                              copySource + endIndex,
                              s);
    char expectedS[] = "testing pro????";
    char expectedFreeFragment = '?';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copy_fullCopying_emptyString() {
    char s[10] = "";
    char copySource[] = "laptop";
    size_t endIndex = strlen_(copySource);
    char *freeFragment = copy(copySource,
                              copySource + endIndex,
                              s);
    char expectedS[] = "laptop";
    char expectedFreeFragment = '\0';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copy_fullCopying_filledString() {
    char s[10] = "gitlog";
    char copySource[] = "branch";
    size_t endIndex = strlen_(copySource);
    char *freeFragment = copy(copySource,
                              copySource + endIndex,
                              s);
    char expectedS[] = "branch";
    char expectedFreeFragment = '\0';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copy() {
    test_copy_partialCopying_emptyString();
    test_copy_partialCopying_filledString();
    test_copy_partialCopying_fullString();
    test_copy_fullCopying_emptyString();
    test_copy_fullCopying_filledString();
}

void test_copyIf_stringToCopyWithRequestedSymbols_emptyString() {
    char s[5] = "";
    char copySource[] = "use l4ptop 4 cod1n8";
    size_t endIndex = strlen_(copySource);
    char *freeFragment = copyIf(copySource, copySource + endIndex,
                                s, isDigit);
    char expectedS[] = "4418";
    char expectedFreeFragment = '\0';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copyIf_stringToCopyWithRequestedSymbols_filledString() {
    char s[10] = "exit code";
    char copySource[] = "return 30*";
    size_t endIndex = strlen_(copySource);
    char *freeFragment = copyIf(copySource, copySource + endIndex,
                                s, isDigit);
    char expectedS[] = "30it code";
    char expectedFreeFragment = 'i';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copyIf_stringToCopyWithRequestedSymbols_fullString() {
    char s[] = "add necessary CMakes";
    char copySource[] = "nd4spd/";
    size_t endIndex = strlen_(copySource);
    char *freeFragment = copyIf(copySource, copySource + endIndex,
                                s, isDigit);
    char expectedS[] = "4dd necessary CMakes";
    char expectedFreeFragment = 'd';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copyIf_stringToCopyWithoutRequestedSymbols_emptyString() {
    char s[5] = "";
    char copySource[] = "#surfing the @net\n";
    size_t endIndex = strlen_(copySource);
    char *freeFragment = copyIf(copySource, copySource + endIndex,
                                s, isDigit);
    char expectedS[] = "";
    char expectedFreeFragment = '\0';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copyIf_stringToCopyWithoutRequestedSymbols_filledString() {
    char s[15] = "using of mouse";
    char copySource[] = "\thotkeys ";
    size_t endIndex = strlen_(copySource);
    char *freeFragment = copyIf(copySource, copySource + endIndex,
                                s, isDigit);
    char expectedS[] = "using of mouse";
    char expectedFreeFragment = 'u';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copyIf_stringToCopyWithoutRequestedSymbols_fullString() {
    char s[] = "work implementation";
    char copySource[] = "hours of debug";
    size_t endIndex = strlen_(s);
    char *freeFragment = copyIf(copySource, copySource + endIndex,
                                s, isDigit);
    char expectedS[] = "work implementation";
    char expectedFreeFragment = 'w';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copyIf() {
    test_copyIf_stringToCopyWithRequestedSymbols_emptyString();
    test_copyIf_stringToCopyWithRequestedSymbols_filledString();
    test_copyIf_stringToCopyWithRequestedSymbols_fullString();
    test_copyIf_stringToCopyWithoutRequestedSymbols_emptyString();
    test_copyIf_stringToCopyWithoutRequestedSymbols_filledString();
    test_copyIf_stringToCopyWithoutRequestedSymbols_fullString();
}

void test_copyIfReverse_stringToCopyWithRequestedSymbols_emptyString() {
    char s[5] = "";
    char copySource[] = "#pull requ3st 5^02\t";
    size_t beginIndex = strlen_(copySource);
    char *freeFragment = copyIfReverse(copySource + beginIndex, copySource,
                                       s, isDigit);
    char expectedS[] = "2053";
    char expectedFreeFragment = '\0';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copyIfReverse_stringToCopyWithRequestedSymbols_filledString() {
    char s[10] = "to22 year";
    char copySource[] = "version 0.2";
    size_t beginIndex = strlen_(copySource);
    char *freeFragment = copyIfReverse(copySource + beginIndex, copySource,
                                       s, isDigit);
    char expectedS[] = "2022 year";
    char expectedFreeFragment = '2';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copyIfReverse_stringToCopyWithRequestedSymbols_fullString() {
    char s[] = "in MacBooks";
    char copySource[] = "cp77";
    size_t beginIndex = strlen_(copySource);
    char *freeFragment = copyIfReverse(copySource + beginIndex, copySource,
                                       s, isDigit);
    char expectedS[] = "77 MacBooks";
    char expectedFreeFragment = ' ';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copyIfReverse_stringToCopyWithoutRequestedSymbols_emptyString() {
    char s[5] = "";
    char copySource[] = "repository";
    size_t beginIndex = strlen_(copySource);
    char *freeFragment = copyIfReverse(copySource + beginIndex, copySource,
                                       s, isDigit);
    char expectedS[] = "";
    char expectedFreeFragment = '\0';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copyIfReverse_stringToCopyWithoutRequestedSymbols_filledString() {
    char s[15] = "turbulence";
    char copySource[] = "air flow";
    size_t beginIndex = strlen_(copySource);
    char *freeFragment = copyIfReverse(copySource + beginIndex, copySource,
                                       s, isDigit);
    char expectedS[] = "turbulence";
    char expectedFreeFragment = 't';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copyIfReverse_stringToCopyWithoutRequestedSymbols_fullString() {
    char s[] = "now everyone uses messenger";
    char copySource[] = "nobody picks up the landline";
    size_t beginIndex = strlen_(copySource);
    char *freeFragment = copyIfReverse(copySource + beginIndex, copySource,
                                       s, isDigit);
    char expectedS[] = "now everyone uses messenger";
    char expectedFreeFragment = 'n';
    assert(strcmp_(s, expectedS) == 0 &&
           *freeFragment == expectedFreeFragment);
}

void test_copyIfReverse() {
    test_copyIfReverse_stringToCopyWithRequestedSymbols_emptyString();
    test_copyIfReverse_stringToCopyWithRequestedSymbols_filledString();
    test_copyIfReverse_stringToCopyWithRequestedSymbols_fullString();
    test_copyIfReverse_stringToCopyWithoutRequestedSymbols_emptyString();
    test_copyIfReverse_stringToCopyWithoutRequestedSymbols_filledString();
    test_copyIfReverse_stringToCopyWithoutRequestedSymbols_fullString();
}

void test_getEndOfString_emptyString() {
    char s[] = "";
    char *endS = getEndOfString(s);
    assert(s == endS);
}

void test_getEndOfString_stringWithOneSymbol() {
    char s[] = "%";
    char *endS = getEndOfString(s);
    assert(endS - s == strlen_(s));
}

void test_getEndOfString_filledString() {
    char s[10] = "desert";
    char *endS = getEndOfString(s);
    assert(endS - s == strlen_(s));
}

void test_getEndOfString_fullString() {
    char s[10] = "desert";
    char *endS = getEndOfString(s);
    assert(endS - s == strlen_(s));
}

void test_getEndOfString_stringWithNullSymbol_beforeOtherSymbols() {
    char s[] = "\0 translation";
    char *endS = getEndOfString(s);
    assert(endS == s);
}

void test_getEndOfString_stringWithNullSymbol_betweenOtherSymbols() {
    char s[] = "str\0uct";
    char *endS = getEndOfString(s);
    assert(endS - s == strlen_(s));
}

void test_getEndOfString() {
    test_getEndOfString_emptyString();
    test_getEndOfString_stringWithOneSymbol();
    test_getEndOfString_filledString();
    test_getEndOfString_fullString();
    test_getEndOfString_stringWithNullSymbol_beforeOtherSymbols();
    test_getEndOfString_stringWithNullSymbol_betweenOtherSymbols();
}

void test_getWord_emptyString() {
    char s[] = "";
    wordDescriptor word;
    int isWordInString = getWord(s, &word);
    assert(!isWordInString);
}

void test_getWord_filledString_withoutWords() {
    char s[10] = " \t   \n";
    wordDescriptor word;
    int isWordInString = getWord(s, &word);
    assert(!isWordInString);
}

void test_getWord_filledString_withWords() {
    char s[30] = "   cmake build debug";
    wordDescriptor word;
    int isWordInString = getWord(s, &word);
    char expectedW[] = "cmake ";
    wordDescriptor expectedWord = {expectedW, expectedW + strlen_(expectedW) - 1};
    assert(isWordInString && areWordsEqual(word, expectedWord));
}

void test_getWord_fullString_withoutWords() {
    char s[] = " \n    \v";
    wordDescriptor word;
    int isWordInString = getWord(s, &word);
    assert(!isWordInString);
}

void test_getWord_fullString_withWords() {
    char s[] = "\t backspace key";
    wordDescriptor word;
    int isWordInString = getWord(s, &word);
    char expectedW[] = "backspace ";
    wordDescriptor expectedWord = {expectedW, expectedW + strlen_(expectedW) - 1};
    assert(isWordInString && areWordsEqual(word, expectedWord));
}

void test_getWord() {
    test_getWord_emptyString();
    test_getWord_filledString_withoutWords();
    test_getWord_filledString_withWords();
    test_getWord_fullString_withoutWords();
    test_getWord_fullString_withWords();
}

void test_getWordReverse_emptyString() {
    char s[] = "";
    wordDescriptor word;
    char *endStr = getEndOfString(s);
    int isWordInString = getWordReverse(endStr, s, &word);
    assert(!isWordInString);
}

void test_getWordReverse_filledString_withoutWords() {
    char s[10] = " \t   \n";
    wordDescriptor word;
    char *endStr = getEndOfString(s);
    int isWordInString = getWordReverse(endStr, s, &word);
    assert(!isWordInString);
}

void test_getWordReverse_filledString_withWords() {
    char s[30] = "   cmake build debug   \t";
    wordDescriptor word;
    char *endStr = getEndOfString(s);
    int isWordInString = getWordReverse(endStr, s, &word);
    char expectedW[] = "debug ";
    wordDescriptor expectedWord = {expectedW, expectedW + strlen_(expectedW) - 1};
    assert(isWordInString && areWordsEqual(word, expectedWord));
}

void test_getWordReverse_fullString_withoutWords() {
    char s[] = " \n    \v";
    wordDescriptor word;
    char *endStr = getEndOfString(s);
    int isWordInString = getWordReverse(endStr, s, &word);
    assert(!isWordInString);
}

void test_getWordReverse_fullString_withWords() {
    char s[] = "\t backspace key ";
    wordDescriptor word;
    char *endStr = getEndOfString(s);
    int isWordInString = getWordReverse(endStr, s, &word);
    char expectedW[] = "key ";
    wordDescriptor expectedWord = {expectedW, expectedW + strlen_(expectedW) - 1};
    assert(isWordInString && areWordsEqual(word, expectedWord));
}

void test_getWordReverse() {
    test_getWordReverse_emptyString();
    test_getWordReverse_filledString_withWords();
    test_getWordReverse_filledString_withoutWords();
    test_getWordReverse_fullString_withWords();
    test_getWordReverse_fullString_withoutWords();
}

void test_getBagOfWords_emptyString() {
    char s[] = "";
    bagOfWords b;
    getBagOfWords(&b, s);
    bagOfWords expectedB = {{}, 0};
    assert(areEqualBagsOfWords(b, expectedB));
}

void test_getBagOfWords_filledString_withoutWords() {
    char s[10] = "  \t   \n";
    bagOfWords b;
    getBagOfWords(&b, s);
    bagOfWords expectedB = {{}, 0};
    assert(areEqualBagsOfWords(b, expectedB));
}

void test_getBagOfWords_filledString_withWords() {
    char s[20] = " windows 11 update";
    bagOfWords b;
    getBagOfWords(&b, s);
    char w1[] = "windows";
    wordDescriptor word1;
    getWord(w1, &word1);
    char w2[] = "11";
    wordDescriptor word2;
    getWord(w2, &word2);
    char w3[] = "update";
    wordDescriptor word3;
    getWord(w3, &word3);
    bagOfWords expectedB = {{word1, word2, word3}, 3};
    assert(areEqualBagsOfWords(b, expectedB));
}

void test_getBagOfWords_fullString_withoutWords() {
    char s[] = "\v    ";
    bagOfWords b;
    getBagOfWords(&b, s);
    bagOfWords expectedB = {{}, 0};
    assert(areEqualBagsOfWords(b, expectedB));
}

void test_getBagOfWords_fullString_withWords() {
    char s[] = " do you speak english ?";
    bagOfWords b;
    getBagOfWords(&b, s);
    char w1[] = "do";
    wordDescriptor word1;
    getWord(w1, &word1);
    char w2[] = "you";
    wordDescriptor word2;
    getWord(w2, &word2);
    char w3[] = "speak";
    wordDescriptor word3;
    getWord(w3, &word3);
    char w4[] = "english";
    wordDescriptor word4;
    getWord(w4, &word4);
    char w5[] = "?";
    wordDescriptor word5;
    getWord(w5, &word5);
    bagOfWords expectedB = {{word1, word2, word3, word4, word5}, 5};
    assert(areEqualBagsOfWords(b, expectedB));
}

void test_getBagOfWords() {
    test_getBagOfWords_emptyString();
    test_getBagOfWords_filledString_withoutWords();
    test_getBagOfWords_filledString_withWords();
    test_getBagOfWords_fullString_withoutWords();
    test_getBagOfWords_fullString_withWords();
}

void test_getWordByDivider_emptyString() {
    char s[] = "";
    wordDescriptor word;
    int isWordInString = getWordByDivider(s, &word, ',');
    assert(!isWordInString);
}

void test_getWordByDivider_filledString_withoutWords() {
    char s[15] = "  \n \t";
    wordDescriptor word;
    int isWordInString = getWordByDivider(s, &word, ',');
    assert(!isWordInString);
}

void test_getWordByDivider_filledString_oneWord() {
    char s[15] = " yellow    ";
    wordDescriptor word;
    int isWordInString = getWordByDivider(s, &word, ',');
    char expectedW[] = "yellow ";
    wordDescriptor expectedWord = {expectedW, expectedW + strlen_(expectedW) - 1};
    assert(isWordInString && areWordsEqual(word, expectedWord));
}

void test_getWordByDivider_filledString_withNecessaryDivider() {
    char s[30] = " new,lamborghini,countach";
    wordDescriptor word;
    int isWordInString = getWordByDivider(s, &word, ',');
    char expectedW[] = "new,";
    wordDescriptor expectedWord = {expectedW, expectedW + strlen_(expectedW) - 1};
    assert(isWordInString && areWordsEqual(word, expectedWord));
}

void test_getWordByDivider_filledString_withoutNecessaryDivider() {
    char s[15] = " galaxy s 22";
    wordDescriptor word;
    int isWordInString = getWordByDivider(s, &word, ',');
    assert(!isWordInString);
}

void test_getWordByDivider_fullString_withoutWords() {
    char s[] = " \t   ";
    wordDescriptor word;
    int isWordInString = getWordByDivider(s, &word, ',');
    assert(!isWordInString);
}

void test_getWordByDivider_fullString_oneWord() {
    char s[] = " red   ";
    wordDescriptor word;
    int isWordInString = getWordByDivider(s, &word, ',');
    char expectedW[] = "red ";
    wordDescriptor expectedWord = {expectedW, expectedW + strlen_(expectedW) - 1};
    assert(isWordInString && areWordsEqual(word, expectedWord));
}

void test_getWordByDivider_fullString_withNecessaryDivider() {
    char s[] = " just,do,it   ";
    wordDescriptor word;
    int isWordInString = getWordByDivider(s, &word, ',');
    char expectedW[] = "just,";
    wordDescriptor expectedWord = {expectedW, expectedW + strlen_(expectedW) - 1};
    assert(isWordInString && areWordsEqual(word, expectedWord));
}

void test_getWordByDivider_fullString_withoutNecessaryDivider() {
    char s[] = " i listen to music every day";
    wordDescriptor word;
    int isWordInString = getWordByDivider(s, &word, ',');
    assert(!isWordInString);
}

void test_getWordByDivider() {
    test_getWordByDivider_emptyString();
    test_getWordByDivider_filledString_withoutWords();
    test_getWordByDivider_filledString_oneWord();
    test_getWordByDivider_filledString_withNecessaryDivider();
    test_getWordByDivider_filledString_withoutNecessaryDivider();
    test_getWordByDivider_fullString_withoutWords();
    test_getWordByDivider_fullString_oneWord();
    test_getWordByDivider_fullString_withNecessaryDivider();
    test_getWordByDivider_fullString_withoutNecessaryDivider();
}

void test_string_lib() {
    test_strlen_();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp_();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
    test_getEndOfString();
    test_getWord();
    test_getWordReverse();
    test_getBagOfWords();
    test_getWordByDivider();
}

void assertString(const char *expected, const char *got,
                  const char *fileName, const char *funcName,
                  const int line) {
    if (strcmp_(expected, got) != 0) {
        fprintf(stderr, "file %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "expected: \"%s\"\n", expected);
        fprintf(stderr, "got: \"%s\"\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void test_removeNonLetters_emptyString() {
    char s[] = "";
    char expectedS[] = "";
    removeNonLetters(s);
    ASSERT_STRING(expectedS, s);
}

void test_removeNonLetters_filledString_withSpaceSymbols() {
    char s[10] = "a B  1\t23";
    char expectedS[] = "aB123";
    removeNonLetters(s);
    ASSERT_STRING(expectedS, s);
}

void test_removeNonLetters_filledString_withoutSpaceSymbols() {
    char s[10] = "check";
    removeNonLetters(s);
    char expectedS[] = "check";
    ASSERT_STRING(expectedS, s);
}

void test_removeNonLetters_fullString_withSpaceSymbols() {
    char s[] = "cut\t  THE  \vrope";
    removeNonLetters(s);
    char expectedS[] = "cutTHErope";
    ASSERT_STRING(expectedS, s);
}

void test_removeNonLetters_fullString_withoutSpaceSymbols() {
    char s[] = "okloqi";
    removeNonLetters(s);
    char expectedS[] = "okloqi";
    ASSERT_STRING(expectedS, s);
}

void test_removeNonLetters() {
    test_removeNonLetters_emptyString();
    test_removeNonLetters_filledString_withSpaceSymbols();
    test_removeNonLetters_filledString_withoutSpaceSymbols();
    test_removeNonLetters_fullString_withSpaceSymbols();
    test_removeNonLetters_fullString_withoutSpaceSymbols();
}

void test_removeExtraSpaces_emptyString() {
    char s[] = "";
    removeExtraSpaces(s);
    char expectedS[] = "";
    ASSERT_STRING(expectedS, s);
}

void test_removeExtraSpaces_filledString_withoutWords_withExtraSpaces() {
    char s[] = "     ";
    removeExtraSpaces(s);
    char expectedS[] = "     ";
    ASSERT_STRING(expectedS, s);
}

void test_removeExtraSpaces_filledString_withoutWords_withoutExtraSpaces() {
    char s[] = " ";
    removeExtraSpaces(s);
    char expectedS[] = " ";
    ASSERT_STRING(expectedS, s);
}

void test_removeExtraSpaces_filledString_withWords_withExtraAndBasicSpaces() {
    char s[35] = "  dawn  \t  FM after  hours 2   ";
    removeExtraSpaces(s);
    char expectedS[] = "  dawn FM after hours 2   ";
    ASSERT_STRING(expectedS, s);
}

void test_removeExtraSpaces_filledString_withWords_withoutSpaces() {
    char s[20] = "windows11";
    removeExtraSpaces(s);
    char expectedS[] = "windows11";
    ASSERT_STRING(expectedS, s);
}

void test_removeExtraSpaces_fullString_withoutWords_withExtraSpaces() {
    char s[] = "  \t horizons   / east  ";
    removeExtraSpaces(s);
    char expectedS[] = "  \t horizons / east  ";
    ASSERT_STRING(expectedS, s);
}

void test_removeExtraSpaces_fullString_withWords_withExtraAndBasicSpaces() {
    char s[] = "flashes moments \t  memories";
    removeExtraSpaces(s);
    char expectedS[] = "flashes moments memories";
    ASSERT_STRING(expectedS, s);
}

void test_removeExtraSpaces_fullString_withWords_withoutSpaces() {
    char s[] = "voyager1";
    removeExtraSpaces(s);
    char expectedS[] = "voyager1";
    ASSERT_STRING(expectedS, s);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_emptyString();
    test_removeExtraSpaces_filledString_withoutWords_withExtraSpaces();
    test_removeExtraSpaces_filledString_withoutWords_withoutExtraSpaces();
    test_removeExtraSpaces_filledString_withWords_withExtraAndBasicSpaces();
    test_removeExtraSpaces_filledString_withWords_withoutSpaces();
    test_removeExtraSpaces_fullString_withoutWords_withExtraSpaces();
    test_removeExtraSpaces_fullString_withWords_withExtraAndBasicSpaces();
    test_removeExtraSpaces_fullString_withWords_withoutSpaces();
}

void test_digitToStartReverse_withDigits_withLetters() {
    char w[] = "0wallpap3r321";
    wordDescriptor word = {};
    int wordFlag = getWord(w, &word);
    digitToStartReverse(word);
    char expectedW[] = "12330wallpapr";
    ASSERT_STRING(expectedW, w);
}

void test_digitToStartReverse_withoutDigits_withLetters() {
    char w[] = "capital";
    wordDescriptor word = {};
    int wordFlag = getWord(w, &word);
    digitToStartReverse(word);
    char expectedW[] = "capital";
    ASSERT_STRING(expectedW, w);
}

void test_digitToStartReverse_withDigits_withoutLetters() {
    char w[] = "34502";
    wordDescriptor word = {};
    int wordFlag = getWord(w, &word);
    digitToStartReverse(word);
    char expectedW[] = "20543";
    ASSERT_STRING(expectedW, w);
}

void test_digitToStartReverse() {
    test_digitToStartReverse_withDigits_withLetters();
    test_digitToStartReverse_withoutDigits_withLetters();
    test_digitToStartReverse_withDigits_withoutLetters();
}

void test_digitToStartReverseTransform_emptyString() {
    char s[] = "";
    digitToStartReverseTransform(s);
    char expectedS[] = "";
    ASSERT_STRING(expectedS, s);
}

void test_digitToStartReverseTransform_filledString() {
    char s[25] = "  hi321 b1g update  \t";
    digitToStartReverseTransform(s);
    char expectedS[] = "  123hi 1bg update  \t";
    ASSERT_STRING(expectedS, s);
}

void test_digitToStartReverseTransform_fullString() {
    char s[] = " Moscow 1s th3 c4pital of Russia\t";
    digitToStartReverseTransform(s);
    char expectedS[] = " Moscow 1s 3th 4cpital of Russia\t";
    ASSERT_STRING(expectedS, s);
}

void test_digitToStartReverseTransform() {
    test_digitToStartReverseTransform_emptyString();
    test_digitToStartReverseTransform_filledString();
    test_digitToStartReverseTransform_fullString();
}

void test_digitToEnd_withDigits_withLetters() {
    char w[] = " 0s4msungS22 ";
    wordDescriptor word = {};
    int wordFlag = getWord(w, &word);
    digitToEnd(word);
    char expectedW[] = " smsungS0422 ";
    ASSERT_STRING(expectedW, w);
}

void test_digitToEnd_withoutDigits_withLetters() {
    char w[] = "odyssey";
    wordDescriptor word = {};
    int wordFlag = getWord(w, &word);
    digitToEnd(word);
    char expectedW[] = "odyssey";
    ASSERT_STRING(expectedW, w);
}

void test_digitToEnd_withDigits_withoutLetters() {
    char w[] = "3000";
    wordDescriptor word = {};
    int wordFlag = getWord(w, &word);
    digitToEnd(word);
    char expectedW[] = "3000";
    ASSERT_STRING(expectedW, w);
}

void test_digitToEnd() {
    test_digitToEnd_withDigits_withLetters();
    test_digitToEnd_withoutDigits_withLetters();
    test_digitToEnd_withDigits_withoutLetters();
}

void test_digitToEndTransform_emptyString() {
    char s[] = "";
    digitToEndTransform(s);
    char expectedS[] = "";
    ASSERT_STRING(expectedS, s);
}

void test_digitToEndTransform_filledString() {
    char s[] = " wa1ts wait8 0ldma  ";
    digitToEndTransform(s);
    char expectedS[] = " wats1 wait8 ldma0  ";
    ASSERT_STRING(expectedS, s);
}

void test_digitToEndTransform_fullString() {
    char s[] = "g1t remote c010mmit";
    digitToEndTransform(s);
    char expectedS[] = "gt1 remote cmmit010";
    ASSERT_STRING(expectedS, s);
}

void test_digitToEndTransform() {
    test_digitToEndTransform_emptyString();
    test_digitToEndTransform_filledString();
    test_digitToEndTransform_fullString();
}

void test_replaceDigitsBySpaces_emptyString() {
    char s[MAX_STRING_SIZE + 1] = "";
    replaceDigitsBySpaces(s);
    char expectedS[] = "";
    ASSERT_STRING(expectedS, s);
}

void test_replaceDigitsBySpaces_filledString_withDigits() {
    char s[MAX_STRING_SIZE + 1] = "0I4,3robot";
    replaceDigitsBySpaces(s);
    char expectedS[] = "I    ,   robot";
    ASSERT_STRING(expectedS, s);
}

void test_replaceDigitsBySpaces_filledString_withoutDigits() {
    char s[MAX_STRING_SIZE + 1] = "team";
    replaceDigitsBySpaces(s);
    char expectedS[] = "team";
    ASSERT_STRING(expectedS, s);
}

void test_replaceDigitsBySpaces() {
    test_replaceDigitsBySpaces_emptyString();
    test_replaceDigitsBySpaces_filledString_withDigits();
    test_replaceDigitsBySpaces_filledString_withoutDigits();
}

void test_replace_filledString_equalLensOfW1AndW2() {
    char s[MAX_STRING_SIZE + 1] = "Lens are used in glasses. Lens are used in cameras";
    char w1[] = "used";
    char w2[] = "auto";
    replace(s, w1, w2);
    char expectedS[] = "Lens are auto in glasses. Lens are auto in cameras";
    ASSERT_STRING(expectedS, s);
}

void test_replace_filledString_w1LenMoreThanW2Len() {
    char s[MAX_STRING_SIZE + 1] = "I bought notebook last year. I use notebook for labs";
    char w1[] = "notebook";
    char w2[] = "laptop";
    replace(s, w1, w2);
    char expectedS[] = "I bought laptop last year. I use laptop for labs";
    ASSERT_STRING(expectedS, s);
}

void test_replace_filledString_w1LenLessThanW2Len() {
    char s[MAX_STRING_SIZE + 1] = "We work in autoCAD app during drafting lesson. autoCAD is powerful tool.";
    char w1[] = "autoCAD";
    char w2[] = "autodesk";
    replace(s, w1, w2);
    char expectedS[] = "We work in autodesk app during drafting lesson. autodesk is powerful tool.";
    ASSERT_STRING(expectedS, s);
}

void test_replace() {
    test_replace_filledString_equalLensOfW1AndW2();
    test_replace_filledString_w1LenMoreThanW2Len();
    test_replace_filledString_w1LenLessThanW2Len();
}

void test_areWordsLexicographicallyOrdered_emptyString() {
    char s[] = "";
    assert(areWordsLexicographicallyOrdered(s));
}

void test_areWordsLexicographicallyOrdered_filledString_withoutWords() {
    char s[] = " \t   \v";
    assert(areWordsLexicographicallyOrdered(s));
}

void test_areWordsLexicographicallyOrdered_filledString_wordsAreOrdered() {
    char s[30] = " app blog tablet ";
    assert(areWordsLexicographicallyOrdered(s));
}

void test_areWordsLexicographicallyOrdered_filledString_wordsAreNotOrdered() {
    char s[30] = "monument valley game";
    assert(!areWordsLexicographicallyOrdered(s));
}

void test_areWordsLexicographicallyOrdered_fulltring_withoutWords() {
    char s[] = "     ";
    assert(areWordsLexicographicallyOrdered(s));
}

void test_areWordsLexicographicallyOrdered_fullString_wordsAreOrdered() {
    char s[] = " new nvidia rtx videocard";
    assert(areWordsLexicographicallyOrdered(s));
}

void test_areWordsLexicographicallyOrdered_fullString_wordsAreNotOrdered() {
    char s[] = " break poco phone ";
    int flag = areWordsLexicographicallyOrdered(s);
    assert(!areWordsLexicographicallyOrdered(s));
}

void test_areWordsLexicographicallyOrdered() {
    test_areWordsLexicographicallyOrdered_emptyString();
    test_areWordsLexicographicallyOrdered_filledString_withoutWords();
    test_areWordsLexicographicallyOrdered_filledString_wordsAreOrdered();
    test_areWordsLexicographicallyOrdered_filledString_wordsAreNotOrdered();
    test_areWordsLexicographicallyOrdered_fullString_wordsAreNotOrdered();
    test_areWordsLexicographicallyOrdered_fulltring_withoutWords();
    test_areWordsLexicographicallyOrdered_fullString_wordsAreOrdered();
    test_areWordsLexicographicallyOrdered_fullString_wordsAreNotOrdered();
}

void test_getPalindromesCount_emptyString() {
    char s[] = "";
    int palindromesCount = getPalindromesCount(s);
    int expectedPalindromesCount = 0;
    assert(palindromesCount == expectedPalindromesCount);
}

void test_getPalindromesCount_filledString() {
    char s[30] = "    tenet,rotor,stat8,25  ";
    int palindromesCount = getPalindromesCount(s);
    int expectedPalindromesCount = 2;
    assert(palindromesCount == expectedPalindromesCount);
}

void test_getPalindromesCount_fullString() {
    char s[] = " racecar,radar,pop,ref3r   ";
    int palindromesCount = getPalindromesCount(s);
    int expectedPalindromesCount = 3;
    assert(palindromesCount == expectedPalindromesCount);
}

void test_getPalindromesCount() {
    test_getPalindromesCount_emptyString();
    test_getPalindromesCount_filledString();
    test_getPalindromesCount_fullString();
}

void test_fillStringWithAlternatingWordsOfTwoOtherStrings_twoEmptyStrings() {
    char s1[] = "";
    char s2[] = "";
    char res[MAX_STRING_SIZE + 1] = "";
    fillStringWithAlternatingWordsOfTwoOtherStrings(res, s1, s2);
    char expectedRes[] = "";
    ASSERT_STRING(expectedRes, res);
}

void test_fillStringWithAlternatingWordsOfTwoOtherStrings_emptyAndNonEmptyString() {
    char s1[] = "";
    char s2[] = " make contribution";
    char res[MAX_STRING_SIZE + 1] = "";
    fillStringWithAlternatingWordsOfTwoOtherStrings(res, s1, s2);
    char expectedRes[] = "make contribution";
    ASSERT_STRING(expectedRes, res);
}

void test_fillStringWithAlternatingWordsOfTwoOtherStrings_twoNonEmptyString_equalWordsCounts() {
    char s1[] = "  oneplus 10 pro  ";
    char s2[] = " iphone 13 mini";
    char res[MAX_STRING_SIZE + 1] = "";
    fillStringWithAlternatingWordsOfTwoOtherStrings(res, s1, s2);
    char expectedRes[] = "oneplus iphone 10 13 pro mini";
    ASSERT_STRING(expectedRes, res);
}

void test_fillStringWithAlternatingWordsOfTwoOtherStrings_twoNonEmptyString_s1LenMoreThanS2Len() {
    char s1[] = " super mario bros";
    char s2[] = " external libraries";
    char res[MAX_STRING_SIZE + 1] = "";
    fillStringWithAlternatingWordsOfTwoOtherStrings(res, s1, s2);
    char expectedRes[] = "super external mario libraries bros";
    ASSERT_STRING(expectedRes, res);
}

void test_fillStringWithAlternatingWordsOfTwoOtherStrings_twoNonEmptyString_s1LenLessThanS2Len() {
    char s1[] = " quok imago";
    char s2[] = " archy brown untitled 250";
    char res[MAX_STRING_SIZE + 1] = "";
    fillStringWithAlternatingWordsOfTwoOtherStrings(res, s1, s2);
    char expectedRes[] = "quok archy imago brown untitled 250";
    ASSERT_STRING(expectedRes, res);
}

void test_fillStringWithAlternatingWordsOfTwoOtherStrings() {
    test_fillStringWithAlternatingWordsOfTwoOtherStrings_twoEmptyStrings();
    test_fillStringWithAlternatingWordsOfTwoOtherStrings_emptyAndNonEmptyString();
    test_fillStringWithAlternatingWordsOfTwoOtherStrings_twoNonEmptyString_equalWordsCounts();
    test_fillStringWithAlternatingWordsOfTwoOtherStrings_twoNonEmptyString_s1LenMoreThanS2Len();
    test_fillStringWithAlternatingWordsOfTwoOtherStrings_twoNonEmptyString_s1LenLessThanS2Len();
}

void test_reverseWordOrderInString_emptyString() {
    char s[] = "";
    reverseWordOrderInString(s);
    char expectedS[] = "";
    ASSERT_STRING(expectedS, s);
}

void test_reverseWordOrderInString_filledString_oneWordInString() {
    char s[10] = "  jedi";
    reverseWordOrderInString(s);
    char expectedS[] = "jedi";
    ASSERT_STRING(expectedS, s);
}

void test_reverseWordOrderInString_filledString() {
    char s[40] = "may the force come with you";
    reverseWordOrderInString(s);
    char expectedS[] = "you with come force the may";
    ASSERT_STRING(expectedS, s);
}

void test_reverseWordOrderInString_fullString_oneWordInString() {
    char s[] = "Yoda  ";
    reverseWordOrderInString(s);
    char expectedS[] = "Yoda";
    ASSERT_STRING(expectedS, s);
}

void test_reverseWordOrderInString_fullString() {
    char s[] = "do or do not there is no try";
    reverseWordOrderInString(s);
    char expectedS[] = "try no is there not do or do";
    ASSERT_STRING(expectedS, s);
}

void test_reverseWordOrderInString() {
    test_reverseWordOrderInString_emptyString();
    test_reverseWordOrderInString_filledString_oneWordInString();
    test_reverseWordOrderInString_filledString();
    test_reverseWordOrderInString_fullString_oneWordInString();
    test_reverseWordOrderInString_fullString();
}

void testAll_getWordBeforeFirstWordWithA() {
    char *beginWord, *endWord;

    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1,
                                       &beginWord,
                                       &endWord) == EMPTY_STRING);

    char s2[] = " ABC";
    assert(getWordBeforeFirstWordWithA(s2,
                                       &beginWord,
                                       &endWord) == FIRST_WORD_WITH_A);


    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3,
                                       &beginWord,
                                       &endWord) == WORD_FOUND);

    char got[MAX_WORD_SIZE];

    copy(beginWord, endWord, got);

    got[endWord - beginWord] = NULL_SYMBOL;

    ASSERT_STRING("BC", got);

    char s4[] = "B Q WE YR OW Isis ";
    assert(getWordBeforeFirstWordWithA(s4,
                                       &beginWord,
                                       &endWord) == NOT_FOUND_A_WORD_WITH_A);
}

void test_lastWordInFirstStringInSecondString_twoEmptyStrings() {
    char s1[] = "";
    char s2[] = "";
    wordDescriptor w = lastWordInFirstStringInSecondString(s1, s2);
    char word[MAX_WORD_SIZE] = "";
    wordDescriptorToString(w, word);
    char expectedWord[] = "";
    ASSERT_STRING(expectedWord, word);
}

void test_lastWordInFirstStringInSecondString_emptyS1AndNonEmptyS2() {
    char s1[] = "";
    char s2[] = " airports decadance";
    wordDescriptor w = lastWordInFirstStringInSecondString(s1, s2);
    char word[MAX_WORD_SIZE] = "";
    wordDescriptorToString(w, word);
    char expectedWord[] = "";
    ASSERT_STRING(expectedWord, word);
}

void test_lastWordInFirstStringInSecondString_nonEmptyS1AndEmptyS1() {
    char s1[] = " kino 2 yasumi";
    char s2[] = " ";
    wordDescriptor w = lastWordInFirstStringInSecondString(s1, s2);
    char word[MAX_WORD_SIZE] = "";
    wordDescriptorToString(w, word);
    char expectedWord[] = "";
    ASSERT_STRING(expectedWord, word);
}

void test_lastWordInFirstStringInSecondString_twoNonEmptyStrings_1() {
    char s1[] = "la moscow paris";
    char s2[] = "moscow la kaliningrad";
    wordDescriptor w = lastWordInFirstStringInSecondString(s1, s2);
    char word[MAX_WORD_SIZE] = "";
    wordDescriptorToString(w, word);
    char expectedWord[] = "moscow";
    ASSERT_STRING(expectedWord, word);
}

void test_lastWordInFirstStringInSecondString_twoNonEmptyStrings_2() {
    char s1[] = " sony mdr zx 770 bn";
    char s2[] = " apple mdr airpods 3 zx";
    wordDescriptor w = lastWordInFirstStringInSecondString(s1, s2);
    char word[MAX_WORD_SIZE] = "";
    wordDescriptorToString(w, word);
    char expectedWord[] = "zx";
    ASSERT_STRING(expectedWord, word);
}

void test_lastWordInFirstStringInSecondString_twoNonEmptyStrings_3() {
    char s1[] = " leica hasselblad nikon sony";
    char s2[] = " nikon sharp hasselblad";
    wordDescriptor w = lastWordInFirstStringInSecondString(s1, s2);
    char word[MAX_WORD_SIZE] = "";
    wordDescriptorToString(w, word);
    char expectedWord[] = "nikon";
    ASSERT_STRING(expectedWord, word);
}

void test_lastWordInFirstStringInSecondString() {
    test_lastWordInFirstStringInSecondString_twoEmptyStrings();
    test_lastWordInFirstStringInSecondString_emptyS1AndNonEmptyS2();
    test_lastWordInFirstStringInSecondString_nonEmptyS1AndEmptyS1();
    test_lastWordInFirstStringInSecondString_twoNonEmptyStrings_1();
    test_lastWordInFirstStringInSecondString_twoNonEmptyStrings_2();
    test_lastWordInFirstStringInSecondString_twoNonEmptyStrings_3();
}

void test_hasStringIdenticalWords_emptyString() {
    char s[] = "";
    int areIdenticalWordsInString = hasStringIdenticalWords(s);
    assert(!areIdenticalWordsInString);
}

void test_hasStringIdenticalWords_filledString_oneWord() {
    char s[10] = "display";
    int areIdenticalWordsInString = hasStringIdenticalWords(s);
    assert(!areIdenticalWordsInString);
}

void test_hasStringIdenticalWords_filledString_withIdenticalWords() {
    char s[50] = "pen pineapple pen apple pen";
    int areIdenticalWordsInString = hasStringIdenticalWords(s);
    assert(areIdenticalWordsInString);
}

void test_hasStringIdenticalWords_filledString_withoutIdenticalWords() {
    char s[50] = "London is the capital of Great Britain.";
    int areIdenticalWordsInString = hasStringIdenticalWords(s);
    assert(!areIdenticalWordsInString);
}

void test_hasStringIdenticalWords_fullString_oneWord() {
    char s[] = " MacStudio   ";
    int areIdenticalWordsInString = hasStringIdenticalWords(s);
    assert(!areIdenticalWordsInString);
}

void test_hasStringIdenticalWords_fullString_withIdenticalWords() {
    char s[] = " write code, test, commit, write code again";
    int areIdenticalWordsInString = hasStringIdenticalWords(s);
    assert(areIdenticalWordsInString);
}

void test_hasStringIdenticalWords_fullString_withoutIdenticalWords() {
    char s[] = "London is the capital of Great Britain.";
    int areIdenticalWordsInString = hasStringIdenticalWords(s);
    assert(!areIdenticalWordsInString);
}

void test_hasStringIdenticalWords() {
    test_hasStringIdenticalWords_emptyString();
    test_hasStringIdenticalWords_filledString_oneWord();
    test_hasStringIdenticalWords_filledString_withIdenticalWords();
    test_hasStringIdenticalWords_filledString_withoutIdenticalWords();
    test_hasStringIdenticalWords_fullString_oneWord();
    test_hasStringIdenticalWords_fullString_withIdenticalWords();
    test_hasStringIdenticalWords_fullString_withoutIdenticalWords();
}

void test_hasStringPairOfWordsWithIdenticalCharacters_emptyString() {
    char s[] = "";
    int isPairOfWordsWithIdenticalCharactersInString = hasStringPairOfWordsWithIdenticalCharacters(s);
    assert(!isPairOfWordsWithIdenticalCharactersInString);
}

void test_hasStringPairOfWordsWithIdenticalCharacters_filledString_oneWord() {
    char s[5] = "hp";
    int isPairOfWordsWithIdenticalCharactersInString = hasStringPairOfWordsWithIdenticalCharacters(s);
    assert(!isPairOfWordsWithIdenticalCharactersInString);
}

void test_hasStringPairOfWordsWithIdenticalCharacters_filledString_withRequestedWords() {
    char s[25] = "laf animated series alf";
    int isPairOfWordsWithIdenticalCharactersInString = hasStringPairOfWordsWithIdenticalCharacters(s);
    assert(isPairOfWordsWithIdenticalCharactersInString);
}

void test_hasStringPairOfWordsWithIdenticalCharacters_filledString_withoutRequestedWords() {
    char s[25] = "sony yns0 xperia 1 IV";
    int isPairOfWordsWithIdenticalCharactersInString = hasStringPairOfWordsWithIdenticalCharacters(s);
    assert(!isPairOfWordsWithIdenticalCharactersInString);
}

void test_hasStringPairOfWordsWithIdenticalCharacters_fullString_oneWord() {
    char s[] = " dell";
    int isPairOfWordsWithIdenticalCharactersInString = hasStringPairOfWordsWithIdenticalCharacters(s);
    assert(!isPairOfWordsWithIdenticalCharactersInString);
}

void test_hasStringPairOfWordsWithIdenticalCharacters_fullString_withRequestedWords() {
    char s[] = "write music in the studio . studio process";
    int isPairOfWordsWithIdenticalCharactersInString = hasStringPairOfWordsWithIdenticalCharacters(s);
    assert(isPairOfWordsWithIdenticalCharactersInString);
}

void test_hasStringPairOfWordsWithIdenticalCharacters_fullString_withoutRequestedWords() {
    char s[] = " create of program";
    int isPairOfWordsWithIdenticalCharactersInString = hasStringPairOfWordsWithIdenticalCharacters(s);
    assert(!isPairOfWordsWithIdenticalCharactersInString);
}

void test_hasStringPairOfWordsWithIdenticalCharacters() {
    test_hasStringPairOfWordsWithIdenticalCharacters_emptyString();
    test_hasStringPairOfWordsWithIdenticalCharacters_filledString_oneWord();
    test_hasStringPairOfWordsWithIdenticalCharacters_filledString_withRequestedWords();
    test_hasStringPairOfWordsWithIdenticalCharacters_filledString_withoutRequestedWords();
    test_hasStringPairOfWordsWithIdenticalCharacters_fullString_oneWord();
    test_hasStringPairOfWordsWithIdenticalCharacters_fullString_withRequestedWords();
    test_hasStringPairOfWordsWithIdenticalCharacters_fullString_withoutRequestedWords();
}

void test_getStringFromWordsOfStringWhichIsNotEqualToLastWord_emptyString() {
    char s[] = "";
    getStringFromWordsOfStringWhichIsNotEqualToLastWord(s);
    char expectedS[] = "";
    ASSERT_STRING(expectedS, s);
}

void test_getStringFromWordsOfStringWhichIsNotEqualToLastWord_filledString_oneWord() {
    char s[7] = "  jvc";
    getStringFromWordsOfStringWhichIsNotEqualToLastWord(s);
    char expectedS[] = "";
    ASSERT_STRING(expectedS, s);
}

void test_getStringFromWordsOfStringWhichIsNotEqualToLastWord_filledString() {
    char s[50] = " pulpy nectar home sweet home";
    getStringFromWordsOfStringWhichIsNotEqualToLastWord(s);
    char expectedS[] = "pulpy nectar sweet";
    ASSERT_STRING(expectedS, s);
}

void test_getStringFromWordsOfStringWhichIsNotEqualToLastWord_fullString_oneWord() {
    char s[] = " jbl";
    getStringFromWordsOfStringWhichIsNotEqualToLastWord(s);
    char expectedS[] = "";
    ASSERT_STRING(expectedS, s);
}

void test_getStringFromWordsOfStringWhichIsNotEqualToLastWord_fullString() {
    char s[] = " instagram like story tell story";
    getStringFromWordsOfStringWhichIsNotEqualToLastWord(s);
    char expectedS[] = "instagram like tell";
    ASSERT_STRING(expectedS, s);
}

void test_getStringFromWordsOfStringWhichIsNotEqualToLastWord() {
    test_getStringFromWordsOfStringWhichIsNotEqualToLastWord_emptyString();
    test_getStringFromWordsOfStringWhichIsNotEqualToLastWord_filledString_oneWord();
    test_getStringFromWordsOfStringWhichIsNotEqualToLastWord_filledString();
    test_getStringFromWordsOfStringWhichIsNotEqualToLastWord_fullString_oneWord();
    test_getStringFromWordsOfStringWhichIsNotEqualToLastWord_fullString();
}

void test_string_tasks() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_digitToStartReverse();
    test_digitToStartReverseTransform();
    test_digitToEnd();
    test_digitToEndTransform();
    test_replaceDigitsBySpaces();
    test_replace();
    test_areWordsLexicographicallyOrdered();
    test_getPalindromesCount();
    test_fillStringWithAlternatingWordsOfTwoOtherStrings();
    test_reverseWordOrderInString();
    testAll_getWordBeforeFirstWordWithA();
    test_lastWordInFirstStringInSecondString();
    test_hasStringIdenticalWords();
    test_hasStringPairOfWordsWithIdenticalCharacters();
    test_getStringFromWordsOfStringWhichIsNotEqualToLastWord();
}

int main() {
    test_string_lib();
    test_string_tasks();

    return 0;
}