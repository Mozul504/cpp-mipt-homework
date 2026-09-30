#include <stdio.h>

void alice(int n);
void bob(int n);

void alice(int n)
{
    n = 3 * n + 1;
    printf("Alice: %d\n", n);
    bob(n);
}

void bob(int n)
{
    while (n % 2 == 0)
    {
        n = n / 2;
        printf("Bob: %d\n", n);
    }

    if (n == 1)
        return;

    alice(n);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    alice(n);
    return 0;
}
