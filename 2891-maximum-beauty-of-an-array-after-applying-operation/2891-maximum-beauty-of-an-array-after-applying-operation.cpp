class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        int i=0,j=1,c=1;
        while(j<n)
        {
            if(nums[j]-nums[i]<=2*k)
            j++;
            else
            {
                while(nums[j]-nums[i]>2*k)
                i++;
            }
            c=max(c,j-i);
        }    

        return c;
    }
};