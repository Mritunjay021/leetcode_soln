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
        if(n==0)
        return nums[0];
        int n=nums.size();
        vector<int> dp(n+1,-1);
        vector<int> dp1(n+1,-1);
        int a1= func(nums,n-2,dp);
        nums.erase(nums.begin());
        int a2=func(nums,n-2,dp1);
        return max(a1,a2);    
    }
};