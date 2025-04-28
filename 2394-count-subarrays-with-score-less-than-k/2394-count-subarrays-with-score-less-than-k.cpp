class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        int l=0,r=0;
        long long c=0,sm=0;

        while(r<nums.size())
        {
            sm+=nums[r];

            while(sm*(r-l+1)>=k && l<=r)
            {
                sm-=nums[l];
                l++;
            }
            c+=r-l+1;
            r++;
        }    

        return c;
    }
};