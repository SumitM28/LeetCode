// score of parenthese
#include <bits/stdc++.h>
using namespace std;

int scoreOfParentheses(string s)
{
    stack<int> st;
    int score = 0;

    for (auto ch : s)
    {
        if (ch == '(')
        {
            st.push(score);
            score = 0;
        }
        else
        {
            score = st.top() + max(2 * score, 1);
            st.pop();
        }
    }
    return score;
}

int main()
{
}