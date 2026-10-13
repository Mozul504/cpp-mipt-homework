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
