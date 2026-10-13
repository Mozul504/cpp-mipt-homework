#include <stdio.h>
#include <math.h>

int solve_quadratic(double a, double b, double c, double* px1, double* px2)
{
    const double eps = 1e-10;

    if (fabs(a) < eps)
    {
        if (fabs(b) < eps)
            return 0;
        *px1 = -c / b;
        return 1;
    }

    double D = b * b - 4 * a * c;

    if (D < -eps)
        return 0;

    if (fabs(D) < eps)
    {
        *px1 = -b / (2 * a);
        return 1;
    }

    *px1 = (-b - sqrt(D)) / (2 * a);
    *px2 = (-b + sqrt(D)) / (2 * a);
    return 2;
}

int main(void)
{
    double x1, x2;

    // x^2 - 5x + 6 = 0  →  корни 2 и 3
    int n = solve_quadratic(1, -5, 6, &x1, &x2);
    printf("n=%d, x1=%.4f, x2=%.4f\n", n, x1, x2);

    // x^2 - 4x + 4 = 0  →  один корень 2
    n = solve_quadratic(1, -4, 4, &x1, &x2);
    printf("n=%d, x1=%.4f\n", n, x1);

    // x^2 + x + 1 = 0  →  нет корней
    n = solve_quadratic(1, 1, 1, &x1, &x2);
    printf("n=%d\n", n);

    return 0;
}
