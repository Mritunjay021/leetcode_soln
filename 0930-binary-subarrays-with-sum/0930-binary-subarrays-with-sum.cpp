class Solution {
public:
    int val(vector<int> &nums,int g)
    {
        if(g<0)
        return 0;
        int r=0,l=0,s=0,n=0;
        while(r<nums.size())
        {
            s+=nums[r];
            while(s>g)
            {
                s-=nums[l];
                l++;
            }
            n+=r-l+1;
            r++;
        }
        return n;
    }
    
    
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        return val(nums,goal)-val(nums,goal-1);
    }
};