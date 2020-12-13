#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
    char fname_tmp[L_tmpnam] = "temp.txt";

    mkstemp(fname_tmp);
    FILE* fp = fopen(fname_tmp, "w+");
    if(fp == NULL)
    {
        printf("Couldn't open file \"%s\".\n", fname_tmp);
        return -1;
    }

    fputs("hello...\n", fp);
    fclose(fp);

    int result = rename(fname_tmp, "finished.txt");
    if(result)
    {
        remove("finished.txt");
        result = rename(fname_tmp, "finished.txt");
        if(result)
        {
            printf("Error %d om trying to rename output file\n", errno);
        }
    }

    result = remove("finished.txt");
    if(result == 0)
    {
        printf("erase text file\n");
    }
}

/*
$ cc removeSample.c
/usr/bin/ld: /tmp/ccuUS35x.o: in function `main':
removeSample.c:(.text+0x3a): åxçê: the use of `tmpnam' is dangerous, better use `mkstemp'
*/

/*
$ ./a.out
erase text file
*/