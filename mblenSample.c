#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <stddef.h>

size_t mbsrcat(char* restrict s1, char* restrict s2, mbstate_t* restrict p_s1state, size_t n)
{
    int result = -1;
    size_t i = strlen(s1);
    // 0�o�C�g���������Ă��Ȃ�
    if(i >= n - (MB_CUR_MAX + 1))
    {
        return 0;
    }
    // s1��������ԂɃV�t�g�_�E��
    if (! mbsinit(p_s1state))
    {
        // �V�t�g�V�[�P���X��������Ԃ𓾂�悤�ɕt������
        result = wcrtomb(s1 + i, L'\0', p_s1state);
        // �������G���[
        if(result == -1)
        {
            s1[i] = '\0';
            return (size_t)-1;
        }
        else
        {
            i += result;
        }
    }

    // �}���`�o�C�g�����S�̂���x�ɃR�s�[����
    // ��Ԃ�ς����Ɏ��̕����̒��������߂�
    size_t j = 0;
    while ((result = mblen(s2 + j, MB_CUR_MAX)) <= (n - (i + 1)))
    {
        if(result == 0)
        {
            break;
        }
        if(result == -1)
        {
            s1[i] = '\0';
            return (size_t)-1;
        }
        // ���̕��������܂�B�R�s�[���ď�Ԃ��X�V
        strncpy(s1 + i, s2 + j, mbrlen(s2 + j, MB_CUR_MAX, p_s1state));
        i += result;
        j += result;
    }
    s1[i] = '\0';
    return j;
}

int main(void)
{
    char *s1;
    char *s2;
    mbstate_t *p_s1state;
    int i;
    size_t j;

    j = mbsrcat(s1, s2, p_s1state, i);

    return 0;

}