#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* fp;
    int c;

    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        fprintf(stderr, "open error\n");
        exit(EXIT_FAILURE);
    }

    while((c = getc(fp)) != EOF)
    {
        putchar(c);
    }
    fclose(fp);

    return 0;
}