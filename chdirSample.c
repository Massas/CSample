#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define PATHNAME_SIZE 512

int main(void)
{
    char pathname[PATHNAME_SIZE];
    memset(pathname, '\0', PATHNAME_SIZE);
    // get current directory
    getcwd(pathname, PATHNAME_SIZE);
    fprintf(stdout, "current working directory : %s\n", pathname);
    // change directory
    chdir("..");
    getcwd(pathname, PATHNAME_SIZE);
    fprintf(stdout, "current working directory : %s\n", pathname);

}