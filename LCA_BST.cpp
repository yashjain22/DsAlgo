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
     l,r are in left subtree
     then lca is in left subtree
     if l,r are in right subtree
     then lca is in right subtree
     if is in left-subtree,and r is in right_subtree, then this node is lca
     also if root == l || root == r then root is the lca
*/
class Solution {
public:
    void swap(TreeNode** p,TreeNode** q)
    {
        TreeNode* temp = *p;
        *p = *q;
        *q = temp;
    }
    TreeNode* solve(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root == p || root == q)
        {
            return root;
        }
    
        if(root->val>p->val && root->val <q->val)
        {
            return root;
        }
        
        if(root->val > q->val)
        {
            return solve(root->left,p,q);
        }
        else
        {
            return solve(root->right,p,q);
        }        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(p->val > q->val)
        {
            swap(&p,&q);
        }
        return solve(root,p,q);
    }
};