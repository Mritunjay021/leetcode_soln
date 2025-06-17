class Solution {
public:

    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    int m,n;

    void dfs(vector<vector<char>>& board,int r,int c,vector<vector<int>>& vis)
    {
        vis[r][c]=1;

        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc]=='O')
            {
                dfs(board,nr,nc,vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) 
    {
        m=board.size();
        n=board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
            dfs(board,i,0,vis);
            if(board[i][n-1]=='O')
            dfs(board,i,n-1,vis);
        }

        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O')
            dfs(board,0,i,vis);
            if(board[m-1][i]=='O')
            dfs(board,m-1,i,vis);
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                board[i][j]='X';
            }
        }
    }
};