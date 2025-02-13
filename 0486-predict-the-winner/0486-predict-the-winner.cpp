class Solution {
public:
    bool func(vector<int>& nums, int s1, int s2, int i, int j, int k) 
    {
        if(i > j) 
        {
            return s1 >= s2; 
        }
        
        if(k)
        {
            return func(nums, s1 + nums[i], s2, i + 1, j, !k) || 
                   func(nums, s1 + nums[j], s2, i, j - 1, !k);
        } 
        else
        {
            return func(nums, s1, s2 + nums[i], i + 1, j, !k) && 
                   func(nums, s1, s2 + nums[j], i, j - 1, !k);
        }
    }
    
    bool predictTheWinner(vector<int>& nums) {
        if(nums.size() <= 1) return true;  
        return func(nums, 0, 0, 0, nums.size() - 1, 1);
    }
};