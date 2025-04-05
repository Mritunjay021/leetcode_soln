class Solution {
public:

    int func(vector<int>& nums,int i,int s)
    {
        if(i==nums.size())
        return s;

        return func(nums,i+1,s^nums[i])+func(nums,i+1,s);
    }

    int subsetXORSum(vector<int>& nums) 
    {
        return func(nums,0,0);
    }
};