#define _GNU_SOURCE

#include <dlfcn.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <math.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/timeb.h>
#include <sys/time.h>
#include <fcntl.h>
#include <errno.h>

// get thread id 
static pid_t gettid() {
    return syscall(__NR_gettid);
}

typedef void *(*malloc_pfn_t)(size_t size);
static malloc_pfn_t orig_malloc_func = NULL;


void *malloc(size_t size) {
    if (!orig_malloc_func) {
        orig_malloc_func = dlsym(RTLD_NEXT, "malloc");
        if (!orig_malloc_func) {
            return NULL;
        }
    }
    void *p;
    p = orig_malloc_func(size);

    fprintf(stderr, "[%d] [] [] malloc(%u)\t= 0x%08x \n", gettid(), size, p);
    return p;
}