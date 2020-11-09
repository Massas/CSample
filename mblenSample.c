#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <stddef.h>

size_t mbsrcat(char* restrict s1, char* restrict s2, mbstate_t* restrict p_s1state, size_t n)
{
    int result = -1;
    size_t i = strlen(s1);
    // 0バイトしか書いていない
    if(i >= n - (MB_CUR_MAX + 1))
    {
        return 0;
    }
    // s1を初期状態にシフトダウン
    if (! mbsinit(p_s1state))
    {
        // シフトシーケンスを初期状態を得るように付加する
        result = wcrtomb(s1 + i, L'\0', p_s1state);
        // 符号化エラー
        if(result == -1)
        {
            s1[i] = '\0';
            return (size_t)-1;
        }
        else
        {
            i += result;
        }
    }

    // マルチバイト文字全体を一度にコピーする
    // 状態を変えずに次の文字の長さを求める
    size_t j = 0;
    while ((result = mblen(s2 + j, MB_CUR_MAX)) <= (n - (i + 1)))
    {
        if(result == 0)
        {
            break;
        }
        if(result == -1)
        {
            s1[i] = '\0';
            return (size_t)-1;
        }
        // 次の文字が収まる。コピーして状態を更新
        strncpy(s1 + i, s2 + j, mbrlen(s2 + j, MB_CUR_MAX, p_s1state));
        i += result;
        j += result;
    }
    s1[i] = '\0';
    return j;
}

int main(void)
{
    char *s1;
    char *s2;
    mbstate_t *p_s1state;
    int i;
    size_t j;

    j = mbsrcat(s1, s2, p_s1state, i);

    return 0;

}