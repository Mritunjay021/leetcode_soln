class Solution {
public:

    int mod=1000000007;

    int func(vector<vector<int>> grid,int i,int j,int k,vector<vector<int>>& dp,int& re)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int d=grid[i][j]+func(grid,i+1,j,k,dp,re);
        int r=grid[i][j]+func(grid,i,j+1,k,dp,re);
        if(((d+r)%mod)%k==0)
        {
            ++re;
        }
        dp[i][j]=(d+r)%mod;
        return dp[i][j];
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int re=0;
        return func(grid,0,0,k,dp,re);  
    }
};