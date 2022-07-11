#include <iostream>
#include <memory>

struct MyException {};

struct A
{
    std::unique_ptr<int> data = nullptr;

    A()
    {
        std::unique_ptr<int> tmp = std::make_unique<int>();
        throw MyException{};
        std::swap(data, tmp);
    }
};

int main()
{
    try {
        A a;
    }  catch (...)
    {}

    return 0;
}
