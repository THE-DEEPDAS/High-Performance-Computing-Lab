#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <omp.h>

#define N 20000000

int main()
{
    double complex *A, *B;
    double complex dot_static = 0.0 + 0.0 * I;
    double complex dot_dynamic = 0.0 + 0.0 * I;

    double start, end;

    A = (double complex *)malloc(N * sizeof(double complex));
    B = (double complex *)malloc(N * sizeof(double complex));

#pragma omp parallel for
    for (long i = 0; i < N; i++)
    {
        A[i] = cos(i * 0.001) + sin(i * 0.002) * I;
        B[i] = sin(i * 0.003) + cos(i * 0.004) * I;
    }

    start = omp_get_wtime();

#pragma omp parallel for schedule(static) reduction(+ : dot_static)
    for (long i = 0; i < N; i++)
    {
        double complex temp = A[i] * B[i];

        if (i % 3 == 0)
        {
            for (int k = 0; k < 50; k++)
                temp += csin(temp) * ccos(temp);
        }
        else
        {
            for (int k = 0; k < 5; k++)
                temp += csqrt(temp);
        }

        dot_static += temp;
    }

    end = omp_get_wtime();
    printf("Static Scheduling Time: %f seconds\n", end - start);

    start = omp_get_wtime();

#pragma omp parallel for schedule(dynamic) reduction(+ : dot_dynamic)
    for (long i = 0; i < N; i++)
    {
        double complex temp = A[i] * B[i];

        if (i % 3 == 0)
        {
            for (int k = 0; k < 50; k++)
                temp += csin(temp) * ccos(temp);
        }
        else
        {
            for (int k = 0; k < 5; k++)
                temp += csqrt(temp);
        }

        dot_dynamic += temp;
    }

    end = omp_get_wtime();
    printf("Dynamic Scheduling Time: %f seconds\n", end - start);
}
