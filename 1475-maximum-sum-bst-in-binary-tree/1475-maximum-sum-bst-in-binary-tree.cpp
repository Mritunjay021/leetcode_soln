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

    int re;

    vector<int> func(TreeNode* root)
    {
        if(root==NULL)
        return {INT_MAX,INT_MIN,0};

        vector<int> l=func(root->left);
        vector<int> r=func(root->right);

        if((l[1]>=root->val)||(r[0]<=root->val))
        return {INT_MIN,INT_MAX,0};

        int sum=root->val+l[2]+r[2];
        re=max(re,sum);

        return {min(root->val,l[0]),max(root->val,r[1]),sum};
    }

    int maxSumBST(TreeNode* root) 
    {
        re=0;
        func(root);
        return re>0?re:0; 
    }
};