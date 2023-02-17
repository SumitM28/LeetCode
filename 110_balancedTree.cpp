// check if the given tree if a balanced tree or not.
#include<bits/stdc++.h>
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
int solve(TreeNode *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    int left = solve(root->left);
    int right = solve(root->right);

    if (left == -1 || right == -1 || abs(left - right) > 1)
        return -1;
    return max(left, right) + 1;
}
bool isBalanced(TreeNode *root)
{
    int ans = solve(root);
    if (ans == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}