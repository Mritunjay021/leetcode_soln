class Solution {
public:
    int help(vector<int>& nums, int s,int i,int p,int sum,vector<vector<int>>& dp) 
    {
        if(s==0)
        return p;
        if (i == sum-1) 
        {
            return 0;
        }
        if(dp[i][s]!=-1)
        return dp[i][s];
        
        int nt = help(nums, s,i + 1, p,sum,dp);
        int t = 0;
        if (s >= nums[i])
            t = help(nums,s - nums[i],i, p * nums[i],sum,dp);
        
        
        return dp[i][s]=max(t, nt);
    }
    
    int integerBreak(int s) 
    {
        vector<int> nums;
        int su=1;
        for (int i = 1; i < s; i++) 
        { 
            nums.push_back(i);
            su+=i;
        }
        vector<vector<int>> dp(nums.size()+1,vector<int> (su+1,-1));
        return help(nums,s,0,1,s,dp);
    }
};