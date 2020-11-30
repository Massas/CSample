#include <stdio.h>
#include <string.h>

int main(void)
{
    const char* path = "/usr/local/bin:/usr/bin:/bin:/usr/bin/X11:/usr/games";
    const char* basename = "aprogram";
    char fullname[1024]= "";

    int separator = strcspn(path, ":");
    printf("separator: %d\n", separator);
    strncpy(fullname, path, separator);
    fullname[separator] = '\0';
    strncat(fullname, "/", sizeof(fullname) - strlen(fullname) -1);
    strncat(fullname, basename, sizeof(fullname) - strlen(fullname) -1);

    puts(fullname);

    return 0;

}

/*
$ ./a.out
separator: 14
/usr/local/bin/aprogram
*/