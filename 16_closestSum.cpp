// find the closest sum
#include <bits/stdc++.h>
using namespace std;

// appraoch 1st
int threeSumClosest(vector<int> &nums, int target)
{
    int ans = 0;
    int diff = INT_MAX;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == target)
                {
                    return target;
                }
                if (abs(nums[i] + nums[j] + nums[k] - target) < diff)
                {
                    diff = nums[i] + nums[j] + nums[k] - target;
                    ans = nums[i] + nums[j] + nums[k];
                }
            }
        }
    }
    return ans;
}


// approach 2nd
int threeSumClosest(vector<int> &nums, int target)
{
    int ans = 0;
    int diff = INT_MAX;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        // using formula a+b+c=0 then b+c=-a
        int s = i + 1, e = n - 1;
        while (s < e)
        {
            if (nums[i] + nums[s] + nums[e] == target)
            {
                return target;
            }
            else if (abs(nums[i] + nums[s] + nums[e] - target) < diff)
            {
                diff = abs(nums[i] + nums[s] + nums[e] - target);
                ans = nums[i] + nums[s] + nums[e];
            }
            if (nums[i] + nums[s] + nums[e] < target)
                s++;
            else
                e--;
        }
    }

    return ans;
}