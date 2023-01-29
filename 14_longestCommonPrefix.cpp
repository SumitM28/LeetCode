// find longest common prefix.
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int countChild = 0;
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        countChild = 0;
        isTerminal = false;
    }
};
class Trie
{
public:
    TrieNode *root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }
    void insertUtils(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return;
        }
        int idx = word[0] - 'a';
        TrieNode *child;
        if (root->children[idx] != NULL)
        {
            child = root->children[idx];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->countChild++;
            root->children[idx] = child;
        }
        insertUtils(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtils(root, word);
    }

    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (root->countChild == 1)
            {
                ans.push_back(ch);
                int idx = ch - 'a';
                root = root->children[idx];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
            {
                break;
            }
        }
    }
};
class Solution
{
public:
    string bruteForce(vector<string> &strs)
    {
        string first = strs[0];
        string ans = "";
        for (int i = 0; i < first.length(); i++)
        {
            bool flag = true;
            for (int j = 1; j < strs.size(); j++)
            {
                if (first[i] != strs[j][i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag == false)
            {
                break;
            }
            ans += first[i];
        }
        return ans;
    }

    string optimize(vector<string> &strs, int n)
    {
        Trie *t = new Trie('/');

        for (int i = 0; i < n; i++)
        {
            t->insertWord(strs[i]);
        }
        string first = strs[0];
        string ans = "";
        t->lcp(first, ans);
        return ans;
    }

    string longestCommonPrefix(vector<string> &strs)
    {

        // return bruteForce(strc);
        return optimize(strs, strs.size());
    }
};

int main()
{
}