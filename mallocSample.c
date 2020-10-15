#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void* malloc(size_t size);

int main(void)
{
    struct linelink
    {
        char* line;
        struct linelink* next;
    };
    struct linelink* head = NULL;
    struct linelink* tail = NULL;

    const char filename[] = "malloc.txt";
    FILE* fp_in = fopen(filename, "r");
    if(fp_in == NULL)
    {
        perror("Opening input file");
    }
    char buffer[2048];
    while (NULL != fgets(buffer, sizeof(buffer), fp_in))
    {
        if(head == NULL)
        {
            head = (struct linelink*)malloc(sizeof(struct linelink));
            tail = (struct linelink*)malloc(sizeof(struct linelink));
            if(head != NULL)
            {
                head->line = (char*)malloc(strlen(buffer) + 1);
                if(head->line != NULL)
                {
                    strcpy(head->line, buffer);
                    printf("head->line : %s\n", head->line);
                    head->next = NULL;
                }
                else
                {
                    fprintf(stderr, "Out of memory\n");
                    return -1;
                }
            }
            else
            {
                fprintf(stderr, "Out of memory\n");
                return -1;
            }
        }
    }
}

/*
$ cat malloc.txt
tonikaku code wo kake.
dekiru dekinai no hanashi ha sono atoda.
$ ./a.out
head->line : tonikaku code wo kake.

*/