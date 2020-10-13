#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void free(void* ptr);

int main(void)
{
    char* ptr = calloc(4096, sizeof(char));
    if(ptr == NULL)
    {
        fprintf(stderr, "Insufficient memory.\n");
        abort();
    }
    else
    {
        strncpy(ptr, "Imagine this is a long string.\n", 4095);
        printf("%s", ptr);
        free(ptr);
    }
    return 0;
}

/*
$ ./a.out
Imagine this is a long string.
*/