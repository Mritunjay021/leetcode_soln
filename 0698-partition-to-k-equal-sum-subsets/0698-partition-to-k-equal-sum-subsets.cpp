class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        for (auto it : nums)
            sum += it;

        if (sum % k != 0)
            return false;

        int target = sum / k;
        vector<bool> used(n, false);

        sort(nums.begin(), nums.end(), greater<int>());

        return func(nums, used, 0, target, 0, k);
    }
    
    bool func(vector<int>& nums, vector<bool>& used, int start, int val, int sum, int k) 
    {
        if (k == 0) return true;
        
        if (sum == val) 
        return func(nums, used, 0, val, 0, k-1);
        
        for (int i = start; i < nums.size(); i++) 
        {
            if (used[i] || sum + nums[i] > val) continue;
            
            used[i] = true;

            if (func(nums, used, i + 1, val, sum + nums[i], k)) 
            return true;

            used[i] = false;
            
        }
        
        return false;
    }
};