class Solution 
{
public:

    int maxProduct(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
        return nums[0];
        int l=0,r=1,re=0,k=nums[0];
        while(r<n)
        {
            if(k*nums[r]>k)
            {
                k*=nums[r];
                re=max(re,k);
                r++;
            }
            else
            {
                l=r;
                r++;
                k=1;
            }
        }
        return re;
    }
};