#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex Mdata;

void fun1()
{
    for(int i = 0; i <100; ++i)
    {
        std::lock_guard<std::mutex> lock_1(Mdata);
        cout<< "111" << "111" << "111"<< endl;
    }
}

void fun2()
{
    for(int i = 0; i <100; ++i)
    {
        Mdata.lock();
        cout<< "222" << "222" << "222"<< endl;
        Mdata.unlock();
    }
}
int main()
{
   std::thread thread_1(fun1);
   std::thread thread_2(fun2);

   if(thread_1.joinable())
   {
       thread_1.join();
   }

   if(thread_2.joinable())
   {
       thread_2.join();
   }

    return 0;
}
