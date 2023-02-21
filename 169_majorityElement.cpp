// find an element have occurance more than n/2 where n is the size of array
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    // approach 1st

    // unordered_map<int,int> mp;
    // int n=nums.size();
    // for(int i=0;i<n;i++){
    //     if(mp[nums[i]]){
    //         mp[nums[i]]++;
    //     }else{
    //         mp[nums[i]]=1;
    //     }
    // }
    // int ans=0;
    // for(auto num:mp){
    //     if(num.second>n/2){
    //         ans=num.first;
    //     }
    // }
    // return ans;

    // approach 2nd
    int ans = nums[0];
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt == 0)
            ans = nums[i];
        cnt += (ans == nums[i]) ? 1 : -1;
    }
    return ans;
}

int main(){
    
}