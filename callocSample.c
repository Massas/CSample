#include <stdio.h>
#include <stdlib.h>
void* calloc(size_t n, size_t size);

int main(void)
{
    size_t n;
    printf("\nHow many integers do you want to enter?\n");
    scanf("%lu", &n);
    int* p = (int*) calloc(n, sizeof(int));
    if(p == NULL)
    {
        printf("Insufficient memory.\n");
    }
    else
    {
        printf("successed allocationg memory.\n");
    }
    exit(EXIT_SUCCESS);
}

/*
How many integers do you want to enter?
8888888
successed allocationg memory.
*/