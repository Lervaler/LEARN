#include "part_task_4.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../04_task_4/part_task_4.h"

int part_task_4 (int* val, int* val2)
{
  int *x = val;
  int *y =  val2;
    int A[*x][*y];

int sumA = 0;
for (int i = 0; i < *x; ++i)
{
    for (int j = 0; j < *y; ++j)
    {
        A[i][j] = rand ()% 10;
        printf ("%2d ", A[i][j]);
    }
    printf ("  \n");
}
for (int j = 0; j < *y; ++j)
{
    for (int i = 0; i <*x - j-1; ++i)
    {
        sumA = sumA + A[j][i];
    }
}
return sumA;
}



