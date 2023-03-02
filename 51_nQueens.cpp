// place the n Queens in n*n board
#include <bits/stdc++.h>
using namespace std;

bool isSafeToPlaceQueen(int row, int col, vector<string> &nQueens, int n)
{
    for (int i = 0; i < n; i++)
    {
        // check in col
        if (nQueens[i][col] == 'Q')
            return false;
    }

    // check in left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (nQueens[i][j] == 'Q')
            return false;
    }

    // check in right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (nQueens[i][j] == 'Q')
            return false;
    }

    return true;
}

void solve(int n, vector<string> &nQueens, int row, vector<vector<string>> &ans)
{
    // base case
    if (row == n)
    {
        ans.push_back(nQueens);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafeToPlaceQueen(row, col, nQueens, n))
        {
            nQueens[row][col] = 'Q';
            solve(n, nQueens, row + 1, ans);
            nQueens[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> nQueens(n, string(n, '.'));
    solve(n, nQueens, 0, ans);
    return ans;
}