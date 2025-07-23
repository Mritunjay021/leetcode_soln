class Solution {
public:
    int n;

    int func(vector<vector<int>>& grid,int r1,int c1,int r2,int c2,int dp[50][50][50][50])
    {
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
        return INT_MIN;

        if(dp[r1][c1][r2][c2]!=-1)
        return dp[r1][c1][r2][c2];

        int ch;
        if(r1==r2 && c1==c2)
        ch=grid[r1][c1];
        else
        ch=grid[r1][c1]+grid[r2][c2];

        if((r1==n-1 && c1==n-1) && (r2==n-1 && c2==n-1))
        return ch;

        int p1=func(grid,r1+1,c1,r2+1,c2,dp);
        int p2=func(grid,r1,c1+1,r2+1,c2,dp);
        int p3=func(grid,r1,c1+1,r2,c2+1,dp);
        int p4=func(grid,r1+1,c1,r2,c2+1,dp);

        return dp[r1][c1][r2][c2]=ch+max(p1,max(p2,max(p3,p4)));
    }

    int cherryPickup(vector<vector<int>>& grid) 
    {
        n=grid.size();
        int dp[50][50][50][50];

        memset(dp, -1, sizeof(dp));

        return max(0,func(grid,0,0,0,0,dp));    
    }
};