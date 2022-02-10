//Найти наименьший общий делитель трех натуральных чисел
// (1 будет считаться наименьшим общим делителем только в том случае,
//когда других общих делителей у заданных чисел нет).

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

    int a = fmin (N1, N2); // опеределяем меньшее число
    int b = fmin (a, N3); // победитель минимальной олимпиады

    for ( int i = b; i >1; --i) //
    {
        if ((N1%i == 0) && (N2%i == 0) && (N3%i == 0))
        printf ("result = %d \n", i);
        else printf ("result = 1\n");
    };
    return 0;
}
