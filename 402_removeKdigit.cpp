// remove the k digit from the stirng and give possible smallest number
#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
    stack<char> st;
    for (auto c : num)
    {

        while (!st.empty() && k > 0 && st.top() > c)
        {
            st.pop();
            k--;
        }
        if (!st.empty() || c != '0')
        {
            st.push(c);
        }
    }

    while (!st.empty() && k--)
    {
        st.pop();
    }

    if (st.empty())
        return "0";

    string ans = "";

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
}