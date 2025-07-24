class Solution {
public:

    int m,n;

    int func(vector<vector<int>>& grid,int i,int j,int k,vector<vector<vector<int>>>& dp)
    {
        if(i>=m || j<0 || j>=n || k<0 || k>=n)
        return INT_MIN;

        if(dp[i][j][k]!=-1)
        return dp[i][j][k];

        int re=0;

        if(j==k)
        re+=grid[i][j];
        else
        re+=grid[i][k]+grid[i][j];

        if(i==m-1)
        return dp[i][j][k]=re;

        re+=max({
            func(grid,i+1,j-1,k-1,dp),
            func(grid,i+1,j,k-1,dp),
            func(grid,i+1,j+1,k-1,dp),
            func(grid,i+1,j-1,k,dp),
            func(grid,i+1,j+1,k,dp),
            func(grid,i+1,j,k,dp),
            func(grid,i+1,j-1,k+1,dp),
            func(grid,i+1,j,k+1,dp),
            func(grid,i+1,j+1,k+1,dp),
        });

        return dp[i][j][k]=re;
    }

    int cherryPickup(vector<vector<int>>& grid) 
    {
        m=grid.size();
        n=grid[0].size();

        vector<vector<vector<int>>> dp(m+1,vector<vector<int>> (n,vector<int> (n,-1)));
        
        return func(grid,0,0,n-1,dp);
    }
};