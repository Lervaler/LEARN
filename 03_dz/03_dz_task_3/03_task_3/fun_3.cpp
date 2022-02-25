
#include <stdio.h>
#include <cmath>

int fun_3 (int R)
{
    int m;
    m = log10 (R) +1;                             // тут считаем количество знаков в числе
    int first = R / pow (10, (m - 1));            // первое
    int last = R % 10;                            // последнее
    int middle = (R - first*pow (10, (m-1)))/10;  // серединка
    int res = printf("%d%d%d", last, middle, first);
    return (res);
}
