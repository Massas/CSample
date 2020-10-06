#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char str[] = " -1.02857e+2 \260C"; //Û‹L†
    const double z = atof(str);
    printf("\"%s\" becomes %.2f\n", str, z);
}

/*
* " -1.02857e+2 C" becomes -102.86
*/