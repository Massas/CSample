#include <stdio.h>
#include <time.h>

void main(void){
    time_t now = {0};
    time(&now);
    struct tm* localnow = localtime(&now);

    char hdr_date[999] = "";
    if(strftime(hdr_date, 78, "Date: %a, %d %b %Y %T %z", localnow))
    {
        puts(hdr_date);
    }
    else
    {
        puts("fail...");
        exit(-1);
    }
    exit(0);
}

/*
$ ./strftimeSample
Date: Thu, 09 Jun 2022 03:43:28 +0900
*/