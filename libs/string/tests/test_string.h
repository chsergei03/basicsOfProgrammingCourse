#ifndef INC_TEST_STRING_H
#define INC_TEST_STRING_H

#include "../string_.h"
#include "../tasks/removeNonLetters.h"
#include "../tasks/removeExtraSpaces.h"
#include "../tasks/digitToStartReverseTransform.h"
#include "../tasks/digitToEndTransform.h"
#include "../tasks/replaceDigitsBySpaces.h"
#include "../tasks/replace.h"
#include "../tasks/areWordsLexicographicallyOrdered.h"
#include "../tasks/getPalindromesCount.h"
#include "../tasks/fillStringWithAlternatingWordsOfTwoOtherStrings.h"
#include "../tasks/reverseWordOrderInString.h"
#include "../tasks/getWordBeforeFirstWordWithA.h"
#include "../tasks/lastWordInFirstStringInSecondString.h"
#include "../tasks/hasStringIdenticalWords.h"
#include "../tasks/hasStringPairOfWordsWithIdenticalCharacters.h"
#include "../tasks/getStringFromWordsOfStringWhichAreNotEqualToLastWord.h"
#include "../tasks/getWordBeforeFirstWWord.h"
#include "../tasks/deleteWordsWhichAreEqualToLastWord.h"
#include "../tasks/complementS2.h"
#include "../tasks/hasStringEveryCharOfWord.h"

void test_strlen_emptyString();

void test_strlen_stringWithOneSymbol();

void test_strlen_filledString();

void test_strlen_fullString();

void test_strlen_stringWithNullSymbol_beforeOtherSymbols();

void test_strlen_stringWithNullSymbol_betweenOtherSymbols();

void test_strlen_();

void test_findNonSpace_emptyString();

void test_findNonSpace_stringWithRequestedSymbol();

void test_findNonSpace_stringWithoutRequestedSymbol();

void test_findNonSpace();

void test_findSpace_emptyString();

void test_findSpace_stringWithRequestedSymbol();

void test_findSpace_stringWithoutRequestedSymbol();

void test_findSpace();

void test_findSpaceReverse_emptyString();

void test_findSpaceReverse_stringWithRequestedSymbol();

void test_findSpaceReverse_stringWithoutRequestedSymbol();

void test_findSpaceReverse();

void test_strcmp_emptyStrings();

void test_strcmp_identicalNonEmptyStrings();

void test_strcmp_almostIdenticalNonEmptyStrings_lhs_before_rhs();

void test_strcmp_almostIdenticalNonEmptyStrings_lhs_after_rhs();

void test_strcmp_definitelyNotIdenticalNonEmptyStrings_lhs_before_rhs();

void test_strcmp_definitelyNotIdenticalNonEmptyStrings_lhs_after_rhs();

void test_strcmp_();

void test_copy_partialCopying_emptyString();

void test_copy_partialCopying_filledString();

void test_copy_partialCopying_fullString();

void test_copy_fullCopying_emptyString();

void test_copy_fullCopying_filledString();

void test_copy();

void test_copyIf_stringToCopyWithRequestedSymbols_emptyString();

void test_copyIf_stringToCopyWithRequestedSymbols_filledString();

void test_copyIf_stringToCopyWithRequestedSymbols_fullString();

void test_copyIf_stringToCopyWithoutRequestedSymbols_emptyString();

void test_copyIf_stringToCopyWithoutRequestedSymbols_filledString();

void test_copyIf_stringToCopyWithoutRequestedSymbols_fullString();

void test_copyIf();

void test_copyIfReverse_stringToCopyWithRequestedSymbols_emptyString();

void test_copyIfReverse_stringToCopyWithRequestedSymbols_filledString();

void test_copyIfReverse_stringToCopyWithRequestedSymbols_fullString();

void test_copyIfReverse_stringToCopyWithoutRequestedSymbols_emptyString();

void test_copyIfReverse_stringToCopyWithoutRequestedSymbols_filledString();

void test_copyIfReverse_stringToCopyWithoutRequestedSymbols_fullString();

void test_copyIfReverse();

void test_getEndOfString_emptyString();

void test_getEndOfString_stringWithOneSymbol();

void test_getEndOfString_filledString();

void test_getEndOfString_fullString();

void test_getEndOfString_stringWithNullSymbol_beforeOtherSymbols();

void test_getEndOfString_stringWithNullSymbol_betweenOtherSymbols();

void test_getEndOfString();

void test_getWord_emptyString();

void test_getWord_filledString_withoutWords();

void test_getWord_filledString_withWords();

