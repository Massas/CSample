/*
* inline.c
* Copyright (C) 2014 kaoru <kaoru@bsd>
*/
#include <stdio.h>
#include <stdlib.h>

inline static int max(int i1, int i2)
{
    return (i1 > i2) ? i1 : i2;
}

int main(int argc, char* argv[])
{
    printf("max : %d\n",max(1, 5));
    exit(EXIT_SUCCESS);
}