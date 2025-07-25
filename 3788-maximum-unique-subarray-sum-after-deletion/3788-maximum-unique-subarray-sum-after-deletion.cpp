class Solution {
public:
    int maxSum(vector<int>& nums) 
    {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        int sm=nums[0]>0?nums[0]:0;

        for(int i=1;i<n;i++)
        {
            if(nums[i]>0 && nums[i]!=nums[i-1])
            sm+=nums[i];
        }

        if(sm==0)
        return nums[n-1];
        
        return sm;
    }
};