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
    int countNodes(TreeNode* root) 
    {
        if(root==NULL)
        return 0;
        int lh=fnc1(root);
        int rh=fnc2(root);
        if(lh==rh)
        return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);    
    }
    int fnc1(TreeNode* node)
    {
        int hg=0;
        while(node)
        {
            hg++;
            node=node->left;
        }
        return hg;
    }
    int fnc2(TreeNode* node)
    {
        int hg=0;
        while(node)
        {
            hg++;
            node=node->right;
        }
        return hg;
    }
};