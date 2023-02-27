// solve the sodoku
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, char board[9][9], char val)
{
    // check in row
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == val)
        {
            return false;
        }
    }

    // check in column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == val)
        {
            return false;
        }
    }

    // check in grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (board[i][j] == val)
            {
                return false;
            }
        }
    }

    return true;
}

void solveSudoku(char board[9][9])
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (char ch='1';ch<='9';ch++)
                {
                    if (isSafe(i, j, board, ch))
                    {
                        board[i][j] = ch;
                    }
                }
            }
        }
    }
}

int main()
{
    char board[9][9] = { 
        { '5', '3', '.', '.', '7', '.', '.', '.', '.' }, 
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' }, 
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' }, 
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' }, 
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' }, 
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' }, 
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' }, 
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' }, 
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
    
    solveSudoku(board);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }cout<<endl;
    }

}