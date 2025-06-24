

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,1e9));
        vis[0][0]=0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0,{0,0}});

        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        while(!pq.empty())
        {
            int d=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;

            if(x==n-1 && y==m-1)
            return d;

            pq.pop();

            for(int i=0;i<4;i++)
            {
                int nr=x+dr[i];
                int nc=y+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    int df=max(abs(grid[x][y]-grid[nr][nc]),d);
                    if(df<vis[nr][nc])
                    {
                        vis[nr][nc]=df;
                        pq.push({df,{nr,nc}});
                    }
                }
            }
        }   

        return 0;
    }
};