#include "convert_word_my.h"
#include "My_string.h"
#include <iostream>

My::String convert_word_my (My::String& word)
{
    My::String new_word {""};

    for (const char& ch: word)
    {
        if(std::isalpha(ch) || std::isdigit(ch) || ch == ' ')
            new_word += std::toupper(ch);
    }
    word = new_word;

    return word;
}
