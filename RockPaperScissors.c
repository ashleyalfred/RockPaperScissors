#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // Initialize random number generator
    srand(time(NULL));

    // Allocate space for variables
    int userChoice;
    int aiChoice;
    int round = 0;

    // Initialize constants
    const int Rock = 1; 
    const int Paper = 2; 
    const int Scissors = 3; 
    
    do 
    {
        printf ("Your turn! \n");
        do
        {
            userChoice = get_int ("Rock = 1, Paper = 2, Scissors = 3. Please enter a number to play: \n");
        }
        while (userChoice < Rock || userChoice > Scissors);
    
        if (userChoice == Rock)
        {
            printf ("You picked Rock. Now, it's my turn! \n");
        }
        else if (userChoice == Paper)
        {
            printf ("You picked Paper. Now, it's my turn! \n");
        }
        else if (userChoice == Scissors)
        {
            printf ("You picked Scissors. Now, it's my turn! \n");
        }
        else
        {
           // This shouldn't normally happen. But if it does, the computer will warn the user about it.
           // This will save debugging nightmares in the future.
           printf("ERROR: The computer accepted a value other than 1, 2, 3. This should not happen. Please check business logic. Exiting."); 
           exit(-1) 
        }
    
        printf ("Rolling the dice .... \n");
    
        aiChoice = rand() % 3 + 1;

        if (aiChoice == Rock)
        {
            printf ("I picked Rock. \n");
        }
        else if (aiChoice == Paper)
        {
            printf ("I picked Paper. \n");
        }
        else if (aiChoice == Scissors)
        {
            printf ("I picked Scissors. \n");
        }
        

        if ((userChoice == Rock && aiChoice == Scissors) || (userChoice == Paper && aiChoice == Rock) || (userChoice == Scissors && aiChoice == Paper))
        {
            printf ("You Won! \n");
        }
    
       if ((aiChoice == Rock && userChoice == Scissors) || (aiChoice == Paper && userChoice == Rock) || (aiChoice == Scissors && userChoice == Paper))
        {
            printf ("Better luck next time! \n"); 
        }
        
        round++;
    }
    while (round < 3);
    
}
