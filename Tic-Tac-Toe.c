// Tic-Tac-Toe

#include <stdio.h>

void Display_Board(char Array[]) 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf("%c ", Array[i * 3 + j]);
        }
        printf("\n");
    }
}

void Index_Full(char Array[], int *index_full) 
{
    *index_full = 1;  // Assume the board is full
    for (int i = 0; i < 9; i++) 
    {
        if (Array[i] == '*') 
        {
            *index_full = 0;  // Empty spot found
            break;
        }
    }
}

void Player_1_Input(char Array[], int *player_number) 
{
    int n;
    printf("Player 1: Enter Index Number: ");
    scanf("%d", &n);
    if (n < 1 || n > 9) 
    {
        printf("Choose Index between 1 to 9.\n");
    } 
    else if (Array[n - 1] == '*') 
    {
        Array[n - 1] = 'X';
        *player_number = 2;
    } 
    else 
    {
        printf("INVALID!!! Index already used.\n");
    }
}

void Player_2_Input(char Array[], int *player_number) 
{
    int n;
    printf("Player 2: Enter Index Number: ");
    scanf("%d", &n);
    if (n < 1 || n > 9) 
    {
        printf("Choose Index between 1 to 9.\n");
    } 
    else if (Array[n - 1] == '*') 
    {
        Array[n - 1] = 'O';
        *player_number = 1;
    } 
    else 
    {
        printf("INVALID!!! Index already used.\n");
    }
}

int Check_Win(char Array[], int *player_number, int *winner) {
    if ((Array[0] == Array[1] && Array[1] == Array[2] && Array[0] != '*') ||  // Row 1
        (Array[3] == Array[4] && Array[4] == Array[5] && Array[3] != '*') ||  // Row 2
        (Array[6] == Array[7] && Array[7] == Array[8] && Array[6] != '*') ||  // Row 3
        (Array[0] == Array[3] && Array[3] == Array[6] && Array[0] != '*') ||  // Col 1
        (Array[1] == Array[4] && Array[4] == Array[7] && Array[1] != '*') ||  // Col 2
        (Array[2] == Array[5] && Array[5] == Array[8] && Array[2] != '*') ||  // Col 3
        (Array[0] == Array[4] && Array[4] == Array[8] && Array[0] != '*') ||  // Diag 1
        (Array[2] == Array[4] && Array[4] == Array[6] && Array[2] != '*'))    // Diag 2
    {   
        printf("Winner is Player %d.\n", *player_number);
        *winner = 0;  // Game over
        return 0; 
    }
    return 1;
}

int main() {
    printf("Enter the Index Number Accordingly:\n1 2 3\n4 5 6\n7 8 9\n");
    char board[] = {'*', '*', '*', '*', '*', '*', '*', '*', '*'};
    int winner = 1;  // Game continues until a winner is found
    int index_full = 1;  // Track if board is full (draw)
    int player_number = 1;

    while (winner == 1) 
    {
        Index_Full(board, &index_full);  // Check if the board is full
        if (index_full == 1) 
        {
            printf("The game is a draw!\n");
            break;
        }

        if (player_number == 1) 
        {
            Player_1_Input(board, &player_number);
        } 
        else 
        {
            Player_2_Input(board, &player_number);
        }
        
        Display_Board(board);
        Check_Win(board, &player_number, &winner);
    }

    return 0;
}
