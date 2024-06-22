class Solution {
public:

    int func(int m,int n,vector<vector<int>>&dp)
    {
        if(m==0 && n==0)
        return 1;
        if(dp[m][n]!=-1)
        return dp[m][n];
        int l=0,r=0;
        if(n!=0)
        l+=func(m,n-1,dp);
        if(m!=0  )
        r+=func(m-1,n,dp);
        return dp[m][n]=l+r;
    }

    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(m-1,n-1,dp);
    }
};