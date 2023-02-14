// find the length of the last word
#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{
    if (s.size() == 1)
    {
        return 1;
    }
    int i = s.size() - 1;
    int ans = 0;
    while (i >= 0)
    {
        if (s[i] != ' ')
        {
            ans++;
            if (i - 1 == -1 || s[i - 1] == ' ')
            {
                return ans;
            }
        }
        i--;
    }
    return ans;
}