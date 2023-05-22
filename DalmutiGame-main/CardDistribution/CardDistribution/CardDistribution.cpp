#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 80 // 카드 개수 80개

void distributeCards(int num_players) {
    int num_cards_per_player = NUM_CARDS / num_players;
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

    // 카드 나누기
    for (int i = 0; i < num_players; i++) {
        printf("Player %d's cards: ", i + 1);
        for (int j = i * num_cards_per_player; j < (i + 1) * num_cards_per_player; j++) {
            printf("%d ", cards[j]);
        }
        printf("\n");
    }
}

int main() {
    int num_players = 4; // 플레이어 4명으로 고정
    distributeCards(num_players);
    return 0;
}