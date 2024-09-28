class Solution {
public:
    int mod=1000000007;
     
    int func(int n,vector<int>& dp)
    {
        if(n==0)
        return 1;
        else if(n==1)
        return 2;
        if(dp[n]!=-1)
        return dp[n];
        int p=func(n-2,dp);
        int np=func(n-1,dp);
        return dp[n]=(p+np)%mod;
    }

    int countHousePlacements(int n) 
    {
        
        vector<int> dp2(n+1,-1);
        long long re=func(n,dp2)%mod;
        
        return (re*re)%mod;
    }
};