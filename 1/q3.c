#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main() {
    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        for(int i = 0; i < 200000000; i++);
        printf("Hello World from %d\n", tid);
    }
    return 0;
}
