#include <stdio.h>
#include <stdlib.h>
div_t div(int dividend, int divisor);

int main(void)
{
    for(int apples = -3; apples < 6; apples += 3)
    {
        if(apples == 0)
        {
            continue;
        }
        for(int people = -2; people < 4; people += 2)
        {
            if(people == 0)
            {
                continue;
            }
            div_t share = div(apples, people);

            printf("If there are %+i of us and %+i apples, we each get %+i with %+i left over.\n", people, apples, share.quot, share.rem);
        }
    }
}

/*
./a.out
If there are -2 of us and -3 apples, we each get +1 with -1 left over.
If there are +2 of us and -3 apples, we each get -1 with -1 left over.
If there are -2 of us and +3 apples, we each get -1 with +1 left over.
If there are +2 of us and +3 apples, we each get +1 with +1 left over.
*/
//execute it on ubuntu, WSL2