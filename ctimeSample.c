#include <stdio.h>
#include <time.h>
char* ctime(const time_t* seconds);

int main(void)
{
    time_t eventtime = {0};
    short errorcode = 23;
    //���ݎ�����b�Ŏ擾
    time(&eventtime);
    //�b�f�[�^��l�Ԃ��ǂ߂郍�[�J���̓��t�Ǝ���������������ɕϊ�����
    fprintf(stderr, "%s: Error number %d occured.\n", ctime(&eventtime), errorcode);

    return 0;
}

/*
./a.out
Thu Oct  8 02:06:19 2020
: Error number 23 occured.
*/