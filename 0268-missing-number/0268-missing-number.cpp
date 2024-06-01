class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int ds = nums.size(), gs = 0;
        for (int i = 0; i < nums.size(); i++) { gs += nums[i]; ds += i; }
        return ds-gs;
    }
};