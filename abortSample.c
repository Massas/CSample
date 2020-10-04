#include <stdio.h>
#include <stdlib.h>
_Noreturn void abort(void);

struct record
{
    long id;
    int data[256];
    struct record* next;
};

int main(void)
{
    struct record* new = (struct record*)malloc(sizeof(struct record));
    if(new != NULL)
    {
        printf("%s: malloc\n", __func__);
        abort();    // 中止 (コアダンプ)を伴う
    }
    else
    {
        printf("\n");
    }
}

