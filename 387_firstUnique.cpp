// find the index of first unique character in string
#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s)
{
    vector<int> freq(26);

    for (auto c : s)
    {
        freq[c - 'a']++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (freq[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}


int main()
{
}