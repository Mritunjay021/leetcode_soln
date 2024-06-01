class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        if(target<nums[0])
        return 0;
        else if(target>nums[nums.size()-1])
        return nums.size();

        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(target==nums[mid])
            return mid;
            else if(nums[mid]<target && nums[mid+1]>target) return mid+1;

            else if(nums[mid]>target && nums[mid-1]<target) return mid;

            else if(target < nums[mid])
            r=mid-1;

            else l=mid+1;
        }    
        return -1;
    }
};