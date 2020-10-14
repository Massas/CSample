#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* getenv(const char* name);

#define MAXPATH 1024

int main(void)
{
    char sPath[MAXPATH] = "";
    const char* pTmp = getenv("SHELL");

    if(pTmp != NULL)
    {
        strncpy(sPath, pTmp, MAXPATH - 1);
        printf("%s\n", sPath);
    }
    else
    {
        fprintf(stderr, "No PATH variable set.\n");
    }
}

/*
$ env | grep SHELL
SHELL=/bin/bash
$ ./a.out
/bin/bash
*/