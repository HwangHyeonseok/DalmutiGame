//// 카드 제출 로직
//
//// sub_fail_check 함수 : 카드 제출 시 틀린 카드를 제출했는지 체크 (카드 제출 유효성 체크)
//// ----------------틀린 카드 제출 조건------------------------------
////  1) 제출 카드 범위가 1~13이 아닌 경우
////  2) 제출하는 카드가 지금 가지고 있는 카드보다 더 많은 경우
//// ----------------------------------------------------------------------------------------
//
//// check_cards 함수 : 어떤 카드를 냈는지 알려주는 함수
//// card_sub 함수 : 입력받은 카드 제출 구현 함수
//// check_player_card 함수 : 현재 플레이어가 가지고 있는 카드를 실시간으로 출력
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stack>
//#include "[Algorithm]Sorting.h"
//
//int subCardArr[20] = { 0, };
//// 이전 카드 정보
//int beforeCardName = 99;
//int beforeCardCount = 99;
//int pass_3 = 0;
//
//int jokerCount = 0;
//
//#pragma region SubmitCardCheck 함수 : 카드 제출 시 틀린 카드를 제출했는지 체크(카드 제출 유효성 체크)
//int sub_fail_check(int cardName, int cardCount, char nowTurnPlayer, int playerCards[4][20], int jokerCount) //카드 제출시 오류사항있는지 체크
//{
//    if (cardName < 0 || cardName > 13)
//    {
//        return 1; //제출 카드 범위가 1~13이 아니라면 오류코드 1 return
//    }
//
//    int count = 0; // 현재 들고 있는 카드 장수
//    int count_J = 0; //현재 들고 있는 조커 카드 장수
//
//    for (int j = 0; j < 20; j++) // 현재 들고 있는 카드 장수를 확인하는 반복문
//    {
//        // nowTurnPlayer : 현재 player을 지칭
//        // cardName : 제출한 카드 번호
//        // 덱에서 제출한 카드 번호와 덱에서 카드 번호가 몇 개 일치하는지 체크
//        // ex) player2가 가지고 있는 덱은 ..... 10 10 10 10 10 10 ....
//        //10 10 10 10 10 제출 => cardName : 10, count : 6, cardCount : 5
//        if (playerCards[nowTurnPlayer][j] == cardName)
//        {
//            count = count + 1;
//            //제출한 카드 번호와 일치하는 현재 플레이어가 가지고 있는 카드 장수
//        }
//        if (playerCards[nowTurnPlayer][j] == 13)
//        {
//            count_J = count_J + 1;
//            //현재 플레이어가 가지고 있는 조커 장수
//        }
//    }
//
//    // card_count : 제출한 카드의 장수
//    if (cardCount - jokerCount > count || jokerCount > count_J) return 2;               //제출하려고 한 카드 장수가 들고있는 카드 장수보다 크면 오류코드 2 return
//    if ((beforeCardCount != 99) && (cardCount != beforeCardCount)) return 3;    //제출한 카드가 이전 플레이어가 제출한 카드 장수와 같지 않다면 오류코드 3 return
//    if (cardName >= beforeCardName) return 4;       //제출한 카드가 이전 플레이어가 제출한 카드보다 높은등급이 아니면 오류코드 4 return
//
//
//    beforeCardName = cardName;      //다음 플레이어가 높은 등급의 카드를 제출할 수 있게 저장
//    beforeCardCount = cardCount;    //다음 플레이어가 제출할 카드 장수 저장
//
//    return 0; //문제 없이 정상이라면 0 return
//}
//#pragma endregion
//
//#pragma region check_cards 함수 : 어떤 카드를 냈는지 알려주는 함수 - 제출한 카드 개수도 알려준다.
//int check_cards(char inputCards[])         //문자열 배열로 받은 값이 어떤 카드를 냈는지 알려줌 int로 return
//{
//    // ex) 11 11 11 => i : 3, ptr : 11, cards 배열에는 [11, 11, 11]
//    int cardCount = 0; // cardCount는 제출한 카드 개수
//    char* ptr = strtok(inputCards, " ");   // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환
//    while (ptr != NULL)                  // 자른 문자열이 나오지 않을 때까지 반복
//    {
//        subCardArr[cardCount++] = atoi(ptr);    //잘린 문자열은 char형이므로 int형 변환
//        ptr = strtok(NULL, " ");         // 다음 문자열을 잘라서 포인터를 반환
//    }
//
//    bubble_sort(subCardArr, cardCount);     //조커가 섞여 있을 수도 있음으로 정렬
//    //ex. 10 13 10 13 제출시 10 10 13 13으로 정렬
//    return cardCount;                       //제출한 카드장수 return
//}
//#pragma endregion
//
//#pragma region joker_count 함수 : 제출한 카드에 조커가 몇장 포함되어 있는지 알려주는 함수
//int joker_count(int subCardArr[20], int cardName, int cardCount)    //제출한 카드에 조커가 몇장 포함되어 있는지 알려준다
//{
//    jokerCount = 0;
//    for (int i = 0; i < cardCount; i++)                 //제출한 카드 장수만큼 반복
//    {
//        if (subCardArr[i] == 13) jokerCount++;           //제출한 카드 배열에 13(조커)카드가 있다면 jokerCount 1씩 증가 - 최대 2까지 증가할것
//    }
//
//    return jokerCount;                                  //제출한 조커 개수를 return
//}
//#pragma endregion
//
//#pragma region delete_submited_card 함수 : 오류 검사까지 끝난 제출 로직을 완료했다면 제출한 카드를 각 플레이어 덱에서 삭제 시켜주는 함수
//int delete_submited_card(int player_Cards[4][20], char nowTurnPlayer, int cardName, int cardCount, int jokerCount)
//{   //제출한 카드를 각 플레이어 덱에서 삭제 시켜준다
//    for (int i = 0; i < cardCount - jokerCount; i++) //제출한 카드중 '조커가 아닌 카드'를 플레이어 덱에서 카드 제외
//    {   //10 10 13 13 제출시 (전체 카드 장수) - (조커 카드 장수) = 4 - 2로 2번만 반복
//        for (int j = 0; j < 20; j++)
//        {
//            if (player_Cards[nowTurnPlayer][j] == cardName)     //제출한 카드번호와 일치하면 0으로 삭제
//            {
//                player_Cards[nowTurnPlayer][j] = 0;
//                break;
//            }
//        }
//    }
//    for (int i = 0; i < jokerCount; i++) //제출한 카드중 '조커 카드'를 플레이어 덱에서 카드 제외
//    {   //10 10 13 13 제출시 조커 카드가 2장이므로 2번 반복
//        for (int j = 0; j < 20; j++)
//        {
//            if (player_Cards[nowTurnPlayer][j] == 13)           //제출한 조커와 일치하면 0으로 삭제
//            {
//                player_Cards[nowTurnPlayer][j] = 0;
//                break;
//            }
//        }
//    }
//
//    return 0;
//}
//#pragma endregion
//
//#pragma region card_sub 함수 : 입력받은 카드 제출 구현 함수 (submitCard.cpp의 메인점)
//int card_sub(char player_Name, int player_Cards[4][20]) //카드 제출 함수
//{
//    if (player_Cards[player_Name][19] == 0)
//    {
//        pass_3++;
//        return 0;
//    }
//    char nowTurnPlayer = player_Name;
//    int playerCards[4][20];
//    for (int i = 0; i < 4; i++) //sub_fail_check함수로 인수 넘겨주기 위한 배열복사
//    {
//        for (int j = 0; j < 20; j++)
//            playerCards[i][j] = player_Cards[i][j];
//    }
//
//    int cardName;        //제출할 카드 번호
//    int cardCount;      //제출할 카드 수량
//    int correctCard;      //오류코드 번호
//    int pass;            //pass유무 변수
//    char inputCards[100];
//
//reset:
//    printf("pass는 1, 카드제출은 0을 입력하시오(1.pass/0.제출) : "); //pass여부 확인
//    scanf("%d", &pass);
//    getchar();
//
//    if (pass_3 >= 3) { // 아무거나 제출할 수 있도록 한다.
//        beforeCardName = 99;
//        beforeCardCount = 99;
//    }
//
//    if (pass == 1)
//    {
//        printf("턴을 pass하셨습니다.\n\n");
//        pass_3++;
//    }
//    else if (pass == 0) //pass하지 않았다면 카드 제출 로직 실행
//    {
//        printf("제출할 카드를 입력하시오 : ");
//        gets_s(inputCards);     //문자열로 제출할 카드들 입력받기
//
//        cardCount = check_cards(inputCards);    //카드 장수
//        cardName = subCardArr[0];               //카드 번호
//
//        int jokerCount = joker_count(subCardArr, cardName, cardCount);
//
//        correctCard = sub_fail_check(cardName, cardCount, nowTurnPlayer, playerCards, jokerCount); //제출한 카드 범위 오류 확인
//
//        if (correctCard == 0) printf("카드가 정상적으로 제출되었습니다. \n\n      %d, %d\n", beforeCardName, beforeCardCount);     //return 0 정상
//        else if (correctCard == 1) { printf("%d번 카드가 존재하지 않습니다.\n\n", cardName); goto reset; }                         //return 1 오류
//        else if (correctCard == 2) { printf("%d번 카드의 개수가 부족합니다.\n\n", cardName); goto reset; }                         //return 2 오류
//        else if (correctCard == 3) { printf("이전 플레이어와 같은 장수인 %d장의 카드를 제출해야 합니다.\n\n", beforeCardCount); goto reset; } //return 3 오류
//        else if (correctCard == 4) { printf("이전 플레이어가 제출한 %d번 카드보다 높은 등급의 카드를 제출해야합니다.\n\n", beforeCardName); goto reset; } //return 4 오류
//
//        delete_submited_card(player_Cards, nowTurnPlayer, cardName, cardCount, jokerCount);
//        pass_3 = 0;
//    }
//    return 0;
//}
//
//#pragma endregion

