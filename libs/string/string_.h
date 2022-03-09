#ifndef INC_STRING_H
#define INC_STRING_H

#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <memory.h>

#include "../../libs/algorithms/algorithm.h"

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
#define NULL_SYMBOL '\0'
#define SPACE_CHAR ' '
#define NULL_CHAR '0'

char _stringBuffer[MAX_STRING_SIZE + 1];

typedef struct wordDescriptor {
    char *begin; // позиция начала слова.
    char *end;
    // позиция первого символа после
    // последнего символа слова.
} wordDescriptor;

typedef struct bagOfWords {
    wordDescriptor words[MAX_N_WORDS_IN_STRING]; // массив слов.
    size_t size;                                 // размер массива слов.
} bagOfWords;

bagOfWords _bag;
bagOfWords _bag2;

typedef enum wordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} wordBeforeFirstWordWithAReturnCode;

// возвращает количество символов в строке
// до первого нуль-символа.
size_t strlen_(const char *begin);

// возвращает указатель на первый элемент с кодом ch,
// расположенный на ленте памяти между адресами begin и
// end не включая end, если символ не найден, возвращается
// значение end.
char *find(char *begin, const char *end, int ch);

// возвращает указатель на первый символ, отличный от пробельных,
// расположенный на ленте памятм начиная с begin и заканчивая
// нуль-символом, если символ не найден, возвращается адрес первого
// нуль-символа.
char *findNonSpace(char *begin);

// возвращает указатель на первый пробельный символ, расположенный
// на ленте памяти начиная с адреса begin и заканчивая нуль-символом,
// если символ не найден, возвращается адрес первого нуль-символа.
char *findSpace(char *begin);

// возвращает указатель на первый справа символ, отличный от пробельных
// расположенный на ленте памяти начиная с rbegin (последний символ
// строки, за которым следует нуль-символ) и заканчивая (адрес символа
// перед началом строки), если символ не найден, возвращает адрес rend.
char *findNonSpaceReverse(char *rbegin, const char *rend);

// возвращает указатель на первый справа пробельный символ, расположенный
// на ленте памяти начиная с rbegin (последний символ строки, за которым
// следует нуль-символ) и заканчивая rend (адрес символа перед началом строки),
// если символ не найден, возвращает адрес rend.
char *findSpaceReverse(char *rbegin, const char *rend);

// возвращает отрицательное значение, если lhs располагается до rhs в
// лексикографическом порядке; значение 0, если lhs и rhs равны; значение 1,
// если lhs распологается после rhs в лексикографическом порядке.
int strcmp_(const char *lhs, const char *rhs);

// записывает по адресу beginDestination фрагмент памяти начиная с адреса beginSource
// до endSource, возвращает указатель на следующий свободный фрагмент памяти в destination.
char *copy(const char *beginSource,
           const char *endSource,
           char *beginDestination);

// возвращает значение 'истина', если символ с кодом ch является цифрой, в противном
// случае - 'ложь'.
int isDigit(int ch);

// записывает по адресу beginDestination элементы фрагмента памяти, удовлетворяющие
// функции-предикату f, начиная с адреса beginSource до адреса endSource, возвращает
// указатель на следующий свободный фрагмент памяти в beginDestination.
char *copyIf(const char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

// записывает по адресу beginDestination элементы из фрагмента памяти,
// удовлетворяющие функции-предикату f, начиная с адреса rbeginSource до
// адреса rendSource (проверка элементов фрагмента памяти на предмет
// удовлетворения функции-предикату f осуществляется с его конца до начала),
// возвращает указатель на следующий свободный фрагмент памяти в beginDestination.
char *copyIfReverse(const char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

// возвращает указатель на первый нуль-символ в строке.
char *getEndOfString(char *begin);

// возвращает значение 0, если слово в строке beginSearch не было считано,
// в противном случае - значение 1; в переменную word типа wordDescriptor
// записывает позицию начала слова и позицию первого символа после конца слова.
int getWord(char *beginSearch, wordDescriptor *word);

// возвращает значение 0, если слово не было считано с конца строки
// (rbegin - указатель на начало поиска (конец строки), rend - указатель
// на конец поиска (начала строки), в противном случае - значение 1; в
// переменную word типа wordDescriptor записывает позицию начала слова и
// позицию первого символа после конца слова.
int getWordReverse(char *rbegin, char *rend, wordDescriptor *word);

// возвращает количество символов в слове word.
size_t wordlen_(wordDescriptor word);

// возвращает отрицательное значение, если w1 располагается до w2 в
// лексикографическом порядке; значение 0, если w1 и w2 равны; значение 1,
// если w1 распологается после w2 в лексикографическом порядке.
int wordcmp_(wordDescriptor w1, wordDescriptor w2);

// возвращает значение 1, если слова w1 и w2 идентичны, в противном случае - 'ложь'.
int areWordsEqual(wordDescriptor w1, wordDescriptor w2);

// получает позиции начала и конца каждого слова строки s,
// записывает их в массив слов bag типа bagOfWords.
void getBagOfWords(bagOfWords *bag, char *s);

// возвращает значение истина, если массивы слов bag1 и bag2 равны,
// в противном случае - 'ложь'.
int areEqualBagsOfWords(const bagOfWords bag1, const bagOfWords bag2);

// выводит слово word.
void printWord(wordDescriptor word);

// возвращает значение 0, если слово в строке beginSearch не было считано
// (divider - код символа, выступающего в роли разделителя между словами),
// в противном случае - значение 1; в переменную word типа wordDescriptor
// записывает позицию начала слова и позицию первого символа после конца слова.
int getWordByDivider(char *beginSearch, wordDescriptor *word,
                     const int divider);

// освобождает буфер _stringBuffer.
void freeBuffer();

// переводит слово word, являющееся переменной типа wordDescriptor, в строку,
// записывая в адрес destination.
void wordDescriptorToString(wordDescriptor word, char *destination);

// получает позиции начала и конца каждого слова строки s, сортирует
// буквы слова и записывает их в массив слов bag типа bagOfWords.
void getBagOfWordsWithWordSorting(bagOfWords *bag, char *s);

#endif