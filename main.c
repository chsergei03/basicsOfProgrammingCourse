#include <stdio.h>
#include <assert.h>

#include "libs/string/string_.h"
#include "libs/string/tasks/removeNonLetters.h"

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

void test_string_tasks() {
    test_removeNonLetters();
}

int main() {
    test_string_lib();
    test_string_tasks();

    return 0;
}