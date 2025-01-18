class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        if(nums.size()==1)
        return nums[0];

        int l=0,u=nums.size()-1;

        while(l<u)
        {
            int m=(l+u)/2;
            if(m%2)
            m--;

            if(nums[m]==nums[m+1])
            l=m+2;
            else
            u=m-1;
        }    
        return nums[l];
    }
};