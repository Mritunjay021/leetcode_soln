class Solution {
public:

    void dfs(int r,int c,vector<vector<int>>& board,vector<vector<int>>& vis,int dr[],int dc[])
    {
        vis[r][c]=1;
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && vis[nr][nc]==0 
            && board[nr][nc]==1)
            {
                //board[nr][nc]=0;
                dfs(nr,nc,board,vis,dr,dc);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& board) 
    {
        int n=board.size();
        int m=board[0].size(); 
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            if(!vis[0][i] && board[0][i]==1)
            {
                dfs(0,i,board,vis,dr,dc);
            }
            if(!vis[n-1][i]&& board[n-1][i]==1)
            {
                dfs(n-1,i,board,vis,dr,dc);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0]&& board[i][0]==1)
            dfs(i,0,board,vis,dr,dc);
            if(!vis[i][m-1]&& board[i][m-1]==1)
            dfs(i,m-1,board,vis,dr,dc);
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j]==1)
                cnt++;
            }
        }
        return cnt;
    }
};