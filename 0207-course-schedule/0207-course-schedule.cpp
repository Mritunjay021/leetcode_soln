class Solution {
public:

    bool dfs(vector<int>& vis,int i,vector<vector<int>>& adj,vector<int>& pvis)
    {
        vis[i]=1;
        pvis[i]=1;

        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                if(!dfs(vis,it,adj,pvis))
                return false;
            }
            else if(pvis[it])
            return false;
        }
        pvis[i]=0;
        return true;
    }

    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        vector<vector<int>> adj(n);
        vector<int> pvis(n,0),vis(n,0);

        for(int i=0;i<pre.size();i++)
        adj[pre[i][1]].push_back(pre[i][0]);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                {
                    if(!dfs(vis,i,adj,pvis))
                    return false;
                }
        }
        return true;
    }
};