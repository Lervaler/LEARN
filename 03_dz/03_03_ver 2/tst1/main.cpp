#include <stdio.h>
#include <math.h>

unsigned int N;

int main()
{
   printf ("enter value:");
   scanf ("%u", &N);

   int m = 0;
    if (N >= 1)
    {
    m = log10 (N) +1;
    printf ("Kol-vo znakov = %u \n", m);
    }
    else printf ("WTF???\n");

    return 0;
}
