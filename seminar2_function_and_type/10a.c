#include <stdio.h>
#define MAX 100

void assign(float A[MAX][MAX], float B[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = B[i][j];
}

int main(void)
{
    float A[MAX][MAX] = {{0}};
    float B[MAX][MAX] = {
        {1.5, 2.5, 3.5},
        {4.5, 5.5, 6.5},
        {7.5, 8.5, 9.5}
    };

    assign(A, B, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%.1f ", A[i][j]);
        printf("\n");
    }

    return 0;
}
