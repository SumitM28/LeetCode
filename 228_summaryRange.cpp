/*
You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int> &nums)
{
    int n = nums.size();
    vector<string> ans;
    if (n == 0)
    {
        return ans;
    }
    int s = nums[0];
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] + 1 != nums[i + 1])
        {
            string temp = "";
            if (nums[i] == s)
            {
                temp += to_string(s);
            }
            else
            {
                temp += to_string(s) + "->" + to_string(nums[i]);
            }
            ans.push_back(temp);
            s = nums[i + 1];
        }
    }
    if (s == nums[n - 1])
    {
        ans.push_back(to_string(s));
    }
    else
    {
        ans.push_back(to_string(s) + "->" + to_string(nums[n - 1]));
    }
    return ans;
}