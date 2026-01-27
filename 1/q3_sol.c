#include <stdio.h>
#include <omp.h>

int main() {
    int tid;

    #pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();
        for (long i = 0; i < 100000000; i++);
        printf("Hello World from thread %d\n", tid);
    }
}
