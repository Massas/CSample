#include <stdio.h>
#include <threads.h>

mtx_t mtx;

int main(void)
{
    if(mtx_init(&mtx, mtx_plain) != thrd_success)
    {
        fputs("Error initializing the mutex.\n", stderr);
        return -1;
    }
    printf("Success: initializing the mutex.\n");
    mtx_destroy(&mtx);
    return 0;
}

/*
$ cc mtx_initSample.c
/usr/bin/ld: /tmp/cc6VCmf4.o: in function `main':
mtx_initSample.c:(.text+0x15): undefined reference to `mtx_init'
/usr/bin/ld: mtx_initSample.c:(.text+0x38): undefined reference to `mtx_destroy'
collect2: error: ld returned 1 exit status
*/