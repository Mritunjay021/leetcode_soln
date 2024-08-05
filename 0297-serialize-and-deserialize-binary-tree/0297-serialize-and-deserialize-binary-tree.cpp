// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// //  #include<bits/stdc++.h>
// using namespace std;

// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) 
//     {
//         if(root==NULL)
//         return "";
//         string s="";
//         queue<TreeNode* >q;
//         q.push(root);
//         while(!q.empty())
//         {
//             TreeNode* cur=q.front();
//             q.pop();
//             if(cur==NULL)
//             s+="#,";
//             else
//             s+=cur->val;
//             if(cur!=NULL)
//             {
//                 q.push(cur->left);
//                 q.push(cur->right);
//             }
//         }    
//         return s;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) 
//     {
//         if(data.size()==0)
//         return NULL;
//         stringstream s(data);
//         string str;
//         getline(s,str,',');
//         TreeNode* root=new TreeNode(stoi(str));
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty())
//         {
//             TreeNode* node=q.front();
//             q.pop();
//             getline(s,str,',');
//             if(str=="#")
//             node->left=NULL;
//             else
//             {
//                 TreeNode* lft=new TreeNode(stoi(str));
//                 node->left=lft;
//                 q.push(lft);
//             }
//             getline(s,str,',');
//             if(str=="#")
//             node->right=NULL;
//             else
//             {
//                 TreeNode* rgt=new TreeNode(stoi(str));
//                 node->left=rgt;
//                 q.push(rgt);
//             }
//         }
//         return root;

//     }
// };

// // Your Codec object will be instantiated and called as such:
// // Codec ser, deser;
// // TreeNode* ans = deser.deserialize(ser.serialize(root));


#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur == NULL)
                s += "#,";
            else {
                s += to_string(cur->val) + ",";
                q.push(cur->left);
                q.push(cur->right);
            }
        }    
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (getline(s, str, ',')) {
                if (str == "#")
                    node->left = NULL;
                else {
                    TreeNode* lft = new TreeNode(stoi(str));
                    node->left = lft;
                    q.push(lft);
                }
            }
            if (getline(s, str, ',')) {
                if (str == "#")
                    node->right = NULL;
                else {
                    TreeNode* rgt = new TreeNode(stoi(str));
                    node->right = rgt;
                    q.push(rgt);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
