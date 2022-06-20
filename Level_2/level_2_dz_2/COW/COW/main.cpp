#include <iostream>

#include "My_string.h"

using namespace std;

int main()
{
    My::String object_1("stroka ");   std::cout << "oblect 1 : " << object_1.begin() << std::endl;

   My::String object_2(" privet ");   std::cout << "oblect 2 : " << object_2.begin() << std::endl;
//
//   My::String object_3(object_1);    std::cout << "oblect 3 = obl 1: " << object_3.c_str() << std::endl;
//
//   object_1 = "nanana";     std::cout << "obj 1 = obj 2 : " << object_1.c_str() << std::endl;
//
//   object_2 = object_3; std::cout << "obj 2 = obj 3 : " << object_2.c_str() << std::endl;
//
//   std::cout << "oblect 1 : " << object_1.c_str() << std::endl;
//   std::cout << "oblect 2 : " << object_2.c_str() << std::endl;
//   std::cout << "oblect 3 : " << object_3.c_str() << std::endl;

//    std::cout << "oblect 1 : " << object_1.end_str() << std::endl;

//    while (!object_1.end_str())
//    {
//        std::cout << "oblect 1 : " << object_1.c_str() << std::endl;
//    }
char a = 'f';
    object_1 += a;
    std::cout << "oblect 1 : " << object_1.begin() << std::endl;

        return 0;
}
