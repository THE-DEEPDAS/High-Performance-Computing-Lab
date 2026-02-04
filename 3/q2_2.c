#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 4000

int main() {
    static double A[N][N], x[N], y[N];
    double start, end;

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        x[i] = 1.0;
        y[i] = 0.0;
        for (int j = 0; j < N; j++)
            A[i][j] = 1.0;
    }

    start = omp_get_wtime();

    #pragma omp parallel for
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            #pragma omp critical
            {
                y[i] += A[i][j] * x[j]; // common che aa yi across threads
            }
        }
    }

    end = omp_get_wtime();
    printf("Column-wise time: %f seconds\n", end - start);
}
