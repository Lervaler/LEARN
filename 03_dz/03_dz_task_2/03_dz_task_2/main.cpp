//Найти наименьший общий делитель трех натуральных чисел
// (1 будет считаться наименьшим общим делителем только в том случае,
//когда других общих делителей у заданных чисел нет).
#include "fun_1.h"
#include <stdio.h>
#include <math.h>


int main()
{
    int N1, N2, N3;

    printf ("Enter natural value 1: ");
    scanf ("%d", &N1);
    printf ("Enter natural value 2: ");
    scanf ("%d", &N2);
    printf ("Enter natural value 3: ");
    scanf ("%d", &N3);

    int Delitel = fun (N1, N2, N3);
    printf ("delitel is - %d\n", Delitel);
    return 0;
}
