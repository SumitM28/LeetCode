// find all the pascal triangle upto nth row.
#include<bits/stdc++.h>
using namespace std;

void solve(int s, int e, vector<vector<int>> &ans)
{
    if (s > e)
    {
        return;
    }
    vector<int> temp(s);

    // first and last element fill 1
    temp[0] = 1;
    temp[s - 1] = 1;
    for (int i = 1; i < s - 1; i++)
    {
        temp[i] = ans[s - 2][i - 1] + ans[s - 2][i];
    }
    ans.push_back(temp);
    solve(s + 1, e, ans);
}
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    int s = 1;
    solve(s, numRows, ans);

    return ans;
}