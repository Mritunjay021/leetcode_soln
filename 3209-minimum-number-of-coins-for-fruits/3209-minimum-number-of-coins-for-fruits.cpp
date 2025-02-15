class Solution {
public:

    int func(vector<int>& pr,int i,vector<int>& dp)
    {
        if(i>=pr.size())
        return 0;

        if(dp[i]!=-1)
        return dp[i];

        int re=INT_MAX;

        for(int k=i+1;k<=2*i+2;k++)
        {
            re=min(re,func(pr,k,dp));
        }

        return dp[i]=re+pr[i];
    }

    int minimumCoins(vector<int>& pr) 
    {
        vector<int> dp(pr.size(),-1);
        return func(pr,0,dp);    
    }
};