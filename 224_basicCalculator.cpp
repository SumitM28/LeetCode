#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        stack<char> st;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                if (st.empty())
                {
                    st.push(s[i]);
                }
                else
                {
                    if (s[i] == '(')
                    {

                        int bracket_evaluation = 0;

                        while (st.top() != ')')
                        {
                            int symbol = 1;
                            int d = 0;
                            if (st.top() == '-')
                            {

                                // removing symbol
                                st.pop();
                                symbol = -1;
                            }
                            else
                            {

                                if (st.top() == '+')
                                {
                                    // removing symbol
                                    st.pop();
                                }
                            }
                            if (!st.empty() && st.top() == '-')
                            {
                                st.pop();
                                symbol *= -1;
                            }

                            // making the integer if it is greater than 9
                            while (st.top() - '0' <= 9 && st.top() - '0' >= 0)
                            {
                                d = (d * 10) + (st.top() - '0');
                                st.pop();
                            }
                            d *= symbol;
                            // aading value to total bracket evaluation
                            bracket_evaluation += d;
                        }

                        // removing the opening bracket from stack
                        st.pop();
                        bool negative = false;
                        if (bracket_evaluation < 0)
                        {
                            bracket_evaluation *= -1;
                            negative = true;
                        }
                        // push final evaluation in stack in correct order
                        string m = to_string(bracket_evaluation);
                        cout << m << endl;
                        for (int k = m.size() - 1; k >= 0; k--)
                        {
                            st.push(m[k]);
                        }
                        if (negative)
                        {
                            st.push('-');
                        }
                    }
                    else
                    {
                        st.push(s[i]);
                    }
                }
            }
        }
        long long final_evaluation = 0;
        while (!st.empty())
        {
            // making the integer if it is greater than 9
            long long d = 0;
            int symbol = 1;
            // checking its symbol and then addition to result
            if (!st.empty() && st.top() == '-')
            {
                st.pop();
                symbol = -1;
            }
            else
            {
                if (!st.empty() && st.top() == '+')
                {
                    st.pop();
                }
            }
            if (!st.empty() && st.top() == '-')
            {
                st.pop();
                symbol *= -1;
            }
            while (!st.empty() && st.top() - '0' <= 9 && st.top() - '0' >= 0)
            {
                d = (d * 10) + st.top() - '0';
                st.pop();
            }
            d *= symbol;
            final_evaluation += d;
        }

        return final_evaluation;
    }
};