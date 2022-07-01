#include "summ_proiz.h"
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

Summ_Proizvodn::Summ_Proizvodn (int&& all_host_number, int&& host_num_for_one)
    : _all_host_number(all_host_number)
    , _host_num_for_one (host_num_for_one)
{
    if (!all_host_number && !host_num_for_one)
    {
        std::cout<<"error - no host number or kol-vo strok";
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

    std::ofstream file_1; // сюда запишется очищенная таблица
    file_1.open("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/clear_tab.txt");
    std::copy(new_word.begin(), new_word.end(), std::ostream_iterator<std::string>(file_1));
    file_1.close();
    std::cout<<"table cleared "<< std::endl;

    std::string new_path = "D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/clear_tab.txt";
    return new_path; //метод вернет новый путь к очищенной таблице
}

void Summ_Proizvodn::gen_tab_summ_proizvodn(const std::string &path, const Summ_Proizvodn& other)
{
    std::ifstream myfile(path);
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
    // в инфо записываются данные из файла
    std::vector<Tab_1>info (other._host_num_for_one*  other._all_host_number * 4);

    for (int i = 0; myfile; ++i)
    {
        (myfile >> info[i].host).get();
        (myfile >> info[i].time).get();
        (myfile >> info[i].data).get();
        (myfile >> info[i].count).get();
    }
    myfile.close();

    // считаем проивзодные

    std::vector<double> pro_host {}; //сюда запишутся все производные подряд
    std::ofstream file_1; // сюда запишутся все производные по хостам
    file_1.open("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/all_proizvod.txt");

    double d = 0; //для просчета данных
    double t = 0; //для просчета времени
    double p = 0; //для просчета производных

    for (int j = 0; j <= other._all_host_number; ++j) // до количества хостов
    {
        for (int i = 0; i <= (other._host_num_for_one*  other._all_host_number * 4); ++i) // до кол-ва данных = кол-во хостов * столбцов в таблице * строк по одному хосту
        {
            if (info[i].host ==( "host_" + std::to_string(j)))
            {
                d = (info[i+1].data) - (info[i].data);
                t= info[i+1].time - info[i].time;
                p = d /t;
                pro_host.push_back(p); // запишем в про-хост все производные всех хостов подряд
                file_1 << p << std::endl;
            }
        }
    }
    file_1.close();

    std::ofstream file_2; // сюда запишутся суммы производных хостов
    file_2.open("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/summ_proizvod.txt");

    for (int k = 0; k <other._all_host_number; ++k)
    {
        double summa = 0; // сюда суммируются производные
        for (int f = 0; f <_host_num_for_one; ++f)   // по количеству даных на 1 хост
        {
            summa += pro_host[k+(f*_host_num_for_one)];
        }
        file_2 << summa << std::endl;
    }
    file_2.close();

    std::cout<<"sucsess all pr \n";
}
