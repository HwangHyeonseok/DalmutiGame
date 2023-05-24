#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "[Logic]cardDistribute.h" // 카드 분배 로직 
#include "[Logic]submitCard.h" // 카드 제출 로직 (유효성 체크 포함)
#include "[Logic]turnManager.h" // 턴 관리 로직
#include "[Algorithm]sorting.h" // 정렬 알고리즘 정의
#include "[Logic]PrintPlayerCards.h" // 카드 출력


int main()
{
    srand(time(NULL));
    int player1, player2, player3, player4;
    int NumPlayers = 4; // 플레이어 인원 수 (현재는 4명으로 고정)
    int players[4][20];


    distributeCards(NumPlayers, players); // 카드 분배 
    printPlayerCards(players); // 분배한 카드 출력

    printf("\n\n\n\n\n");

    PlayerTurnManagement(players); // 플레이어 턴 로직


    return 0;
}