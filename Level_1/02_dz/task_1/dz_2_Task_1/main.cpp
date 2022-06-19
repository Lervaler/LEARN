#include <stdio.h>
#include <math.h>

int main()
{

    double x;        // наша переменная
    double y;     // Итоговое значение уравнения
    double S;     //  синус

    printf("ENTER value of x = ");

    scanf ("%lf", &x);

    double c = x - (M_PI/6);     // с - зачение косинуса в градусах (кусок из формулы)

 //   double a = (c*M_PI)/180;    // а - это певод в радианы значения косинуса

    double K = sqrt (2);      // К - это корень из двух

    double LN = 1 / (2 * log (x));   // Ln naturalьный логарифм (сразу в значении куска из формулы)

    double Z = pow (x, 2); // квадрат х

    S = sin(Z);            // синус от квадрата х

    double z = pow (S, 2); // квадрат синуса квадратного х

    double E = exp (3 * x);  // e в степени 3х

    y = (((2 * cos (c)) +sqrt (2)) / (LN + z)) * E;   // наша задача

     printf("ANSWER IS y = %f\n", y);
     printf("\n CHECK YOURSELF \n");
     printf("K = %f\n", K);
     printf("LN = %f\n", LN);
     printf("sinx2 = %f\n", S);
     printf("sin2x2 = %f\n", z);
     printf("exp3x = %f\n", E);

    return 0;
}
