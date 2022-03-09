// Поменять местами максимальный и последний отрицательный элементы массива M(40).

// #include <time.h> - использовать если делать рандом от времени
#include <stdlib.h>
#include <stdio.h>

int main()
{
    constexpr int size = 40;
    int M [size];
    int updated_M [size];
    int index_updated_M = 0;
    int max = 0;    //максимальное число
    int last_min = 0;    //последнее отрицательное
    srand(1000);    //надо разобраться с srand и  rand  (при отключении просто меняется рандом)

    for (int i = 0; i < size; ++i)
    {
        M [i] = rand ()% 1000 - 500;    //делаем рандом
        printf ("%d ", M[i]);
    }
        printf ("\n");

    for (int i = 0; i<size; ++i)    // считаем максимум
    {
        if (M[i] > max && M[i] < 1000 && M[i] > 0)    // тут меньше 1000 потому что я знаю диапазон, как сделать для любого диапазона??
        {
            max = M[i];
        }
    }
        printf ("max = %d\n", max);

    for (int i = 0; i < size; ++i)    // считаем минимум
    {
        if ( M[i] < 0 )
        {
            last_min = M[i];
        }
    }
        printf ("last min = %d\n", last_min);

    for(int i = 0; i <size; ++i)    // меняем местами минимум и максимум
    {
        if (M[i] == max)
            updated_M [index_updated_M] = last_min;
        else if (M[i] == last_min)
            updated_M [index_updated_M] = max;
        else updated_M [index_updated_M] = M[i];
            ++index_updated_M;
    }

    for(int i = 0; i < index_updated_M; ++i)    // результат
        printf ("%d ", updated_M [i]);

    printf ("\n");
    return 0;
}
