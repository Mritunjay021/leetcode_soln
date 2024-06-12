class Solution {
public:
    int func(vector<int>& nums,int k)
    {
        // if(k<0)
        // return 0;
        int l=0,r=0,c=0,n=0;
        while(r<nums.size())
        {
            if(nums[r]%2!=0)
            c++;
            while(c>k)
            {
                if((nums[l]%2)!=0)
                c--;
                l++;
            }
            //if(c>=1)
            n+=r-l+1;
            r++;
        }
        return n;
    }

    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        return func(nums,k)-func(nums,k-1);    
    }
};