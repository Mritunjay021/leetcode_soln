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
class Solution 
{
public:
    
    int func(TreeNode* root, long sum) {
        if (!root) 
        return 0;

        int re = 0;
        if (root->val == sum) 
        re++;  
        
        re += func(root->left, sum - root->val);
        re += func(root->right, sum - root->val);

        return re;
    }

    int pathSum(TreeNode* root, int s) 
    {
        if (!root) 
        return 0;

        return func(root,s)+pathSum(root->left,s)+pathSum(root->right,s);
    }
};
