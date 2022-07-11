#include <iostream>

struct MyException
{};

int func()
{
    throw MyException{};
}

int main()
{

    func();
    return 0;
}
