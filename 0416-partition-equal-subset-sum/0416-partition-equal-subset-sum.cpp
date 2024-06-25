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

    bool isSubsetSum(vector<int>arr, int sum)
    {
        // code here 
        //vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
        vector<vector<bool>>dp(arr.size(),vector<bool>(sum+1,0));
        for(int i=0;i<arr.size();i++)
        dp[i][0]=true;
        //dp[0][arr[0]]=true;
        
        for(int i=1;i<arr.size();i++)
        {
            for(int j=1;j<=sum;j++)
            {
                bool nt =dp[i-1][j];
                bool t=false;
                if(arr[i]<=j)
                t=dp[i-1][j-arr[i]];
                dp[i][j]=t|nt;
            }
        }
        
        return dp[arr.size()-1][sum];
    }

    bool canPartition(vector<int>& nums) 
    {
        int k=0;
        for(int i=0;i<nums.size();i++)
        k+=nums[i];

        // vector<vector<int>> dp(nums.size(),vector<int>(k,-1));
        // return func(nums,nums.size(),0,0,k,dp);

        if(k%2) return false;

        return isSubsetSum(nums,k/2);
    }
};
