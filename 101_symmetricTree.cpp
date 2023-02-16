// check is the tree is symmetric tree or not.
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// approach 1st
void inOrder(TreeNode *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }

    inOrder(root->left, ans);
    ans.push_back(root->val);
    inOrder(root->right, ans);
}

bool isSymmetric(TreeNode *root)
{
    vector<int> ans;
    inOrder(root, ans);

    int i = 0;
    int j = ans.size() - 1;
    while (i < j)
    {
        if (ans[i] != ans[j])
        {
            return false;
        }
        i++, j--;
    }
    return true;
}

// using recursion
bool solve(TreeNode *r1, TreeNode *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if (r1 == NULL || r2 == NULL)
    {
        return false;
    }
    if (r1->val != r2->val)
        return false;
    bool case1 = solve(r1->left, r2->right);
    bool case2 = solve(r1->right, r2->left);

    return case1 && case2;
}

int main()
{

    
}