#include <iostream>

#include "My_string.h"

using namespace std;

int main()
{
    My::String object_1("stroka ");                                    // создаем строку объект-1
    std::cout << "oblect 1 : " << object_1.c_str() << std::endl;

   My::String object_2(" privet ");

    object_1 = object_2;
    object_1.append(object_2);                                         // добавляем в объект-3 новую информацию (выделяем память)

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