// START - goto문 제거
#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include "[Algorithm]Sorting.h"

int subCardArr[20] = { 0, };
int beforeCardName = 99;
int beforeCardCount = 99;
int pass_3 = 0;
int jokerCount = 0;

int sub_fail_check(int cardName, int cardCount, char nowTurnPlayer, int playerCards[4][20], int jokerCount) {
    if (cardName < 0 || cardName > 13) {
        return 1;
    }

    int count = 0;
    int count_J = 0;

    for (int j = 0; j < 20; j++) {
        if (playerCards[nowTurnPlayer][j] == cardName) {
            count = count + 1;
        }
        if (playerCards[nowTurnPlayer][j] == 13) {
            count_J = count_J + 1;
        }
    }

    if (cardCount - jokerCount > count || jokerCount > count_J) return 2;
    if ((beforeCardCount != 99) && (cardCount != beforeCardCount)) return 3;
    if (cardName >= beforeCardName) return 4;

    beforeCardName = cardName;
    beforeCardCount = cardCount;

    return 0;
}

int check_cards(char inputCards[]) {
    int cardCount = 0;
    char* ptr = strtok(inputCards, " ");
    while (ptr != NULL) {
        subCardArr[cardCount++] = atoi(ptr);
        ptr = strtok(NULL, " ");
    }

    bubble_sort(subCardArr, cardCount);

    return cardCount;
}

