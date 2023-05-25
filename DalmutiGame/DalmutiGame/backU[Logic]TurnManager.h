#pragma once
#define MAX_NAME_LENGTH 20
void randTurn(char players[][MAX_NAME_LENGTH]);
void initTurn(void);
char* currentTurn(void);
void endTurn(void);