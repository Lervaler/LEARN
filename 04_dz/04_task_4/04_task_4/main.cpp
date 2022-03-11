//Вычислить сумму элементов матрицы лежащих слева от побочной диагонали.
#include "part_task_4.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Mass[2][3] = { {1, 2, 3}, {4, 5, 6} };

    printf("SUMM = %d ", part_task_4((int*)Mass, 2, 3));
    printf("\n");

    return 0;
}
