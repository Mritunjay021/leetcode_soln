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
        if(!root)
        return 0;

        int lh=fl(root);
        int rh=fr(root);
        if(lh==rh)
        return (1<<lh)-1;

        return 1+ countNodes(root->left)+countNodes(root->right);   
    }

    int fl(TreeNode* root)
    {
        int ht=0;
        while(root)
        {
            ht++;
            root=root->left;
        }
        return ht;
    }

    int fr(TreeNode* root)
    {
        int ht=0;
        while(root)
        {
            ht++;
            root=root->right;
        }
        return ht;
    }


};