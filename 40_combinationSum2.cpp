// combination sum 2
#include <bits/stdc++.h>
using namespace std;

// approach 1st
// time complexity O(2^n*k)
void solve(int i, vector<int> &candidates, int target, vector<int> &temp, set<vector<int>> &s)
{
    // base case
    if (i == candidates.size())
    {
        if (target == 0)
        {
            s.insert(temp);
        }
        return;
    }
    if (target == 0)
    {
        s.insert(temp);
        return;
    }
    if (target < 0)
    {
        return;
    }

    // include
    temp.push_back(candidates[i]);
    solve(i + 1, candidates, target - candidates[i], temp, s);
    temp.pop_back();

    // exclude
    solve(i + 1, candidates, target, temp, s);
}

// optimize approach
// time complexoty O(2^n)

void solve(int index, vector<int> &candidates, int target, vector<int> &temp, vector<vector<int>> &ans)
{
    if(target<0){
        return;
    }
    if(target==0){
        ans.push_back(temp);
        return;
    }

    for(int i=index;i<candidates.size();i++){
        if(i>index && candidates[i]==candidates[i-1]) continue;
        temp.push_back(candidates[i]);
        solve(i+1,candidates,target-candidates[i],temp,ans);
        temp.pop_back();
    }
}


vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    if (candidates.size() == 1)
    {
        if (candidates[0] == target)
        {
            ans.push_back({target});
        }
        return ans;
    }

    sort(candidates.begin(), candidates.end());
    set<vector<int>> s;
    vector<int> temp;
    solve(0, candidates, target, temp, s);

    for (auto v : s)
    {
        ans.push_back(v);
    }
    return ans;
}