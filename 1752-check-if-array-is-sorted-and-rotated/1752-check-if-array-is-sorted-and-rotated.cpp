class Solution {
public:
    bool check(vector<int>& nums)
    {
        int i=0;
        int n=nums.size();
        while(i<n-1 && nums[i+1]>=nums[i])
        {
            i++;
        }
        if( i == n-1)
        return true;
        
        i++;
        while(i<n-1 && nums[i+1] >= nums[i])
        i++;
        if( i == n-1 && nums[i] <= nums[0])
        return true;
        else
        return false;
    }
};