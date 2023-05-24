// 카드 제출 로직

// sub_fail_check 함수 : 카드 제출 시 틀린 카드를 제출했는지 체크 (카드 제출 유효성 체크)
// ----------------틀린 카드 제출 조건------------------------------
//  1) 제출 카드 범위가 1~13이 아닌 경우
//  2) 제출하는 카드가 지금 가지고 있는 카드보다 더 많은 경우
// ----------------------------------------------------------------------------------------

// check_cards 함수 : 어떤 카드를 냈는지 알려주는 함수
// card_sub 함수 : 입력받은 카드 제출 구현 함수
// check_player_card 함수 : 현재 플레이어가 가지고 있는 카드를 실시간으로 출력

#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include "[Algorithm]Sorting.h"

int cards[20] = { 0, };
// 이전 카드 정보
int beforeCardName = 99;
int beforeCardCount = 99;

int joker_count = 0;

#pragma region SubmitCardCheck 함수 : 카드 제출 시 틀린 카드를 제출했는지 체크(카드 제출 유효성 체크)
int sub_fail_check(int card_name, int card_count, char s_name, int s[4][20]) //카드 제출시 오류사항있는지 체크
{
    if (card_name < 0 || card_name > 13)
    {
        return 1; //제출 카드 범위가 1~13이 아니라면 오류코드 1 return
    }

    int count = 0; // 현재 들고 있는 카드 장수
    for (int j = 0; j < 20; j++) // 현재 들고 있는 카드 장수를 확인하는 반복문
    {
        // s_name : player을 지칭
        // card_name : 제출한 카드 번호
        // 덱에서 제출한 카드 번호와 덱에서 카드 번호가 몇 개 일치하는지 체크
        // ex) player2가 가지고 있는 덱은 ..... 10 10 10 10 10 10 ....
        //10 10 10 10 10 제출 => card_name : 10, count : 6, card_count : 5
        if (s[s_name][j] == card_name) 
        {
            count = count + 1;
        }
    }
    // card_count : 제출한 카드의 장수
    if (card_count > count) return 2;               //제출하려고 한 카드 장수가 들고있는 카드 장수보다 크면 오류코드 2 return
    if ((beforeCardCount != 99) && (card_count != beforeCardCount)) return 3;    //제출한 카드가 이전 플레이어가 제출한 카드 장수와 같지 않다면 오류코드 3 return
    if (card_name > beforeCardName) return 4;       //제출한 카드가 이전 플레이어가 제출한 카드보다 높은등급이 아니면 오류코드 4 return


    beforeCardName = card_name;
    beforeCardCount = card_count;
    if (joker_count == 1) {
        beforeCardCount += 1;
    }
    if (joker_count == 2) {
        beforeCardCount += 2;
    }

    return 0; //문제 없이 정상이라면 0 return
}
#pragma endregion

#pragma region check_cards 함수 : 어떤 카드를 냈는지 알려주는 함수 - 제출한 카드 개수도 알려준다.
int check_cards(char input_cards[])         //문자열 배열로 받은 값이 어떤 카드를 냈는지 알려줌 int로 return
{
    // ex) 11 11 11 => i : 3, ptr : 11, cards 배열에는 [11, 11, 11]
    int i = 0; // i는 개수
    char* ptr = strtok(input_cards, " ");   // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환
    while (ptr != NULL)                  // 자른 문자열이 나오지 않을 때까지 반복
    {
        cards[i++] = atoi(ptr);
        ptr = strtok(NULL, " ");         // 다음 문자열을 잘라서 포인터를 반환
    }

    bubble_sort(cards, i);
    return i;
}
#pragma endregion

#pragma region card_sub 함수 : 입력받은 카드 제출 구현 함수 (submitCard.cpp의 메인점)
int card_sub(char player_name, int playerCards[4][20]) //카드 제출 함수
{
    char s_name = player_name;
    int s[4][20];
    for (int i = 0; i < 4; i++) //sub_fail_check함수로 인수 넘겨주기 위한 배열복사
    {
        for (int j = 0; j < 20; j++) 
            s[i][j] = playerCards[i][j];
    }

    int card_name = 13;         //제출할 카드 번호
    int card_count = 0;      //제출할 카드 수량
    int correct_card;      //오류코드 번호
    int pass;            //pass유무 변수
    char input_cards[100];

reset:
    printf("pass는 1, 카드제출은 0을 입력하시오(1.pass/0.제출) : "); //기술적 문제로 pass여부 먼저 확인/ 추후 템플릿 적용예정
    scanf("%d", &pass);
    getchar();


    if (pass == 1)
    {
        printf("턴을 pass하셨습니다.\n\n");
    }
    else if (pass == 0) //pass하지 않았다면 카드 제출 로직 실행
    {
        printf("제출할 카드를 입력하시오 : ");
        gets_s(input_cards);

        card_count = check_cards(input_cards);

        int k = card_count;            //조커 유무 확인 및 제출한 카드 번호 정하기


        // 여러장의 카드를 제출했을 경우 (2장 이상)
        if (k > 1)
        {
            for (int i = 0; i < k-1; i++)
            { // cards : 낸 카드 배열
                if ((cards[i] == cards[i + 1]) && ((0 < cards[i]) && (cards[i] < 13))) card_name = cards[i];         //카드 번호를 알려줌
                if (cards[i] != cards[i + 1] && cards[i + 1] == 13)
                {
                    card_count--;
                    joker_count++;   //조커 1장을 제출했을 경우
                }
                if (cards[i] == cards[i + 1] && cards[i + 1] == 13) {
                    card_count--;
                    joker_count++;   //조커 2장을 제출했을 경우
                }
            }
        }
        // 카드를 하나만 제출했을 경우
        if (k == 1) {
            card_name = cards[0];
            if (card_name == 13) { // 1장의 조커 카드만 낸 경우
                printf("조커카드를 1장만 단일로 제출할 수 없습니다. 조커카드 효과는 카드 복제 효과입니다.\n");
                goto reset;
            }
        }

        correct_card = sub_fail_check(card_name, card_count, s_name, s); //제출한 카드 범위 오류 확인

        if (correct_card == 0) printf("카드가 정상적으로 제출되었습니다. \n\n      %d, %d\n", beforeCardName, beforeCardCount);
        else if (correct_card == 1) { printf("%d번 카드가 존재하지 않습니다.\n\n", card_name); goto reset; }
        else if (correct_card == 2) { printf("%d번 카드의 개수가 부족합니다.\n\n", card_name); goto reset; }
        else if (correct_card == 3) { printf("이전 플레이어와 같은 장수인 %d장의 카드를 제출해야 합니다.\n\n", beforeCardCount); goto reset; }
        else if (correct_card == 4) { printf("이전 플레이어가 제출한 %d번 카드보다 높은 등급의 카드를 제출해야합니다.\n\n", beforeCardName); goto reset; }

        for (int i = 0; i < card_count; i++) //제출한 카드를 플레이어 덱에서 카드 제외
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
        for (int i = 0; i < joker_count; i++) //제출한 조커 카드를 플레이어 덱에서 카드 제외
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