void test_getWord_fullString_withoutWords();

void test_getWord_fullString_withWords();

void test_getWord();

void test_getWordReverse_emptyString();

void test_getWordReverse_filledString_withWords();

void test_getWordReverse_filledString_withoutWords();

void test_getWordReverse_fullString_withWords();

void test_getWordReverse_fullString_withoutWords();

void test_getWordReverse();

void test_getBagOfWords_emptyString();

void test_getBagOfWords_filledString_withoutWords();

void test_getBagOfWords_filledString_withWords();

void test_getBagOfWords_fullString_withoutWords();

void test_getBagOfWords_fullString_withWords();

void test_getBagOfWords();

void test_getWordByDivider_emptyString();

void test_getWordByDivider_filledString_withoutWords();

void test_getWordByDivider_filledString_oneWord();

void test_getWordByDivider_filledString_withNecessaryDivider();

void test_getWordByDivider_filledString_withoutNecessaryDivider();

void test_getWordByDivider_fullString_withoutWords();

void test_getWordByDivider_fullString_oneWord();

void test_getWordByDivider_fullString_withNecessaryDivider();

void test_getWordByDivider_fullString_withoutNecessaryDivider();

void test_getWordByDivider();

void test_string_lib();

void assertString(const char *expected, const char *got,
                  const char *fileName, const char *funcName,
                  const int line);

void test_removeNonLetters_emptyString();

void test_removeNonLetters_filledString_withSpaceSymbols();

void test_removeNonLetters_filledString_withoutSpaceSymbols();

void test_removeNonLetters_fullString_withSpaceSymbols();

void test_removeNonLetters_fullString_withoutSpaceSymbols();

void test_removeNonLetters();

void test_removeExtraSpaces_emptyString();

void test_removeExtraSpaces_filledString_withoutWords_withExtraSpaces();

void test_removeExtraSpaces_filledString_withoutWords_withoutExtraSpaces();

void test_removeExtraSpaces_filledString_withWords_withExtraAndBasicSpaces();

void test_removeExtraSpaces_filledString_withWords_withoutSpaces();

void test_removeExtraSpaces_fullString_withoutWords_withExtraSpaces();

void test_removeExtraSpaces_fullString_withWords_withExtraAndBasicSpaces();

void test_removeExtraSpaces_fullString_withWords_withoutSpaces();

void test_removeExtraSpaces();

void test_digitToStartReverse_withDigits_withLetters();

void test_digitToStartReverse_withoutDigits_withLetters();

void test_digitToStartReverse_withDigits_withoutLetters();

void test_digitToStartReverse();

void test_digitToStartReverseTransform_emptyString();

void test_digitToStartReverseTransform_filledString();

void test_digitToStartReverseTransform_fullString();

void test_digitToStartReverseTransform();

void test_digitToEnd_withDigits_withLetters();

void test_digitToEnd_withoutDigits_withLetters();

void test_digitToEnd_withDigits_withoutLetters();

void test_digitToEnd();

void test_replaceDigitsBySpaces_emptyString();

void test_replaceDigitsBySpaces_filledString_withDigits();

void test_replaceDigitsBySpaces_filledString_withoutDigits();

void test_replaceDigitsBySpaces();

void test_replace_filledString_equalLensOfW1AndW2();

void test_replace_filledString_w1LenMoreThanW2Len();

void test_replace_filledString_w1LenLessThanW2Len();

void test_replace();

void test_areWordsLexicographicallyOrdered_emptyString();

void test_areWordsLexicographicallyOrdered_filledString_withoutWords();

void test_areWordsLexicographicallyOrdered_filledString_wordsAreOrdered();

void test_areWordsLexicographicallyOrdered_filledString_wordsAreNotOrdered();

void test_areWordsLexicographicallyOrdered_fullString_wordsAreNotOrdered();

void test_areWordsLexicographicallyOrdered_fulltring_withoutWords();

void test_areWordsLexicographicallyOrdered_fullString_wordsAreOrdered();

void test_areWordsLexicographicallyOrdered_fullString_wordsAreNotOrdered();

void test_areWordsLexicographicallyOrdered();

void test_getPalindromesCount_emptyString();

void test_getPalindromesCount_filledString();

void test_getPalindromesCount_fullString();

void test_getPalindromesCount();

void test_fillStringWithAlternatingWordsOfTwoOtherStrings_twoEmptyStrings();

void test_fillStringWithAlternatingWordsOfTwoOtherStrings_emptyAndNonEmptyString();

void test_fillStringWithAlternatingWordsOfTwoOtherStrings_twoNonEmptyString_equalWordsCounts();

