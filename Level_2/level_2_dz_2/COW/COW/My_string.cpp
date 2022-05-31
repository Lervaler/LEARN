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

String::String(const char* str)              // конструктор создания строки
    : _ptr(nullptr)
    , _size(0)
    , _copasity(0)
    , _is_copy (false)
{
    std::cout << "String::String(const char* str) - konstructor create stroki" << std::endl;
    if (str == nullptr)
        return;

    _size = strlen(str);
    _copasity = _size * 2;
    _ptr = new char[_copasity + 1]{};
    strncpy(_ptr, str, _copasity);
    std::cout << "                      OPEN MEMORY " <<static_cast<void*>(_ptr) <<std::endl;
}

String::String(const String& other)        // конструктор копирования
    : _ptr(other._ptr)
    , _size(other._size)
    , _copasity(other._copasity)
    , _is_copy (true)
{
    std::cout << "String::String(const String& other)  - konstructor copy-rowaniya" << std::endl;
    if (other._is_copy == false)
     {_is_copy = false;}
    other._is_copy = true;                 // создаваемая строка это копия
}

String::String(String&& other)           // конструктор перемещения
    : _ptr(other._ptr)
    , _size(other._size)
    , _copasity(other._copasity)
    , _is_copy (other._is_copy)
{
    std::cout << "String::String(String&& other)  - konstructor move" << std::endl;
    other._ptr = nullptr;
    other._size = 0;
    other._copasity = 0;
    other._is_copy = false;
}

String::~String()
{
    std::cout << "String::~String()" << std::endl;
    if (!_is_copy)
    {
        delete [] _ptr;
        std::cout << "                                                           DELETE MEMORY BY DESTCUCT " << static_cast<void*>(_ptr)<< std::endl;
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
    std::cout << "String::append(const String& other) - METOD copy" << std::endl;

    if (!other._ptr)
        return *this;

    if (_is_copy && _ptr)
    {
        char* tmp = new char[_copasity + 1]{};
        strncpy(tmp, _ptr, _copasity);
        _ptr = tmp;
        _is_copy = false;
        std::cout << "                      OPEN MEMORY " <<static_cast<void*>(_ptr) <<std::endl;
    }

    if (_copasity < (other._size + _size) && _ptr)           // если новые данные не влезают в старую строку
    {
        _copasity = (other._size + _size) * 2;
        char* tmp = new char[_copasity + 1]{};
        strncpy(tmp, _ptr, _copasity);
        std::cout << "                      OPEN MEMORY for copy " << static_cast<void*>(tmp) << std::endl;

        delete [] _ptr;
        std::cout << "                                                           DELETE MEMORY for copy " << static_cast<void*>(_ptr) << std::endl;
        _ptr = tmp;
    }

    if (_ptr)
    {
        strncat(_ptr, other._ptr, _copasity - _size);      // копипаста новых данных в конец старой строки
        _size += other._size;
    }

    return *this;
}

String& String::append(String&& other)                        // метод класса перемещение
{
    std::cout << "String::append(String&& other) - metod move" << std::endl;
    append(other);
    if(other._is_copy == true)
    {
        other._ptr = nullptr;
        other._size = 0;
        other._copasity = 0;
        other._is_copy = false;
    }
    return *this;
}
}
// My

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
