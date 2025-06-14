class Solution {
public:

    int func(vector<int>& nums,int m)
    {
        int c=1,s=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(s+nums[i]<=m)
            s+=nums[i];
            else
            {
                s=nums[i];
                c++;
            }
        }
        return c;
    }

    int splitArray(vector<int>& nums, int k) 
    {
        int l=INT_MIN,h=0;

        for(int i:nums)
        {
            l=max(l,i);
            h+=i;
        }    

        while(l<=h)
        {
            int m=(l+h)/2;
            int re=func(nums,m);
            if(re>k)
            l=m+1;
            else
            h=m-1;
        }
        return l;
    }
};