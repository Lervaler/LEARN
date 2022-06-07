#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "convert_word.h"

int main()
{
    std::ifstream file("D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_3/It.txt");
    std::string word;

//    word.reserve(50000);

    std::unordered_map<std::string, int> count_map;
    count_map.reserve(1000000);

    while(file)
    {

        file >> word;
       std::string new_word = convert_word(word);
        if(!new_word.empty())
        {
            ++count_map[new_word];
        }
    }

   for(const std::pair<std::string, int>& value: count_map)
   {
        std::cout << value.first << " : " << value.second << std::endl;
   }

 //   std::cout << count_map.count("IT")<< std::endl;


    return 0;
}
