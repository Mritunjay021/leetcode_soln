class Solution {
public:
    int help(vector<int>& nums, int s,int i,int p,int sum) 
    {
        if(s==0)
        return p;
        if (i == sum-1) 
        {
            return 0;
        }
        int t = 0;
        if (s >= nums[i])
            t = help(nums,s - nums[i],i, p * nums[i],sum);
        
        int nt = help(nums, s,i + 1, p,sum);
        
        return max(t, nt);
    }
    
    int integerBreak(int s) {
        vector<int> nums;
        //int s=1;
        for (int i = 1; i < s; i++) 
        { 
            nums.push_back(i);
        }
        int p=1;
        //vector<int> dp(s,-1);
        return help(nums,s,0,p,s);
    }
};