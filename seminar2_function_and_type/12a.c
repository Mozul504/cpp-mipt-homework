#include <stdio.h>
#define MAX 100

void assign(int A[MAX][MAX], int B[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = B[i][j];
}

void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

void power(int A[MAX][MAX], int C[MAX][MAX], int n, int k)
{
    int B[MAX][MAX];      
    int T[MAX][MAX];      

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = (i == j) ? 1 : 0;

    assign(B, A, n);

    while (k > 0)
    {
        if (k & 1)                    
        {
            multiply(C, B, T, n);     
            assign(C, T, n);         
        }

        k >>= 1;                     

        if (k > 0)                    
        {
            multiply(B, B, T, n);     
            assign(B, T, n);         
        }
    }
}
