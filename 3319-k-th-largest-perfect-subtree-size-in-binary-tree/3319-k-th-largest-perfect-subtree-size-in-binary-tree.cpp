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
    priority_queue<int,vector<int> ,greater<int>> pq;

    int func(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        
        int lh=func(root->left);

        int rh=func(root->right);

        if(lh>=0 && lh==rh)
        {
            pq.push(lh+rh+1);
            return lh+rh+1;
        }
        
        return -1;
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) 
    {
        func(root);

        if(k>pq.size() || k<=0)
        return -1;
        while(pq.size()>k)
        {
            pq.pop();
        }

        return pq.top();
    }
};