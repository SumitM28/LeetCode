// largest rectangular area which contains 1's
#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];

        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> next;
    next = nextSmallerElement(heights, n);

    vector<int> prev;
    prev = prevSmallerElement(heights, n);

    int area = 0;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;

        area = max(area, l * b);
    }
    return area;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<int> histogram(matrix[0].size(), 0);
    int maxi = INT_MIN;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == '1')
            {
                histogram[j]++;
            }
            else
            {
                histogram[j] = 0;
            }
        }

        maxi = max(maxi, largestRectangleArea(histogram));
    }
    return maxi;
}