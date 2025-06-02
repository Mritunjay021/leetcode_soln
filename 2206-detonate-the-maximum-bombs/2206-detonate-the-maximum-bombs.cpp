#include <cmath>

class Solution {
public:

    int func(vector<vector<int>>& adj,vector<int>& vis,int i)
    {
        vis[i]=1;
        int c=1;

        for(auto it:adj[i])
        {
            if(!vis[it])
            c+=func(adj,vis,it);
        }
        return c;
    }

    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        int n=bombs.size();
        vector<vector<int>> adj(n);
        int mx=0;
        

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    long long dx = bombs[i][0] - bombs[j][0];
                    long long dy = bombs[i][1] - bombs[j][1];
                    long long dis_sq = dx * dx + dy * dy;
                    long long r_sq = (long long)bombs[i][2] * bombs[i][2];
                    if (dis_sq <= r_sq)
                    {
                        adj[i].push_back(j);
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            vector<int> vis(n,0);
            mx=max(mx,func(adj,vis,i));
        }
        return mx;
    }
};