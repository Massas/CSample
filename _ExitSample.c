#include <stdio.h>
#include <stdlib.h>
_Noreturn void _Exit(int status);

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        printf("Missing required arguments.\n");
        _Exit(-1);
    }
}