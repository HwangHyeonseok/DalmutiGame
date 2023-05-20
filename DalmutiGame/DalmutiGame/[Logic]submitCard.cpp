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

#pragma region sub_fail_check �Լ� : ī�� ���� �� Ʋ�� ī�带 �����ߴ��� üũ(ī�� ���� ��ȿ�� üũ)
int sub_fail_check(int card_name, int card_count, char s_name, int s[4][20]) //ī�� ����� ���������ִ��� üũ
{
    if (card_name < 0 || card_name > 13)
    {
        return 1; //���� ī�� ������ 1~13�� �ƴ϶�� �����ڵ� 1 return
    }

    int count = 0;
    for (int j = 0; j < 20; j++) //���� ��� �ִ� ī�� ����� Ȯ���ϴ� �ݺ���
    {
        if (s[s_name][j] == card_name)
        {
            count = count + 1;
        }
    }

    if (card_count > count)
    {
        return 2; //�����Ϸ��� �� ī�� ����� ����ִ� ī�� ������� ũ�� �����ڵ� 2 return
    }

    return 0; //���� ���� �����̶�� 0 return
}
#pragma endregion

#pragma region check_cards �Լ� : � ī�带 �´��� �˷��ִ� �Լ�
int check_cards(char input_cards[])         //���ڿ� �迭�� ���� ���� � ī�带 �´��� �˷��� int�� return
{
    int i = 0;
    char* ptr = strtok(input_cards, " ");   // " " ���� ���ڸ� �������� ���ڿ��� �ڸ�, ������ ��ȯ
    while (ptr != NULL)                  // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
    {
        cards[i++] = atoi(ptr);
        ptr = strtok(NULL, " ");         // ���� ���ڿ��� �߶� �����͸� ��ȯ
    }

    return i;
}
#pragma endregion

#pragma region card_sub �Լ� : �Է¹��� ī�� ���� ���� �Լ�
int card_sub(char player_name, int players[4][20]) //ī�� ���� �Լ�
{
    char s_name = player_name;
    int s[4][20];
    for (int i = 0; i < 4; i++) //sub_fail_check�Լ��� �μ� �Ѱ��ֱ� ���� �迭����
    {
        for (int j = 0; j < 20; j++) s[i][j] = players[i][j];
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
        int joker_count = 0;

        // �������� ī�带 �������� ��� (2�� �̻�)
        if (k > 1)
        {
            for (int i = 0; i < k; i++)
            {
                if (cards[i] == cards[i + 1] && (0 < cards[i] && cards[i] < 13)) card_name = cards[i];         //ī�� ��ȣ�� �˷���
                if (cards[i] != cards[i + 1] && cards[i + 1] == 13) card_count = card_count - 1; joker_count = 1;   //��Ŀ 1���� �������� ���
                if (cards[i] == cards[i + 1] && cards[i + 1] == 13) card_count = card_count - 2; joker_count = 2;   //��Ŀ 2���� �������� ���
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

        if (correct_card == 0) printf("ī�尡 ���������� ����Ǿ����ϴ�. \n\n");
        else if (correct_card == 1) { printf("%d�� ī�尡 �������� �ʽ��ϴ�.\n\n", card_name); goto reset; }
        else if (correct_card == 2) { printf("%d�� ī���� ������ �����մϴ�.\n\n", card_name); goto reset; }

        for (int i = 0; i < card_count; i++) //������ ī�带 �÷��̾� ������ ī�� ����
        {
            for (int j = 0; j < 20; j++)
            {
                if (players[player_name][j] == card_name)
                {
                    players[player_name][j] = 0;
                    break;
                }
            }
        }
        for (int i = 0; i < joker_count; i++) //������ ��Ŀ ī�带 �÷��̾� ������ ī�� ����
        {
            for (int j = 0; j < 20; j++)
            {
                if (players[player_name][j] == 13)
                {
                    players[player_name][j] = 0;
                    break;
                }
            }
        }
    }

    return 0;
}
#pragma endregion

#pragma region check_player_card �Լ� : ���� �÷��̾ ������ �ִ� ī�带 �ǽð����� ���
void check_player_card(int players[4][20]) //�ǽð� �÷��̾� ī�� ��Ȳ ���(print)
{
    for (int i = 0; i < 4; i++) {
        printf("�÷��̾� %d�� ��: ", i + 1);
        bubble_sort(players[i], 20); // ���� ���ķ� ����
        for (int j = 0; j < 20; j++) {
            printf("%d ", players[i][j]);
        }
        printf("\n");
    }
}
#pragma endregion