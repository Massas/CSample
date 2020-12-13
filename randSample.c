#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main(void)
{
    printf("Think of a number between on and twenty.\n"
           "Press Enter when you're erady.");
    getchar();

    srand((unsigned) time(NULL));
    for(int i = 0; i < 3; i++)
    {
        printf("Is it %u? (y or n) ", 1 + rand() % 20);
        if(tolower(getchar()) == 'y')
        {
            printf("WOW!YES!\n");
            exit(0);
        }
        getchar();
    }
    printf("FIN\n");
}

/*
$ ./a.out
Think of a number between on and twenty.
Press Enter when you're erady.
Is it 6? (y or n) n
Is it 15? (y or n) n
Is it 9? (y or n) y
WOW!YES!
*/