#include <omp.h>
#include <stdio.h>

int numt;
int tid;

#pragma omp threadprivate(tid)
int main() {

    #pragma omp parallel
    {
        tid = omp_get_thread_num();

        if (tid == 0) {
            numt = omp_get_num_threads();
        }
    }   

    // implicit barrier here

    #pragma omp parallel
    {
        printf("Hello World from Thread %d of %d\n", tid, numt);
    }
}