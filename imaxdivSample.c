#include <stdio.h>
#include <inttypes.h>
imaxdiv_t imaxdiv(intmax_t diviend, intmax_t divisor);

int main(void)
{
    const intmax_t people = 110284;
    const intmax_t apples = 9043291;
    imaxdiv_t share = {0};

    //ƒ[ƒ‰‰Z‚ğ”ğ‚¯‚é
    if(people == 0)
    {
        printf("There is no one here to take the apples.\n");
        return -1;
    }
    else
    {
        share = imaxdiv(apples, people);
    }
    printf("If there are %ji of us and %ji apples, each of us gets %ji, with %ji left over.\n", people, apples, share.quot, share.rem);
}

/*
$ ./a.out
If there are 110284 of us and 9043291 apples, each of us gets 82, with 3 left over.
*/