#include <stdio.h>

int main(void)
{
    FILE* fp;
    fp = fopen("sample.txt", "wr");
    if(fp != NULL)
    {
        (void) fputc('*',fp);
        if(ferror(fp))
        {
            fprintf(stderr, "Error writiong.\n");
            return -1;
        }
    }
    fclose(fp);
    return 0;
}