#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[30] = "That's not what I said.";
    printf("before : %s\n", a);
    memmove(a+7, a+11, 13);
    printf("after : %s\n", a);

    return 0;
}

/*
$ ./a.out
before : That's not what I said.
after : That's what I said.
*/