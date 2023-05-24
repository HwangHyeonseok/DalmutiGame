// ī�� ���� ����

// sub_fail_check �Լ� : ī�� ���� �� Ʋ�� ī�带 �����ߴ��� üũ (ī�� ���� ��ȿ�� üũ)
// ----------------Ʋ�� ī�� ���� ����------------------------------
//  1) ���� ī�� ������ 1~13�� �ƴ� ���
//  2) �����ϴ� ī�尡 ���� ������ �ִ� ī�庸�� �� ���� ���
// ----------------------------------------------------------------------------------------

// check_cards �Լ� : � ī�带 �´��� �˷��ִ� �Լ�
// card_sub �Լ� : �Է¹��� ī�� ���� ���� �Լ�
// check_player_card �Լ� : ���� �÷��̾ ������ �ִ� ī�带 �ǽð����� ���

#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include "[Algorithm]Sorting.h"

int cards[20] = { 0, };
// ���� ī�� ����
int beforeCardName = 99;
int beforeCardCount = 99;

int joker_count = 0;

#pragma region SubmitCardCheck �Լ� : ī�� ���� �� Ʋ�� ī�带 �����ߴ��� üũ(ī�� ���� ��ȿ�� üũ)
int sub_fail_check(int card_name, int card_count, char s_name, int s[4][20]) //ī�� ����� ���������ִ��� üũ
{
    if (card_name < 0 || card_name > 13)
    {
        return 1; //���� ī�� ������ 1~13�� �ƴ϶�� �����ڵ� 1 return
    }

    int count = 0; // ���� ��� �ִ� ī�� ���
    for (int j = 0; j < 20; j++) // ���� ��� �ִ� ī�� ����� Ȯ���ϴ� �ݺ���
    {
        // s_name : player�� ��Ī
        // card_name : ������ ī�� ��ȣ
        // ������ ������ ī�� ��ȣ�� ������ ī�� ��ȣ�� �� �� ��ġ�ϴ��� üũ
        // ex) player2�� ������ �ִ� ���� ..... 10 10 10 10 10 10 ....
        //10 10 10 10 10 ���� => card_name : 10, count : 6, card_count : 5
        if (s[s_name][j] == card_name) 
        {
            count = count + 1;
        }
    }
    // card_count : ������ ī���� ���
    if (card_count > count) return 2;               //�����Ϸ��� �� ī�� ����� ����ִ� ī�� ������� ũ�� �����ڵ� 2 return
    if ((beforeCardCount != 99) && (card_count != beforeCardCount)) return 3;    //������ ī�尡 ���� �÷��̾ ������ ī�� ����� ���� �ʴٸ� �����ڵ� 3 return
    if (card_name > beforeCardName) return 4;       //������ ī�尡 ���� �÷��̾ ������ ī�庸�� ��������� �ƴϸ� �����ڵ� 4 return


    beforeCardName = card_name;
    beforeCardCount = card_count;
    if (joker_count == 1) {
        beforeCardCount += 1;
    }
    if (joker_count == 2) {
        beforeCardCount += 2;
    }

    return 0; //���� ���� �����̶�� 0 return
}
#pragma endregion

#pragma region check_cards �Լ� : � ī�带 �´��� �˷��ִ� �Լ� - ������ ī�� ������ �˷��ش�.
int check_cards(char input_cards[])         //���ڿ� �迭�� ���� ���� � ī�带 �´��� �˷��� int�� return
{
    // ex) 11 11 11 => i : 3, ptr : 11, cards �迭���� [11, 11, 11]
    int i = 0; // i�� ����
    char* ptr = strtok(input_cards, " ");   // " " ���� ���ڸ� �������� ���ڿ��� �ڸ�, ������ ��ȯ
    while (ptr != NULL)                  // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
    {
        cards[i++] = atoi(ptr);
        ptr = strtok(NULL, " ");         // ���� ���ڿ��� �߶� �����͸� ��ȯ
    }

    bubble_sort(cards, i);
    return i;
}
#pragma endregion

