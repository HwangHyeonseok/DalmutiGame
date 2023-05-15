#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int sub_fail_check(int card_name, int card_count)
{
    if (card_name < 0 || card_name > 12)
    {
        return 1;
    }
    //if (card_count < "player가 들고있는 카드 갯수")
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

    printf("pass는 1, 카드제출은0을 입력하시오(1.pass/0.제출) : ");
    scanf("%d", &pass);


    if (pass == 1)
    {
        printf("턴을 pass하셨습니다.\n");
    }
    else if (pass == 0)
    {
        printf("제출할 카드를 번호와 갯수를 입력하사오(카드번호/장수) : ");
        scanf("%d/%d", &card_name, &card_count);

        correct_card = sub_fail_check(card_name, card_count);

        if (correct_card == 0) printf("%d번 카드 %d장이 정상정으로 제출되었습니다. \n", card_name, card_count);
        else if (correct_card == 1) printf("%d번 카드가 존재하지 않습니다.\n", card_name);
    }

    return 0;
}




int main()
{
    card_sub();

    printf("프로그램을 종료하려면 아무기나 누르시오....\n");
    getchar();

    return 0;
}