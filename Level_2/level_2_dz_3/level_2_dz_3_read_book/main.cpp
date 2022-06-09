#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <ctime>
#include "convert_word.h"
#include "by_map.h"
#include "search.h"

int main()
{
    std::string path;
    std::string book;
    path = "D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_3/";
    std::cout <<"Hello, user!"<<std::endl<<"Enter your book: ";
    std::cin>>book;
    path += book;

    std::clock_t clock_1 = std::clock();
    std::unordered_map<std::string, int> count_map = by_map(path);
    std::clock_t clock_2 = std::clock();
    std::cout<< "time spend: "<< 1'000'000*(clock_2 - clock_1)/CLOCKS_PER_SEC << "ms"<<std::endl;



    std::cout <<"Enter word for search: ";
    std::string word;
    std::cin>>word;

     search (word, count_map);

    return 0;
}
