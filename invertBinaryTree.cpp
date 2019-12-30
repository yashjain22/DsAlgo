/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
Leetcode 226 - Invert Binary tree

*/
class Solution {
public:
    void swap(TreeNode** x,TreeNode** y)
    {
        TreeNode* temp = *x;
        *x = *y;
        *y = temp;
    }
    void solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        solve(root->left);
        solve(root->right);
        swap(&root->left,&root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};