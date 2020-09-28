#include <stdio.h>

int main(void)
{
    FILE* fp;
    long pos;
    char list[1000];

    fopen_s(fp, "createfile.txt", "rb");
    if(fp == 0)
    {
        fread(list, sizeof(char), 100, fp);
        pos = ftell(fp);
        printf("Position after trying to read 100 bytes : %ld\n", pos);
        fclose(fp);
    }

    return 0;
}