add_library(string
        string_.c
        tasks/removeNonLetters.c
        tasks/removeExtraSpaces.c
        tasks/digitToStartReverseTransform.c
        tasks/digitToEndTransform.c
        tasks/replaceDigitsBySpaces.c
        tasks/replace.c
        tasks/areWordsLexicographicallyOrdered.c
        tasks/printWordsReverse.c
        tasks/getPalindromesCount.c
        tasks/fillStringWithAlternatingWordsOfTwoOtherStrings.c
        tasks/reverseWordOrderInString.c
        tasks/getWordBeforeFirstWordWithA.c
        tasks/lastWordInFirstStringInSecondString.c
        tasks/hasStringIdenticalWords.c
        tasks/hasStringPairOfWordsWithIdenticalCharacters.c
        tasks/getStringFromWordsOfStringWhichAreNotEqualToLastWord.c
        tasks/getWordBeforeFirstWWord.c
        tasks/deleteWordsWhichAreEqualToLastWord.c
        tasks/complementS2.c
        tasks/hasStringEveryCharOfWord.c

        tests/test_string.c
)

target_link_libraries(string algorithms)