#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 4000

int main()
{
    static double A[N][N], x[N], y[N];
    double start, end;

#pragma omp parallel for
    for (int i = 0; i < N; i++)
    {
        x[i] = 1.0;
        y[i] = 0.0;
        for (int j = 0; j < N; j++)
            A[i][j] = 1.0;
    }

    start = omp_get_wtime();

#pragma omp parallel for
    for (int i = 0; i < N; i++)
    {
        double sum = 0.0;
        for (int j = 0; j < N; j++)
        {
            sum += A[i][j] * x[j];
        }
        y[i] = sum; // each thread writes to its own yi
    }

    end = omp_get_wtime();
    printf("Row-wise time: %f seconds\n", end - start);
}
