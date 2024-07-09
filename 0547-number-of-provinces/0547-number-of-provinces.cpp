class Solution {
public:

    void dfs(int node, vector<int> adjLs[],int vis[]) {
        // mark the more as visited
        vis[node] = 1; 
        for(auto it: adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis); 
            }
        }
    }

    int findCircleNum(vector<vector<int>>& ar) 
    {
        int n=ar.size();
        vector<int> adj[n];
        int vis[n];
        for(int i=0;i<n;i++)
        vis[i]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && ar[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }    
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                c++;
            }
        }
        return c;
    }
};