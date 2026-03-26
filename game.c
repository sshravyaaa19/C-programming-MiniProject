#include "game.h"
#include <stdlib.h>

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

void add_random_tile(int x[4][4])
{
    int empty_tiles[16][2];
    int count = 0;
    int i, j;

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(x[i][j] == 0)
            {
                empty_tiles[count][0] = i;
                empty_tiles[count][1] = j;
                count++;
            }
        }
    }

    if(count == 0)
        return;

    int index = rand() % count;
    int row = empty_tiles[index][0];
    int col = empty_tiles[index][1];

    if(rand() % 2 == 0)
        x[row][col] = 2;
    else
        x[row][col] = 4;
}

int move_left(int x[4][4])
{
    int i, j, k;
    int changed = 0;

    for(i = 0; i < 4; i++)
    {
        int temp[4] = {0,0,0,0};
        int original[4];

        for(j = 0; j < 4; j++)
            original[j] = x[i][j];

        k = 0;
        for(j = 0; j < 4; j++)
        {
            if(x[i][j] != 0)
            {
                temp[k] = x[i][j];
                k++;
            }
        }

        for(j = 0; j < 3; j++)
        {
            if(temp[j] != 0 && temp[j] == temp[j+1])
            {
                temp[j] *= 2;
                temp[j+1] = 0;
            }
        }

        int final[4] = {0,0,0,0};
        k = 0;

        for(j = 0; j < 4; j++)
        {
            if(temp[j] != 0)
            {
                final[k] = temp[j];
                k++;
            }
        }

        for(j = 0; j < 4; j++)
        {
            x[i][j] = final[j];
            if(x[i][j] != original[j])
                changed = 1;
        }
    }

    return changed;
}

int move_right(int x[4][4])
{
    int i, j, k;
    int changed = 0;

    for(i = 0; i < 4; i++)
    {
        int temp[4] = {0,0,0,0};
        int original[4];

        for(j = 0; j < 4; j++)
            original[j] = x[i][j];

        k = 3;
        for(j = 3; j >= 0; j--)
        {
            if(x[i][j] != 0)
            {
                temp[k] = x[i][j];
                k--;
            }
        }

        for(j = 3; j > 0; j--)
        {
            if(temp[j] != 0 && temp[j] == temp[j-1])
            {
                temp[j] *= 2;
                temp[j-1] = 0;
            }
        }

        int final[4] = {0,0,0,0};
        k = 3;

        for(j = 3; j >= 0; j--)
        {
            if(temp[j] != 0)
            {
                final[k] = temp[j];
                k--;
            }
        }

        for(j = 0; j < 4; j++)
        {
            x[i][j] = final[j];
            if(x[i][j] != original[j])
                changed = 1;
        }
    }

    return changed;
}

int move_up(int board[4][4])
{
    int i, j, k;
    int changed = 0;

    for(j = 0; j < 4; j++)
    {
        int temp[4] = {0,0,0,0};
        int original[4];

        for(i = 0; i < 4; i++)
            original[i] = board[i][j];

        k = 0;
        for(i = 0; i < 4; i++)
        {
            if(board[i][j] != 0)
            {
                temp[k] = board[i][j];
                k++;
            }
        }

        for(i = 0; i < 3; i++)
        {
            if(temp[i] != 0 && temp[i] == temp[i+1])
            {
                temp[i] *= 2;
                temp[i+1] = 0;
            }
        }

        int final[4] = {0,0,0,0};
        k = 0;

        for(i = 0; i < 4; i++)
        {
            if(temp[i] != 0)
            {
                final[k] = temp[i];
                k++;
            }
        }

        for(i = 0; i < 4; i++)
        {
            board[i][j] = final[i];
            if(board[i][j] != original[i])
                changed = 1;
        }
    }

    return changed;
}

int move_down(int board[4][4])
{
    int i, j, k;
    int changed = 0;

    for(j = 0; j < 4; j++)
    {
        int temp[4] = {0,0,0,0};
        int original[4];

        for(i = 0; i < 4; i++)
            original[i] = board[i][j];

        k = 3;
        for(i = 3; i >= 0; i--)
        {
            if(board[i][j] != 0)
            {
                temp[k] = board[i][j];
                k--;
            }
        }

        for(i = 3; i > 0; i--)
        {
            if(temp[i] != 0 && temp[i] == temp[i-1])
            {
                temp[i] *= 2;
                temp[i-1] = 0;
            }
        }

        int final[4] = {0,0,0,0};
        k = 3;

        for(i = 3; i >= 0; i--)
        {
            if(temp[i] != 0)
            {
                final[k] = temp[i];
                k--;
            }
        }

        for(i = 0; i < 4; i++)
        {
            board[i][j] = final[i];
            if(board[i][j] != original[i])
                changed = 1;
        }
    }

    return changed;
}

int is_game_over(int x[4][4])
{
    int i, j;

    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            if(x[i][j] == 0)
                return 0;

    for(i = 0; i < 4; i++)
        for(j = 0; j < 3; j++)
            if(x[i][j] == x[i][j+1])
                return 0;

    for(j = 0; j < 4; j++)
        for(i = 0; i < 3; i++)
            if(x[i][j] == x[i+1][j])
                return 0;

    return 1;
}

  int score(int x[4][4])
 {
    int i, j;
    int sum = 0;

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            sum += x[i][j];
        }
    }

    return sum;
 }