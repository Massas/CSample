#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
wint_t fgetwc(FILE* fp);

int main(void)
{
    if(setlocale(LC_CTYPE, "") == NULL)
    {
        fwprintf(stderr, L"Sorry, couldn't change to the system's native  locale.\n"),
        exit(1);
    }
    const char file_in[] = "local_in.txt";
    FILE* fp_in_wide = fopen(file_in, "r");
    if(fp_in_wide == NULL)
    {
        fprintf(stderr, "Error opening the file %s\n", file_in);
        exit(2);
    }
    const char file_out[] = "local_out.txt";
    FILE* fp_out_wide = fopen(file_out, "w");
    if(fp_out_wide == NULL)
    {
        fprintf(stderr, "Error opening the file %s\n", file_out);
        exit(3);
    }
    fwide(fp_in_wide, 1);
    fwide(fp_out_wide, 1);

    wint_t wc;
    while((wc = fgetwc(fp_in_wide)) != WEOF)
    {
        //ì«Ç›éÊÇ¡ÇΩäeÉèÉCÉhï∂éöÇèàóù

        if(fputwc((wchar_t)wc, fp_out_wide) == WEOF)
        {
            break;
        }
    }
    if(ferror(fp_in_wide))
    {
        fprintf(stderr, "Error reading the file %s\n", file_in);
    }
    if(ferror(fp_out_wide))
    {
        fprintf(stderr, "Error reading the file %s\n", file_out);
    }

    fclose(fp_out_wide);
    fclose(fp_in_wide);
}

/*
$ cat local_out.txt
asdfasdfasff
zxcvzxcv
qwerqwer
$ diff local_in.txt local_out.txt
*/