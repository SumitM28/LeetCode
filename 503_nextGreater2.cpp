// next greater element 2
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> st;
    vector<int> res;
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--)
    {
        st.push(nums[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }
        if (st.size() == 0)
            res.push_back(-1);
        else
            res.push_back(st.top());
        st.push(nums[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);

    vector<int> ans = nextGreaterElements(nums);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}