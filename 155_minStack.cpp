// min stack implementation
#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    int *arr;
    int *mini;
    int peek;
    MinStack()
    {
        arr = new int[10000];
        mini = new int[10000];
        peek = -1;
    }

    void push(int val)
    {
        if (peek == -1)
        {
            peek++;
            arr[peek] = val;
            mini[peek] = val;
        }
        else
        {
            peek++;
            arr[peek] = val;
            mini[peek] = min(val, mini[peek - 1]);
        }
    }

    void pop()
    {
        peek--;
    }

    int top()
    {
        return arr[peek];
    }

    int getMin()
    {
        return mini[peek];
    }
};

int main()
{
}