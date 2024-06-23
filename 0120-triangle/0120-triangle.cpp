class Solution {
public:

    int func(vector<vector<int>>& tri,int r,int i,int j,vector<vector<int>>&dp)
    {
        if(i==r-1)
        return tri[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int d=tri[i][j]+func(tri,r,i+1,j,dp);
        int dg=tri[i][j]+func(tri,r,i+1,j+1,dp);
        return dp[i][j]=min(d,dg);
    }

    int minimumTotal(vector<vector<int>>& tri) 
    {
        int r=tri.size();
        int c=tri[r-1].size();
        vector<vector<int>>dp (r,vector<int>(c,-1));
        return func(tri,r,0,0,dp);
    }
};