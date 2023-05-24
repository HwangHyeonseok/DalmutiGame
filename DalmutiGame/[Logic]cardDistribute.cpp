// 카드 분배 로직 구현
// 각 플레이어들에게 카드를 분배해준다.

// NumPlayers : 플레이어 수
// playerCards : 각 플레이어가 가지고 있는 카드 배열
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM_CARDS 80 // 카드 개수 80개

#pragma region distributeCards 함수 : 카드 분배 로직
void distributeCards(int NumPlayers, int playerCards[4][20]) {
    int num_cards_per_player = NUM_CARDS / NumPlayers;
    int cards[NUM_CARDS];
    int idx = 0;

    // 카드 초기화
    for (int i = 1; i <= 12; i++) {
        for (int j = 0; j < i; j++) {
            cards[idx++] = i;
        }
    }
    cards[idx++] = 13;  // 조커 카드
    cards[idx++] = 13;

    // 카드 섞기
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }

    // 카드 분배
    int k = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 4; j++) {
            playerCards[j][i] = cards[k++];
        }
    }
}
#pragma endregion