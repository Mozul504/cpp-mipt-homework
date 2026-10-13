#include <stdio.h>

void cube(float* px)
{
    *px = (*px) * (*px) * (*px);
}

int main(void)
{
    float x = 2.0f;
    printf("До:    %.2f\n", x);
    cube(&x);
    printf("После: %.2f\n", x);

    float y = 3.0f;
    cube(&y);
    printf("3^3 = %.2f\n", y);

    return 0;
}
