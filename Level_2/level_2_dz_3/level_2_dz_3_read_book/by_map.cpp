#include "by_map.h"
#include "convert_word.h"
#include <fstream>

std::unordered_map<std::string, int> by_map (std::string path)
{
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
    return count_map;
}
