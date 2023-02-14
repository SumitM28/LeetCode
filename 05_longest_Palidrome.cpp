#include <bits/stdc++.h>
using namespace std;

bool checkPalidrome(string s)
{
    int i = 0, j = s.size() - 1;

    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        else
        {
            i++, j--;
        }
    }
    return true;
}
string solve(string &s, int i, int n, string ans, int maxi)
{
    // base case
    if (i >= n)
    {
        if (ans.size() > maxi && checkPalidrome(ans))
        {
                maxi=ans.size();
               return ans;
        }
        else
        {
            return "";
        }
    }

    string include= solve(s,i+1,n,ans+s[i],maxi);
    string exclude= solve(s,i+1,n,ans,maxi);

    if(include.size() >= exclude.size()){
        return include;
    }else{
        return exclude;
    }
}
string longestPalindrome(string s)
{
    int n = s.size();
    int start = 0;
    string ans = "";
    return solve(s, start, n, ans, 0);
    
}

int main()
{
    cout << longestPalindrome("cbbd");
}