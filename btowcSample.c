#include <stdio.h>
#include <wchar.h>
wint_t btowc(int c);

int main(void)
{
    // �ŏ���128�o�C�g�l�̃��C�h�����̕\�����
    wint_t low_table[128];
    // 1�I���W���ɂ���
    for(int i = 1; i < 129; i++)
    {
        low_table[i] = (wchar_t) btowc(i);
        printf("%lc ", low_table[i]);
        // 16��o�͂�������s�����
        if((i % 16) == 0)
        {
            printf("\n");
        }
    }
}

/*
     
   
          

1 2 3 4 5 6 7 8 9 : ; < = > ? @
A B C D E F G H I J K L M N O P
Q R S T U V W X Y Z [ \ ] ^ _ `
a b c d e f g h i j k l m n o p
q r s t u v w x y z { | } ~ 
*/