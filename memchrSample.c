#include <stdio.h>
#include <string.h>
void* memchr(const void* buffer, int c, size_t n);

int main(void)
{
    char* found;
    char buffer[4096] = "";
    int ch = ' ';
    short i = 0;

    fgets(buffer, sizeof(buffer), stdin);
    printf("STRING:%s\n",buffer);
    // •¶š—ñ‚Ì‹ó”’‚ğ‰ºü‚É’u‚«Š·‚¦‚é
    while((found = memchr(buffer, ch, strlen(buffer))) != NULL)
    {
        *found = '_';
        i++;
    }
    printf("num of char you search:%d\n",i);

    return 0;
}

/*
$ ./a.out
a b c
STRING:a b c

num of char you search:2

$ ./a.out
abc
STRING:abc

num of char you search:0

$ ./a.out
a  b  c  d
STRING:a  b  c  d

num of char you search:6
*/