class Solution {
public:

    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int n=nums.size();
        
        if(n<3)
        return 0;
        
        int l=0,r=1,diff=nums[1]-nums[0],c=0;
        while(r<n-1)
        {
            int d=nums[r+1]-nums[r];

            if(d!=diff)
            {
                diff=d;
                l=0;
            }
            else
            l++;

            r++;c+=l;
        }
        return c;
    }
};