void test_fillStringWithAlternatingWordsOfTwoOtherStrings_twoNonEmptyString_s1LenMoreThanS2Len();

void test_fillStringWithAlternatingWordsOfTwoOtherStrings_twoNonEmptyString_s1LenLessThanS2Len();

void test_fillStringWithAlternatingWordsOfTwoOtherStrings();

void test_reverseWordOrderInString_emptyString();

void test_reverseWordOrderInString_filledString_oneWordInString();

void test_reverseWordOrderInString_filledString();

void test_reverseWordOrderInString_fullString_oneWordInString();

void test_reverseWordOrderInString_fullString();

void test_reverseWordOrderInString();

void testAll_getWordBeforeFirstWordWithA();

void test_lastWordInFirstStringInSecondString_twoEmptyStrings();

void test_lastWordInFirstStringInSecondString_emptyS1AndNonEmptyS2();

void test_lastWordInFirstStringInSecondString_nonEmptyS1AndEmptyS1();

void test_lastWordInFirstStringInSecondString_twoNonEmptyStrings_1();

void test_lastWordInFirstStringInSecondString_twoNonEmptyStrings_2();

void test_lastWordInFirstStringInSecondString_twoNonEmptyStrings_3();

void test_lastWordInFirstStringInSecondString();

void test_hasStringIdenticalWords_emptyString();

void test_hasStringIdenticalWords_filledString_oneWord();

void test_hasStringIdenticalWords_filledString_withIdenticalWords();

void test_hasStringIdenticalWords_filledString_withoutIdenticalWords();

void test_hasStringIdenticalWords_fullString_oneWord();

void test_hasStringIdenticalWords_fullString_withIdenticalWords();

void test_hasStringIdenticalWords_fullString_withoutIdenticalWords();

void test_hasStringIdenticalWords();

void test_hasStringPairOfWordsWithIdenticalCharacters_emptyString();

void test_hasStringPairOfWordsWithIdenticalCharacters_filledString_oneWord();

void test_hasStringPairOfWordsWithIdenticalCharacters_filledString_withRequestedWords();

void test_hasStringPairOfWordsWithIdenticalCharacters_filledString_withoutRequestedWords();

void test_hasStringPairOfWordsWithIdenticalCharacters_fullString_oneWord();

void test_hasStringPairOfWordsWithIdenticalCharacters_fullString_withRequestedWords();

void test_hasStringPairOfWordsWithIdenticalCharacters_fullString_withoutRequestedWords();

void test_hasStringPairOfWordsWithIdenticalCharacters();

void test_getStringFromWordsOfStringWhichIsNotEqualToLastWord_emptyString();

void test_getStringFromWordsOfStringWhichIsNotEqualToLastWord_filledString_oneWord();

void test_getStringFromWordsOfStringWhichIsNotEqualToLastWord_filledString();

void test_getStringFromWordsOfStringWhichIsNotEqualToLastWord_fullString_oneWord();

void test_getStringFromWordsOfStringWhichIsNotEqualToLastWord_fullString();

void test_getStringFromWordsOfStringWhichIsNotEqualToLastWord();

void testAll_getWordBeforeFirstWWord();

void test_deleteWordsWhichAreEqualToLastWord_emptyString();

void test_deleteWordsWhichAreEqualToLastWord_filledString_oneWord();

void test_deleteWordsWhichAreEqualToLastWord_filledString();

void test_deleteWordsWhichAreEqualToLastWord_fullString_oneWord();

void test_deleteWordsWhichAreEqualToLastWord_fullString();

void test_deleteWordsWhichAreEqualToLastWord();

void test_complementS2_twoEmptyStrings();

void test_complementS2_emptyS1AndNonEmptyS2();

void test_complementS2_nonEmptyS1AndEmptyS2();

void test_complementS2_twoNonEmptyStrings_equalN1AndN2();

void test_complementS2_twoNonEmptyStrings_n1MoreThanN2();

void test_complementS2_twoNonEmptyStrings_n1LessThanN2();

void test_complementS2();

void test_hasStringEveryCharOfWord_emptyString();

void test_hasStringEveryCharOfWord_filledString_allCharsOfWordInString();

void test_hasStringEveryCharOfWord_filledString_notAllCharsOfWordInString();

void test_hasStringEveryCharOfWord_fullString_allCharsOfWordInString();

void test_hasStringEveryCharOfWord_fullString_notAllCharsOfWordInString();

void test_hasStringEveryCharOfWord();

void test_string_tasks();

void test_string_lib();

void test_string_tasks();

void test_string();

#endif