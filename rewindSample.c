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
    printf("���݂̃t�@�C���ʒu(�������ݑO)�F %ld\n", ftell(fp));

    for(i = 0; i < 10; i++)
    {
        putc('A', fp);
    }
    printf("���݂̃t�@�C���ʒu(�������݌�)�F %ld\n", ftell(fp));

    rewind(fp);

    printf("���݂̃t�@�C���ʒu(rewind��)�F %ld\n", ftell(fp));

    fclose(fp);

    return 0;
}