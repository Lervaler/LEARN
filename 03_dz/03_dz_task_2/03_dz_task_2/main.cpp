//Найти наименьший общий делитель трех натуральных чисел
// (1 будет считаться наименьшим общим делителем только в том случае,
//когда других общих делителей у заданных чисел нет).

#include <stdio.h>
#include <math.h>

int main()
{
int N1, N2, N3;

printf ("Enter natural value 1: ");
scanf ("%d", &N1);
printf ("Enter natural value 2: ");
scanf ("%d", &N2);
printf ("Enter natural value 3: ");
scanf ("%d", &N3);


if ( (N1 > N2) && (N2 > N3) )
{ int i = N3;
do
{
  N1 = N1%i;
  N2 = N2%i;
  N3 = N3%i;
  -i;
  printf ("resultat = %u \n", i);
}
while ((N1%i == 0) && (N2%i == 0) && (N3%i == 0));
}


if  ((N1 % 2 == 0) && (N2 % 2 == 0) && (N3 % 2 == 0))
printf ("delitel is - 2 \n");
if ((N1 % 3 == 0) &&  (N2 % 3 == 0) && (N3 % 3 == 0))
printf ("delitel is - 3 \n");
if ((N1 % 4 == 0) && (N2 % 4 == 0) && (N3 % 4 == 0))
printf ("delitel is - 4 \n");
if ((N1 % 5 == 0) && (N2 % 5 == 0) && (N3 % 5 == 0))
printf ("delitel is - 5 \n");
if ((N1 % 6 == 0) && (N2 % 6 == 0) && (N3 % 6 == 0))
printf ("delitel is - 6 \n");
if ((N1 % 7 == 0) && (N2 % 7 == 0) && (N3 % 7 == 0))
printf ("delitel is - 7 \n");
if ((N1 % 8 == 0) && (N2 % 8 == 0) && (N3 % 8 == 0))
printf ("delitel is - 8 \n");
if ((N1 % 9 == 0) && (N2 % 9 == 0) && (N3 % 9 == 0))
printf ("delitel is - 9 \n");
else ((N1 % 1 == 0) && (N2 % 1 == 0) && (N3 % 1 == 0));
printf ("delitel is - 1 \n");

    return 0;
}
