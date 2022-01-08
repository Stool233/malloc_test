#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>


#define K (1024)
#define MAXNUM 500000

int main() {

    printf("Welcome to memory leak example::%d\n", getpid());

    char *ptrs[MAXNUM];
    int i;
    // malloc large block memory
    for (int i = 0; i < MAXNUM; i++) {
        ptrs[i] = (char *)malloc(1 * K);
        memset(ptrs[i], 0, 1 * K);
    }
    // never free only 1B memory leak, what it will impact to the system?
    char *tmp1 = (char *)malloc(1);
    memset(tmp1, 0, 1);

    printf("%s\n", "malloc done");
    getchar();

    printf("%s\n", "start free memory");

    // for (i = 0; i < MAXNUM; i++) {
    //     free(ptrs[i]);
    // }
    // reverse work?
     for (i = MAXNUM-1; i >= 0; i--) {
        free(ptrs[i]);
    }
    printf("%s\n", "free done");

    getchar();

    return 0;
}