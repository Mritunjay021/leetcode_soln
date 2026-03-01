class Solution {
public:

    bool func(vector<int>& nums,int m,int b)
    {
        int k=0;b--;
        for(int i=1;i<nums.size();i++)
        {
            k+=nums[i]-nums[i-1];

            if(b==0)
            break;

            if(k>=m)
            {
                b--;
                k=0;
            }
            
        }
        return b==0;
    }

    int maxDistance(vector<int>& nums, int b) 
    {
        sort(nums.begin(),nums.end());
        int l=1,h=nums[nums.size()-1]-nums[0];

        while(l<=h)
        {
            int m=(l+h)/2;

            if(func(nums,m,b))
            l=m+1;
            else
            h=m-1;
        }    
        return h;
    }
};