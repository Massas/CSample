#include <stdio.h>
#include <string.h>
void* memset(void* dest, int c, unsigned int n);

int main(void)
{
    char str[] = "Account number: 1234567890";
    char digits[] = "0123456789";
    unsigned int pos = strcspn(str, digits);
    printf("before : %s\n", str);
    puts(memset(str + pos, 'x', 7));
}

/*
$ ./a.out
before : Account number: 1234567890
xxxxxxx890
*/