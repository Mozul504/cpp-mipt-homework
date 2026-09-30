#include <stdio.h>
#include <math.h>

int main(void)
{
    double x1, y1, r1;
    double x2, y2, r2;

    scanf("%lf %lf %lf", &x1, &y1, &r1);
    scanf("%lf %lf %lf", &x2, &y2, &r2);

    double dx = x2 - x1;
    double dy = y2 - y1;
    double d = sqrt(dx * dx + dy * dy);

    const double EPS = 1e-5;

    double sum = r1 + r2;
    double diff = fabs(r1 - r2);

    if (fabs(d - sum) < EPS || fabs(d - diff) < EPS)
        printf("Touch\n");
    else if (d > sum || d < diff)
        printf("Do not intersect\n");
    else
        printf("Intersect\n");

    return 0;
}
