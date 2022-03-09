#include "part1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void part1(const char* src, char* dest)
{
    const char* str = src;
    char* result_str = dest;

    for(unsigned int i = 0; i <strlen(str); )
    {
        char word[255]= {};
//        *word[254] = '\0';
        sscanf(str +i, "%s", word);
            if((strlen(word)%2) == 0)
            {
                 strncat(result_str, word, sizeof(word));
                 strncat(result_str, " ", sizeof(word));
            }
                i= i + strlen(word) +1;
    }

    printf("%s ", result_str);
//    *result_str = '\0';
}


