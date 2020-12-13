#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    typedef struct{
        int len;
        float array[];
    } DynArray_t;

    DynArray_t* daPtr = (DynArray_t*)malloc(sizeof(DynArray_t)) + 10 * sizeof(float);

    if(daPtr == NULL)
    {
        return -1;
    }
    daPtr->len = 10;
    for(int i = 0; i < daPtr->len; ++i)
    {
        daPtr->array[i] = 1.0F / (i+1);
        printf("%d: %f\n", i, daPtr->array[i]);
    }

    DynArray_t* daResizePtr = (DynArray_t*)realloc(daPtr, sizeof(DynArray_t) + 11 * sizeof(float));

    if(daResizePtr != NULL)
    {
        daPtr = daResizePtr;
        daPtr->len = 11;
        daPtr->array[10] = 0.1F / 12;
        printf("%d: %f\n", 10, daPtr->array[10]);
    }
    else
    {
        return -1;
    }

}

/*
$ ./a.out
0: 1.000000
1: 0.500000
2: 0.333333
3: 0.250000
4: 0.200000
5: 0.166667
6: 0.142857
7: 0.125000
8: 0.111111
9: 0.100000
realloc(): invalid pointer
’†Ž~
*/