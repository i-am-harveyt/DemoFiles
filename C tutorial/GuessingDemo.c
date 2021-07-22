#include <stdio.h>
#include <stdlib.h>
#include "PlayFunction.h"

int main(void)
{
    int option;
    do
    {
        printf("-------Welcome to Guessing Number Game-------\n");
        printf("press \'1\' to play\n");
        printf("press \'2\' to exit\n");
        scanf("%d", &option);
        if (option ==1)
        {
            printf("-------Game Starts-------\n");
            play();
            option = 0;
        }
        
    } while (option != 2);
    printf("Thanks, goodbye!");
    
    return 0;
}