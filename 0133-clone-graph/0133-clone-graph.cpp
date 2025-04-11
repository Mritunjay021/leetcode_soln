/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* dfs(Node* node,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> nei;
        Node* clone=new Node(node->val);
        mp[node]=clone;

        for(auto it:node->neighbors)
        {
            if(mp.find(it)!=mp.end())
            nei.push_back(mp[it]);
            else
            nei.push_back(dfs(it,mp));
        }
        clone->neighbors=nei;

        return clone;

    }

    Node* cloneGraph(Node* node) 
    {
        if(node == NULL)
        return NULL;

        unordered_map<Node*,Node*> mp;

        if(node->neighbors.size()==0)   //if only one node present no neighbors
        {
            Node* clone= new Node(node->val);
            return clone; 
        }

        return dfs(node,mp);
    }
};