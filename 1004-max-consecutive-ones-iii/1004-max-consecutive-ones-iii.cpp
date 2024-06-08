class Solution
{
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int l=0,r=0,mx=0,nz=0,len=0;
        while(r<nums.size())
        {
            if(nums[r]==0)
            nz++;
            while(nz>k)
            {
                if(nums[l]==0)
                nz--;
                l++;
            }
            len=r-l+1;
            mx=max(mx,len);
            r++;
        }
        return mx;
    }
};