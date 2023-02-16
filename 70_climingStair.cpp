// climing stair and find total number of ways to clime stair.
#include<bits/stdc++.h>
using namespace std;

// usign recursion
int solve(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    int step1 = solve(n - 1);
    int step2 = solve(n - 2);

    return step1 + step2;
}

// dp approach 1st
// using recursion +memoization
int solveMem(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (dp[n] != -1)
        return dp[n];

    int step1 = solveMem(n - 1, dp);
    int step2 = solveMem(n - 2, dp);

    return dp[n] = step1 + step2;
}

// dp approach 2nd
// tabulation
int solveTab(int n)
{
    vector<int> dp(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        int step1 = 0, step2 = 0;
        if (i - 1 >= 0)
            step1 = dp[i - 1];
        if (i - 2 >= 0)
            step2 = dp[i - 2];

        dp[i] = step1 + step2;
    }

    return dp[n];
}

// space optimization
int solveSpaceOptimize(int n)
{
    int prev1 = 1;
    int prev2 = 0;
    for (int i = 1; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int climbStairs(int n)
{

    // recursion
    // return solve(n);

    // recursion + memoization
    // vector<int> dp(n+1,-1);
    // return solveMem(n,dp);

    // tabulation
    // return solveTab(n);

    // space optimization
    return solveSpaceOptimize(n);
}

int main(){

}