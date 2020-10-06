//NDEBUGマクロが有効ならassertマクロは実行されない
#define NDEBUG
#include <stdio.h>
#include <assert.h>
void asseert(int expression);

int main(void)
{
    int units_in_stock = 10;
    units_in_stock--;
    assert(units_in_stock >= 0);
    units_in_stock = units_in_stock - 10;
    assert(units_in_stock >= 0);
    printf("end\n");

}