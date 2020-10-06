#include <stdio.h>
#include <stdlib.h>
int atexit(void (*func)(void)); //�����F�Ȃ��A�߂�l�^��void�̊֐��ւ̃|�C���^

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

//�ȉ��̏����Ŏ��s�����
/*
* Registering the atexit functions fi and f2; done.
* Exiting now.
* Running the atexit function f2().
* Running the atexit function f1().
*/