#pragma region card_sub �Լ� : �Է¹��� ī�� ���� ���� �Լ� (submitCard.cpp�� ������)
int card_sub(char player_name, int playerCards[4][20]) //ī�� ���� �Լ�
{
    char s_name = player_name;
    int s[4][20];
    for (int i = 0; i < 4; i++) //sub_fail_check�Լ��� �μ� �Ѱ��ֱ� ���� �迭����
    {
        for (int j = 0; j < 20; j++) 
            s[i][j] = playerCards[i][j];
    }

    int card_name = 13;         //������ ī�� ��ȣ
    int card_count = 0;      //������ ī�� ����
    int correct_card;      //�����ڵ� ��ȣ
    int pass;            //pass���� ����
    char input_cards[100];

reset:
    printf("pass�� 1, ī�������� 0�� �Է��Ͻÿ�(1.pass/0.����) : "); //����� ������ pass���� ���� Ȯ��/ ���� ���ø� ���뿹��
    scanf("%d", &pass);
    getchar();


    if (pass == 1)
    {
        printf("���� pass�ϼ̽��ϴ�.\n\n");
    }
    else if (pass == 0) //pass���� �ʾҴٸ� ī�� ���� ���� ����
    {
        printf("������ ī�带 �Է��Ͻÿ� : ");
        gets_s(input_cards);

        card_count = check_cards(input_cards);

        int k = card_count;            //��Ŀ ���� Ȯ�� �� ������ ī�� ��ȣ ���ϱ�


        // �������� ī�带 �������� ��� (2�� �̻�)
        if (k > 1)
        {
            for (int i = 0; i < k-1; i++)
            { // cards : �� ī�� �迭
                if ((cards[i] == cards[i + 1]) && ((0 < cards[i]) && (cards[i] < 13))) card_name = cards[i];         //ī�� ��ȣ�� �˷���
                if (cards[i] != cards[i + 1] && cards[i + 1] == 13)
                {
                    card_count--;
                    joker_count++;   //��Ŀ 1���� �������� ���
                }
                if (cards[i] == cards[i + 1] && cards[i + 1] == 13) {
                    card_count--;
                    joker_count++;   //��Ŀ 2���� �������� ���
                }
            }
        }
        // ī�带 �ϳ��� �������� ���
        if (k == 1) {
            card_name = cards[0];
            if (card_name == 13) { // 1���� ��Ŀ ī�常 �� ���
                printf("��Ŀī�带 1�常 ���Ϸ� ������ �� �����ϴ�. ��Ŀī�� ȿ���� ī�� ���� ȿ���Դϴ�.\n");
                goto reset;
            }
        }

        correct_card = sub_fail_check(card_name, card_count, s_name, s); //������ ī�� ���� ���� Ȯ��

        if (correct_card == 0) printf("ī�尡 ���������� ����Ǿ����ϴ�. \n\n      %d, %d\n", beforeCardName, beforeCardCount);
        else if (correct_card == 1) { printf("%d�� ī�尡 �������� �ʽ��ϴ�.\n\n", card_name); goto reset; }
        else if (correct_card == 2) { printf("%d�� ī���� ������ �����մϴ�.\n\n", card_name); goto reset; }
        else if (correct_card == 3) { printf("���� �÷��̾�� ���� ����� %d���� ī�带 �����ؾ� �մϴ�.\n\n", beforeCardCount); goto reset; }
        else if (correct_card == 4) { printf("���� �÷��̾ ������ %d�� ī�庸�� ���� ����� ī�带 �����ؾ��մϴ�.\n\n", beforeCardName); goto reset; }

        for (int i = 0; i < card_count; i++) //������ ī�带 �÷��̾� ������ ī�� ����
        {
            for (int j = 0; j < 20; j++)
            {
                if (playerCards[player_name][j] == card_name)
                {
                    playerCards[player_name][j] = 0;
                    break;
                }
            }
        }
        for (int i = 0; i < joker_count; i++) //������ ��Ŀ ī�带 �÷��̾� ������ ī�� ����
        {
            for (int j = 0; j < 20; j++)
            {
                if (playerCards[player_name][j] == 13)
                {
                    playerCards[player_name][j] = 0;
                    break;
                }
            }
        }
        //joker_count = 0; 
    }

    return 0;
}
#pragma endregion