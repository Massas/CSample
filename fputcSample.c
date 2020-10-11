#include <stdio.h>
int fputc(int c, FILE* fp);

#define CYCLES 10000
#define DOTS 4

int main(void)
{
    printf("Performing %d modulo operations .", CYCLES);
    for(int count = 0; count < CYCLES; ++count)
    {
        if (count % (CYCLES / DOTS) == 0)
        {
            fputc('.', stdout);
        }
    }
    printf(" done.\n");
}

/*
$ ./a.out
Performing 10000 modulo operations ..... done.
*/