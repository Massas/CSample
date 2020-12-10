#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    typedef struct record {
        char name[32];
        double data;
        struct record* next;
        struct record* prev;
    } Rec_t;
    Rec_t template = { "Another fine product", -0.0, NULL, NULL};
    Rec_t* tmp_new;

    if((tmp_new = (Rec_t*) malloc(sizeof(Rec_t))) != NULL)
    {
        memcpy(tmp_new, &template, sizeof(Rec_t));
        printf("name: %s data: %f\n", tmp_new->name, tmp_new->data);
        // *tmp_new = template; ‚Æ“™‰¿
    }
    else
    {
        printf("Out of memory.\n");
    }

    return 0;
}

/*
$ ./a.out
name: Another fine product data: -0.000000
*/