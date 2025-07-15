class Solution {
public:
    int func(vector<int>& nums,int i,vector<int>& dp)
    {
        if(i>=nums.size())
        return 0;

        if(dp[i]!=-1)
        return dp[i];

        int p=nums[i]+func(nums,i+2,dp);
        int np=func(nums,i+1,dp);

        return dp[i]=max(p,np);
    }

    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
        return nums[0];
        
        vector<int> dp(n,-1);

        int x=func(nums,1,dp);

        nums.erase(nums.end());
        vector<int> dp1(n-1,-1);

        int y=func(nums,0,dp1);

        return max(x,y);
    }
};