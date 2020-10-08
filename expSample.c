#include <stdio.h>
#include <math.h>
double exp(double x);

int main(void)
{
    //•ÔÏ‘Šz  Œ³‹à * e^(—˜—¦ * ŠúŠÔ)
    const int principal = 10000;    //1–œ‰~‚ğØ‚è“ü‚ê‚é
    const double rate = 0.055;      //—˜—¦‚Í”N5.5%
    const double time = 1.5;        //Ø“üŠúŠÔ:18‚©Œ
    const int balance = principal * exp(rate * time);

    printf("Invest %d yen at %.1f%% compound interest, and in %.1f years \nyou'll have %d yen.\n", principal, rate * 100.0, time, balance);
}

/*
cc expSample.c
/usr/bin/ld: /tmp/cctSCbDV.o: in function `main':
expSample.c:(.text+0x42): undefined reference to `exp'
collect2: error: ld returned 1 exit status
*/