class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,c=0;

        for(int i=0;i<n;i++)
        {
            if(abs(nums[i]-nums[l])<=k)
            continue;
            else
            {
                c++;
                l=i;
                i--;
            }
        }  
        return c+1;  
    }
};