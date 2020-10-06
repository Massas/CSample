#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned long id;
    int data;
} record;

// 比較関数
static int id_cmp(const void* s1, const void* s2);

int main(void)
{
    record recordset[] = {{3UL, 5}, {5UL, -5}, {4UL, 10}, {2UL, 2}, {1UL, -17}};
    const size_t recordcount = sizeof(recordset) / sizeof(recordset[0]);

    printf("Query record number: ");
    record querykey = {0};
    scanf("%lu", &querykey.id);

    printf("\nRecords before sorting:\n\n %8s %8s %8s\n", "Index", "ID", "Data");

    for(int i = 0; i < recordcount; i++)
    {
        printf("%8d %8lu %8d\n", i, recordset[i].id, recordset[i].data);
    }
    // ソート処理
    qsort(recordset, recordcount, sizeof(record), id_cmp);

    printf("\nRecords after sorting:\n\n %8s %8s %8s\n", "Index", "ID", "Data");

    for(int i = 0; i < recordcount; i++)
    {
        printf("%8d %8lu %8d\n", i, recordset[i].id, recordset[i].data);
    }
    // バイナリサーチ処理：void型ポインタが返るのでrecord型ポインタにキャストして変数に格納する
    const record* found = (record*) bsearch(&querykey, recordset, recordcount, sizeof(record), id_cmp);

    if(found == NULL)
    {
        printf("No record with the ID %lu found.\n", querykey.id);
    }
    else
    {
        printf("The data value in record %lu 's data is %d.\n", querykey.id, found->data);
    }
} // end of main()

static int id_cmp(const void* s1, const void* s2)
{
    const record* p1 = (const record*) s1;
    const record* p2 = (const record*) s2;

    if(p1->id < p2->id)
    {
        return -1;
    }
    else if(p1->id == p2->id)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/*
Query record number: 4

Records before sorting:

    Index       ID     Data
       0        3        5
       1        5       -5
       2        4       10
       3        2        2
       4        1      -17

Records after sorting:

    Index       ID     Data
       0        1      -17
       1        2        2
       2        3        5
       3        4       10
       4        5       -5
The data value in record 4 's data is 10.
*/
