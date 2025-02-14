class Solution {
public:

    int func(int i,vector<int>& cost,int n,vector<int>& dp)
    {
        if(i>=n)
        return 1e9;
        else if(i==n-1 || i==n-2)
        return cost[i];
        if(dp[i]!=-1)
        return dp[i];
        dp[i] = cost[i] + min(func(i + 1, cost, n, dp), func(i + 2, cost, n, dp));
        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size();
        //int c=0;
        vector<int> dp(n,-1);
        return min(func(0,cost,n,dp),func(1,cost,n,dp));    
    }
};