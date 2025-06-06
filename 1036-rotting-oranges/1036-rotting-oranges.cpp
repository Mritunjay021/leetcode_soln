class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue<pair<int,pair<int,int>>> q;

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int fr=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
                else
                vis[i][j]=0;

                if(grid[i][j]==1)
                fr++;
            }
        }   

        int tm=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int cnt=0;

        while(!q.empty())
        {
            int t=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            tm=max(t,tm);

            q.pop();

            for(int i=0;i<4;i++)
            {
                int nr=dr[i]+x;
                int nc=dc[i]+y;

                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && vis[nr][nc]==0)
                {
                    vis[nr][nc]=1;
                    q.push({t+1,{nr,nc}});
                    cnt++;
                }
            }
        } 

        if(cnt==fr)
        return tm;
        return -1;


    }
};