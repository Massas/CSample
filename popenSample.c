#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* fp;
    char buf[1024];
    char* cmd = "/usr/bin/ls -l /";
//    char* cmd = "/usr/bin/ps -ef";

    fp = popen(cmd, "r");
    if(fp != NULL)
    {
        while(fgets(buf, sizeof(buf), fp) != NULL)
        {
            printf("%s", buf);
        }
        pclose(fp);
        return 0;
    }
    return -1;
}