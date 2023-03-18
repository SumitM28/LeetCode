// count subarray with fixex bounds
#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int> &nums, int minK, int maxK)
{
    long long ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            vector<int> temp;
            for (int k = i; k <= j; k++)
            {
                temp.push_back(nums[k]);
            }
            int minTemp = INT_MAX, maxTemp = INT_MIN;

            for (int k = 0; k < temp.size(); k++)
            {
                minTemp = min(minTemp, temp[k]);
                maxTemp = max(maxTemp, temp[k]);
            }

            if (minTemp == minK && maxTemp == maxK)
            {
                ans++;
            }
        }
    }
    return ans;
}

long long countSubarraysOptimise(vector<int> &nums, int minK, int maxK)
{
    int n=nums.size();
    int lastMin=-1;
    int lastMax=-1; 
    int leftBound=-1;
    int count=0;

    for(int i=0;i<n;i++){
        if(nums[i]==minK && nums[i]<=maxK){
            lastMin=(nums[i]==minK)?i:lastMin;
            lastMax=(nums[i]==maxK)?i:lastMax;

            count+= max(0,min(lastMax,lastMin)-leftBound);
        }else{
            leftBound=i;
            lastMin=-1;
            lastMax=-1;
        }
    }
    return count;
}