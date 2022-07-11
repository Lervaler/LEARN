#include <iostream>

struct MyException0
{};
struct MyException1
{};
struct MyException2
{};

int func()
{
    throw MyException1{};
}

int main()
{
    try
    {
        try
        {
            func();
        } catch(MyException0& ex)
        {
            std::cout <<"cathed MyEx_0"<<std::endl;
        }catch(MyException1& ex)
        {
            std::cout <<"cathed MyEx_1"<<std::endl;
            throw MyException2{};
        }
    }
    catch(MyException1& ex)
    {
        std::cout <<"cathed MyEx_1 DONE"<<std::endl;
    }
    catch(...)
    {
        std::cout <<"cathed any DONE"<<std::endl;
    }
    std::cout <<"DONE"<<std::endl;

    return 0;
}
