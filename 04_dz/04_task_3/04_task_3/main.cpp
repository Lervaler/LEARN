//Дана матрица размером 7х7. Поменять местами k-й столбец с k-ой строкой.

#include <stdio.h>
#include <stdlib.h>


int main()
{
    constexpr int X = 7;
    constexpr int Y = 7;
    int A[X][Y];
    int index_X = 0;
    int index_Y = 0;
    int k;
    srand(100);

    for (int i = 0; i < X; ++i)
    {
        for (int j = 0; j < Y; ++j)
        {
            A [i][j] = rand ()% 10;
            printf ("%2d ", A[i][j]);
        }
    printf ("  \n");
    }

    printf ("Enter number of column to replace same line: ");
    scanf ("%d", &k);

    for (int i = 0; i < X; ++i)
    {
        for (int j = 0; j < Y; ++j)
        {
            if (i == k)
            {
            index_X = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = index_X;
            }
         }
    }
    printf ("  \n");

    for(int i = 0; i < X; ++i)
       {
           for(int j = 0; j < Y; ++j)
           {
               printf("%2d ", A[i][j]);
           }
           printf("\n");
      }

    return 0;
}
