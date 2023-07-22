//***             Rock, Paper & Scissors               ***

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int playerScore, compScore;
int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int greater(char c1, char c2)
{
    if (c1 == c2)
    {
        return -1;
    }
    else if (c1 == 'r' && c2 == 's')
    {
        return 1;
    }
    else if (c2 == 'r' && c1 == 's')
    {
        return 0;
    }
    else if (c1 == 'p' && c2 == 'r')
    {
        return 1;
    }
    else if (c2 == 'p' && c1 == 'r')
    {
        return 0;
    }

    else if (c1 == 's' && c2 == 'p')
    {
        return 1;
    }
    else if (c2 == 's' && c1 == 'p')
    {
        return 0;
    }
}

void compare_and_increment(char compChar, char playerChar)
{
    // compater character and increment the score
        if (greater(compChar, playerChar) == 1)
        {
            compScore++;
            printf("\t\tComputer Got It!\n\n");
        }
        else if (greater(compChar, playerChar) == -1)
        {
            compScore++;
            playerScore++;
            printf("\t\tIt's a draw. Both got 1 point!\n\n");
        }
        else
        {
            playerScore++;
            printf("\t\tYou Got It!\n\n");
        }

        printf("\t -------------\n");
        printf("\t| You: %d      |\n", playerScore);
        printf("\t| Computer: %d |\n", compScore);
        printf("\t -------------\n\n");

        printf("\t===========================================================\n\n");
}

void compare_score_and_print_result(int playerScore, int compScore)
{
    // compare score
    if (playerScore > compScore)
    {
        printf("\n\t -------------------\n");
        printf("\t| You Won the match! |\n");
        printf("\t -------------------\n");
    }
    else if (playerScore < compScore)
    {
        printf("\n\t ------------------------\n");
        printf("\t| Computer Won the match! |\n");
        printf("\t ------------------------\n");
    }
    else
    {
        printf("\n\t -------------\n");
        printf("\t| It's a draw! |\n");
        printf("\t -------------\n");
    }
}
int main()
{
    int temp, n;
    char playerChar, compChar;
    char dict[] = {'r', 'p', 's'};
    printf("\t------------------------------------------\n");
    printf("\t Welcome to the Rock Paper Scissors Game!\n");
    printf("\t------------------------------------------\n\n");
    printf("\tEnter the number of turns: ");
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++)
    {
        // Take player input
        printf("\n\tTurn %d:", i+1);
        printf("\n\n\tPress 1 for Rock, Press 2 for Paper, Press 3 for Scissors\n\n");
        printf("\tPlayer's turn: ");
        scanf("%d", &temp);
  
        playerChar = dict[temp - 1];
        
        if(playerChar == 'r')
        {
            printf("\t -----------------\n");
            printf("\t| You chose: Rock   |\n");
            printf("\t -----------------\n\n");
        }
        else if(playerChar == 'p')
        {
            printf("\t  ------------------\n");
            printf("\t|  You chose: Paper   |\n");
            printf("\t  ------------------\n\n");
        }
        else
        {
            printf("\t  ---------------------\n");
            printf("\t|  You chose: Scissors   |\n");
            printf("\t  ---------------------\n\n");
        }

        //computer generate
        printf("\tPress 1 for Rock, Press 2 for Paper, Press 3 for Scissors\n\n");
        printf("\tComputer's turn\n");
        temp = generateRandomNumber(3) + 1;
        compChar = dict[temp - 1];
        if(compChar == 'r')
        {
            printf("\t --------------------\n");
            printf("\t| Computer chose: Rock |\n");
            printf("\t --------------------\n\n");
        }
        else if(compChar == 'p')
        {
            printf("\t --------------------\n");
            printf("\t| Computer chose: Paper |\n");
            printf("\t --------------------\n\n");
        }
        else
        {
            printf("\t --------------------\n");
            printf("\t| Computer chose: Scissors |\n");
            printf("\t --------------------\n\n");
        }
        
        compare_and_increment(compChar, playerChar);

    }

    printf("\t -----------------\n");
    printf("\t|   Final Score   |\n");
    printf("\t -----------------\n");
    printf("\t|  You | Computer |\n");
    printf("\t|------|----------|\n");
    printf("\t|   %d  |    %d     |\n", playerScore, compScore);
    printf("\t -----------------\n\n");

    compare_score_and_print_result(playerScore, compScore);

    return 0;
}

