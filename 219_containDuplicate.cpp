/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
*/
#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (freq.count(nums[i]) && abs(freq[nums[i]] - i) <= k)
            return true;
        freq[nums[i]] = i;
    }
    return false;
}