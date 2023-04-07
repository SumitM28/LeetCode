// Implement Queue using Stacks
#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> st;
    MyQueue()
    {
    }

    void pushUtil(stack<int> &st, int val)
    {

        if (st.size() == 0)
        {
            st.push(val);
            return;
        }

        int top = st.top();
        st.pop();
        pushUtil(st, val);
        st.push(top);
    }
    void push(int x)
    {
        pushUtil(st, x);
    }

    int pop()
    {
        int temp = st.top();
        st.pop();
        return temp;
    }

    int peek()
    {
        return st.top();
    }

    bool empty()
    {
        return st.size() == 0;
    }
};