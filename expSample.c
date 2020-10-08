#include <stdio.h>
#include <math.h>
double exp(double x);

int main(void)
{
    //�ԍϑ��z �� ���� * e^(���� * ����)
    const int principal = 10000;    //1���~���؂�����
    const double rate = 0.055;      //�����͔N5.5%
    const double time = 1.5;        //�ؓ�����:18����
    const int balance = principal * exp(rate * time);

    printf("Invest %d yen at %.1f%% compound interest, and in %.1f years \nyou'll have %d yen.\n", principal, rate * 100.0, time, balance);
}

/*
cc expSample.c
/usr/bin/ld: /tmp/cctSCbDV.o: in function `main':
expSample.c:(.text+0x42): undefined reference to `exp'
collect2: error: ld returned 1 exit status
*/