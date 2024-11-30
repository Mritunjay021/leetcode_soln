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
    bool func(TreeNode* root,long long lh,long long rh)
    {
        if(root==nullptr)
        return true;

        if(root->val <=lh || root->val >= rh)
        return false;

        return func(root->left,lh,root->val) && func(root->right,root->val,rh);
    }
    
    bool isValidBST(TreeNode* root)
    {
        return func(root,LLONG_MIN,LLONG_MAX);
    }
    
    // bool isValidBST(TreeNode* root) 
    // {
    //     if (!root) return true;
        
    //     stack<TreeNode*> st;
    //     TreeNode* prev = nullptr;

    //     while (!st.empty() || root != nullptr) 
    //     {
            
    //         while (root != nullptr) 
    //         {
    //             st.push(root);
    //             root = root->left;
    //         }

    //         root = st.top();
    //         st.pop();

    //         if (prev != nullptr && root->val <= prev->val)
    //             return false;

    //         prev = root; 
    //         root = root->right; 
    //     }
        
    //     return true;
    // }
};
