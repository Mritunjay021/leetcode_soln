class Solution {
public:

    int findNumberOfLIS(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int> dp(n,1),cnt(n,1);
        int mx=1;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(arr[i]>arr[prev] && dp[i]<1+dp[prev])
                {
                    dp[i]=dp[prev]+1;
                    cnt[i]=cnt[prev];
                }
                else if(arr[prev]<arr[i] && 1+dp[prev]==dp[i])
                {
                    cnt[i]+=cnt[prev];
                }
            }
            mx=max(mx,dp[i]);
        }   
        int nos=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==mx) nos+=cnt[i];
        }
        return nos;
    }
};