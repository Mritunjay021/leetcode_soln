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

    void func(TreeNode* root,int& mx,int ht)
    {
        if(!root)
        {
            mx=max(mx,ht);
            return;
        }

        func(root->left,mx,1+ht);
        func(root->right,mx,1+ht);
    }

    int maxDepth(TreeNode* root) 
    {
        int mx=INT_MIN;
        func(root,mx,0);
        return mx;   
    }
};