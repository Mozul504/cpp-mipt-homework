#include <stdio.h>
#include <stddef.h>

void mult2(int* p, size_t n)
{
    for (size_t i = 0; i < n; i++)
        p[i] *= 2;
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};
    size_t n = sizeof(a) / sizeof(a[0]);

    mult2(a, n);

    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
