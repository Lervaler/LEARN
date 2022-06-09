#include "My_string.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace My
{
String::String()                                 // конструктор по умолчанию
    : _ptr(nullptr)
    , _size(0)
    , _copasity(0)
    , _count_ref (new Counter)
{
    ++_count_ref->count;
}

String::String(const char* str)              // конструктор создания строки
    : _ptr(nullptr)
    , _size(0)
    , _copasity(0)
    , _count_ref (new Counter)
{
    if (str == nullptr)
    {
        return;
    }

    _size = strlen(str);
    _copasity = _size * 2;
    _ptr = new char[_copasity + 1]{};
    strncpy(_ptr, str, _copasity);
    ++_count_ref->count;
}

String::String(const String& other)        // конструктор копирования
    : _ptr(other._ptr)
    , _size(other._size)
    , _copasity(other._copasity)
    , _count_ref (other._count_ref)
{
    ++_count_ref->count;
}

String::String(String&& other)           // конструктор перемещения
    : _ptr(other._ptr)
    , _size(other._size)
    , _copasity(other._copasity)
    , _count_ref (other._count_ref)
{
    other._ptr = nullptr;
    other._size = 0;
    other._copasity = 0;
    other._count_ref = 0;
}

String::~String()
{
    if (!--_count_ref->count )
    {
        delete [] _ptr;
        delete _count_ref;
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
    if (!other._ptr)
        return *this;

    if (_copasity < (other._size + _size) || _count_ref->count != 1)
    {
        _copasity = _copasity + other._copasity;
        char* tmp = new char[_copasity]{};
        strncpy(tmp, _ptr, _copasity);

        if (_count_ref->count == 1)
        {
            delete[] _ptr;
        }
        else
        {
            --_count_ref->count;
            _count_ref = new Counter();
        }
        _ptr = tmp;
    }

    if (other._ptr)
    {
        strncat(_ptr, other._ptr, _copasity - _size);      // копипаста новых данных в конец старой строки
        _size += other._size;
    }

    return *this;
}

String& String::append(String&& other)                        // метод класса для временного объекта - перемещение
{
    append(other);
    other._ptr = nullptr;
    other._size = 0;
    other._copasity = 0;
    --other._count_ref->count;
    return *this;
}
}