#include <stdio.h>
#include <complex.h>
double cabs(double complex z);

int main(void)
{
    double complex z[4];
    z[0] = 3.0 + 4.0 * I;
    z[1] = conj(z[0]);
    z[2] = z[0] * I;
    z[3] = -(z[0]);

    for(int i = 0; i < 4; i++)
    {
        const double a = creal(z[i]);
        const double b = cimag(z[i]);
        printf("absolute value of (%4.2f %+4.2f * I) is ", a, b);

        const double absolute_z = cabs(z[i]);
        printf("%4.2f.\n", absolute_z);
    }
}

/*
$ cc cabsSample.c
/usr/bin/ld: /tmp/ccydGzG4.o: in function `main':
cabsSample.c:(.text+0x166): undefined reference to `cabs'
collect2: error: ld returned 1 exit status
*/