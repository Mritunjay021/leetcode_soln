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

    void dfs(TreeNode* root,stack<int>& st)
    {
        if(!root)
        return;

        st.push(root->val);

        dfs(root->right,st);
        dfs(root->left,st);
    }

    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(!root)
        return {};

        stack<int> st;
        dfs(root,st);

        vector<int> rs;

        while(!st.empty())
        {
            rs.push_back(st.top());
            st.pop();
        }

        return rs;
    }
};