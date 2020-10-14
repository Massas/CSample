#include <stdio.h>
#include <string.h>
#include <time.h>
struct tm* gmtime(const time_t* timer);

int main(void)
{
    time_t rawtime;
    time(&rawtime); //Œ»İ‚ğ®”‚Åæ“¾

    struct tm* ptr_tm = gmtime(&rawtime);   //tm\‘¢‘Ì‚Ì’l‚ğ‹¦’è¢ŠE‚É•ÏŠ·‚·‚é
    struct tm utc_tm;
    memcpy(&utc_tm, ptr_tm, sizeof(struct tm));
    ptr_tm = localtime(&rawtime);   //Œ»’nŠÔ‚ğæ“¾
    struct tm local_tm;
    memcpy(&local_tm, ptr_tm, sizeof(struct tm));

    char buffer[1024] = "";
    if(strftime(buffer, sizeof(buffer), "It's %A, %B %d, %Y, %R o'clock, UTC.", &utc_tm))
    {
        puts(buffer);
    }
    if(strftime(buffer, sizeof(buffer), "Here it's %A, %B %d, %Y, %R o'clock, UTC %z.", &local_tm))
    {
        puts(buffer);
    }
    return 0;
}

/*
$ ./a.out
It's Wednesday, October 14, 2020, 15:43 o'clock, UTC.
Here it's Thursday, October 15, 2020, 00:43 o'clock, UTC +0900.
*/