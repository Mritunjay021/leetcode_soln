class Solution {
public:

    int n;

    int func(vector<int>& nums,int mx,int i,int cr,vector<vector<int>>& dp)
    {
        if(i==n)
        {
            if(mx==cr)
            return 1;

            return 0;
        }

        if(dp[i][cr]!=-1)
        return dp[i][cr];

        int p=func(nums,mx,i+1,cr|nums[i],dp);
        int np=func(nums,mx,i+1,cr,dp);

        return dp[i][cr]=p+np;
    }

    int countMaxOrSubsets(vector<int>& nums) 
    {
        n=nums.size(); 

        int mx=0; 

        for(auto it:nums)
        {
            mx|=it;
        }  

        vector<vector<int>> dp(n+1,vector<int>(mx+1,-1));

        return func(nums,mx,0,0,dp);
    }
};