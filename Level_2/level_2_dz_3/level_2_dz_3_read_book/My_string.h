#ifndef MY_STRING_H
#define MY_STRING_H

#include <cinttypes>

namespace My
{
class String
{
public:
    String();                             // конструктор по умолчанию
    String(const char* str);              // конструктор добавления новой строки к имеющейся
    String(const String& other);          // конструктор копирования
    String(String&& other);               // конструктор перемещения

    ~String();                            // деструктор

    const char* c_str();                  // функция возвр. указатель на начало строки (выведет строку на экран)
    int64_t size();                      // функция возвращ. размер строки

    String& append(const String& other);    // функция копирования в строку реального объекта
    String& append(String&& other);        // функция копирования в строку временных объектов

private:
    struct Counter
    {
        size_t count = 0;
    };

    char*   _ptr;                   // данные (строка)
    int64_t _size;                  // размер
    int64_t _copasity;              // вместимость
    mutable Counter* _count_ref;    // подсчет копий
};
}

#endif // MY_STRING_H