#include <stdio.h>
#define MAX 100
#define N 10

void multiply(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

int main(void)
{
    float A[MAX][MAX] = {{0}};
    float B[MAX][MAX] = {{0}};
    float C[MAX][MAX] = {{0}};

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%f", &A[i][j]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%f", &B[i][j]);

    multiply(A, B, C, N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%g ", C[i][j]);
        printf("\n");
    }

    return 0;
}
