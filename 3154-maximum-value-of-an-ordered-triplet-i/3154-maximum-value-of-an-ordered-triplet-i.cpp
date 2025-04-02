class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        long long mx=0;
        int n=nums.size();
        int a=nums[0];

        vector<int> rm(n,-1);
        rm[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rm[i]=max(nums[i],rm[i+1]);
        }

        for(int i=1;i<n-1;i++)
        {
            mx = max(mx, (long long)(a - nums[i]) * (long long)rm[i+1]);
            a=max(a,nums[i]);
        }    

        return mx;
    }
};