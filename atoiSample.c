#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char* s = " -135792468.00 Balance on Dec. 31";
    printf("\"LONG::: %s\" becomes %ld\n", s, atol(s));
    printf("\"INT::: %s\" becomes %d\n", s, atoi(s));
}

/*
* "LONG:::  -135792468.00 Balance on Dec. 31" becomes -135792468
* "INT:::  -135792468.00 Balance on Dec. 31" becomes -135792468
*/