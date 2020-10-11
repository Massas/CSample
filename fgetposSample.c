#include <stdio.h>
int fgetpos(FILE* restrict fp, fpos_t* restrict ppos);

int main(void)
{
    FILE* datafile;
    datafile = fopen(".testfile", "r+");
    if(datafile == NULL)
    {
        fprintf(stderr, "Unable to open file %s.\n", ".testfile");
        return 1;
    }
    fpos_t bookmark;
    if(fgetpos(datafile, &bookmark))
    {
        perror("Saving file position");
    }
    else
    {
        if(fsetpos(datafile, &bookmark))
        {
            perror("Restoring file position");
        }
    }
}