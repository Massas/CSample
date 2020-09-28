#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* fp;
    int i;

    fp = fopen(argv[1], "w+");
    if(fp == NULL)
    {
        fprintf(stderr, "file open error\n");
        exit(EXIT_FAILURE);
    }
    printf("現在のファイル位置(書き込み前)： %ld\n", ftell(fp));

    for(i = 0; i < 10; i++)
    {
        putc('A', fp);
    }
    printf("現在のファイル位置(書き込み後)： %ld\n", ftell(fp));

    rewind(fp);

    printf("現在のファイル位置(rewind後)： %ld\n", ftell(fp));

    fclose(fp);

    return 0;
}