#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {
    double *A, *B, *C;
    double start, end;
    int i;

    A = (double *)malloc(N * sizeof(double));
    B = (double *)malloc(N * sizeof(double));
    C = (double *)malloc(N * sizeof(double));

    for (i = 0; i < N; i++) {
        A[i] = i * 1.0;
        B[i] = i * 2.0;
    }

    start = omp_get_wtime();
    for (i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }
    end = omp_get_wtime();
    printf("Sequential Time: %f seconds\n", end - start);

    start = omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }
    end = omp_get_wtime();
    printf("Parallel Time: %f seconds\n", end - start);

    free(A);
    free(B);
    free(C);
}
