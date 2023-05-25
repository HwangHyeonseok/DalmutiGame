#include <stdio.h>
#include "[Algorithm]sorting.h"

// 각 플레이어의 패 출력 (전체)
// 해당 턴에 해당하는 플레이어의 패를 출력해야 한다. => 턴 관리 로직에 있음.
void printPlayerCards(int playerCards[4][20]) {
    for (int i = 0; i < 4; i++) {
        printf("플레이어 %d의 패: ", i + 1);
        bubble_sort(playerCards[i], 20); // 버블 정렬로 정렬
        for (int j = 0; j < 20; j++) {
            if (playerCards[i][j] == 0) continue; // 카드 번호가 0인 것은 제출한 카드이므로 출력에서 제외한다.
            printf("%d ", playerCards[i][j]);
        }
        printf("\n");
    }
}

// 해당 플레이어의 패만 출력
void PrintThisTurnPlayerCards(int playerCards[4][20], int thisturn) {
    for (int i = 0; i < 4; i++) {
        if (i == thisturn) { // 해당 플레이어의 패만 보여준다.
            printf("플레이어 %d의 패: ", i + 1);
            bubble_sort(playerCards[i], 20); // 버블 정렬로 정렬
            for (int j = 0; j < 20; j++) {
                if (playerCards[i][j] == 0) continue; // 카드 번호가 0인 것은 제출한 카드이므로 출력에서 제외한다.
                printf("%d ", playerCards[i][j]);
            }
            printf("\n");
        }
    }
}