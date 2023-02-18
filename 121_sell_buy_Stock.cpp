// best time to sell or buy any stock
// return the max profit by a stock between a price range

#include<bits/stdc++.h>
using namespace std;

// approach 1st
int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;
    int n = prices.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (prices[j] > prices[i])
            {
                int profit = prices[j] - prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }
    }

    return maxProfit;
}