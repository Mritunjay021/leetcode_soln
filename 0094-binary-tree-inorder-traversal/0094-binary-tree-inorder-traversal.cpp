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
    void ino(TreeNode *root,vector<int>& re)
{
    if(root==NULL)
    return ;
    
    ino(root->left,re);
    re.push_back(root->val);
    ino(root->right,re);
    
}

    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>re;
        // ino(root,re);
        // return re;    
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(true)
        {
            if(node!=NULL)
            {
                st.push(node);
                node=node->left;
            }
            else
            {
                if(st.empty())
                break;
                node=st.top();
                st.pop();
                re.push_back(node->val);
                node=node->right;
            }
        }
        return re;
    }
};