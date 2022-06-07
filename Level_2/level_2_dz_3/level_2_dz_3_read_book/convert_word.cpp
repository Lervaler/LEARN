#include "convert_word.h"
#include <string>

std::string convert_word (const std::string& word)
{
    std::string new_word;
    for (const char& ch: word)
    {
        if(std::isalpha(ch) || std::isdigit(ch))
            new_word += std::toupper(ch);
    }
    return new_word;
}
