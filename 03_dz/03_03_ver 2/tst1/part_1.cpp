#include "part_1.h"
#include <stdio.h>
#include <math.h>

int part_1 (int *value)
{
    int* Z = value;
    int m = 0;
        if (*Z >= 1)  // если N больше или равно 1 - делает по формуле и дает ответ
        {
             m = log10 (*Z) +1;
             printf ("Kol-vo znakov = %u \n", m);
        }
        else printf ("warning: input singned value\n"); // если ввели всякую фигню или меньше 1
    return m;
}

