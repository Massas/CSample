#include <stdio.h>
#include <string.h>
char* fgets(char* restrict buffer, int n, FILE* fp);

int main(void)
{
    FILE* titlefile = fopen("titlefile.txt", "r");
    if(titlefile == NULL)
    {
        perror("Opening title file");
    }
    else
    {
        int counter = 0;
        char title[256];
        while(fgets(title, sizeof(title), titlefile) != NULL)
        {
            title[strlen(title) - 1] = '\0';
            printf("%3d: \"%s\"\n", ++counter, title);
        }
        if(feof(titlefile))
        {
            printf("Total: %d titles.\n", counter);
        }
        fclose(titlefile);
    }
}

/*
$ cat titlefile.txt
The Amazing Maurice
La condition humaine
Die Eroberung der Maschinen
$ ./a.out
  1: "The Amazing Maurice"
  2: "La condition humaine"
  3: "Die Eroberung der Maschinen"
Total: 3 titles.
*/