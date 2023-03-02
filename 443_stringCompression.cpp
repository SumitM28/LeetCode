// string compression
#include <bits/stdc++.h>
using namespace std;


int compress(vector<char> &chars)
{
    if (chars.empty())
        return 0;
    char curr = chars[0];
    string s;
    int cnt = 1;

    for (int i = 1; i <= chars.size(); i++)
    {
        if (i < chars.size() && chars[i] == curr)
        {
            cnt++;
        }
        else
        {
            s.push_back(curr);
            if (cnt > 1)
            {
                string str = to_string(cnt);
                for (auto c : str)
                {
                    s.push_back(c);
                }
            }
            curr = i < chars.size() ? chars[i] : 0;
            cnt = 1;
        }
    }

    for (int i = 0; i < chars.size(); i++)
    {
        chars[i] = s[i];
    }
    return s.size();
}