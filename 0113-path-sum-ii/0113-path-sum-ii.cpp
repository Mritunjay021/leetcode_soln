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

    vector<vector<int>> ans;

    void func(TreeNode* root,int s,vector<int>& re)
    {
        if(!root)
        return;

        if(!root->left && !root->right && root->val==s)
        {
            re.push_back(root->val);
            ans.push_back(re);
            re.pop_back();
        }

        if(root->left )
        {
            re.push_back(root->val);
            func(root->left,s-root->val,re);
            re.pop_back();
        }

        if(root->right )
        {
            re.push_back(root->val);
            func(root->right,s-root->val,re);
            re.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int sm) 
    {
        vector<int> re;
        
        if(!root)
        return ans;
        
        func(root,sm,re);

        return ans;

    }
};