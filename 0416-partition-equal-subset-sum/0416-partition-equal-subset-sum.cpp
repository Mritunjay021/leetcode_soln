class Solution {
public:

    bool func(vector<int>& nums,int n,int i,int s,int k,vector<vector<int>>& dp)
    {
        if(i==n-1)
        return (k-s==s);
        if(dp[i][s]!=-1)
        return dp[i][s];
        bool p=func(nums,n,i+1,s+nums[i],k,dp);
        bool np=func(nums,n,i+1,s,k,dp);
        return dp[i][s]=p|np;
    }

    bool canPartition(vector<int>& nums) 
    {
        int k=0;
        for(int i=0;i<nums.size();i++)
        k+=nums[i];
        vector<vector<int>> dp(nums.size(),vector<int>(k,-1));
        return func(nums,nums.size(),0,0,k,dp);    
    }
};
