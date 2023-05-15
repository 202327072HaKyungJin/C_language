#include <stdio.h>

int printf_titile_screen()
{
    printf("###################################\n");
    printf("##                               ##\n");
    printf("##          Dino Run             ##\n");
    printf("##          -Vo.1-               ##\n");
    printf("##                               ##\n");
    printf("##   1. Game Start               ##\n");
    printf("##   2. How To Play              ##\n");
    printf("##   3. Exit                     ##\n");
    printf("##                               ##\n");
    printf("###################################\n");             
    return 0;

}

int main()
{ 
    print_title_screen();
    int game_state = 1;
    int input = 0;
    int tutorial = 1;
	  while(game_state)
    {
        printf("input(1~3)>");
        scanf("%d",&input);
        if(input==2)
        {
            game_state=0;
        }  

int printf_titile_screen()
{
	printf("##############################\n");
	printf("##       How to Play        ##\n");
        printf("##                          ##\n");
	printf("##  1.Press the Space bar   ##\n");
	printf("##  2. Jump the avoid Enemy ##\n");
	printf("##                          ##\n");
	printf("##############################\n");
	printf("##      Return to menu?     ##\n");
	printf("##                          ##\n");
	printf("##        1.Yes  2.No       ##\n");
	printf("##############################\n");

       } 

       return 0;
}
