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

class BST{
    stack<TreeNode*> st;
    bool rev;

public:
    BST(TreeNode* root,bool rev)
    {
        this->rev = rev;
        pushall(root);
    }

    bool hasnext()
    {
        return !st.empty();
    }

    int next()
    {
        TreeNode* tp = st.top();
        st.pop();

        if(rev)
            pushall(tp->left);
        else
            pushall(tp->right);

        return tp->val;
    }

private:
    void pushall(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            if(rev)
                root = root->right;
            else
                root = root->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) 
    {
        if(!root)
        return 0;

        BST l(root,0);
        BST r(root,1);

        int i=l.next();
        int j=r.next();

        while(i<j)
        {
            if(i+j==k)
            return 1;
            else if(i+j<k)
            i=l.next();
            else
            j=r.next();
        }
        return 0;

    }
};