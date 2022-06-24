#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
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

    String& operator =(const String&);   // оператор присваивания копирования
    String& operator =(String&&);       // оператор присваивания перемещения
    String& operator +=(const char& ch);
    String& operator +=(const String&);
    String& operator +=(const std::string&);
    friend std::ostream& operator <<(std::ostream& out, const My::String& other);
    friend std::istream& operator >>(std::istream& in, My::String& other);

    const char* begin();                  // функция возвр. указатель на начало строки (выведет строку на экран)
    uint64_t size();                      // функция возвращ. размер строки
    const char* end();

    String& append(const String& other);    // метод копирования в строку реального объекта
    String& append(String&& other);        // метод копирования в строку временных объектов

private:
    struct Counter
    {
        size_t count = 0;
    };

    char*   _ptr;                   // данные (строка)
    uint64_t _size;                  // размер
    uint64_t _copasity;              // вместимость
};
}

#endif // MY_STRING_H
