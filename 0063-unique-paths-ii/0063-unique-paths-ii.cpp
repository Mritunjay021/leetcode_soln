class Solution {
public:

    int func(int m,int n,vector<vector<int>>& dp,vector<vector<int>>& og)
    {
        if(m>=0 && n>=0 && og[m][n]==1)
        return 0;
        if(m==0 && n==0)
        return 1;
        if(dp[m][n]!=-1)
        return dp[m][n];
        int l=0,r=0;
        if(n!=0)
        l=func(m,n-1,dp,og);
        if(m!=0)
        r=func(m-1,n,dp,og);
        return dp[m][n]=l+r;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& og) 
    {
        int m=og.size();
        int n=og[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(m-1,n-1,dp,og);
    }
};