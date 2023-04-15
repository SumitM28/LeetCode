// basic calculator 2
#include <bits/stdc++.h>
using namespace std;


int calculate(string s)
{
    stack<int> st;
    long long tmp = 0;
    char sign = '+';
    long long ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            tmp = 10 * tmp + s[i] - '0';
        }

        if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1)
        {

            if (sign == '-')
            {
                st.push(-tmp);
            }
            else if (sign == '+')
            {
                st.push(tmp);
            }
            else
            {
                int num;
                if (sign == '*')
                {
                    num = st.top() * tmp;
                }
                else
                {
                    num = st.top() / tmp;
                }

                st.pop();
                st.push(num);
            }

            sign = s[i];
            tmp = 0;
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main()
{
}
