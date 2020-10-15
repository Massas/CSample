#include <stdio.h>
#include <ctype.h>
#include <locale.h>
int _isprint(int c);

int main(void)
{
    printf("\nThe current locale for the 'is...' function is '%s'.\n", setlocale(LC_CTYPE, NULL));
    printf("Here is a table of the 'is...' values for the characters from 0 to 127 in this locale:\n\n");

    for(unsigned int c = 0U; c < 128U; c++)
    {
        if(c % 24U == 0U)
        {
            printf("Code char alnum alpha blank cntrl digit graph lower print punct space\n");
            printf("---------------------------------------------------------------------\n");
        }
        printf("%4u %4c %3c %5c %5c %5c %5c %5c %5c %5c %5c %5c\n", c,
        (isprint(c) ?  c  : ' '),
        (isalnum(c) ? 'X' : ' '),
        (isalpha(c) ? 'X' : ' '),
        (isblank(c) ? 'X' : ' '),
        (iscntrl(c) ? 'X' : ' '),
        (isdigit(c) ? 'X' : ' '),
        (isgraph(c) ? 'X' : ' '),
        (islower(c) ? 'X' : ' '),
        (isprint(c) ? 'X' : ' '),
        (ispunct(c) ? 'X' : ' '),
        (isspace(c) ? 'X' : ' '));
    }
    return 0;
}

/*
$ ./a.out

The current locale for the 'is...' function is 'C'.
Here is a table of the 'is...' values for the characters from 0 to 127 in this locale:

Code char alnum alpha blank cntrl digit graph lower print punct space
---------------------------------------------------------------------
   0                          X
   1                          X
   2                          X
   3                          X
   4                          X
   5                          X
   6                          X
   7                          X
   8                          X
   9                    X     X                                   X
  10                          X                                   X
  11                          X                                   X
  12                          X                                   X
  13                          X                                   X
  14                          X
  15                          X
  16                          X
  17                          X
  18                          X
  19                          X
  20                          X
  21                          X
  22                          X
  23                          X
Code char alnum alpha blank cntrl digit graph lower print punct space
---------------------------------------------------------------------
  24                          X
  25                          X
  26                          X
  27                          X
  28                          X
  29                          X
  30                          X
  31                          X
  32                    X                             X           X
  33    !                                 X           X     X
  34    "                                 X           X     X
  35    #                                 X           X     X
  36    $                                 X           X     X
  37    %                                 X           X     X
  38    &                                 X           X     X
  39    '                                 X           X     X
  40    (                                 X           X     X
  41    )                                 X           X     X
  42    *                                 X           X     X
  43    +                                 X           X     X
  44    ,                                 X           X     X
  45    -                                 X           X     X
  46    .                                 X           X     X
  47    /                                 X           X     X
Code char alnum alpha blank cntrl digit graph lower print punct space
---------------------------------------------------------------------
  48    0   X                       X     X           X
  49    1   X                       X     X           X
  50    2   X                       X     X           X
  51    3   X                       X     X           X
  52    4   X                       X     X           X
  53    5   X                       X     X           X
  54    6   X                       X     X           X
  55    7   X                       X     X           X
  56    8   X                       X     X           X
  57    9   X                       X     X           X
  58    :                                 X           X     X
  59    ;                                 X           X     X
  60    <                                 X           X     X
  61    =                                 X           X     X
  62    >                                 X           X     X
  63    ?                                 X           X     X
  64    @                                 X           X     X
  65    A   X     X                       X           X
  66    B   X     X                       X           X
  67    C   X     X                       X           X
  68    D   X     X                       X           X
  69    E   X     X                       X           X
  70    F   X     X                       X           X
  71    G   X     X                       X           X
Code char alnum alpha blank cntrl digit graph lower print punct space
---------------------------------------------------------------------
  72    H   X     X                       X           X
  73    I   X     X                       X           X
  74    J   X     X                       X           X
  75    K   X     X                       X           X
  76    L   X     X                       X           X
  77    M   X     X                       X           X
  78    N   X     X                       X           X
  79    O   X     X                       X           X
  80    P   X     X                       X           X
  81    Q   X     X                       X           X
  82    R   X     X                       X           X
  83    S   X     X                       X           X
  84    T   X     X                       X           X
  85    U   X     X                       X           X
  86    V   X     X                       X           X
  87    W   X     X                       X           X
  88    X   X     X                       X           X
  89    Y   X     X                       X           X
  90    Z   X     X                       X           X
  91    [                                 X           X     X
  92    \                                 X           X     X
  93    ]                                 X           X     X
  94    ^                                 X           X     X
  95    _                                 X           X     X
Code char alnum alpha blank cntrl digit graph lower print punct space
---------------------------------------------------------------------
  96    `                                 X           X     X
  97    a   X     X                       X     X     X
  98    b   X     X                       X     X     X
  99    c   X     X                       X     X     X
 100    d   X     X                       X     X     X
 101    e   X     X                       X     X     X
 102    f   X     X                       X     X     X
 103    g   X     X                       X     X     X
 104    h   X     X                       X     X     X
 105    i   X     X                       X     X     X
 106    j   X     X                       X     X     X
 107    k   X     X                       X     X     X
 108    l   X     X                       X     X     X
 109    m   X     X                       X     X     X
 110    n   X     X                       X     X     X
 111    o   X     X                       X     X     X
 112    p   X     X                       X     X     X
 113    q   X     X                       X     X     X
 114    r   X     X                       X     X     X
 115    s   X     X                       X     X     X
 116    t   X     X                       X     X     X
 117    u   X     X                       X     X     X
 118    v   X     X                       X     X     X
 119    w   X     X                       X     X     X
Code char alnum alpha blank cntrl digit graph lower print punct space
---------------------------------------------------------------------
 120    x   X     X                       X     X     X
 121    y   X     X                       X     X     X
 122    z   X     X                       X     X     X
 123    {                                 X           X     X
 124    |                                 X           X     X
 125    }                                 X           X     X
 126    ~                                 X           X     X
 127                          X
*/