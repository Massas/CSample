#include <stdio.h>
#include <string.h>

int searchFile(FILE* fp, const char* keyword)
{
    #define MAX_LINE 256
    char line[MAX_LINE] = "";
    int count = 0;

    if(fp == NULL || keyword == NULL)
    {
        return -1;
    }
    else
    {
        rewind(fp);
    }
    while(fgets(line, MAX_LINE, fp) != NULL)
    {
        if(strstr(line, keyword) != NULL)
        {
            ++count;
            fputs(line, stdout);
        }
    }
    if(! feof(fp))
    {
        return -1;
    }
    else
    {
        return count;
    }
}