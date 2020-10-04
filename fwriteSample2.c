#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 100

typedef struct
{
    long key;
    char name[32];
} Record_t;

char inFile[] = "records.dat";
char outFile[] = "packed.dat";

static inline void error_exit(int status, const char* error_msg)
{
    fputs(error_msg, stderr);
    exit(status);
}

int main(void)
{
    FILE* fpIn = NULL;
    FILE* fpOut = NULL;
    Record_t* pArray = NULL;

    fpIn = fopen(inFile, "rb");
    fpOut = fopen(outFile, "wb");
    if(fpIn == NULL)
    {
        error_exit(1, "Error on opening input file.");
    }
    else if(fpOut == NULL)
    {
        error_exit(2, "Error on opening output file.");
    }
    else
    {
        pArray = malloc(ARRAY_LEN * sizeof(Record_t));
        if(pArray == NULL)
        {
            error_exit(3, "Insufficient memory.");
        }
    }

    Record_t record = {0};
    unsigned int i = 0U;
    // 100件ずつレコードを書く
    while(fread(&record, sizeof(Record_t),1, fpIn) == 1)
    {
        if(record.key != 0L)
        {
            pArray[i++] = record;
            if(i == ARRAY_LEN)
            {
                if(fwrite(pArray, sizeof(Record_t), i, fpOut) < i)
                {
                    break;
                }
                i = 0U;
            }
        }
    }
    // 残りのレコードを書く
    if(i > 0 && !ferror(fpOut))
    {
        fwrite(pArray, sizeof(Record_t), i, fpOut);
    }

    if(ferror(fpOut))
    {
        error_exit(4, "Error on writing to output file.");
    }
    else if(ferror(fpIn))
    {
        error_exit(5, "error on reading input file.");
    }

    return 0;
}