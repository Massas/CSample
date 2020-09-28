#include <stdio.h>

int main()
{
    FILE* fp;
    long int pos;

    fp = fopen("myfile.dat", "rb");
    pos = ftell(fp);
    if(pos != EOF)
    {
        printf("Current position of file pointer found : %ld", pos);
    }
    fclose(fp);

    return 0;
}