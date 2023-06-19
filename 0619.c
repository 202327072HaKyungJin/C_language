#include <stdio.h>

void prinTitle();
void BeginGame();
void UpdateGame();
void EndGame();

int gameState;

int main()
{
    /*초기화시 실행*/
    BeginGame();

    while (gameState)
    {
	UpdateGame();
    }

    /*종료 전 실행*/
    EndGame();

    return 0;
}

void BeginGame()
{
     gameState = 1;
}
void UpdateGame()
{
     printTitile();

     int gameInput = 0;
     
     scanf_s("%d", &gameInput);

     gameState = gameInput;
}
void EndGame()
{

}


void printTitle()
{
    printf("####################### \n");
    printf("#                     # \n");
    printf("#                     # \n");
    printf("#  [과제 하기 싫어]   # \n");
    printf("#                     # \n");
    printf("#     1. 게임시작     # \n");
    printf("#     2. 게임종료     # \n");
    printf("#                     # \n");
    printf("####################### \n");
    printf("메뉴선택>");

    return 0;
}
