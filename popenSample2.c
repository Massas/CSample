#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int process_start(const char* cmd);

int main(void)
{
    int i;
    char* cmd = "/usr/bin/sleep 10&";

    for(i = 0; i < 10; i++)
    {
        printf("create sleep process\n");
        process_start(cmd);
    }

    printf("sleeping......\n");
    sleep(20);
    printf("wake up\n");
}

int process_start(const char* cmd)
{
    FILE* p;
    p = popen(cmd, "w");
    if(p == NULL)
    {
        printf("precess_start() : failure\n");
        return -1;
    }
    printf("precess_start() : success\n");
    pclose(p);
    return 0;
}
