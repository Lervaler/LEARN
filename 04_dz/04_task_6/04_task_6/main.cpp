//Дана строка символов. Определить, является ли она правильным скобочным выражением.
#include <stdio.h>
#include<string.h>

int main()
{
    int ch;
    int a = 0;
    printf("enter skobocki: ");

    do
    {
        ch = getchar();
        if (ch == '(')
        a++;
        else if (ch == ')' && --a < 0)
        break;
    }
    while (ch != '\n');

    if (a == 0)
    printf("true \n");
    else
    printf("false \n");

    return 0;
}
