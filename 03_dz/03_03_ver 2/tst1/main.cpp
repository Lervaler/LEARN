#include <stdio.h>
#include <math.h>

unsigned long long int N;
unsigned long long int N2;

int main()
{
   printf ("enter value:");
   scanf ("%llu", &N);

   int m = 0;
    if (N >= 1)  // если N больше или равно 1 - делает по формуле и дает ответ
    {
    m = log10 (N) +1;
    printf ("Kol-vo znakov = %u \n", m);
    }
    else printf ("warning: don't input <= 0\n"); // если ввели всякую фигню или меньше 1

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
