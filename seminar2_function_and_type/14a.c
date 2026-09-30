#include <stdio.h>

unsigned long long permutations(int n, int k)
{
    unsigned long long result = 1;

    for (int i = 0; i < k; i++)
        result *= (n - i);

    return result;
}

int main(void)
{
    int n, k;

    while (scanf("%d %d", &n, &k) == 2)
        printf("%llu\n", permutations(n, k));

    return 0;
}
