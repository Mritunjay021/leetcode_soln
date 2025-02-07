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
private:
    TreeNode* a = nullptr;
    TreeNode* b = nullptr;
    TreeNode* prev = nullptr;

public:
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(a->val,b->val);
    }

    void helper(TreeNode* curr) {
        if (!curr) return;

        helper(curr->left);

        if (prev != nullptr && prev->val > curr->val) {
            if (!a) a = prev;
            b = curr;
        }

        prev = curr;

        helper(curr->right);
    }
};
