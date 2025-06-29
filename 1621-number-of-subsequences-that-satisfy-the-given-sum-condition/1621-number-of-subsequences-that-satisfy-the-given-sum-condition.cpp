class Solution {
public:

    int mod=1e9+7;

    int numSubseq(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());

        int l=0,r=nums.size()-1,c=0;

        vector<int> powers(r+1);
        powers[0] = 1;
        for (int i = 1; i < r+1; i++) {
            powers[i] = (powers[i-1] * 2) % mod;
        }

        while(l<=r)
        {
            if(nums[l]+nums[r]>target)
            {
                if(nums[r]*2<=target)
                c++;

                r--;
            }
            else
            {
                c=(c+(powers[r-l])%mod)%mod;
                l++;
            }
        }

        return c;
    }
};