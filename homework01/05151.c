#include "dino.h"
#include <stdio.h>

int main() 
{
    print_title_screen();
    
    int game_state = 1;
    int input = 0;
    int how = 0; 
    int user = 0;
    
    while (game_state) 
    {
        printf("input(1~3)>");
        scanf("%d", &input);
       
        if (input == 2) 
        {   
            how = 1;
           
            print_howtoplay_screen();
            
            while (how)
            {
               printf("Return to menu? (1.yes 2.no)");
               scanf("%d", &user);
               
                if (user == 1)
	       	    {
                    how = 0;
                    input = 0;
                   
                    print_title_screen();
                }
                
                else if (user == 2)
                {

                } 
                
                else 
                {
                    printf("다시 입력해 주세요.\n");
                }   
            }
        }

        else if (input == 3) 
	    {
            game_state = 0;
        }

        else 
        {
            printf("다시 입력해 주세요.\n");
        }
   
    }

    return 0;
}

