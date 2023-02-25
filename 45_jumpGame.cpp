#include <bits/stdc++.h>
using namespace std;

// using dp approach top to down
int solve(vector<int> &nums, int i, vector<int> &dp)
{
    if (i >= nums.size() - 1)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int ans = INT_MAX;
    for (int j = 1; j <= nums[i] && i + j < nums.size(); j++)
    {
        ans = min(ans, solve(nums, i + j, dp));
    }
    return dp[i] = (ans == INT_MAX) ? ans : ans + 1;
}

int jump(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    return solve(nums, 0, dp);
}

// approach optimize
int jump(vector<int> &nums)
{
    int jump = 0;
    int end = 0;
    int farthest = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        farthest = max(farthest, i + nums[i]);
        if (i == end)
        {
            jump++;
            end = farthest;
        }
    }
    return jump;
}