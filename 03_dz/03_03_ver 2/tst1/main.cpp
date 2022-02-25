#include "part_1.h"
#include <stdio.h>
#include <math.h>

unsigned long long int N;
unsigned long long int N2;

int main()
{
   printf ("enter value:");
   scanf ("%llu", &N);

    part_1 (N);

    printf ("enter new value:");
    scanf ("%llu", &N2);

    int sum = 0;
    while (N2>0) // повторяется пока значение не станет ложным
      {
      N2 = N2/10;  // делит нашу N2 до момента пока значение не будет меньше 1 - т.е. 0,5 - это уже 0 = значит false
      sum = sum +1;  // считает сколько раз разделили до 0, потом добавляем 1
      }
      printf("sum = %u\n", sum); // вывод значения суммы

    return 0;
}
