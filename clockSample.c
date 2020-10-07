#include <stdio.h>
#include <time.h>
clock_t clock(void);

int main(void)
{
    time_t start = {0};
    time(&start);
    for(long count = 0; count <= 50000000; ++count)
    {
        if(count % 1000000 != 0)
        {
            continue;
        }
        //CPUŽžŠÔ‚ÌŽæ“¾
        const clock_t ticks = clock();
        printf("Performed %ld million integer divisions; used %0.2f seconds of CPU time.\n"
                , count / 1000000, (double) ticks / CLOCKS_PER_SEC);
    }
    time_t stop = {0};
    time(&stop);
    printf("Finished in about %.0f seconds.\n", difftime(stop, start));

    return 0;
}

/*
$ ./a.out
Performed 0 million integer divisions; used 0.00 seconds of CPU time.
Performed 1 million integer divisions; used 0.00 seconds of CPU time.
Performed 2 million integer divisions; used 0.02 seconds of CPU time.
Performed 3 million integer divisions; used 0.02 seconds of CPU time.
Performed 4 million integer divisions; used 0.02 seconds of CPU time.
Performed 5 million integer divisions; used 0.03 seconds of CPU time.
Performed 6 million integer divisions; used 0.03 seconds of CPU time.
Performed 7 million integer divisions; used 0.03 seconds of CPU time.
Performed 8 million integer divisions; used 0.03 seconds of CPU time.
Performed 9 million integer divisions; used 0.05 seconds of CPU time.
Performed 10 million integer divisions; used 0.05 seconds of CPU time.
Performed 11 million integer divisions; used 0.05 seconds of CPU time.
Performed 12 million integer divisions; used 0.05 seconds of CPU time.
Performed 13 million integer divisions; used 0.05 seconds of CPU time.
Performed 14 million integer divisions; used 0.06 seconds of CPU time.
Performed 15 million integer divisions; used 0.06 seconds of CPU time.
Performed 16 million integer divisions; used 0.06 seconds of CPU time.
Performed 17 million integer divisions; used 0.06 seconds of CPU time.
Performed 18 million integer divisions; used 0.06 seconds of CPU time.
Performed 19 million integer divisions; used 0.06 seconds of CPU time.
Performed 20 million integer divisions; used 0.08 seconds of CPU time.
Performed 21 million integer divisions; used 0.08 seconds of CPU time.
Performed 22 million integer divisions; used 0.08 seconds of CPU time.
Performed 23 million integer divisions; used 0.08 seconds of CPU time.
Performed 24 million integer divisions; used 0.08 seconds of CPU time.
Performed 25 million integer divisions; used 0.08 seconds of CPU time.
Performed 26 million integer divisions; used 0.08 seconds of CPU time.
Performed 27 million integer divisions; used 0.08 seconds of CPU time.
Performed 28 million integer divisions; used 0.09 seconds of CPU time.
Performed 29 million integer divisions; used 0.09 seconds of CPU time.
Performed 30 million integer divisions; used 0.09 seconds of CPU time.
Performed 31 million integer divisions; used 0.09 seconds of CPU time.
Performed 32 million integer divisions; used 0.11 seconds of CPU time.
Performed 33 million integer divisions; used 0.11 seconds of CPU time.
Performed 34 million integer divisions; used 0.11 seconds of CPU time.
Performed 35 million integer divisions; used 0.11 seconds of CPU time.
Performed 36 million integer divisions; used 0.11 seconds of CPU time.
Performed 37 million integer divisions; used 0.12 seconds of CPU time.
Performed 38 million integer divisions; used 0.12 seconds of CPU time.
Performed 39 million integer divisions; used 0.12 seconds of CPU time.
Performed 40 million integer divisions; used 0.12 seconds of CPU time.
Performed 41 million integer divisions; used 0.12 seconds of CPU time.
Performed 42 million integer divisions; used 0.12 seconds of CPU time.
Performed 43 million integer divisions; used 0.14 seconds of CPU time.
Performed 44 million integer divisions; used 0.14 seconds of CPU time.
Performed 45 million integer divisions; used 0.14 seconds of CPU time.
Performed 46 million integer divisions; used 0.14 seconds of CPU time.
Performed 47 million integer divisions; used 0.14 seconds of CPU time.
Performed 48 million integer divisions; used 0.14 seconds of CPU time.
Performed 49 million integer divisions; used 0.16 seconds of CPU time.
Performed 50 million integer divisions; used 0.16 seconds of CPU time.
Finished in about 1 seconds.
*/