#include <stdio.h>
#include <time.h>

int main(void)
{
    struct tm sometime = {0};

    sometime.tm_sec = 10;
    sometime.tm_min = 80;
    sometime.tm_hour = 40;
    sometime.tm_mday = 23;
    sometime.tm_mon = 1;
    sometime.tm_year = 105;
    sometime.tm_wday = 11;
    sometime.tm_yday = 111;
    sometime.tm_isdst = -1;

    const time_t seconds = mktime(&sometime);
    if(seconds == -1)
    {
        printf("mktime() couldn't make sense of its input.\n");
    }
    printf("The return value, %ld, represents %s", (long)seconds, ctime(&seconds));

    printf("The structure has been adjusted as follows:\n"
            "tm_sec   == %d\n"
            "tm_min   == %d\n"
            "tm_hour  == %d\n"
            "tm_mday  == %d\n"
            "tm_mon   == %d\n"
            "tm_year  == %d\n"
            "tm_wday  == %d\n"
            "tm_yday  == %d\n"
            "tm_isdst == %d\n",
            sometime.tm_sec,
            sometime.tm_min,
            sometime.tm_hour,
            sometime.tm_mday,
            sometime.tm_mon,
            sometime.tm_year,
            sometime.tm_wday,
            sometime.tm_yday,
            sometime.tm_isdst);
    printf("The structure now represents %s", asctime(&sometime));
}

/*
$ ./a.out
The return value, 1109233210, represents Thu Feb 24 17:20:10 2005
The structure has been adjusted as follows:
tm_sec   == 10
tm_min   == 20
tm_hour  == 17
tm_mday  == 24
tm_mon   == 1
tm_year  == 105
tm_wday  == 4
tm_yday  == 54
tm_isdst == 0
The structure now represents Thu Feb 24 17:20:10 2005
*/