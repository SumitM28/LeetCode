// find 4 sum
#include <bits/stdc++.h>
using namespace std;

// approach 1st
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (l < n - 1 && nums[l] == nums[l + 1])
                            l++;
                    }
                }
                while (k < n - 1 && nums[k] == nums[k + 1])
                    k++;
            }
            while (j < n - 1 && nums[j] == nums[j + 1])
                j++;
        }
        while (i < n - 1 && nums[i] == nums[i + 1])
            i++;
    }
    return ans;
}

// approach 2nd
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    set<vector<int>> s;
    for (int i = 0; i < n; i++)
    {
        int a = nums[i];
        for (int j = i + 1; j < n; j++)
        {

            long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];

            int low = j + 1, high = n - 1;

            while (low < high)
            {
                if (nums[low] + nums[high] == newTarget)
                {
                    s.insert({nums[i], nums[j], nums[low], nums[high]});
                    low++, high--;
                }
                else if (nums[low] + nums[high] > newTarget)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
        }
    }
    for (auto v : s)
    {
        ans.push_back(v);
    }
    return ans;
}