#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int hight = 10;
    int dlina = 10;
    int x_exit = 3;
    int y_exit = 3;
    int x = 6;
    int y = 6;

while (true)
{
for(int i=0; i != hight; i++)
    {
         for (int j = 0 ; j != dlina; j++)
         {
             if ((i == 0) || (i == hight-1) || (j == dlina-1) || (j == 0))
             {
             printf("*");
             }
             else if ((i == x) && (j == y))
             {
              printf ("$");
             }
             else if ((i == x_exit) && (j == y_exit))
             {
              printf ("@");
             }
             else  printf(" ");
          }
     printf ("\n");
    }

    int z;
    printf ("where are we goin to?");
    scanf ("%u", &z);
    switch (z)
    {
    case 1: x = x + 1;
    break;
    case 2: x = x - 1;
    break;
    case 3: y = y - 1;
    break;
    case 4: y = y + 1;
    break;
    }
    system("cls");
}
    return 0;
}
