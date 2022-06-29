#include <iostream>
#include <string>
#include "tab_generator.h"
#include "Proizvodn.h"


int main()
{
//    Tab_Generator one(100, 1); // задаем количество хостов и добавку к начальному времени
//    const std::string path = "D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/one.txt";
//    one.Gen_file(path); // генерирует таблицу данных
//    std::string new_path = one.tab_cleaner(path); // создает файл two.txt
////    cout<<new_path<<endl;

    Proizvodn pro(2); // выбираем хост, у которого считаем производные
    pro.gen_tab_proizvodn("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_host/level_1_dz_host/two.txt", pro); // генерирует таблицу производных

    return 0;
}
