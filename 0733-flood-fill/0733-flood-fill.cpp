class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) 
    {
        if(img[sr][sc]==color)
        return img;
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>> grid(n,vector<int>(m));
        grid[sr][sc]=color;
        int vis[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            vis[i][j]=0;
        }
        vis[sr][sc]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && img[nrow][ncol]!=0 && vis[nrow][ncol]==0)
                {
                    grid[nrow][ncol]=color;
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                } 
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0)
                grid[i][j]=img[i][j];
            }
        }
        return grid;

    }
};