class Solution {
public:
    int func(vector<int>&  arr, int n, int sum, int i, int s, vector<vector<int>>& dp) {
        if (s > sum)
            return 0;
        if (i == n)
            return s == sum;
        if (dp[i][s] != -1)
            return dp[i][s];

        int c1 = func(arr, n, sum, i + 1, s + arr[i], dp);
        int c2 = func(arr, n, sum, i + 1, s, dp);

        return dp[i][s] = (c1 + c2) ;
    }
    
    
    int countPartitions(int n, int d, vector<int>& arr) 
    {
        int ts=0;
        for(int i=0;i<n;i++)
        ts+=arr[i];
        vector<vector<int>> dp(n, vector<int>(ts + 1, -1));
        if(ts-d<0 || (ts-d)%2) return false;
        
        return func(arr, n, (ts-d)/2, 0, 0, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return countPartitions(nums.size(),target,nums);  
    }
};