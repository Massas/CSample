// C11 introduced
#define __STDC_WANT_LIB_EXT1__
#include <stdio.h>
#include <time.h>
errno_t asctime_s(char* s, rsize_t maxsize, const struct tm* tmPtr);

int main(void)
{
    time_t now = {0};
    time(&now);
    struct tm timeStruct = {0};
    localtime_s(&now, &timeStruct);
    char timeStr[26];
    int rc;

    rc = asctime_s(timeStr, sizeof(timeStr), &timeStruct);
    if(rc == 0)
    {
        printf("Date and time : %s\n", timeStr);
    }
    return 0;
}