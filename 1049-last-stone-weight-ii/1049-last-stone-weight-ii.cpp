class Solution {
public:

    int func(vector<int>& stones,int i,vector<vector<int>>& dp,int re,int sum)
    {
        if(i>=stones.size())
        return sum;

        if(dp[i][sum]!=-1)
        return dp[i][sum];

        int p=INT_MIN;
        if(sum+stones[i]<=re)
        p=func(stones,i+1,dp,re,sum+stones[i]);

        int np=func(stones,i+1,dp,re,sum);
        dp[i][sum]=max(p,np);
        return dp[i][sum];
    }

    int lastStoneWeightII(vector<int>& stones) 
    {
        int n=stones.size();
        int sum=0;
        for(auto it:stones)
        sum+=it;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        int re=func(stones,0,dp,int(sum/2),0);
        return (sum-re)-re;
    }
};