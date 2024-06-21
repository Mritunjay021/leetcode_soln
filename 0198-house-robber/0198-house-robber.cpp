class Solution {
public:

    int func(vector<int>&  nums,int n,vector<int>& dp)
    {
        if(n<0)
        return 0;
        else if(n==0)
        return nums[0];
        else if(dp[n]!=-1)
        return dp[n];
        int p=nums[n]+func(nums,n-2,dp);
        int np=func(nums,n-1,dp);
        return dp[n]=max(p,np);
    }

    int rob(vector<int>& nums) 
    {
        vector<int> dp(nums.size()+1,-1);
        return func(nums,nums.size()-1,dp);    
    }
};