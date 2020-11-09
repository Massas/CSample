#include <stdio.h>
#include <string.h>
int memcmp(const void *b1, const void *b2, size_t n);

int main(void)
{
    long setone[5] = {1, 3, 5, 7, 9};
    long settwo[5] = {0, 2, 4, 6, 8};
    int ret;

    for(int i = 0; i < 5; i++)
    {
        settwo[i] += 1;
    }

    ret = memcmp(&setone, &settwo, sizeof(settwo));
    if(ret == 0)
    {
        printf("The two arrays are identical, byte for byte.\n");
    }
    else
    {
        printf("The two arrays are not identical.\n");
    }
}

/*
$ ./a.out
The two arrays are identical, byte for byte.
*/