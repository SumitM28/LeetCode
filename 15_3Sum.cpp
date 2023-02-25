// find the three values having the sum should be equal to 0
#include <bits/stdc++.h>
using namespace std;

// time complexity O()
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if ((i != j && i != k && j != k) && (nums[i] + nums[j] + nums[k] == 0))
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);

                    if (!count(ans.begin(), ans.end(), temp))
                        ans.push_back(temp);
                }
            }
        }
    }

    return ans;
}

// approach 2nd
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {

        // using formula a+b+c=0 then b+c=-a
        int a = nums[i];
        int target = -a;

        int s = i + 1, e = n - 1;

        while (s < e)
        {

            if (nums[s] + nums[e] == target)
            {
                ans.push_back({a, nums[s], nums[e]});

                // do this for repeating array
                while (s < e && nums[s] == nums[s + 1])
                    s++;
                while (s < e && nums[e] == nums[e - 1])
                    e--;

                s++, e--;
            }
            else if (nums[s] + nums[e] > target)
            {
                e--;
            }
            else
            {
                s++;
            }
        }
        while (i + 1 < n && nums[i] == nums[i + 1])
            i++;
    }
    return ans;
}

// appraoch 3rd
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> Set;
    for (int i = 0; i < n; i++)
    {
        // using formula a+b+c=0 then b+c=-a
        int s = i + 1, e = n - 1;

        while (s < e)
        {

            if (nums[i] + nums[s] + nums[e] == 0)
            {
                Set.insert({nums[i],nums[s],nums[e]});
                
                s++,e--;
            }
            else if (nums[i] + nums[s] + nums[e]>0)
            {
                e--;
            }
            else
            {
                s++;
            }
        }
        
    }
    for(auto v:Set){
        ans.push_back(v);
    }
    return ans;
}