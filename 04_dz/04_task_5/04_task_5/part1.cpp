#include "part1.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
void part1(const char* src, char* dest)
{

    const char* str = src;
    char* result_str = dest;

 //    if (src == 0 || dest == 0)
//          return;
    for (unsigned int i = 0; i <strlen (str); )
    {
        char* word [255]= {};
  //   *word [254] = '\0';
        sscanf(str +i, "%s", word);
            if ( (strlen ((char*)word)%2) == 0)
               {
                strncat (result_str, (char*)word, sizeof (str));
                strncat (result_str, " ", sizeof(str));
                }
        i= i + strlen((char*)word) +1;
    }
    printf ("%s ", result_str);
//    *result_str = '\0';
}


