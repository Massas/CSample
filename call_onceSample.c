#include <stdio.h>
#include <threads.h>

static once_flag flag = ONCE_FLAG_INIT;
static void doOnce(void)
{
    puts("Function doOnce().");
}

static int th_func(void* arg)
{
    puts((char*) arg);
    call_once(&flag, doOnce);
    return 0;
}

int main(void)
{
    thrd_t th1;
    thrd_t th2;
    thrd_t th3;

    if(thrd_create(&th1, th_func, "Thread 1") != thrd_success
    || thrd_create(&th2, th_func, "Thread 2") != thrd_success
    || thrd_create(&th3, th_func, "Thread 3") != thrd_success)
    {
        fprintf(stderr, "Error creating thread.\n");
        return 0xff;
    }
    puts("Hello ...");

    thrd_join(th1, NULL);
    thrd_join(th2, NULL);
    thrd_join(th3, NULL);

    return 0;
}

/*
$ cc call_onceSample.c
/usr/bin/ld: /tmp/ccWIbK8l.o: in function `th_func':
call_onceSample.c:(.text+0x42): undefined reference to `call_once'
/usr/bin/ld: /tmp/ccWIbK8l.o: in function `main':
call_onceSample.c:(.text+0x7e): undefined reference to `thrd_create'
/usr/bin/ld: call_onceSample.c:(.text+0x9c): undefined reference to `thrd_create'
/usr/bin/ld: call_onceSample.c:(.text+0xba): undefined reference to `thrd_create'
/usr/bin/ld: call_onceSample.c:(.text+0x102): undefined reference to `thrd_join'
/usr/bin/ld: call_onceSample.c:(.text+0x113): undefined reference to `thrd_join'
/usr/bin/ld: call_onceSample.c:(.text+0x124): undefined reference to `thrd_join'
collect2: error: ld returned 1 exit status
*/