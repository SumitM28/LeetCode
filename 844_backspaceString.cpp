// backspace string compare in
#include <bits/stdc++.h>
using namespace std;

bool backspaceCompare(string s, string t)
{
    stack<char> st1;
    stack<char> st2;
    for (auto ch : s)
    {
        if (ch != '#')
        {
            st1.push(ch);
        }
        else if (!st1.empty())
        {
            st1.pop();
        }
    }
    for (auto ch : t)
    {
        if (ch != '#')
        {
            st2.push(ch);
        }
        else if (!st2.empty())
        {
            st2.pop();
        }
    }

    while (!st1.empty() && !st2.empty())
    {
        if (st1.top() != st2.top())
        {
            return false;
        }
        st1.pop();
        st2.pop();
    }

    return st1.size() == st2.size();
}

int main()
{
}