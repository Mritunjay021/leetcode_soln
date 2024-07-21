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
    void post(TreeNode *root,vector<int>& re)
{
    if(root==NULL)
    return ;
    post(root->left,re);
    post(root->right,re);
    re.push_back(root->val);
}

    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>re;
        post(root,re);
        return re;    
    }
};