#include <iostream>
#include <string>
#include "tab_generator.h"
#include "Proizvodn.h"
#include "summ_proiz.h"
#include <thread>
#include <functional>

int main()
{
    const std::string path = "D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/table.txt";

//    Tab_Generator one(10, 10); // задаем кол-во хостов и кол-во строк на 1 хост
//    one.Gen_file(path); // генерирует таблицу данных

    Summ_Proizvodn object(10, 10); // нужно укать кол-во хостов и кол-во строк у 1 хоста
//    sum.gen_tab_summ_proizvodn(path, sum);
    std::thread tr_1(&Summ_Proizvodn::gen_all_proizvodn, &object, path, object, 0, 1640985010);
    tr_1.join();

//    std::thread tr_2(&Summ_Proizvodn::gen_all_proizvodn, &object, path, object, 1640985011, 1640987180);
//    tr_2.join();


    return 0;
}
