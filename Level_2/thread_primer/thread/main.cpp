#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

mutex Mdata;
//int a = 0;  // гонка за данные - число рандомное
atomic<int> a = 0; //атомарная переменная - число 2 млн

void fun1()
{
    for(int i = 0; i <1000000; ++i)
    {
        ++a;
    }
}

void fun2()
{
    for(int i = 0; i <1000000; ++i)
    {
        ++a;
    }
}
int main()
{
   std::thread thread_1(fun1);
   std::thread thread_2(fun2);

    thread_1.join();
    thread_2.join();
    cout<< a;

    return 0;
}
