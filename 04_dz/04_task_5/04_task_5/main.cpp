//Дана строка символов. Удалить из нее все слова нечетной длины.
//Слова отделяются друг от друга одним пробелом.

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
    char str [50] = {};
    char result_str [50] = {};

    gets (str);
    char* word;
    printf ("deleted ne-chetnye \n");

    char sep [10] = " ";
    word = strtok(str, sep);

    while (word != nullptr)
    {
     //printf ("word is %s \n", word);
        word = strtok (nullptr, sep);
            if (word != nullptr && (strlen(word))%2 == 0)
            {
                 strcpy (result_str, word);
                 printf ("%s ", result_str);
            }
    }

    return 0;
}

