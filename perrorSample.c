#include <stdio.h>
#include <errno.h>

#define MSGLEN_MAX (256)

int main(void)
{
    FILE* fp = fopen("nonexistentfile", "r");
    if(fp == NULL)
    {
        char msgbuf[MSGLEN_MAX] = "";
        snprintf(msgbuf, sizeof(msgbuf), "function: %s, file: %s, line %d", __func__, __FILE__, __LINE__);
        perror(msgbuf);
        return errno;
    }
}

/*
$ ./a.out
function: main, file: perrorSample.c, line 12: No such file or directory
*/