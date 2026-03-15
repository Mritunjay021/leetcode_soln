/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int mx;

    int func(TreeNode* root)
    {
        if(!root)
        return 0;

        int lft=func(root->left);
        int rgt=func(root->right);

        mx=max(mx,root->val+lft+rgt);

        if(root->val+max(lft,rgt)<0)
        return 0;
        else
        return root->val+max(lft,rgt);
    }

    int maxPathSum(TreeNode* root) 
    {
        if(!root)
        return 0;

        mx=root->val;

        func(root);

        return mx;
    }
};