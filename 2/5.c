#include <omp.h>
#include <stdio.h>

int numt;

int main()
{
    #pragma omp parallel
    {
        int tid = omp_get_thread_num();

        # pragma omp single nowait
        numt = omp_get_num_threads();

        printf("Hello World from Thread %d of %d\n", tid, numt);
    }
}