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
    printf("��v����ꍇ �F %s\n", sp);
    sp = strstr(s1, s3);
    printf("��v���Ȃ��ꍇ �F %s\n", sp);
    sp = strstr(s1, s4);
    printf("�����Ώە������蒷���ꍇ �F %s\n", sp);
    sp = strstr(s1, s5);
    printf("\\0�̏ꍇ �F %s\n", sp);

    return 0;
}