#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int sub_fail_check(int card_name, int card_count)
{
    if (card_name < 0 || card_name > 12)
    {
        return 1;
    }
    //if (card_count < "player�� ����ִ� ī�� ����")
    {
        //return 2;
    }

    return 0;
}

int card_sub()
{
    int card_name;
    int card_count = 0;
    int correct_card;
    int pass;

    printf("pass�� 1, ī��������0�� �Է��Ͻÿ�(1.pass/0.����) : ");
    scanf("%d", &pass);


    if (pass == 1)
    {
        printf("���� pass�ϼ̽��ϴ�.\n");
    }
    else if (pass == 0)
    {
        printf("������ ī�带 ��ȣ�� ������ �Է��ϻ��(ī���ȣ/���) : ");
        scanf("%d/%d", &card_name, &card_count);

        correct_card = sub_fail_check(card_name, card_count);

        if (correct_card == 0) printf("%d�� ī�� %d���� ���������� ����Ǿ����ϴ�. \n", card_name, card_count);
        else if (correct_card == 1) printf("%d�� ī�尡 �������� �ʽ��ϴ�.\n", card_name);
    }

    return 0;
}




int main()
{
    card_sub();

    printf("���α׷��� �����Ϸ��� �ƹ��⳪ �����ÿ�....\n");
    getchar();

    return 0;
}