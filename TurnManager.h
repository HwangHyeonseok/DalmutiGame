#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NAME_LENGTH 20
#define NUM_PLAYERS 4


//임시로 플레이어 scanf로 입력받은 플레이어들, 전역변수
char players_name[NUM_PLAYERS][MAX_NAME_LENGTH] = { "One", "Two", "Three", "Four" };
Queue turnOrderQueue; // 함수간 간섭을 위해 전역 선언


void randTurn(char players[][MAX_NAME_LENGTH]) {
	srand((unsigned int)time(NULL));
	int turnOrder[4] = {555, 555, 555, 555}; // 초기화 555가 아니여도 괜찮음.
	while (true) { // 턴 순서를 정한다.
		if (turnOrder[0] == 555) {  // 첫번쨰 순서 정한후 다시 while문 진입
			turnOrder[0] = rand() % 4;
		}
		else if (turnOrder[1] == 555) {  // 두번째 순서
			do {
				turnOrder[1] = rand() % 4;
				
			} while (turnOrder[1] == turnOrder[0]);
		}
		else if (turnOrder[2] == 555) { // 세번째 순서
			do {
				turnOrder[2] = rand() % 4;
			} while (turnOrder[2] == turnOrder[0] or turnOrder[2] == turnOrder[1]);
		}
		else if (turnOrder[3] == 555) { // 네번째 순서
			do {
				turnOrder[3] = rand() % 4;
			} while (turnOrder[3] == turnOrder[0] or turnOrder[3] == turnOrder[1] or turnOrder[3] == turnOrder[2]);
		}
		else {
			for (int i = 0; i < 4; i++) {
				printf("%d ", turnOrder[i]+1);

			}
			printf("\n");

			break;
		}
	} // while문 종료  turnOrder에는 {0 3 2 1}과 같이 순서가 배치

	//turnOrder에 맞게 players[][] 재배치
	char tempP[NUM_PLAYERS][MAX_NAME_LENGTH];
	
	for (int i = 0; i < 4; i++) { //순서대로 배치하여 지역변수에 임시저장
		strcpy_s(tempP[i], players_name[turnOrder[i]]);
	}
	for (int i = 0; i < 4; i++) { //임시저장한 변수값을 전역변수에 저장
		strcpy_s(players_name[i], tempP[i]);
	}
}
void initTurn(void) { // randTurn 이후 실행하지않으면 입력받은대로 순서작성
	initializeQueue(&turnOrderQueue); // Q는 함수간 간섭을 위해 전역선언

	for (int i = 0; i < 4; i++) { //입력받은 players를 Q에 저장
		enqueue(&turnOrderQueue, players_name[i]);
	}
}
char* currentTurn(void) { // 현재 턴 플레이어를 char*값으로 반환
	return showNode(&turnOrderQueue);
}

void endTurn(void) { // 현재 턴 플레이어를 맨뒤로 
	char* temp = dequeue(&turnOrderQueue);
	enqueue(&turnOrderQueue, temp);
}
