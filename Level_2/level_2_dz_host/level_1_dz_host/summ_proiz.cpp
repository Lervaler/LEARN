#include "summ_proiz.h"
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

Summ_Proizvodn::Summ_Proizvodn (int&& all_host_number, int&& host_num_for_one)
    : _all_host_number(all_host_number)
    , _host_num_for_one (host_num_for_one)
{
    if (!all_host_number)
    {
        std::cout<<"error - no all host number ";
        return;
    }

        std::cout<<"sucsess all summ \n";
}

std::string Summ_Proizvodn::sum_tab_clean(const std::string &path)
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

        std::ofstream file_4;
        file_4.open("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/two.txt");
        std::copy(new_word.begin(), new_word.end(), std::ostream_iterator<std::string>(file_4));
        file_4.close();
        std::cout<<"table cleared "<< std::endl;
        std::string new_path = "D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/two.txt";
        return new_path;
}

void Summ_Proizvodn::gen_tab_summ_proizvodn(const std::string &path, const Summ_Proizvodn& other)
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
    std::vector <Tab_1>info (other._host_num_for_one*  other._all_host_number * 4); // в инфо записываются данные из файла

    for (int i = 0; myfile; ++i)
    {
        (myfile >> info[i].host).get();
        (myfile >> info[i].time).get();
        (myfile >> info[i].data).get();
        (myfile >> info[i].count).get();
    }
    myfile.close();

    // считаем проивзодные

    std::vector <double> pro_host {};

     double q = 0;
     double w = 0;
     double e = 0;

    std::ofstream file_5;
    file_5.open("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/all_proizvod.txt");
    std::ofstream file_6;
    file_6.open("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/proizvod.txt");
    int host_num = 0;
    host_num = other._all_host_number;
    int all_data = 0;
    all_data = other._host_num_for_one*  other._all_host_number * 4;

    for (int j = 0; j <= host_num; ++j) // до количества хостов
    {
        for (int i = 0; i <=all_data; ++i) // до кол-ва данных = кол-во хостов * столбцов в таблице * строк по одному хосту
        {
            if (info[i].host ==( "host_" + std::to_string(j)))  //
            {
                std::cout <<info[i].data <<std::endl;
                std::cout <<info[i].time <<std::endl;

                q = (info[i+1].data)  -  (info[i].data);
                w= info[i+1].time - info[i].time;
                e = q /w;
                pro_host.push_back(e);

                std::cout << e<< std::endl;

                file_6 << e << std::endl;
            }
        }
    }
    file_6.close();

    for (int k = 0; k <host_num; ++k)
    {
        double summa = 0;
        for (int f = 0; f <_host_num_for_one; ++f)   // по количеству даных на 1 хост
        {
            summa += pro_host[k+(f*_host_num_for_one)];
        }
        file_5 << summa << std::endl;
    }
    file_5.close();
    std::cout<<"sucsess all pr \n";
}
