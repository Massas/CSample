#include <stdio.h>
#include <wchar.h>

int fputws(const wchar_t* restrict ws, FILE* restrict fp);

int main(void)
{
    const wchar_t widestring[] = L"How many umlauts are there in Fahrvergnugen??\n";
    const char fname_wide[] = "widetest.txt";
    FILE* fpw = fopen(fname_wide, "a");
    if(fpw == NULL)
    {
        perror("Opening output file");
        return -1;
    }
    int widemodeflag = 1;   //ファイルをワイド文字志向に変更
    widemodeflag = fwide(fpw, widemodeflag);
    if(widemodeflag < 0)
    {
        fprintf(stderr, "Unable to set output file %s to wide characters\n", fname_wide);
        (void)fclose(fpw);
        return -1;
    }
    const int result = fputws(widestring, fpw); //ワイド文字列をファイルに書き出す
    return 0;
}

/*
$ ./a.out
$ cat widetest.txt
How many umlauts are there in Fahrvergnugen??
*/