int joker_count(int subCardArr[20], int cardName, int cardCount) {
    jokerCount = 0;
    for (int i = 0; i < cardCount; i++) {
        if (subCardArr[i] == 13) jokerCount++;
    }

    return jokerCount;
}

int delete_submited_card(int player_Cards[4][20], char nowTurnPlayer, int cardName, int cardCount, int jokerCount) {
    for (int i = 0; i < cardCount - jokerCount; i++) {
        for (int j = 0; j < 20; j++) {
            if (player_Cards[nowTurnPlayer][j] == cardName) {
                player_Cards[nowTurnPlayer][j] = 0;
                break;
            }
        }
    }
    for (int i = 0; i < jokerCount; i++) {
        for (int j = 0; j < 20; j++) {
            if (player_Cards[nowTurnPlayer][j] == 13) {
                player_Cards[nowTurnPlayer][j] = 0;
                break;
            }
        }
    }

    return 0;
}

#pragma region card_sub 함수 : 입력받은 카드 제출 구현 함수 (submitCard.cpp의 메인점)
int card_sub(char player_Name, int player_Cards[4][20]) //카드 제출 함수
{
    if (player_Cards[player_Name][19] == 0)
    {
        pass_3++;
        return 0;
    }
    char nowTurnPlayer = player_Name;
    int playerCards[4][20];
    for (int i = 0; i < 4; i++) //sub_fail_check함수로 인수 넘겨주기 위한 배열복사
    {
        for (int j = 0; j < 20; j++)
            playerCards[i][j] = player_Cards[i][j];
    }

    int cardName = 0;        //제출할 카드 번호
    int cardCount = 0;      //제출할 카드 수량
    int correctCard = 0;      //오류코드 번호
    int pass = 0;            //pass유무 변수
    char inputCards[100];

    while (pass != 1)
    {
        printf("pass는 1, 카드제출은 0을 입력하시오(1.pass/0.제출) : "); //pass여부 확인
        scanf("%d", &pass);
        getchar();

        if (pass_3 >= 3) { // 아무거나 제출할 수 있도록 한다.
            beforeCardName = 99;
            beforeCardCount = 99;
        }

        if (pass == 1)
        {
            printf("턴을 pass하셨습니다.\n\n");
            pass_3++;
            break;
        }
        else if (pass == 0) //pass하지 않았다면 카드 제출 로직 실행
        {
            printf("제출할 카드를 입력하시오 : ");
            gets_s(inputCards);     //문자열로 제출할 카드들 입력받기

            cardCount = check_cards(inputCards);    //카드 장수
            cardName = subCardArr[0];               //카드 번호

            int jokerCount = joker_count(subCardArr, cardName, cardCount);

            correctCard = sub_fail_check(cardName, cardCount, nowTurnPlayer, playerCards, jokerCount); //제출한 카드 범위 오류 확인

            if (correctCard == 0) {
                printf("카드가 정상적으로 제출되었습니다. \n\n      %d, %d\n", beforeCardName, beforeCardCount);     //return 0 정상
                delete_submited_card(player_Cards, nowTurnPlayer, cardName, cardCount, jokerCount);
                pass_3 = 0;
                break;
            }
            else if (correctCard == 1) {
                printf("%d번 카드가 존재하지 않습니다.\n\n", cardName);
            }
            else if (correctCard == 2) {
                printf("%d번 카드의 개수가 부족합니다.\n\n", cardName);
            }
            else if (correctCard == 3) {
                printf("이전에 제출한 카드보다 적은 개수의 카드를 제출할 수 없습니다.\n\n");
            }
            else if (correctCard == 4) {
                printf("이전에 제출한 카드와 같은 개수의 카드를 제출해야 합니다.\n\n");
            }
            else if (correctCard == 5) {
                printf("카드의 번호가 올바르지 않습니다.\n\n");
            }
        }
        else {
            printf("잘못된 입력입니다. 다시 시도해주세요.\n\n");
        }
    }
    return 0;
}

