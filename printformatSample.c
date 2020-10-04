#include <stdio.h>

int main(void)
{
    int score =120;
    char player[] = "Mary";

    printf("%s has %d points.\n", player, score);
    printf("\n");
    printf("123456789abcdef\n");
    printf("%-10s %s\n", "Player", "Score");
    printf("%-10s %4d\n", "John", 120);
    printf("%-10s %4d\n", "Mary", 77);
    printf("\n");

    int month = 5;
    int day = 1;
    int year = 1987;
    printf("Date of birth: %02d-%02d-%04d\n", month, day, year);
    printf("\n");

    char str[] = "Variable field width";
    int width = 30;
    printf("%-*s!\n", width, str);
    printf("\n");

    char* team[] = {"Vivian", "Tim", "Frank", "Sally"};
    char separator = ';';
    for(int i = 0; i < sizeof(team) / sizeof(team[0]); ++i)
    {
        printf("%10s%c", team[i], separator);
    }
    putchar('\n');
    printf("\n");

    char msg[] = "Every solution breeds new problems.";
    printf("%.14s\n", msg);
    printf("%20.14s\n", msg);
    printf("%.8s\n", msg+6);

    printf("%c %d\n", -120, -120);
    printf("%c %d\n", 120, 120);
    printf("\n");

    printf("%4d %4o %4x %4X\n", 63, 63, 63, 63);
    printf("%d %u %X\n", -1, -1, -1);
    printf("\n");

    long bignumber = 100000L;
    unsigned long long hugenumber = 100000ULL * 100000ULL;
    printf("%ld %llX\n", bignumber, hugenumber);
    printf("\n");

}