#include "summ_proiz.h"
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include "func_1_info.h"
#include <thread>

Summ_Proizvodn::Summ_Proizvodn (int&& all_host_number, int&& host_num_for_one)
    : _all_host_number(all_host_number)
    , _host_num_for_one (host_num_for_one)
{
    std::cout<<"sucsess object \n";
}

std::vector<Tab> Summ_Proizvodn::sum_tab_clean(const std::string &path, const Summ_Proizvodn& other)
{
    std::ifstream file(path);
    std::string word;
    std::vector<std::string> new_word;

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
        }
    }
    file.close();

    Tab tab;
    std::vector<Tab>info (other._host_num_for_one * other._all_host_number);
    // в инфо записываются очищенные данные из файла

    for (int i = 0, j = 0; i < new_word.size(); ++j)
    {
        info[j].host = new_word.at(i);
        info[j].time = std::stoi(new_word.at(i+1));
        info[j].data = std::stoi(new_word.at(i+2));
        info[j].count = std::stoi(new_word.at(i+3));
        i = i+4;
    }
    return info;
}

void Summ_Proizvodn::gen_tab_summ_proizvodn(const std::string &path, const Summ_Proizvodn& other)
{
    // в инфо записываются данные из файла
    std::vector<Tab>info = sum_tab_clean(path, other);

    // считаем проивзодные

    std::vector<double> pro_host {}; //сюда запишутся все производные подряд  - поток
    std::ofstream file_1; // сюда запишутся все производные по хостам
    file_1.open("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/all_proizvod.txt");

    double d = 0; //для просчета данных
    double t = 0; //для просчета времени
    double p = 0; //для просчета производных

    for (int j = 1; j <= other._all_host_number; ++j) // до количества хостов
    {
        for (int i = 1; i <= other._host_num_for_one * other._all_host_number; ++i) // до кол-ва данных = кол-во хостов * столбцов в таблице * строк по одному хосту
        {
//            if(info[i].time >= time_start && info[i].time <= time_end)
            {
                if (info[i-1].host == ("host_" + std::to_string(j)) &&
                    info[i].host == ("host_" + std::to_string(j)))
                {
                    d = info[i].data - info[i-1].data;
                    t= info[i].time - info[i-1].time;
                    p = d /t;
                    pro_host.push_back(p); // запишем в про-хост все производные всех хостов подряд
                    file_1 << p << std::endl;
                }
            }
        }
    }
    std::cout<<"sucsess all pr \n";
    file_1.close();

    std::ofstream file_2; // сюда запишутся суммы производных хостов
    file_2.open("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/summ_proizvod.txt");

    for (int k = 0; k < other._all_host_number -1; ++k)
    {
        double summa = 0; // сюда суммируются производные
        for (int f = 0; f <_host_num_for_one -1; ++f)   // по количеству даных на 1 хост
        {
            summa += pro_host[k+(f*_host_num_for_one)];
        }
        file_2 << summa << std::endl;
    }
    file_2.close();

    std::cout<<"sucsess summ pr \n";
}
