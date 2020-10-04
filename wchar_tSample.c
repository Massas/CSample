#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <stddef.h>

int main(void)
{
    wchar_t ws[] = L"abcde";

    printf("%zu\n", sizeof(wchar_t));
    printf("%zu\n", sizeof(ws));
    printf("%zu\n", sizeof(L'X'));

}