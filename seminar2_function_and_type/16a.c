#include <stdio.h>

int main(void)
{
    int n;
    double sum = 0.0;
    int sign = 1;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        sum += sign * (1.0 / (2 * i - 1));
        sign = -sign;   // чередуем знак: +, -, +, -, ...
    }

    printf("%f\n", 4.0 * sum);
    return 0;
}
