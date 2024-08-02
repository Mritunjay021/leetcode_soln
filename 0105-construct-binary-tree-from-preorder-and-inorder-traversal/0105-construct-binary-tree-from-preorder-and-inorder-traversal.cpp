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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        map<int,int> inmp;
        for(int i=0;i<inorder.size();i++)
        inmp[inorder[i]]=i;
        TreeNode* root=func(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmp);
        return root;
        
    }
    TreeNode* func(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is,int ie
    ,map<int,int>& inmp)
    {
        if(ps>pe || is>ie)
        return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        int inroot=inmp[root->val];
        int nl=inroot-is;
        root->left=func(preorder,ps+1,ps+nl,inorder,is,inroot-1,inmp);
        root->right=func(preorder,ps+nl+1,pe,inorder,inroot+1,ie,inmp);
        return root;
    }
};