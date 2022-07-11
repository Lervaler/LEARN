#include <iostream>

struct MyException
{};

int func()
{
    throw MyException{};
}

int main()
{
    std::set_terminate([](){
        std::cout << "Unhandled exception" << std::endl;
        std::abort();
         });
    func();
    return 0;
}
