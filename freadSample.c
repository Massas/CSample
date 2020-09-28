#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* fp;
    char outbf[10] = {1,2,3,4,5,6,7,8,9,10};
    char inbuf[10];
    int i;

    if(argc != 2)
    {
        printf("ファイル名を指定して下さい\n");
        exit(EXIT_FAILURE);
    }
    fp = fopen(argv[1], "wb+");
    if(fp == NULL)
    {
        printf("ファイルオープンエラー\n");
        exit(EXIT_FAILURE);
    }

    fwrite(outbf, sizeof(char), 10, fp);
    fseek(fp, 0L, SEEK_SET);
    fread(inbuf, sizeof(char), 10, fp);
    fclose(fp);

    for(i = 0; i < 10; i++)
    {
        printf("%3d", inbuf[i]);
    }
    printf("\n");

    return 0;
}