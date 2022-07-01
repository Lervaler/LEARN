#include "Proizvodn.h"
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

Proizvodn::Proizvodn (int&& host_number)
    :_host_number(host_number)
{
    if (!host_number)
    {
        std::cout<<"error - no host number ";
        return;
    }
    std::cout<<"sucsess host num ";
};

std::string Proizvodn::tab_clean(const std::string &path)
{
    std::vector<std::string> new_word;
    std::ifstream file(path);
    std::string word;

    while(!file.eof())
    {
        file >> word;
        if (word != " " && word != "|" && word != "_"&&
            word != "|_____________|_____________|_____________|____________|" &&
            word != "______________________________________________________" &&
            word != "operation" &&
            word != "host_name" &&
            word != "time" &&
            word != "bites")
        {
            new_word.push_back(word);
            new_word.push_back(" ");
        }
    }

    std::ofstream file_1; // сюда запишем очищенную таблицу
    file_1.open("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/clear_tab.txt");
    std::copy(new_word.begin(), new_word.end(), std::ostream_iterator<std::string>(file_1));
    file_1.close();
    std::cout<<"table cleared "<< std::endl;

    std::string new_path = "D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/clear_tab.txt";
    return new_path;  // результат метода вернет новый путь к очищенной таблице

}

void Proizvodn::gen_tab_proizvodn(const std::string &path, const Proizvodn& other)
{
    std::ifstream myfile(path);  //открываем таблицу(очищенную)

    if (!myfile)
    {
        std::cout << "error - no file\n";
    }

    struct Tab_1
    {
        int data = 0;
        std::string host {};
        int time = 0;
        int count = 0;
    };
    Tab_1 tab;
    std::vector <Tab_1>info (4000000); // в инфо записываются данные из строки по структуре

    for (int i = 0; myfile; ++i)
    {
        (myfile >> info[i].host).get();
        (myfile >> info[i].time).get();
        (myfile >> info[i].data).get();
        (myfile >> info[i].count).get();
    }
    myfile.close();

    // считаем производные

     float q = 0;
     float w = 0;
     float e = 0;

    std::ofstream file_5;
    file_5.open("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/proizvod_for_one.txt");
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
    std::cout<<"sucsess pr for one ";
}
