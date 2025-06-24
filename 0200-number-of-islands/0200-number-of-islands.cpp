class Solution {
public:

    int n,m;

    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};

    void bfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int i,int j)
    {
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});

        while (!q.empty()) {
            auto [row, col] = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == '1' && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        n=grid.size();
        m=grid[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));  

        int re=0; 

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    bfs(grid,vis,i,j);
                    re++;
                }
            }
        }
        return re;
    }
};