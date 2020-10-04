#include <stdio.h>
#include <math.h>
#include <wchar.h>
#include <stdlib.h>

void check_orientation(FILE* stream)
{
    int rc;
    rc = fwide(stream, 0);
    if(rc < 0)
    {
        printf("Stream has byte orientation.\n");
    }
    else if(0 < rc)
    {
        printf("Stream has wide orientation.\n");
    }
    else
    {
        printf("Stream has no orientation.\n");
    }
}

int main(void)
{
    FILE* stream;
    stream = fopen("test.dat", "w");
    printf("After opening the file.\n");
    check_orientation(stream);

    fwide(stream, -1);
    printf("Stream fwide(stream, -1).\n");
    check_orientation(stream);
    fclose(stream);
    printf("Close the stream.\n");

    stream = fopen("test.dat", "w");
    fwide(stream, 1);
    printf("Stream fwide(stream, 1).\n");
    check_orientation(stream);
    fclose(stream);
    printf("Close the stream.\n");

    stream = fopen("test.dat", "w");
    printf("After opening the file.\n");
    check_orientation(stream);
    fwprintf(stream, L"pi = %.5f\n", 4 * atan(1.0));
    printf("After fwprintf().\n");
    check_orientation(stream);
    fclose(stream);

//    system("rm -f test.dat");

    return 0;
}