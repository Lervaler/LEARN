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
    std::cout << "String::String() - konstructor default" << std::endl;
}

String::String(const char* str)              // конструктор создания строки
    : _ptr(nullptr)
    , _size(0)
    , _copasity(0)
    , _count_ref (new Counter)
{
    std::cout << "String::String(const char* str) - konstructor create stroki" << std::endl;
    if (str == nullptr)
    {
        return;
    }

    _size = strlen(str);
    _copasity = _size * 2;
    _ptr = new char[_copasity + 1]{};
    strncpy(_ptr, str, _copasity);
    ++_count_ref->count;
    std::cout << "                      OPEN MEMORY " <<static_cast<void*>(_ptr) <<std::endl;
}

String::String(const String& other)        // конструктор копирования
    : _ptr(other._ptr)
    , _size(other._size)
    , _copasity(other._copasity)
    , _count_ref (other._count_ref)
{
    ++_count_ref->count;
    std::cout << "String::String(const String& other)  - konstructor copy-rowaniya" << std::endl;
}

String::String(String&& other)           // конструктор перемещения
    : _ptr(other._ptr)
    , _size(other._size)
    , _copasity(other._copasity)
    , _count_ref (other._count_ref)
{
    std::cout << "String::String(String&& other)  - konstructor move" << std::endl;
    other._ptr = nullptr;
    other._size = 0;
    other._copasity = 0;
    other._count_ref = 0;
}

String::~String()
{
    std::cout << "String::~String()" << std::endl;
    if (!--_count_ref->count)
    {
        delete [] _ptr;
        delete _count_ref;
        std::cout << "                                                          DELETE by konstructor " << static_cast<void*>(_ptr)<< std::endl;
    }
}

 String& String::operator =(const String& other)   // оператор присваивания копирования
{
    if(this == &other)
    return *this;

    delete [] _ptr;        std::cout << "                                                          DELETE by konstructor " << static_cast<void*>(_ptr)<< std::endl;
    _size = 0;
    _copasity = 0;
    delete _count_ref;

    _ptr = other._ptr;
    _size = other._size;
    _copasity = other._copasity;
    _count_ref = other._count_ref;

    return *this;
}

String& String::operator =(String&& other)       // оператор присваивания перемещения
{
    if(this == &other)
    return *this;

    delete [] _ptr;         std::cout << "                                                          DELETE by konstructor " << static_cast<void*>(_ptr)<< std::endl;
    _size = 0;
    _copasity = 0;
    delete _count_ref;

    _ptr = other._ptr;
    _size = other._size;
    _copasity = other._copasity;
    _count_ref = other._count_ref;

    other._ptr = nullptr;
    other._size =0;
    other._copasity = 0;
    --other._count_ref;

    return *this;
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

    if (_copasity < (other._size + _size) || _count_ref->count != 1)
    {
        _copasity = _copasity + other._copasity;
        char* tmp = new char[_copasity]{};    std::cout << "                      OPEN MEMORY " <<static_cast<void*>(tmp) <<std::endl;
        strncpy(tmp, _ptr, _copasity);

        if (_count_ref->count == 1)
        {
            delete[] _ptr;   std::cout << "                                                          DELETE by app " << static_cast<void*>(_ptr)<< std::endl;
        }
        else
        {
            --_count_ref->count;
            _count_ref = new Counter();
            _count_ref->count = 1;          // новый счетчик = 1 (чтобы удалилась память в деструкторе)
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

//String& String::append(String&& other)                        // метод класса для временного объекта - перемещение
//{
//    std::cout << "String::append(String&& other) - metod move" << std::endl;
//    append(other);
//
////   delete [] other._ptr;         std::cout << "                                                          DELETE by konstructor " << static_cast<void*>(_ptr)<< std::endl;
////   other._size = 0;
////   other._copasity = 0;
////   delete other._count_ref;
////
////   _ptr = other._ptr;
////   _size = other._size;
////   _copasity = other._copasity;
////   _count_ref = other._count_ref;
////
////   other._ptr = nullptr;
////   other._size =0;
////   other._copasity = 0;
////   --other._count_ref;
//    return *this;
//}
}
