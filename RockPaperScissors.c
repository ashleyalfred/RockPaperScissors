#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    
    // Initialize random number generator
    srand(time(NULL));
    int n;
    int x = 0;
    int Rock = 1; 
    int Paper = 2; 
    int Scissors = 3; 
    
    do 
    {
        printf ("Your turn! \n");
        do
        {
            n = get_int ("Rock = 1, Paper = 2, Scissors = 3. Please enter a number to play: \n");
        }
        while (n < 1 || n > 3);
    
        if (n == 1)
        {
            printf ("You picked Rock. Now, it's my turn! \n");
        }
        else if (n == 2)
        {
            printf ("You picked Paper. Now, it's my turn! \n");
        }
        else
        {
            printf ("You picked Scissors. Now, it's my turn! \n");
        }
    
        printf ("Rolling the dice .... \n");
    
        int a = rand() % 3 + 1;

        if (a == 1)
        {
            printf ("I picked Rock. \n");
        }
        else if (a == 2)
        {
            printf ("I picked Paper. \n");
        }
        else if (a == 3)
        {
            printf ("I picked Scissors. \n");
        }
        

        if ((n == Rock && a == Scissors) || (n == Paper && a == Rock) || (n == Scissors && a == Paper))
        {
            printf ("You Won! \n");
        }
    
       if ((a == Rock && n == Scissors) || (a == Paper && n == Rock) || (a == Scissors && n == Paper))
        {
            printf ("Better luck next time! \n"); 
        }
        
        x++;
    }
    while (x < 3);
    

}
