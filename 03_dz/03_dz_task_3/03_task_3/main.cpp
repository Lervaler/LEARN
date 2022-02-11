
//Поменять местами цифры старшего и младшего разрядов данного натурального числа
//(например, из числа 3879 получится 9873).

#include <stdio.h>
#include <cmath>

int main()
{
    int N;
    printf ("enter value: \n");
    scanf ("%d", &N);

    int m;
    m = log10 (N) +1;                             // тут считаем количество знаков в числе
//    printf ("m = %d\n", m);                     // проверочное

    int first = N / pow (10, (m - 1));            // первое
    int last = N % 10;                            // последнее
    int middle = (N - first*pow (10, (m-1)))/10;  // серединка

//    printf ("first = %d\n", first);             // проверочное
//    printf ("last = %d\n", last);               // проверочное
//    printf ("middle = %d\n", middle);           // проверочное

    printf ("%d%d%d\n", last, middle, first);
    return 0;
}
