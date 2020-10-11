#include <stdio.h>
int fgetc(FILE* fp);

int main(void)
{
    FILE* fp = NULL;
    char buffer[1024];
    int i = 0;
    fp = fopen("sample.txt", "r");
    if(fp == NULL)
    {
        fprintf(stderr, "file open error.\n");
        return -1;
    }
    while(i < 1023)
    {
        const int c = fgetc(fp);
        if(c == EOF)
        {
            if(feof(fp))
            {
                fprintf(stderr, "End of Input.\n");
            }
            else if(ferror(fp))
            {
                fprintf(stderr, "Input error.\n");
            }
            else
            {
            }
            clearerr(fp);
            break;
        }
        else
        {
            buffer[i++] = (char)c;
        }
    }
    buffer[i] = '\0';
    printf("%s",buffer);
}

/*
./a.out
End of Input.
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaassssssssssssssssssssssssssssssssssdddddddddddddddddddddddddd
<—ª>
*/