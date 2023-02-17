// Minimum Depth of Binary Tree
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

int solve(TreeNode* root){
    // base case
    if(root==nullptr) return 0;

    int left=solve(root->left);
    int right=solve(root->right);

    // check if the current node is a leafnode then
    if(root->left==nullptr && root->right==nullptr) return 1;

    if(root->left==nullptr) return 1+right;
    if(root->right==nullptr) return 1+left;

    return min(left,right)+1;
}

int minDepth(TreeNode *root)
{
    return solve(root);
}