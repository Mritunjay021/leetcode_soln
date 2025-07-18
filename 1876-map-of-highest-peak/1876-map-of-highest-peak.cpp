class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) 
    {
        int m=mat.size();
        int n=mat[0].size();

        queue<pair<pair<int,int>,int>> q;

        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    int d=0;

                    if(i-1<m && i-1>=0 && mat[i-1][j]==1)
                    d=mat[i-1][j]+1;
                    else if(i-1<m && i-1>=0 && j-1<n && j-1>=0 && mat[i-1][j-1]==1)
                    d=mat[i-1][j-1]+1;

                    q.push({{i,j},d});
                    mat[i][j]=d;
                    vis[i][j]=1;
                }
            }
        }  

        int dr[4]={-1,0,1,0};
        int dc[4]={0,-1,0,1};

        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;

            q.pop();

            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc])
                {
                    vis[nr][nc]=1;
                    q.push({{nr,nc},d+1});
                    mat[nr][nc]=d+1;
                }
            }
        }  

        return mat;
    }
};