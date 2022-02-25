
//Поменять местами цифры старшего и младшего разрядов данного натурального числа
//(например, из числа 3879 получится 9873).
#include "fun_3.h"
#include <stdio.h>
#include <cmath>

int main()
{
    int N;
    printf ("enter value: \n");
    scanf ("%d", &N);

    int value = fun_3 (N);

    printf ("\n", value);
    return 0;
}


