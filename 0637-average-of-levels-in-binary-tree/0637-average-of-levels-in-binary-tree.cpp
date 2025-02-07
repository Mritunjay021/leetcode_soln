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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);

        vector<double> v;

        while(!q.empty())
        {
            double avg=0,sm=0;
            int sz=q.size();

            for(int i=0;i<sz;i++)
            {
                TreeNode* tp=q.front();
                q.pop();
                sm+=tp->val;
                if(tp->left)
                q.push(tp->left);
                if(tp->right)
                q.push(tp->right);
            }
            v.push_back(sm/sz);
        }    
        return v;
    }
};