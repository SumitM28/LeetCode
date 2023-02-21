
// find the which no having a single occurance
#include <bits/stdc++.h>
using namespace std;

// approach 1st
int singleNumber(vector<int> &nums)
{
    map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        if (mp[nums[i]])
        {
            mp[nums[i]] += 1;
        }
        else
        {
            mp[nums[i]] = 1;
        }
    }
    int ans = 0;
    for (auto i : mp)
    {
        if (i.second == 1)
        {
            ans = i.first;
            break;
        }
    }
    return ans;
}

int singleNumberOptimize(vector<int> &nums)
{
    int ans = 0;

    for (auto i : nums)
    {
        ans ^= i;
    }
    return ans;
}