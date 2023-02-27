// find the first positive posible interget in arr
#include<bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int> &nums)
{
    vector<int> present(nums.size() + 1, 0);

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < nums.size() + 1)
        {
            present[nums[i]] = 1;
        }
    }

    for (int i = 1; i < nums.size() + 1; i++)
    {
        if (present[i] != true)
        {
            return i;
        }
    }
    return 1;
}