class Solution {
public:

    int mod=1000000007;
    int func(int i,int ep,int k,vector<vector<int>>& dp)
    {
        if(k==0)
        {
            if(i==ep)
            return 1;
            else 
            return 0;
        }
        if(dp[i+1000][k]!=-1)
        return dp[i+1000][k];
        int l=func(i+1,ep,k-1,dp);
        int r=func(i-1,ep,k-1,dp);
        return dp[i+1000][k]=(l+r)%mod;
    }

    int numberOfWays(int sp, int ep, int k) 
    {
        vector<vector<int>> dp(3000,vector<int>(k+1,-1));
        return func(sp,ep,k,dp);    
    }
};