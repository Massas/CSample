/*
* noreturn.c
* Copyright (c) 2014 kaoru <kaoru@bsd>
*/
#include <stdlib.h>

_Noreturn void my_exit(void)
{
    exit(EXIT_SUCCESS);
    //    return 0;
    //_NoreturnSample.c:9:12: warning: function declared ÅenoreturnÅf has a ÅereturnÅf statement
    // 9 |     return 0;
}

#ifdef DEBUG
_Noreturn void none_exit(void)
{
    // this is error
}
#endif

int main(int argc, char* argv[])
{
    my_exit();
    exit(EXIT_SUCCESS);
}