// check the given sudoku is valid or not
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, vector<vector<char>> &board, char ch)
{

    // check in same row
    for (int col = 0; col < board.size(); col++)
    {
        if (col == j)
            continue;
        if (board[i][col] != '.' && ch == board[i][col])
        {
            return false;
        }
    }

    // check in col
    for (int row = 0; row < board.size(); row++)
    {
        if (row == i)
            continue;
        if (board[row][j] != '.' && ch == board[row][j])
            return false;
    }

    // check in grid
    int startRow = i - i % 3;
    int startCol = j - j % 3;

    for (int row = startRow; row < startRow + 3; row++)
    {
        for (int col = startCol; col < startCol + 3; col++)
        {
            if (row == i && col == j)
                continue;
            if (board[row][col] != '.' && board[row][col] == ch)
                return false;
        }
    }
    return true;
}
bool isValidSudoku(vector<vector<char>> &board)
{

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] != '.')
            {
                if (!isSafe(i, j, board, board[i][j]))
                {
                    return false;
                }
            }
        }
    }
    return true;
}