class Solution {
public:

    int f(int i,int n,vector<int>& prices,int c,int buy,vector<vector<vector<int>>>& dp)
    {
        if(i==n || c==0)
        return 0;

        if(dp[i][buy][c]!=-1)
        return dp[i][buy][c];

        int profit=0;
        if(buy==0)
        profit=max(-prices[i]+f(i+1,n,prices,c,1,dp),f(i+1,n,prices,c,0,dp));
        else
        profit=max(prices[i]+f(i+1,n,prices,c-1,0,dp),f(i+1,n,prices,c,1,dp));
        return dp[i][buy][c]=profit;
    }

    int maxProfit(int k, vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,n,prices,k,0,dp);
    }
};