#include "Proizvodn.h"
#include <fstream>
#include <string>
#include <vector>

Proizvodn::Proizvodn (int&& host_number)
    :_host_number(host_number)
{
//    if (!host_number)
//        return;

        std::cout<<"sucsess obj ";
};


void Proizvodn::gen_tab_proizvodn(const std::string &path, const Proizvodn& other)
{
    struct Tab_1
    {
        int data = 0;
        std::string host {};
        int time = 0;
        int count = 0;
    };

    std::ifstream myfile(path);
    if (!myfile)
    {
        std::cout << "error - no file\n";
    }

    Tab_1 tab;
    std::vector <Tab_1>info (4000000); // в инфо записываются данные из строки

    for (int i = 0; myfile; ++i)
    {
        (myfile >> info[i].host).get();
        (myfile >> info[i].time).get();
        (myfile >> info[i].data).get();
        (myfile >> info[i].count).get();
    }
    myfile.close();

    // считаем проивзодные

     float q = 0;
     float w = 0;
     float e = 0;

    std::ofstream file_5;
    file_5.open("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/proizvod.txt");
    int host_num = 0;
    host_num = other._host_number;

    for (int i = 0; i <=4000000; ++i)
    {
        if (info[i].host ==( "host_" + std::to_string(host_num)))
        {
            std::cout <<info[i].data <<std::endl;
            std::cout <<info[i].time <<std::endl;
            q = (info[i+1].data)  -  (info[i].data);
            w= info[i+1].time - info[i].time;
            e = q /w;

            std::cout << e<< std::endl;
            file_5 << e << std::endl;
        }
    }

    file_5.close();
    std::cout<<"sucsess pr ";
}
