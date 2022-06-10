#include "convert_word_my.h"
#include "My_string.h"
#include <iostream>

My::String convert_word_my (My::String& word)
{
    My::String new_word(" ");
    const char* ch = 0;
    for (char i = 0; i < word.size(); ++i)
       {
        ch = word.c_str()+i;
           if (std::isalpha(*ch) || std::isdigit(*ch))
           {
               std::toupper(*ch);
               new_word.append(ch);
           }
       }

    return new_word;
}
