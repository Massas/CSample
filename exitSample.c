#include <stdio.h>
#include <stdlib.h>
_Noreturn void exit(int status);

int main(int argc, char* argv[])
{
    // enumは先頭に値を設定した後の要素はカウントアップした値を持つ
    enum { X_OK = 0, X_ARGS, X_NOIN, X_NOOUT };
    if(argc != 3)
    {
        fprintf(stderr, "Usage: program input-file output-file\n");
        exit(X_ARGS);
    }
    FILE* fp_in = fopen(argv[1], "r");
    if(fp_in == NULL)
    {
        fprintf(stderr, "Unable to open input-file.\n");
        exit(X_NOIN);
    }
    FILE* fp_out = fopen(argv[2], "a+");
    if(fp_out == NULL)
    {
        fprintf(stderr, "Unable to open output-file.\n");
        exit(X_NOOUT);
    }
    fclose(fp_out);
    fclose(fp_in);
}

/*
./a.out
Usage: program input-file output-file
$ ./a.out input.txt
Usage: program input-file output-file
$ ./a.out input.txt output.txt
Unable to open input-file.
$ touch input.txt
$ touch output.txt
$ ./a.out input.txt output.txt
*/
//execute it on ubuntu, WSL2