#include <omp.h>
#include <stdio.h>

int numt;

int main() {

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        if (tid == 0) {
            numt = omp_get_num_threads();
        }
    } 
    
    // implicit barrier here

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        printf("Hello World from Thread %d of %d\n", tid, numt);
    }
}