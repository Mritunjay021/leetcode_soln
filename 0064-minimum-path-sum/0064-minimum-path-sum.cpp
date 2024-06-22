class Solution {
public:

    int func(int m,int n,vector<vector<int>>& dp,vector<vector<int>>& og)
    {
        if(m==0 && n==0)
        return og[m][n];
        if(dp[m][n]!=-1)
        return dp[m][n];
        int l=INT_MAX,r=INT_MAX;
        if(n!=0)
        l=og[m][n]+func(m,n-1,dp,og);
        if(m!=0)
        r=og[m][n]+func(m-1,n,dp,og);
        return dp[m][n]=min(l,r);
    }

    int minPathSum(vector<vector<int>>& og) 
    {
        int m=og.size();
        int n=og[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(m-1,n-1,dp,og);    
    }
};