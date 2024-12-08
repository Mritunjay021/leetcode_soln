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

    bool func(TreeNode* root,int sm)
    {
        if(sm==0)
        return true;

        if(!root)
        return false;
        
        bool lh=hasPathSum(root->left,sm-root->val);
        bool rh=hasPathSum(root->right,sm-root->val);

        return lh||rh;

    }

    bool hasPathSum(TreeNode* root, int sm) 
    {
        if(!root)
        return false;

        if(!root->left && !root->right && root->val==sm)
        return true;

        bool lh=hasPathSum(root->left,sm-root->val);
        bool rh=hasPathSum(root->right,sm-root->val);

        return lh||rh;
    }
};