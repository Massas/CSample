#include <stdio.h>
#include <math.h>
double copysign(double x, double y);

int main(void)
{
    //‘æˆêˆø”‚Ìâ‘Î’l‚Æ‘æ“ñˆø”‚Ì•„†‚ğ‚ÂdoubleŒ^‚Ì’l‚ğ•Ô‚·
    const double x = copysign(0.0, -1.0);
    const double y = copysign(0.0, +1.0);

    printf("x is %+.1f; y is %+.1f.\n", x, y);
    printf("%+.1f is %sequal to %+.1f.\n", x, (x == y) ? "" : "not ", y);

    printf("x is %+.1f; y is %+.1f.\n", x + 1.0, y);
    printf("%+.1f is %sequal to %+.1f.\n", x + 1.0, ((x + 1.0) == y) ? "" : "not ", y);

}

/*
./a.out
x is -0.0; y is +0.0.
-0.0 is equal to +0.0.
x is +1.0; y is +0.0.
+1.0 is not equal to +0.0.
*/