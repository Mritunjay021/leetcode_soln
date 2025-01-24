class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) 
    {
        int c=0,mx=-1;
        for(int i=0;i<nums.size();i++)
        {
            mx=max(mx,nums[i]);

            if(i==mx)
            c++;
        }
        return c;
    }
};