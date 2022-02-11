//Найти сумму ряда с точностью сточностью 10^-5, где 0.05<x<1


#include <math.h>
#include <stdio.h>

int main()
{
    const double eps = 1e-5;
    double sum = 0;
    double step = 0;
    double x = 0;

    printf("Please enter x (0,05 < x < 1): ");
    scanf("%lf", &x);

    if ((0.05 < x) && (x < 1))
    {
        for(int i = 0; true; ++i)
        {
            int fuk = 1;// факториал i
            if (i%2 == 0)
            {
            for(int j=2; j<=i; j+=2)
            {
            fuk = fuk*j;
            }
            printf ("fuk = %d", fuk);
            }
                else
                {
                for(int j=1; j<=i; j+=2)
                {
                fuk = fuk*j;
                }
                printf ("fuk = %d", fuk);
                }
            int fuk2 = 1;// факториал i - 1
            if ((i-1)%2 == 0)
            {
            for(int j=2; j<=(i-1); j+=2)
            {
            fuk2 = fuk2*j;
            }
            printf ("fuk2 = %d", fuk2);
            }
                else
                {
                for(int j=1; j<=(i-1); j+=2)
                {
                fuk2 = fuk2*j;
                }
                printf ("fuk2 = %d", fuk2);
                }

    step = x + ( pow (x,3)/ (2*3) ) + ((1*3 * pow (x, 5))/ 2* 4 * 5) + ((fuk2* pow(x,(2*i +1)))/fuk*(i+1));
    if (step < eps)
    break;
    sum += step;
        }
    }

    printf("Result summ is: %f\n", sum);

    return 0;
}
