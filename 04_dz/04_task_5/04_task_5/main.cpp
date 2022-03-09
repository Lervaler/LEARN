//Дана строка символов. Удалить из нее все слова нечетной длины.
//Слова отделяются друг от друга одним пробелом.
#include "part1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[50] = {};
    char result_str[50] = {};
    gets(str);
    printf("deleted ne-chetnye \n");
    part1(str, (char*)&result_str);

    return 0;
}

