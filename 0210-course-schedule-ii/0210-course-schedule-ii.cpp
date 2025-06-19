class Solution {
public:

    bool dfs(int i,vector<vector<int>>& adj,vector<int>& vis,vector<int>& pvis,vector<int>& res)
    {
        vis[i]=1;
        pvis[i]=1;

        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,pvis,res))
                return true;
            }
            else if(pvis[it])
            return true;
        }
        pvis[i]=0;
        res.push_back(i);
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) 
    {
        if(n==1)
        return {0};

        vector<int> vis(n,0);
        vector<int> pvis(n,0);
        vector<vector<int>> adj(n);
        vector<int> res;
        
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,pvis,res))
                return {};
            }
        }

        reverse(res.begin(),res.end());
        return res;
    }
};