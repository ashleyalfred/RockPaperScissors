#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <time.h>

#define USER 0
#define AI 1

void single_game(int num_hands);
int single_hand(void);
int winner(int userchoice, int aichoice);


int main(void)
{
    // Initialize random number generator
    srand(time(NULL));

    do
    {
        single_game(3);
    }
    while(get_char("Would you like to play again? Y/N \n") == 'Y');
}


void single_game(int num_hands)   //best out of num_hands
{
    int userwins = 0; //counters to store the number
    int aiwins = 0;   //of hands a user won
    for (int i = 0; i < num_hands; i++)
    {
        //calling the function (three times). Calling the function runs the function!
        if (single_hand() == USER) //if game "n" = 0, the userwins and add one to userwins. Else, add one to aiwins. repeat "n" times.
        {
            userwins++;
        }
        else
        {
            aiwins++;
        }
    }
    if (userwins > aiwins)
    {
        printf ("You Won! \n");
    }
    else
    {
        printf("I won ... yes! Better luck next time! \n");
    }
}

//functions outside of main:

int single_hand(void)
{
    int userchoice;
    do
    {
        userchoice = get_int("Rock = 1, Paper = 2, Scissors = 3. Please enter a number to play: \n");
    }
    while (userchoice < 1 || userchoice > 3);

    if (userchoice == 1)
    {
        printf ("You picked Rock.\n");
    }
    else if (userchoice == 2)
    {
        printf ("You picked Paper.\n");
    }
    else
    {
        printf ("You picked Scissors.\n");
    }

    printf("Now, it's my turn!\n");
    printf ("Rolling the dice .... \n");

    int aichoice = rand() % 3 + 1;

    if (aichoice == 1)
    {
        printf ("I picked Rock. \n");
    }
    else if (aichoice == 2)
    {
        printf ("I picked Paper. \n");
    }
    else if (aichoice == 3)
    {
        printf ("I picked Scissors. \n");
    }
    return winner(userchoice, aichoice);
}

int winner(int userchoice, int aichoice)
{
    const int Rock = 1;
    const int Paper = 2;
    const int Scissors = 3;

    if ((userchoice == Rock && aichoice == Scissors) || (userchoice == Paper && aichoice == Rock) || (userchoice == Scissors && aichoice == Paper))
    {
        printf ("You Won best out of 3! \n");
        return USER;
    }
    else
    {
        printf ("I won best out of 3, better luck next time! \n");
        return AI;
    }

}
