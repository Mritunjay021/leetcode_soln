class Solution {
public:

    int func(vector<vector<int>>& mat,int m,int n, int t,int i,int sum,vector<vector<int>>& dp)
    {
        if(i==m)
        return abs(sum-t);

        // if(i==m-1)
        // return mat[i][j];

        if(dp[i][sum]!=-1)
        return dp[i][sum];

        int mn=INT_MAX;

        for(int j=0;j<n;j++)
        {
            mn=min(mn,func(mat,m,n,t,i+1,sum+mat[i][j],dp));
        }
        return dp[i][sum]=mn;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int t) 
    {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> dp(m,vector<int>(4900,-1));
        return func(mat,m,n,t,0,0,dp);
    }
};