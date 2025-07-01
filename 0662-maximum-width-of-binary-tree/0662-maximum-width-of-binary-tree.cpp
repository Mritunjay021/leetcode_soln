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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(!root)
        return 0;

        queue<pair<TreeNode*,long>> q;
        q.push({root,0});

        int ans=0;

        while(!q.empty())
        {
            int sz=q.size();
            int mn=q.front().second;

            int f,l;

            for(int i=0;i<sz;i++)
            {
                TreeNode* n=q.front().first;
                int lvl=q.front().second;

                q.pop();

                int cur=lvl-mn;

                if(i==0)
                f=cur;
                if(i==sz-1)
                l=cur;

                if(n->left)
                q.push({n->left,1+cur*2LL});

                if(n->right)
                q.push({n->right,2+cur*2LL});


            }
            ans=max(ans,l-f+1);

        }    
        return ans;
    }
};