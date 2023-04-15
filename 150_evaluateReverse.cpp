// Eveluate reverse polish notation
#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &tokens)
{

    stack<int> st;

    for (auto str : tokens)
    {

        if (isdigit(str[str.length() - 1]))
        {
            st.push(stoi(str));
        }
        else
        {
            string operation = str;
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            if (operation == "+")
            {
                st.push(val2 + val1);
            }
            else if (operation == "-")
            {
                st.push(val2 - val1);
            }
            else if (operation == "*")
            {
                st.push(val2 * val1);
            }
            else
            {
                // devide case
                st.push(val2 / val1);
            }
        }
    }
    return st.top();
}

int main()
{
}