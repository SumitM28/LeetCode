// check any duplicate is present inside the array or not
#include <bits/stdc++.h>
using namespace std;


// approach 1st
bool containsDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }
    return false;
}


// approach 2nd
bool containsDuplicateOptimize(vector<int> &nums)
{
    set<int> s;
    for(int i=0;i<nums.size();i++){
        s.insert(nums[i]);
    }
    
    return nums.size()>s.size();
}


// appraoch 3rd
// using hashmap 


