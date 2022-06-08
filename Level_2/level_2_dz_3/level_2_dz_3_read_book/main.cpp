#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "convert_word.h"

int main()
{
    std::string path;
    std::string book;
    path = "D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_3/";
    std::cout <<"Enter your book: " << std::endl;
    std::cin>>book;
    path += book;
    std::ifstream file(path);
    std::string word;

    std::unordered_map<std::string, int> count_map;
    count_map.reserve(1'000'000);

    while(file)
    {
        file >> word;
       std::string new_word = convert_word(word);
        if(!new_word.empty())
        {
            ++count_map[new_word];
        }
    }
    std::fstream file_2;
    file_2.open("file:///D:/01_Projects/HomeWork/LEARN/LEARN/Level_2/level_2_dz_3/hello.txt");
// std::string str;
  //  while (count_map)
  //  {
        for(const auto& value: count_map)
        {
            std::string str(value.first, value.second);
 //                   >> value.first >> " : " >> value.second >> std::endl;
         }
  //  }



//  for(const std::pair<std::string, int>& value: count_map)
//  {
//      file_2<<value.first << " : " << value.second << std::endl;
////       std::cout << value.first << " : " << value.second << std::endl;
//  }
//std::unordered_map<std::string, int> it = count_map.find("IT");
//    std::cout << << std::endl;

file_2.close();
    return 0;
}
