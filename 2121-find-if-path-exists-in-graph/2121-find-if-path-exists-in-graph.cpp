class Solution {
public:

    void func(vector<vector<int>>& v,int s,vector<int>& vis)
    {
        vis[s]=1;
        for(auto it:v[s])
        {
            if(!vis[it])
            func(v,it,vis);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int s, int d) 
    {
        vector<vector<int>>v (n);

        for(auto it:edges)
        {
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }

        vector<int> vis(n,0);
        
        func(v,s,vis);

        return vis[d];
    }
};