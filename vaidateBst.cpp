
/**
 LeetCode 98 - validate BST

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

 */
/*

// approach 1 -> deserialize the bst and verify arr[i] > arr[i-1]
//  approach 2 ->
//  inorder traversal while maintaining min and max
//  if this violates,return false,else return true
*/
class Solution {
public:
    bool solve(TreeNode* root,long long int min,long long int max)
    {
        if(root == NULL)
        {
            return true;
        }
        if(root->val < min || root->val > max)
        {
            return false;
        }
        return solve(root->left,min,(long long int)root->val-1)&&solve(root->right,(long long int)root->val+1,max);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,INT_MIN,INT_MAX);
    }
};
