class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int mx=*max_element(nums.begin(),nums.end());

        int l=0,r=0;
        long long c=0,re=0;

        while(r<nums.size())
        {
            if(nums[r]==mx)
            c++;

            while (c == k) 
            {
                re += (nums.size() - r); 

                if (nums[l] == mx)
                c--;

                l++;
            }

            r++;
        }

        return re;

    }
};