#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "[Logic]submitCard.h"

int turn = 0;
void PlayerTurnManagement(int players[4][20]) {

    while (turn != 5) // ī�� ���� Ȯ�ο� ���ѷ���
    {
        srand(time(NULL));
        int turn = rand() % 4 + 1;
        if (turn == 1)
        {
            printf("[player1�� ��]\n");
            getchar();
            printf("player1���� ī�� ���� �����Դϴ�.\n");
            card_sub(0, players);
            printf("player2���� ī�� ���� �����Դϴ�.\n");
            card_sub(1, players);
            printf("player3���� ī�� ���� �����Դϴ�.\n");
            card_sub(2, players);
            printf("player4���� ī�� ���� �����Դϴ�.\n");
            card_sub(3, players);

            check_player_card(players);
        }
        else if (turn == 2)
        {
            printf("[player2�� ��]\n");
            getchar();
            printf("player2���� ī�� ���� �����Դϴ�.\n");
            card_sub(1, players);
            printf("player3���� ī�� ���� �����Դϴ�.\n");
            card_sub(2, players);
            printf("player4���� ī�� ���� �����Դϴ�.\n");
            card_sub(3, players);
            printf("player1���� ī�� ���� �����Դϴ�.\n");
            card_sub(0, players);

            check_player_card(players);
        }
        else if (turn == 3)
        {
            printf("[player3�� ��]\n");
            getchar();
            printf("player3���� ī�� ���� �����Դϴ�.\n");
            card_sub(2, players);
            printf("player4���� ī�� ���� �����Դϴ�.\n");
            card_sub(3, players);
            printf("player1���� ī�� ���� �����Դϴ�.\n");
            card_sub(0, players);
            printf("player2���� ī�� ���� �����Դϴ�.\n");
            card_sub(1, players);

            check_player_card(players);
        }
        else if (turn == 4)
        {
            printf("[player4�� ��]\n");
            getchar();
            printf("player4���� ī�� ���� �����Դϴ�.\n");
            card_sub(3, players);
            printf("player1���� ī�� ���� �����Դϴ�.\n");
            card_sub(0, players);
            printf("player2���� ī�� ���� �����Դϴ�.\n");
            card_sub(1, players);
            printf("player3���� ī�� ���� �����Դϴ�.\n");
            card_sub(2, players);

            check_player_card(players);
        }

        printf("\n\n\n");
    }
}