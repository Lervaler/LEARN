#include "search.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <ctime>

void search (const std::string& word, std::unordered_map<std::string, int>& count_map)
{
    int key = 0;
    std::clock_t clock_1 = std::clock();
    for(const std::pair<std::string, int>& value: count_map)
     {
        if (word == value.first)
         {
             key = value.second;
         }

     }
    std::clock_t clock_2 = std::clock();
//    std::cout<< "time spend for search: "<< 1'000'000*(clock_2 - clock_1)/CLOCKS_PER_SEC <<std::endl;
    std::cout << "number of times in book: "<< key << " / time for search: " <<1'000'000*(clock_2 - clock_1)/CLOCKS_PER_SEC << std::endl;
 //return std::cout << key << " / time: " <<1'000'000*(clock_2 - clock_1)/CLOCKS_PER_SEC << std::endl;
}
