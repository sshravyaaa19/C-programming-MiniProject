#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>



//function to initialize the playing board
void initialize_board(int x[4][4])
{
    int i, j;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            x[i][j] = 0;
        }
    }
}



//Prints the board 
void print_board(int x[4][4])
{
    int i, j;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
}



//genrates a random tile
void add_random_tile(int x[4][4])
{
    int empty_tiles[16][2];
    int count = 0;
    int i,j;
    
    //Find all the empty tiles
    for(i=0;i < 4;i++)
    {
        for(j = 0;j < 4;j++)
        {
            if(x[i][j] == 0)
            {
                empty_tiles[count][0] = i;
                empty_tiles[count][1] = j;
                count++;
            }
        }
    }

    if(count == 0) //If no empty tiles found do nothing
        return;

    //choses a random tile
    int index = rand() % count;
    int row = empty_tiles[index][0];
    int col = empty_tiles[index][1];

    //choses either 2 or 4
    if(rand() % 2 == 0)
    {
        x[row][col] = 2;
    }
    else
    {
        x[row][col] = 4;  
    }

}

//LEFT MOVE 
int move_left(int x[4][4])
{
    int i,j,k;

    for (i=0;i < 4;i ++)
    {
        int temp[4] = {0,0,0,0};
        k = 0;
        
        //Move all row elements to temp array
        for(j=0;j < 4;j++)
        {
            if(x[i][j] != 0)
            {
                temp[k] = x[i][j];
                k++;
            }
        }


        //adding if adjecent numbers are same
        for (j=0;j < 3;j++)
        {
            if(temp[j] != 0 && temp[j] == temp[j +1])
            {
                temp[j] = temp[j] * 2;
                temp[j+1] = 0;
            }
        }

        //final shift
        int final[4] = {0,0,0,0};
        k = 0;

        for(j=0;j < 4;j++)
        {
            if(temp[j] != 0)
            {
                final[k] = temp[j];
                k++; 
            }
        }

        //Copy final to board
        for(j = 0;j < 4;j++)
        {
            x[i][j] = final[j];
        }
    }
    return 0;
}


//RIGHT MOVE
int move_right(int x[4][4])
{
    int i, j, k;

    for(i = 0; i < 4; i++)
    {
        int temp[4] = {0, 0, 0, 0};
        k = 3;

        // Step 1: Move non-zero elements to the right
        for(j = 3; j >= 0; j--)
        {
            if(x[i][j] != 0)
            {
                temp[k] = x[i][j];
                k--;
            }
        }

        // Step 2: Merge equal adjacent elements (right to left)
        for(j = 3; j > 0; j--)
        {
            if(temp[j] != 0 && temp[j] == temp[j-1])
            {
                temp[j] *= 2;
                temp[j-1] = 0;
            }
        }

        // Step 3: Shift again
        int final[4] = {0, 0, 0, 0};
        k = 3;

        for(j = 3; j >= 0; j--)
        {
            if(temp[j] != 0)
            {
                final[k] = temp[j];
                k--;
            }
        }

        // Step 4: Copy back
        for(j = 0; j < 4; j++)
        {
            x[i][j] = final[j];
        }
    }
    return 0;
}


int move_up(int board[4][4])
{
    int i, j, k;

    for(j = 0; j < 4; j++)   // loop column-wise
    {
        int temp[4] = {0, 0, 0, 0};
        k = 0;

        // Step 1: Move non-zero elements upward
        for(i = 0; i < 4; i++)
        {
            if(board[i][j] != 0)
            {
                temp[k] = board[i][j];
                k++;
            }
        }

        // Step 2: Merge equal adjacent elements
        for(i = 0; i < 3; i++)
        {
            if(temp[i] != 0 && temp[i] == temp[i+1])
            {
                temp[i] *= 2;
                temp[i+1] = 0;
            }
        }

        // Step 3: Shift again after merging
        int final[4] = {0, 0, 0, 0};
        k = 0;

        for(i = 0; i < 4; i++)
        {
            if(temp[i] != 0)
            {
                final[k] = temp[i];
                k++;
            }
        }

        // Step 4: Copy back into board
        for(i = 0; i < 4; i++)
        {
            board[i][j] = final[i];
        }
    }
    return 0;
}



int move_down(int board[4][4])
{
    int i, j, k;

    for(j = 0; j < 4; j++)   // loop column-wise
    {
        int temp[4] = {0, 0, 0, 0};
        k = 3;  // start filling from bottom

        // Step 1: Move non-zero elements downward
        for(i = 3; i >= 0; i--)
        {
            if(board[i][j] != 0)
            {
                temp[k] = board[i][j];
                k--;
            }
        }

        // Step 2: Merge equal adjacent elements (bottom to top)
        for(i = 3; i > 0; i--)
        {
            if(temp[i] != 0 && temp[i] == temp[i-1])
            {
                temp[i] *= 2;
                temp[i-1] = 0;
            }
        }

        // Step 3: Shift again after merging
        int final[4] = {0, 0, 0, 0};
        k = 3;

        for(i = 3; i >= 0; i--)
        {
            if(temp[i] != 0)
            {
                final[k] = temp[i];
                k--;
            }
        }

        // Step 4: Copy back into board
        for(i = 0; i < 4; i++)
        {
            board[i][j] = final[i];
        }
    }
    return 0;
}



//Function to check if game is over
int is_game_over(int x[4][4])
{
    int i, j;

    //Check for empty cell
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(x[i][j] == 0)
                return 0;   // Game NOT over
        }
    }

    //Check horizontal merge possibility
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(x[i][j] == x[i][j+1])
                return 0;   // Game NOT over
        }
    }

    //Check vertical merge possibility
    for(j = 0; j < 4; j++)
    {
        for(i = 0; i < 3; i++)
        {
            if(x[i][j] == x[i+1][j])
                return 0;   // Game NOT over
        }
    }

    return 1;   // Game Over
}


int main()
{
    int board[4][4];

    srand(time(NULL)); //Set random seed once
    printf("The moves are : \n W : move up \n A : move left \n S : move down \n D : move right \n Q : quit \n");

    initialize_board(board);

    //Adding the first two tiles
    add_random_tile(board);
    add_random_tile(board);

    //Infinite loop
    while(1)
    {   

        //Checks is game is over
        if(is_game_over(board))
        {
            print_board(board);
            printf("Game Over!\n");
            break;
        }

        char move;
        print_board(board);//Print the board initially 
        printf("enter your move:");
        scanf(" %c",&move);
        move = toupper(move);


        switch(move)
        {
            case'W':
            move_up(board);
            add_random_tile(board);
            break;

            case'A':
            move_left(board);
            add_random_tile(board);
            break;

            case'S':
            move_down(board);
            add_random_tile(board);
            break;

            case'D':
            move_right(board);
            add_random_tile(board);
            break;

            case'Q':
            printf("You have quit the game");
            return 0;

            default:
            printf("Invalid move \n");
        }
        
    }

    print_board(board);
    return 0;
}