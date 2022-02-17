//Вычислить сумму элементов матрицы лежащих слева от побочной диагонали.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    constexpr int X = 5;
    constexpr int Y = 5;
    int A[X][Y];
    int sum = 0;
    int sumA = 0;
    srand(100);

    for (int i = 0; i < X; ++i)                    //делаем матрицу и рандом
    {
        for (int j = 0; j < Y; ++j)
        {
            A[i][j] = rand ()% 10;
            printf ("%2d ", A[i][j]);
        }
        printf ("  \n");
    }

    printf ("numbers from left diag: \n");             //вывод значений слева от побочной диагонали
    for (int j = 0; j < Y; ++j)
    {
        for (int i = 0; i < X - j-1; ++i)
        {
            printf("%2d ", A [i][j]);
        }
    }
    printf ("  \n");

    printf ("Beautiful numbers from left diag: \n");        //вывод значений слева от побочной диагонали в виде матрицы
    for (int j = 0; j < Y; ++j)
    {
        for (int i = 0; i < X - j-1; ++i)
        {
            sum = A[j][i];
            printf("%2d ", sum);
        }
        printf("\n");
    }

    printf ("Sum from left diag: \n");                  // считаем сумму
    for (int j = 0; j < Y; ++j)
    {
        for (int i = 0; i < X - j-1; ++i)
        {
            sumA = sumA + A[j][i];
        }
    }
    printf("%d ", sumA);                                 // выводим сумму
    printf("\n");
    return 0;
}
