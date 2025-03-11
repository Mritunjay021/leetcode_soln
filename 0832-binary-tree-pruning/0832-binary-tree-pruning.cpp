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

    int func(TreeNode* root,int v)
    {
        if(!root)
        return 0;

        int l=func(root->left,v);

        int r=func(root->right,v);

        if(l==0)
        root->left=NULL;

        if(r==0)
        root->right=NULL;

        return root->val || l || r;

    }

    TreeNode* pruneTree(TreeNode* root) 
    {
        int val=func(root,1);

        return val==0?nullptr:root;
   
    }
};