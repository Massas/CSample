#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strptrcmp(const void* sp1, const void* sp2);

int main(void)
{
    const char* words[] = { "Then", "he", "shouted", "What", "I",
                            "didn't", "hear", "what", "you", "said" };
    const size_t n = sizeof(words)/sizeof(words[0]);

    qsort(words, n, sizeof(words[0]), strptrcmp);

    for(int j = 0; j < n; j++)
    {
        puts(words[j]);
    }
    return 0;
}

// �Q�̃|�C���^�Q�Ƃŕ�������r����
int strptrcmp(const void* sp1, const void* sp2)
{
    // qsort()�|�C���^�ɑ΂��ă|�C���^��n��
    // strcmp��char*��n�����߂ɎQ�ƊO��������
    const char* s1 = *(char**) sp1;
    const char* s2 = *(char**) sp2;
    return strcmp(s1, s2);
}

/*
$ ./a.out
I
Then
What
didn't
he
hear
said
shouted
what
you
*/