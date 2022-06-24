#include "my_string.h"
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

namespace My
{
String::String()                                 // конструктор по умолчанию
    : _ptr(nullptr)
    , _size(0)
    , _copasity(0)
{

}

String::String(const char* str)              // конструктор создания строки
    : _ptr(nullptr)
    , _size(0)
    , _copasity(0)
{
    if (str == nullptr)
    {
        return;
    }

    _size = strlen(str);
    _copasity = _size * 2;
    _ptr = new char[_copasity + 1]{};
    strncpy(_ptr, str, _copasity);
}

String::String(const String& other)        // конструктор копирования
    : _ptr(nullptr)
    , _size(other._size)
    , _copasity(other._copasity)
{
    if (other._ptr)
    {
        _ptr = new char[_copasity + 1]{};
        strncpy(_ptr, other._ptr, _copasity);
    }
}

String::String(String&& other)           // конструктор перемещения
    : _ptr(other._ptr)
    , _size(other._size)
    , _copasity(other._copasity)
{
    other._ptr = nullptr;
    other._size = 0;
    other._copasity = 0;
}

String::~String()
{
    delete [] _ptr;
}

String& String::operator =(const String& other)   // оператор присваивания копирования
{
    if(this == &other)
    return *this;

    delete [] _ptr;
    _size = 0;
    _copasity = 0;

    _ptr = new char[other._copasity+ 1];
    _size = other._size;
    _copasity = other._copasity;
    strncpy(_ptr, other._ptr, _copasity);

    return *this;
}

String& String::operator =(String&& other)       // оператор присваивания перемещения
{
    if(this == &other)
    return *this;

    delete [] _ptr;
    _size = 0;
    _copasity = 0;

    _ptr = other._ptr;
    _size = other._size;
    _copasity = other._copasity;

    other._ptr = nullptr;
    other._size =0;
    other._copasity = 0;

    return *this;
}

String& String::operator +=(const char& ch)
{
    if(!ch)
    return *this;

    if (_copasity < ch + _size)
    {
        _copasity = _copasity + ch +1;
        char* tmp = new char[_copasity]{};
        strncpy(tmp, _ptr, _copasity);
        delete[] _ptr;
        _ptr = tmp;
    }
    strncat(_ptr, &ch, 1);
    _copasity = _copasity - 1;
    _size = _size + 1;

    return *this;
}

String& String:: operator +=(const String& other)
{
    if(!other._ptr)
    return *this;

    if (_copasity < other._size + _size +1)
    {
        _copasity = _copasity + other._copasity +1;
        char* tmp = new char[_copasity]{};
        strncpy(tmp, _ptr, _copasity);
        delete[] _ptr;
        _ptr = tmp;
    }
    strncat(_ptr, other._ptr, other._size);
    _copasity = _copasity - _size;
    _size = _size + other._size;

    return *this;
}

String& String::operator +=(const std::string& other)
{
    if(!other.data())
    return *this;

    if (_copasity < other.size() + _size +1)
    {
        _copasity = _copasity*2 +1;
        char* tmp = new char[_copasity]{};
        strncpy(tmp, _ptr, _copasity);
        delete[] _ptr;
        _ptr = tmp;
    }
    strncat(_ptr, other.data(), other.size());
    _copasity = _copasity - _size;
    _size = _size + other.size();

    return *this;
}


const char* String::begin()
{
    return _ptr;
}

uint64_t String::size()
{
    return _size;
}

const char* String::end()
{
    return _ptr + _size + 1;
}


String& String::append(const String& other)                       // метод класса копирование
{
    if (!other._ptr)
        return *this;

    if (_copasity < (other._size + _size))
    {
        _copasity = _copasity + other._copasity;
        char* tmp = new char[_copasity]{};
        strncpy(tmp, _ptr, _copasity);
        delete[] _ptr;
        _ptr = tmp;
    }

    strncat(_ptr, other._ptr, _copasity - _size);      // копипаста новых данных в конец старой строки
    _size += other._size;

    return *this;
}

String& String::append(String&& other)                        // метод класса для временного объекта - перемещение
{
    append(other);
    return *this;
}

std::ostream& operator <<(std::ostream& out, const My::String& other)
{
    out << other._ptr;
    return out;
}

std::istream& operator >>(std::istream& in, My::String& other)
{
//   other._size = sizeof(in);
//   other._copasity = other._size*2;
//   other._ptr = new char[other._copasity + 1]{};

    in >> other._ptr;

//    : _ptr(nullptr)
//    , _size(other._size)
//    , _copasity(other._copasity)
//{
//    if (other._ptr)
//    {
//        _ptr = new char[_copasity + 1]{};
//        strncpy(_ptr, other._ptr, _copasity);


    return in;
}

}

