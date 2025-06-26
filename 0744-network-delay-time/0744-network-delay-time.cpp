class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times)
        adj[it[0]].push_back({it[1],it[2]});
        queue<pair<int,int>> q;
        vector<int> vis(n+1,1e9);
        vis[k]=0;
        q.push({k,0});
        while(!q.empty())
        {
            int node=q.front().first;
            int dis=q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                int nd=it.first;
                int d=it.second;
                if(dis+d<vis[nd])
                {
                    vis[nd]=dis+d;
                    q.push({nd,dis+d});
                }
            }
        }
        int mx=0;
        for(int i=1;i<n+1;i++)
        {
            mx=max(mx,vis[i]);
        }
        if(mx==1e9)
        return -1;
        return mx;
    }
};

