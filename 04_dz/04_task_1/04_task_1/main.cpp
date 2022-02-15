// Поменять местами максимальный и последний отрицательный элементы массива M(40).

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    constexpr int size = 40;
    int M [size];
//    int updated_M [size];
//    int index_updated_M = 0;

    srand(10% - 100);        // почему тут Srand, а дальше по тексту rand . Это одно и тоже??

    for ( int i = 0; i < size; ++i)
    {
        M [i] = rand ()% 100 - 50;
        printf ("%d ", M[i]);
    }
    printf ("\n");

    int max = 0;             //максимальное число
    int last_min = 0;        // последнее отрицательное

    for (int i = 0; i<100; i++)
     {
        if (M[i] > max && M[i] <100 && M[i]>0)
        {
         max = M[i];
        }
      }
      printf ("max = %d\n", max);

       for (int i = 0; i < 40; ++i)
       {
           if ( M[i] < 0 )   //
           {
           last_min = M[i];
           }
        }
       printf ("last min = %d\n", last_min);

    return 0;
}
