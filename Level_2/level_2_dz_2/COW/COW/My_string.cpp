#include "My_string.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace My
{
String::String()                                // конструктор по умолчанию
    : _ptr(nullptr)
    , _size(0)
    , _copasity(0)
    , _is_copy (false)
{
    std::cout << "String::String() - konstructor default" << std::endl;
}

String::String(const char* str)              // конструктор добавления новой строки к имеющейся
    : _ptr(nullptr)
    , _size(0)
    , _copasity(0)
    , _is_copy (false)
{
    std::cout << "String::String(const char* str) - konstructor copy new str into old-srt" << std::endl;
    if (str == nullptr)
        return;

    _size = strlen(str);
    _copasity = _size * 2;
    _ptr = new char[_copasity + 1]{};

    strncpy(_ptr, str, _copasity);
            std::cout << "_is_copy = " << _is_copy << std::endl;
}

String::String(const String& other)        // конструктор копирования
    : _ptr(other._ptr)
    , _size(other._size)
    , _copasity(other._copasity)
    , _is_copy (true)
{
    std::cout << "String::String(const String& other)  - konstructor copy-rowaniya" << std::endl;

        other._is_copy = true;                 // новая строка тоже копия
        std::cout << "_is_copy = " << _is_copy << std::endl;

}

String::String(String&& other)           // конструктор перемещения
    : _ptr(other._ptr)
    , _size(other._size)
    , _copasity(other._copasity)
    , _is_copy (false)
{
    std::cout << "String::String(String&& other)  - konstructor move" << std::endl;

    other._ptr = nullptr;
    other._size = 0;
    other._copasity = 0;
}

String::~String()
{
    std::cout << "String::~String()" << std::endl;
    if (!_is_copy)
    {
        delete [] _ptr;
    }
}

const char* String::c_str()
{
    return _ptr;
}

int64_t String::size()
{
    return _size;
}

String& String::append(const String& other)                       // метод класса копирование
{
    std::cout << "String::append(const String& other) - metod COW" << std::endl;

    if (!other._ptr)
        return *this;

    if (_is_copy && _ptr)
    {
        std::cout << " new memory ready" << std::endl;            // выделяем память
        char* tmp = new char[_copasity + 1]{};
        strncpy(tmp, _ptr, _copasity);
        _ptr = tmp;
        _is_copy = false;
    }

    if (_copasity < (other._size + _size))           // если новые данные не влезают в старую строку
    {
        _copasity = (other._size + _size) * 2;
        char* tmp = new char[_copasity + 1]{};
        strncpy(tmp, _ptr, _copasity);
        delete [] _ptr;
        _ptr = tmp;
    }

    strncat(_ptr, other._ptr, _copasity - _size);      // копипаста новых данных в конец старой строки
    _size += other._size;

    return *this;
}

String& String::append(String&& other)                        // метод класса перемещение
{
    std::cout << "String::append(String&& other) - metod move" << std::endl;

    append(other);
    other._ptr = nullptr;
    other._size = 0;
    other._copasity = 0;

    return *this;
}

} // My

/*
class MyString
{
public:
    String();// конструктор по умолчанию
    String(const char* str);// конструктор добавления новой строки к имеющейся
    String(const String& other);// конструктор копирования
    String(String&& other); // конструктор перемещения

    String& append(const String& other); метод
    String& String::append(String&& other) метод
};
*/
