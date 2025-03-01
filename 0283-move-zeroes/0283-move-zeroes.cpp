class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        if(nums.size()==1)
        return;
        
        int i=0,j=0;

        while(i<nums.size())
        {
            if(nums[i]==0)
            i++;
            else
            {
                swap(nums[i],nums[j]);
                j++;
                i++;
            }
        }    
    }
};