#include <iostream>
#include <string>
#include "tab_generator.h"
#include "Proizvodn.h"
#include "summ_proiz.h"
#include <thread>



int main()
{
    const std::string path = "D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/one.txt";

//    Tab_Generator one(10, 10); // задаем кол-во хостов и кол-во строк на 1 хост
//    one.Gen_file(path); // генерирует таблицу данных
//    std::string new_path = one.tab_cleaner(path); // создает файл two.txt
//    std::cout<<new_path<<std::endl;

//    Proizvodn pro(2); // выбираем хост, у которого считаем производные
//    std::string new_path = pro.tab_clean(path);
//    pro.gen_tab_proizvodn("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/two.txt", pro); // генерирует таблицу производных

    Summ_Proizvodn sum(10, 10);
    std::string new_path =sum.sum_tab_clean(path);
    sum.gen_tab_summ_proizvodn(new_path, sum);


    return 0;
}
