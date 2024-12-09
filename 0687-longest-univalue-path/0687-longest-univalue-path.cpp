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
    int longestPath = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int leftPath = (root->left && root->left->val == root->val) ? left + 1 : 0;
        int rightPath = (root->right && root->right->val == root->val) ? right + 1 : 0;

        longestPath = max(longestPath, leftPath + rightPath);

        return max(leftPath, rightPath);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return longestPath;
    }
};
