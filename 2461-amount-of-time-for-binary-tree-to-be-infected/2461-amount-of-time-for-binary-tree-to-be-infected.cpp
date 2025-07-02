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

    void func(TreeNode* root,map<TreeNode*,TreeNode*>& mp,TreeNode*& tgt,int start)
    {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* n=q.front();
            q.pop();

            if(n->val==start)
            tgt=n;

            if(n->left)
            {
                mp[n->left]=n;
                q.push(n->left);
            }

            if(n->right)
            {
                mp[n->right]=n;
                q.push(n->right);
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) 
    {
        map<TreeNode*,TreeNode*> mp;
        TreeNode* tgt;
        func(root,mp,tgt,start);  

        queue<pair<TreeNode*,int>> q;
        q.push({tgt,0});

        map<TreeNode*,bool> vis;
        vis[tgt]=1;

        int mx=0;

        while(!q.empty())  
        {
            TreeNode* n=q.front().first;
            int d=q.front().second;

            q.pop();

            mx=max(mx,d);

            if(n->left && !vis[n->left])
            {
                vis[n->left]=1;
                q.push({n->left,d+1});
            }

            if(n->right && !vis[n->right])
            {
                vis[n->right]=1;
                q.push({n->right,d+1});
            }

            if(mp[n] && !vis[mp[n]])
            {
                vis[mp[n]]=1;
                q.push({mp[n],d+1});
            }

        }
        return mx;
    }
};