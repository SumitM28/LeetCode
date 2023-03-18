// Build an Array With Stack Operations

#include <bits/stdc++.h>
using namespace std;

vector<string> buildArray(vector<int> &target, int n)
{
    vector<string> ans;
    int curr = 0;

    for (int i = 1; i <= target[target.size() - 1]; i++)
    {
        ans.push_back("Push");
        if (i == target[curr])
        {
            curr++;
        }
        else
        {
            ans.push_back("Pop");
        }
    }

    return ans;
}

int main()
{
}