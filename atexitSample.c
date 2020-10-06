#include <stdio.h>
#include <stdlib.h>
int atexit(void (*func)(void)); //引数：なし、戻り値型がvoidの関数へのポインタ

static void f1(void);
static void f2(void);

int main(void)
{
    printf("Registering the atexit functions fi and f2;");
    if(atexit(f1) || atexit(f2))
    {
        printf(" failed.\n");
    }
    else
    {
        printf(" done.\n");
    }

    printf("Exiting now.\n");
    exit(0);
}

static void f1(void)
{
    printf("Running the atexit function f1().\n");
}

static void f2(void)
{
    printf("Running the atexit function f2().\n");
}

//以下の順序で実行される
/*
* Registering the atexit functions fi and f2; done.
* Exiting now.
* Running the atexit function f2().
* Running the atexit function f1().
*/