class Solution {
public:

    int func(int am,vector<int>& coins,int ind,vector<vector<int>>& dp)
    {
        if(am==0)
        return 1;
        if(ind==0)
        return (am%coins[ind]==0);
        if(dp[ind][am]!=-1)
        return dp[ind][am];

        int nt=func(am,coins,ind-1,dp);

        int t=0;
        if(coins[ind]<=am)
        t=func(am-coins[ind],coins,ind,dp);
        
        return dp[ind][am]=t+nt;

    }
    
    
    int change(int amount, vector<int>& coins) 
    {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return func(amount,coins,coins.size()-1,dp);    
    }
};