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
    bool isUnivalTree(TreeNode* root) 
    {
        if(!root)
        return true;

        bool l = (root->left == nullptr || (root->val == root->left->val && isUnivalTree(root->left)));
        bool r = (root->right == nullptr || (root->val == root->right->val && isUnivalTree(root->right)));
        return l&&r;
    }
};