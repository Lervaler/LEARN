// Перевести число из десятичной системы счисления в двоичную.

#include <stdio.h>

int main()
{
int N;
    printf ("enter value: \n");
    scanf ("%d", &N);

    int a = 0;
    int b = 1;
    while (N > 0)
    {
    a = a + (N%2)*b;
    N = N/2;
    b = b*10;
    printf ("value: %d\n", a);
    }

   // int sum = 0;
   for (int i = 0; i <= 31 ; ++i)  // ЭТО НЕ РАБОТАЕТ
   {
       N = ((N << i) & 1);
       ++i;
       printf ("result: %d\n", N);
   }

    return 0;
}
