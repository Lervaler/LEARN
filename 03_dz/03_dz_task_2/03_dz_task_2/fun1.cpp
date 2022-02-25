

#include <stdio.h>
#include <math.h>

int fun(int N1, int N2, int N3)
{
int a = fmin (N1, N2); // опеределяем меньшее число
int b = fmin (a, N3); // победитель минимальной олимпиады
int result = 0;
for ( int i = b; i >1; --i)
{
    if ((N1%i == 0) && (N2%i == 0) && (N3%i == 0))
        result = i;
    else result = 1;
}
return result;
}
