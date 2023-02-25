// find next permutaion
#include<bits/stdc++.h>
using namespace std;


void nextPermutation(vector<int> &nums)
{
    int toSwap = INT_MIN, withSwap = INT_MIN;
    int n = nums.size();
    for (int i = n - 1; i > 0; i--)
    {
        if (nums[i] > nums[i - 1])
        {
            toSwap = i - 1;
            break;
        }
    }

    if (toSwap == INT_MIN)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        for (int i = n - 1; i > toSwap; i--)
        {
            if (nums[i] > nums[toSwap])
            {
                withSwap = i;
                break;
            }
        }
        swap(nums[toSwap], nums[withSwap]);
        reverse(nums.begin() + toSwap + 1, nums.end());
    }

    // approach 2nd
    next_permutation(nums.begin(),nums.end());
}