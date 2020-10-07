#include <stdio.h>
#include <time.h>
char* ctime(const time_t* seconds);

int main(void)
{
    time_t eventtime = {0};
    short errorcode = 23;
    //現在時刻を秒で取得
    time(&eventtime);
    //秒データを人間が読めるローカルの日付と時刻を示す文字列に変換する
    fprintf(stderr, "%s: Error number %d occured.\n", ctime(&eventtime), errorcode);

    return 0;
}

/*
./a.out
Thu Oct  8 02:06:19 2020
: Error number 23 occured.
*/