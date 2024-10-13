class Solution {
public:

    int func(vector<int> days, vector<int> cost , int i , vector<int>& dp)
    {
        if(i>=days.size())
        return 0;

        if(dp[i]!=-1)
        return dp[i];

        // one day pass
        int o=cost[0]+func(days,cost,i+1,dp);

        // 7 day pass
        int j=i;
        int mxd=days[i]+7;
        while(j<days.size() && days[j]<mxd)
        j++;

        int w=cost[1]+func(days,cost,j,dp);

        // monthly pass
        j=i;
        mxd=days[i]+30;
        while(j<days.size() && days[j]<mxd)
        j++;

        int m=cost[2]+func(days,cost,j,dp);

        dp[i]=min(o,min(w,m));

        return dp[i];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        vector<int> dp(days.size()+1,-1);
        return func(days,costs,0,dp);    
    }
};