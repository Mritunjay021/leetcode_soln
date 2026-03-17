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
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root)
        return NULL;

        if(root->val == key)
        return func(root);

        TreeNode* dummy=root;

        while(dummy)
        {
            if(dummy->val>key)
            {
                if(dummy->left != NULL && dummy->left->val == key)
                {
                    dummy->left=func(dummy->left);
                    break;
                }
                else
                dummy=dummy->left;
            }
            else
            {
                if(dummy->right != NULL && dummy->right->val == key)
                {
                    dummy->right=func(dummy->right);
                    break;
                }
                else
                dummy=dummy->right;
            }
        }
        return root;    
    }

    TreeNode* func(TreeNode* root)
    {
        if(!root->left)
        return root->right;

        if(!root->right)
        return root->left;

        TreeNode* rt=root->right;
        TreeNode* last=lastchild(root->left);
        last->right=rt;
        return root->left;
    }

    TreeNode* lastchild(TreeNode* root)
    {
        if(!root->right)
        return root;

        return lastchild(root->right);
    }
};