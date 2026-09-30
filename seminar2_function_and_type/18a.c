#include <stdio.h>
#include <math.h>

#define STEP 1e-2
#define EPS  1e-10

double gamma_func(double x)
{
    double sum = 0.0;
    double t = 0.0;

    double f_prev = pow(t, x - 1) * exp(-t);

    while (1)
    {
        double t_next = t + STEP;
        double f_next = pow(t_next, x - 1) * exp(-t_next);


        double trapezoid = (f_prev + f_next) / 2.0 * STEP;

        if (trapezoid < EPS)
            break;

        sum += trapezoid;

        t = t_next;
        f_prev = f_next;
    }

    return sum;
}

int main(void)
{
    double x;
    scanf("%lf", &x);
    printf("%g\n", gamma_func(x));
    return 0;
}
