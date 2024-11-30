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
    
    
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            long long sum=0;
            long long sz=q.size();
            for(long long i=0;i<sz;i++)
            {
                TreeNode* node=q.front();
                sum+=node->val;
                q.pop();
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            if (minHeap.size() < k) {
                minHeap.push(sum);
            } else if (sum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(sum);
            }
        }
        return minHeap.size()==k?minHeap.top():-1;
    }
};