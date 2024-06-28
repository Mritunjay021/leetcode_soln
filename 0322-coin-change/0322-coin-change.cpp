class Solution {
public:

    int func(vector<int>& coins, int n,int i)
    {
        
        if(i==0)
        {
            if(n%coins[0]==0) 
            return n/coins[0];
            return 1e9;
        }
        int nt=0+func(coins,n,i-1);
        int t=1e9;
        if(coins[i]<=n)
        t=1+func(coins,n-coins[i],i);
        
        return min(t,nt);
    }

    int coinChange(vector<int>& coins, int n) 
    {
        int v=func(coins,n,coins.size()-1);
        if(v==1e9)
        return -1;
        return v;
    }
};