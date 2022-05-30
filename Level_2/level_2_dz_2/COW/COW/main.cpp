#include <iostream>

#include "My_string.h"

using namespace std;

int main()
{
    My::String object_1("stroka ");                                    // создаем строку объект-1
    std::cout << "oblect 1 : " << object_1.c_str() << std::endl;

    My::String object_2(object_1);                                    //создаем строку объект-2 (копирование без копирования)
    std::cout << "oblect 2 : " << object_2.c_str() << std::endl;

    My::String object_3(object_2);                                    //создаем строку объект-3 (копирование без копирования)
    std::cout << "oblect 3 : " << object_3.c_str() << std::endl;

    object_3.append(object_2);                                         // добавляем в объект-3 новую информацию (выделяем память)
    std::cout << "oblect 3 updated obj2 : " << object_3.c_str() << std::endl;

    My::String object_4(object_2);                                    //создаем строку объект-4 (копирование без копирования)
    std::cout << "oblect 4 : " << object_4.c_str() << std::endl;

    std::cout << "oblect 3 : " << object_3.c_str() << std::endl;
    std::cout << "oblect 2 : " << object_2.c_str() << std::endl;
    std::cout << "oblect 1 : " << object_1.c_str() << std::endl;


        object_3.append("123 ").append("123");                                         // добавляем в объект-3 новую информацию (выделяем память)
        std::cout << "oblect 3-app-123-123 : " << object_3.c_str() << std::endl;


        std::cout << "oblect 4 : " << object_4.c_str() << std::endl;

        std::cout << "oblect 3 : " << object_3.c_str() << std::endl;
        std::cout << "oblect 2 : " << object_2.c_str() << std::endl;
        std::cout << "oblect 1 : " << object_1.c_str() << std::endl;


        return 0;
}
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
