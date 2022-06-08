#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main(void){
    time_t sec;
    time(&sec);

    printf("Time is %lu (%.24s.)\n", sec, ctime(&sec));

    exit(0);
}

/*
$ ./timeSample
Time is 1654715504 (Thu Jun  9 04:11:44 2022.)
*/