#include "part_task_4.h"
#include <stdio.h>
#include <stdlib.h>

int part_task_4(int* matr, int x, int y)
{
    int sumA = 0;

    for(int j = 0; j < y; ++j)
    {
        for(int i = 0; i <x - j-1; ++i)
        {
            sumA = sumA + *(matr +j*x + i);
        }
    }
    return sumA;
}
