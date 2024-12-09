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
    vector<int> v;
    void func(TreeNode* root,int sm)
    {
        if(!root->left && !root->right)
        {
            v.push_back(sm+root->val);
        }

        if(root->left)
        func(root->left,(sm+root->val)*10);

        if(root->right)
        func(root->right,(sm+root->val)*10);
    }

    int sumNumbers(TreeNode* root) 
    {
        if(!root)
        return 0;
        int sm=0;
        func(root,0);
        for(int i=0;i<v.size();i++)
        sm+=v[i];
        return sm;
    }
};