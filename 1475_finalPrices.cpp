// Final prices with a special discount in a shop
#include <bits/stdc++.h>
using namespace std;

vector<int> finalPrices(vector<int> &prices)
{
    int n = prices.size();
    stack<int> st;
    vector<int> nse(n, 0);

    st.push(prices.back());
    for (int i = n - 2; i >= 0; i--)
    {

        while (!st.empty() && prices[i] < st.top())
        {
            st.pop();
        }

        nse[i] = st.empty() ? 0 : st.top();
        st.push(prices[i]);
    }

    for (int i = 0; i < n; i++)
    {
        prices[i] -= nse[i];
    }

    return prices;
}

int main()
{
}