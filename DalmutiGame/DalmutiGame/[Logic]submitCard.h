#pragma once
int sub_fail_check(int cardName, int cardCount, char nowTurnPlayer, int playerCards[4][20], int jokerCount);
int check_cards(char input_cards[]);
int card_sub(char player_name, int players[4][20]);
int joker_count(int subCardArr[20], int cardName, int cardCount);
int delete_submited_card(int player_Cards[4][20], char nowTurnPlayer, int cardName, int cardCount, int jokerCount);