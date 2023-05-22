// ī�� �й� ���� ����
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "[Algorithm]Sorting.h"

#define NUM_CARDS 80 // ī�� ���� 80��

#pragma region distributeCards �Լ� : ī�� �й� ����
void distributeCards(int num_players, int playerCards[4][20]) {
    int num_cards_per_player = NUM_CARDS / num_players;
    int cards[NUM_CARDS];
    int idx = 0;

    // ī�� �ʱ�ȭ
    for (int i = 1; i <= 12; i++) {
        for (int j = 0; j < i; j++) {
            cards[idx++] = i;
        }
    }
    cards[idx++] = 13;  // ��Ŀ ī��
    cards[idx++] = 13;

    // ī�� ����
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }

    // ī�� �й�
    int k = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 4; j++) {
            playerCards[j][i] = cards[k++];
        }
    }
}
#pragma endregion

// �� �÷��̾��� �� ���
void printPlayerCards(int playerCards[4][20]) {
    for (int i = 0; i < 4; i++) {
        printf("�÷��̾� %d�� ��: ", i + 1);
        bubble_sort(playerCards[i], 20); // ���� ���ķ� ����
        for (int j = 0; j < 20; j++) {
            printf("%d ", playerCards[i][j]);
        }
        printf("\n");
    }
}
