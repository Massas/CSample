#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[] = "abcdefghijklmn";
    char s2[] = "defgh";
    char s3[] = "xyz";
    char s4[] = "abcdefghijklmnopqr";
    char s5[] = "";
    char* sp;

    sp = strstr(s1, s2);
    printf("一致する場合 ： %s\n", sp);
    sp = strstr(s1, s3);
    printf("一致しない場合 ： %s\n", sp);
    sp = strstr(s1, s4);
    printf("検索対象文字列より長い場合 ： %s\n", sp);
    sp = strstr(s1, s5);
    printf("\\0の場合 ： %s\n", sp);

    return 0;
}