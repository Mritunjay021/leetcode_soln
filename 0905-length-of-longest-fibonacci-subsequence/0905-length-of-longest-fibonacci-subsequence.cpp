class Solution {
public:

    int func(vector<int>& arr,int i,int j,unordered_map<int,int>& mp,vector<vector<int>>& dp)
    {
        if(dp[i][j]!=0)
        return dp[i][j];

        int l=2;
        
        int key=arr[i]+arr[j];
        if(mp.find(key)!=mp.end())
        {
            l=max(l,1+func(arr,j,mp[key],mp,dp)); 
        }

        return dp[i][j]=l;
    }

    int lenLongestFibSubseq(vector<int>& arr) 
    {
        int n=arr.size();
        int mx=0;

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        mp[arr[i]]=i;

        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int len=func(arr,i,j,mp,dp);
                if(len>2)
                mx=max(mx,len);
            }
        }

        return mx;
    }
};