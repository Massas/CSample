#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
int fflush(FILE* fp);

//#define FLUSH
#ifdef FLUSH
    const char filename[] = "twice.txt";
#else
    const char filename[] = "once.txt";
#endif /* FLUSH */

int main(void)
{
    FILE* fp = fopen(filename, "w");
    if(fp == NULL)
    {
        fprintf(stderr, "Failed to open file '%s' to write.\n", filename);
        return -1;
    }
    fputs("Going once...\n", fp);
    fflush(fp);     //�o�͂𖳏����Ńt���b�V��

    fputs("Going twice...\n", fp);

#ifdef FLUSH
    fflush(fp);     // '-DFLUSH'�ŃR���p�C�������Ƃ������t���b�V��
#endif

    raise(SIGKILL);

    fputs("Gone.\n", fp);
    fclose(fp);

    exit(0);
}

/*
./fflushtwice
�����I��
*/