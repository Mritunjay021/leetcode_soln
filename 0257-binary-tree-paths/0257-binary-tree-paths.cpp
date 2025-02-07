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

    vector<string> re;

    void func(TreeNode* root,string st)
    {
        if(!root)
        return;

        if(!root->left && !root->right)
        {
            re.push_back(st+to_string(root->val));
            return;
        }

        if(root->left)
        func(root->left,st+to_string(root->val)+"->");
        if(root->right)
        func(root->right,st+to_string(root->val)+"->");
        
    }

    vector<string> binaryTreePaths(TreeNode* root) 
    {
        string st="";

        func(root,st); 
        return re;   
    }
};