#include <stdio.h>
#include "[Algorithm]sorting.h"

// �� �÷��̾��� �� ���
// �ش� �Ͽ� �ش��ϴ� �÷��̾��� �и� ����ؾ� �Ѵ�. => �� ���� ������ ����.
void printPlayerCards(int playerCards[4][20]) {
    for (int i = 0; i < 4; i++) {
        printf("�÷��̾� %d�� ��: ", i + 1);
        bubble_sort(playerCards[i], 20); // ���� ���ķ� ����
        for (int j = 0; j < 20; j++) {
            if (playerCards[i][j] == 0) continue; // ī�� ��ȣ�� 0�� ���� ������ ī���̹Ƿ� ��¿��� �����Ѵ�.
            printf("%d ", playerCards[i][j]);
        }
        printf("\n");
    }
}