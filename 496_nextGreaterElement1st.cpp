// Next Greater Element I
#include<bits/stdc++.h>
using namespace std;


vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    stack<int> st;
    vector<int> nextGreater(n2);
    st.push(-1);
    vector<int> ans(n1);
    for (int i = n2 - 1; i >= 0; i--)
    {
        int curr = nums2[i];

        while (st.top() != -1 && st.top() < curr)
        {
            st.pop();
        }
        nextGreater[i] = st.top();
        st.push(curr);

        int idx = -1;
        for (int j = 0; j < n1; j++)
        {
            if (nums1[j] == curr)
            {
                idx = j;
                break;
            }
        }
        if (idx != -1)
        {
            ans[idx] = nextGreater[i];
        }
    }

    return ans;
}