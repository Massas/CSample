#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STRING 80

int main(void)
{
    char raw_name[MAX_STRING];
    printf("Enter your name, please: ");
    fgets(raw_name, sizeof(raw_name), stdin);

    int i = (strlen(raw_name) - 1);
    for(int j = 0; j < i; j++)
    {
        if(raw_name[j] == '\n')
        {
            raw_name[j] = '\0'; //���s������؂�̂Ă�
        }
        else if(isblank(raw_name[i]))
        {
            raw_name[j] = '\0'; //�c��̋󔒂ƃ^�u��؂�̂Ă�
        }
        else
        {
            printf("\n%s\n", raw_name);
            break;
        }
    }
}
