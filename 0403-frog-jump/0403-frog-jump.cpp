class Solution {
public:

    bool func(vector<int>& arr,int i,int j,unordered_map<int,int>& mp,vector<vector<int>>& dp)
    {
        if(i==arr.size()-1)
        return 1;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int p=0,n=0,z=0;

        if(mp.find(arr[i]+j+1)!=mp.end())
        p=func(arr,mp[arr[i]+j+1],j+1,mp,dp);
        
        if(mp.find(arr[i]+j)!=mp.end() && j!=0)
        z=func(arr,mp[arr[i]+j],j,mp,dp);

        if(mp.find(arr[i]+j-1)!=mp.end() && j>=1)
        n=func(arr,mp[arr[i]+j-1],j-1,mp,dp);

        return dp[i][j]=(p || z || n);
    }

    bool canCross(vector<int>& stones) 
    {
        if(stones[1]!=1)
        return 0;

        unordered_map<int,int> mp;

        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        for(int i=1;i<stones.size();i++)
        mp[stones[i]]=i;


        return func(stones,1,1,mp,dp);    
    }
};