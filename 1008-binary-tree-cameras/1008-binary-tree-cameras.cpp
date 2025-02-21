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

    int cameras = 0;

    int dfs(TreeNode* root) {
        if (!root) return 2; // Null nodes are covered
        
        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == 0 || right == 0) { // If any child needs a camera
            cameras++;
            return 1; // Place a camera here
        }

        if (left == 1 || right == 1) return 2; // If a child has a camera, this node is covered

        return 0; // Otherwise, this node needs a camera
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) cameras++; // If root itself is not covered
        return cameras;
    }
};