class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i+=3)
        {
            if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2])
            continue;
            else
            return nums[i];
        }    
        return nums[nums.size()-1];
    }
};