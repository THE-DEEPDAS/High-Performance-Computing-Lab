#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {
    int A[N];
    int max = 0;

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100000;
    }

    /*
    operation: variable
    max is predefined OpenMP reduction operator
    + is for sum
    */
    #pragma omp parallel for reduction(max:max)
    for (int i = 0; i < N; i++) {
        if (A[i] > max)
            max = A[i];
    }

    printf("Maximum value: %d\n", max);
}
