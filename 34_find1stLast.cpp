// Find First and Last Position of Element in Sorted Array

#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums, int target)
{
    int s = 0, e = nums.size() - 1;
    while (s <= e)
    {
        int mid = (s + e) >> 1;
        if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return s;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int s = lowerBound(nums, target);
    int e = lowerBound(nums, target + 1) - 1;

    if (s < nums.size() && nums[s] == target)
    {
        return {s, e};
    }
    return {-1, -1};
}