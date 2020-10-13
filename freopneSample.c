#include <stdio.h>
#include <time.h>
FILE* freopen(const char* restrict name, const char* restrict mode, FILE* restrict fp);

int main()
{
    const char fname[] = "test.dat";
    if(freopen(fname, "w", stdout) == NULL)
    {
        fprintf(stderr, "Unable to redirect stdout.\n");
    }
    else
    {
        time_t sec;
        time(&sec);
        printf("%.24s: This file opened as stdout.\n", ctime(&sec));
    }
}

/*
$ cat test.dat
Tue Oct 13 21:09:36 2020: This file opened as stdout.
*/