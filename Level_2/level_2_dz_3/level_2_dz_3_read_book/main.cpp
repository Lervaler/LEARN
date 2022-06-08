#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <ctime>
#include "convert_word.h"
#include "by_map.h"

int main()
{
    std::string path;
    std::string book;
    path = "D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_3/";
    std::cout <<"Hello, user!"<<std::endl<<"Enter your book: " << std::endl;
    std::cin>>book;
    path += book;

    std::clock_t clock_1 = std::clock();

    std::unordered_map<std::string, int> count_map = by_map(path);

    std::clock_t clock_2 = std::clock();
    std::cout<< "time spend: "<< 1'000'000*(clock_2 - clock_1)/CLOCKS_PER_SEC <<std::endl;

    std::cout <<"what are you looking for? "<<std::endl<<"Enter word for search: " << std::endl;
    std::string word;
    std::cin>>word;
    std::clock_t clock_3 = std::clock();

 //  std::cout<< count_map.find(word)<< std::endl;
   for(const std::pair<std::string, int>& value: count_map)
    {
       if (word == value.first)
         std::cout << value.first << " : " << value.second << std::endl;
    }
   std::clock_t clock_4 = std::clock();
   std::cout<< "time spend for search: "<< 1'000'000'000*(clock_4 - clock_3)/CLOCKS_PER_SEC <<std::endl;




//  for(const std::pair<std::string, int>& value: count_map)
//  {
//       std::cout << value.first << " : " << value.second << std::endl;
//  }


    return 0;
}
