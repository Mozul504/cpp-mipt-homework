#include <stdio.h>

void print_even(int a, int b)
{
    int start = a;
    if (start % 2 != 0)   
        start++;         

    for (int i = start; i <= b; i += 2)
        printf("%d ", i);

    printf("\n");
}
