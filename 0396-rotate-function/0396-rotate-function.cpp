class Solution {
public:

    // int func(vector<int>& nums,int i,int s,int f)
    // {
    //     if(i>=nums.size())
    //     return 0;

    //     int fn=
    //     return max(mx,fn);
    // }

    int maxRotateFunction(vector<int>& nums) 
    {
        int n=nums.size();
        int s=0;

        for(auto it:nums)
        s+=it;

        vector<int> dp(n,0);

        for(int i=0 ;i<nums.size();i++)
        {
            dp[0]+=i*nums[i];
        }

        int mx=dp[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1]+s-(n*nums[n-i]);
            cout<<dp[i]<<endl;
            mx=max(mx,dp[i]);
        }
        
        return mx;
    }
};