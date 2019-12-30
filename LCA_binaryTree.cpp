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
My approach ->

find parent list of node p
find parent list of node q
find the first node that matches in both p and q parent list.
that would be your lowest common ancestor.
Time complexity - O(N)
Space complexity - O(N)
*/

class Solution {
    unordered_map<TreeNode*, TreeNode*> m;
public:
    void findParent(TreeNode* root)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left)
        {
            m[root->left] = root;
        }
        if (root->right)
        {
            m[root->right] = root;
        }
        findParent(root->left);
        findParent(root->right);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_parent;
        vector<TreeNode*> q_parent;
        m[root] = NULL;
        findParent(root);
        do
        {
            p_parent.push_back(p);
            p = m[p];
        } while (p);

        do
        {
            q_parent.push_back(q);
            q = m[q];
        } while (q);

        // 7 2 5 3
        // 6 5 3

        unordered_set<TreeNode*> s;

        for (auto it : p_parent)
        {
            s.insert(it);
        }
        for (auto it : q_parent)
        {
            if (s.find(it) != s.end())
            {
                return it;
            }
        }

        return NULL;
    }
};


