#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t now = {0};
    time(&now); // time from 01/01/1970 by second
    printf("Date: %.24s GMT\n",asctime(gmtime(&now)));

    return 0;
}