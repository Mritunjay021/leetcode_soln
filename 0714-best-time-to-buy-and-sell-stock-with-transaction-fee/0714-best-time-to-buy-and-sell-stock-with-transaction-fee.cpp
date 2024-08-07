class Solution {
public:

    int f(int i,int buy,vector<int>& prices,int n,vector<vector<int>>& dp,int fee)
    {
        if(i==n)
        return 0;
        if(dp[i][buy]!=-1)
        return dp[i][buy];
        int profit=0;
        if(buy)
        profit=max(f(i+1,0,prices,n,dp,fee)-prices[i],f(i+1,1,prices,n,dp,fee));
        else
        profit=max(prices[i]+f(i+1,1,prices,n,dp,fee)-fee,f(i+1,0,prices,n,dp,fee));
        return dp[i][buy]=profit;
        
    }

    int maxProfit(vector<int>& prices, int fee) 
    {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return f(0,1,prices,n,dp,fee);    
    }
};