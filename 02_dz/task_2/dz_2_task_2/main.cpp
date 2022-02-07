#include <stdio.h>
#include <math.h>

int main()
{
   double r, a, d;

   printf("ENTER VALUE FOR circle radius (r): \n");
   scanf ("%lf", &r);

   printf("ENTER VALUE FOR side of triangle (a): \n", &a);
   scanf ("%lf", &a);

   printf("ENTER VALUE FOR side of square (d): \n", &d);
   scanf ("%lf", &d);

   double S_cir = M_PI * pow (r, 2);

   double S_tr = ((sqrt (3)/4) * pow (a, 2));

   double S_sq = pow (d, 2);

   printf ("S_cir = %f \n", S_cir);
   printf ("S_tr = %f \n", S_tr);
   printf ("S_sq = %f \n", S_sq);

   double Res0 = (Res0 = (S_cir > S_tr) ? S_cir : S_tr) > S_sq ? Res0 : S_sq;

   printf("winner is: %f \n", Res0);

   if (S_cir > S_tr & S_cir > S_sq) printf ("The bigges figure is CIRCLE\n");
   else if  (S_tr > S_cir & S_tr > S_sq) printf ("The bigges figure is TRIANGLE\n");
   else if  (S_sq > S_tr & S_sq > S_cir) printf ("The bigges figure is SQUARE\n");

   return 0;
}
