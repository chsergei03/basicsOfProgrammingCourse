#ifndef INC_VOID_VECTOR_H
#define INC_VOID_VECTOR_H

#include <limits.h>
#include <stdbool.h>

typedef struct vectorVoid {
    void *data;          // указатель на нулевой элемент вектора.
    size_t size;         // размер вектора.
    size_t capacity;     // вместимость вектора.
    size_t baseTypeSize;
    // размер базового типа:
    // например, если вектор хранит int,
    // то поле baseTypeSize = sizeof(int);
    // если вектор хранит float, то поле
    // baseTypeSize = sizeof(float).
} vectorVoid;

// выводит в поток ошибок сообщение о том, что операционная
// система не может предоставить нужный объем памяти под
// размещение динамического массива, при этом выполнение
// программы заканчивается с кодом 1.
void isIncorrectMemoryAllocVoid(const int *data,
                                size_t capacity);

// возвращает структуру-дескриптор вектора произвольного типа
// из n значений (baseTypeSize - размер этого произвольного типа).
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

// возвращает вектор произвольного типа c вместимостью
// capacity, состоящий из элементов массива a размера size
// (baseTypeSize - размер базового типа массива a).
vectorVoid createVectorVFromArray(const void *a,
                                  size_t size,
                                  size_t capacity,
                                  size_t baseTypeSize);

// возвращает значение 'истина', если векторы v1 и v2
// произвольного типа идентичны, в противном случае - 'ложь'.
bool isIdenticalVoidVectors(vectorVoid v1,
                            vectorVoid v2);

// изменяет количество памяти, выделенное под хранение
// элементов вектора v произвольного типа (вместимость
// вектора при этом принимает значение newCapacity).
void reserveV(vectorVoid *v, size_t newCapacity);

// удаляет элементы из контейнера вектора v произвольного
// типа без освобождения выделенной памяти.
void clearV(vectorVoid *v);

// освобождает память, выделенную под неиспользуемые
// элементы вектора v произвольного типа.
void shrinkToFitV(vectorVoid *v);

// освобождает память, выделенную вектору v произвольного типа.
void deleteVectorV(vectorVoid *v);

// возвращает значение 'истина', если вектор v произвольного
// типа является пустым, в противном случае - 'ложь'.
bool isEmptyV(const vectorVoid *v);

// возвращает значение 'истина', если вектор v произвольного
// типа является полным, в противном случае - 'ложь'.
bool isFullV(const vectorVoid *v);

// записывает по адресу destination index-ый элемент
// вектора v произвольного типа.
void getVectorValueV(const vectorVoid *v,
                     size_t index,
                     void *destination);

// записывает в index-ый элемент вектора v произвольного
// типа значение, расположенное по адресу source.
void setVectorValueV(vectorVoid *v,
                     size_t index,
                     const void *source);

// выводит сообщение о том, что вектор произвольного типа
// пуст, при этом выполнение программы завершается с кодом 1.
void emptyVoidVectorMessage();

// удаляет последний элемент из вектора v произвольного типа.
void popBackV(vectorVoid *v);

// добавляет элемент x в конец вектора v произвольного типа.
void pushBackV(vectorVoid *v, const void *source);

#endif