#include <stdio.h>
#include <string.h>
#include <limits.h>
int fscanf(FILE* restrict fp, const char* restrict format, ...);

struct pwrecord
{
    unsigned int uid;
    unsigned int gid;
    char user[32];
    char pw[32];
    char realname[32];
    char home[128];
    char shell[128];
};

int main(void)
{
    const char pwfile[] = "pwfile.txt";
    FILE* fp = fopen(pwfile, "r");
    if(fp == NULL)
    {
        perror("Opening input file");
        return -1;
    }
    struct pwrecord record = (struct pwrecord){UINT_MAX, UINT_MAX, "", "", "", "", ""};
    struct pwrecord* recptr = &record;
    int results = fscanf(fp, "%31[^:]:%31[^:]:%u:%u:", recptr->user, recptr->pw, &recptr->uid, &recptr->gid);

    if(results < 4)
    {
        fprintf(stderr, "Unable to parse line.\n");
        fscanf(fp, "%*[^\n]\n"); //s‚ÌŽc‚è‚ð“Ç‚ÝŽÌ‚Ä‚é
    }

    char gecos[256] = "";
    results = fscanf(fp, "%255[^:]:", gecos);
    if(results < 1)
    {
        strcpy(recptr->realname, "[No real name available]");
    }
    else
    {
        sscanf(gecos, "%127[^,]", recptr->realname);
    }

    results = fscanf(fp, "%127[^:]:%127[^:\n]\n", recptr->home, recptr->shell);
    if(results < 2)
    {
        fprintf(stderr, "Unable to parse line.\n");
        fscanf(fp, "%*[^\n]\n");
    }
    printf("The user account %s with UID %u belongs to %s.\n", recptr->user, recptr->uid, recptr->realname);
    fclose(fp);

}

/*
$ cat pwfile.txt
tony:x:1002:31:Tony Crawford,,:/home/tony:/bin/bas
$ ./a.out
The user account tony with UID 1002 belongs to Tony Crawford.
*/