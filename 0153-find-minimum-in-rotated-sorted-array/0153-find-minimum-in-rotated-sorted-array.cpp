class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)
        {
            if(n==1)
            return nums[0];
            else
            return min(nums[0],nums[1]);
        }
        if (nums[0] < nums[n - 1])
            return nums[0];

        int s = 0, e = n - 1;
        while (s < e) {
            int mid = (s + e) / 2;
            if (nums[s] < nums[mid] && nums[e] < nums[mid] && nums[mid]<nums[mid+1])
                s = mid;
            else if(nums[s] < nums[mid] && nums[e] < nums[mid] && nums[mid]>nums[mid+1])
            return nums[mid+1];
            else if (nums[s] > nums[mid] && nums[e] > nums[mid] &&
                     nums[mid - 1] > nums[mid])
                return nums[mid];
            else if (nums[s] > nums[mid] && nums[e] > nums[mid] &&
                     nums[mid - 1] < nums[mid])
                e = mid;
        }
        return 0;
    }
};